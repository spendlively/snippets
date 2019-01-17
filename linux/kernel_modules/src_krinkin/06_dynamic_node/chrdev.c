//Для правильной инициализации модуля
#include <linux/init.h>
#include <linux/module.h>
//Для доступа к файловой системе,
//т.к. мы получаем достум к модулю через файловый интерфейс
#include <linux/fs.h>
//Чтобы передавать данные из пространства пользователя в ядро
#include <linux/uaccess.h>
//Для выделения памяти (тут хранится PAGE_SIZE)
#include <linux/slab.h>
//Определения для создания символьных устройств
#include <linux/cdev.h>

/**
 * Глобальные переменные для реализации символьного устройства.
 * Все они статические, чтобы не экспортировать наружи никакие имена
 */

/**
 * Идентификатор первого устройства в цепочке
 */
static dev_t first;

/**
 * Счетчик устройств
 */
static unsigned int count = 1;

/**
 * Старший номер устройства (Vendor Id)
 * Исправил 700 на 500 из-за ошибки:
 * CHRDEV "mychrdev" major requested (700) is greater than the maximum (512)
 */
static int my_major = 500;

/**
 * Младший номер устройства (Vendor Id)
 */
static int my_minor = 0;

/**
 * Структура для устройства,
 * содержит все операции,
 * кот. мы можем выполнять над символьным устройством
 */
static struct cdev *my_cdev;

/**
 * Имя модуля, кот. будет видно пользователю
 */
#define MYDEV_NAME "mychrdev"

/**
 * Размер буфера кот. будет использовать пользователь
 * (10 страниц памяти)
 */
#define KBUF_SIZE (size_t) ((10) * PAGE_SIZE)

/**
 * Параметр для динамического создания ноды устройства
 */
static struct class *my_class;

/**
 * Прототип для файловой операции open
 */
static int mychrdev_open(struct inode *inode, struct file *file){

    //Для каждого открытия заводим свой буфер устройства
    //и выделяем под него память в ядре
    char *kbuf = kmalloc(KBUF_SIZE, GFP_KERNEL);

    //Счетчик для количества ресурсов
    static int counter = 0;

    //Сохраним адрес этого буффера в структуре файла
    file->private_data = kbuf;

    printk(KERN_INFO "+ Opening device %s\n", MYDEV_NAME);

    counter++;

    //Выводим cчетчик для количества ресурсов
    printk(KERN_INFO "+ Counter: %d\n", counter);

    //Выводим количество пользователей с точки зрения ядра
    printk(KERN_INFO "+ Module refcounter: %d\n", module_refcount(THIS_MODULE));

    return 0;
}

/**
 * Прототип для файловой операции освобождения устройства
 */
static int mychrdev_release(struct inode *inode, struct file *file){

    char *kbuf = file->private_data;

    printk(KERN_INFO "+ Releasing device %s\n", MYDEV_NAME);

    //Освобождаем память, выделенную под буфер устройства
    printk(KERN_INFO "+ Free buffer\n");
    //Перед удалением проверяем что память была выделена
    if(kbuf){
        kfree(kbuf);
    }
    //Обнуляем во избежание ошибок
    kbuf = NULL;
    file->private_data = NULL;

    return 0;
}

/**
 * Прототип для файловой операции read.
 * Макрос __user маркирует параметр buf как пришедший из user space (требующий доп проверки)
 * lbuf - длина буфера
 * ppos - смещение внутри буфера по которому мы будем читать данные
 */
static ssize_t mychrdev_read(struct file *file, char __user *buf, size_t lbuf, loff_t *ppos){

    //буфер устройства
    char *kbuf = file->private_data;

    //Копируем байты из буфера в пространство пользователя
    int nbytes = lbuf - copy_to_user(buf, kbuf + *ppos, lbuf);
    *ppos += nbytes;

    printk(KERN_INFO "+ Reading device %s nbytes = %d, ppos = %d \n", MYDEV_NAME, nbytes, (int)*ppos);

    return nbytes;
}

/**
 * Прототип для файловой операции write
 *
 */
static ssize_t mychrdev_write(struct file *file, const char __user *buf, size_t lbuf, loff_t *ppos){

    //буфер устройства
    char *kbuf = file->private_data;

    int nbytes = lbuf - copy_from_user(kbuf + *ppos, buf, lbuf);
    *ppos += nbytes;

    printk(KERN_INFO "+ Writing into device %s nbytes = %d, ppos = %d \n", MYDEV_NAME, nbytes, (int)*ppos);

    return nbytes;
}

static loff_t mychrdev_lseek(struct file *file, loff_t offset, int orig){

    loff_t testpos;

    switch(orig){
        case SEEK_SET:
            testpos = offset;
            break;
        case SEEK_CUR:
            testpos = file->f_pos + offset;
            break;
        case SEEK_END:
            testpos = KBUF_SIZE + offset;
            break;
        default:
            return ~EINVAL;
    }

    testpos = testpos < KBUF_SIZE ? testpos : KBUF_SIZE;
    testpos = testpos >= 0 ? testpos : 0;
    file->f_pos = testpos;

    printk(KERN_INFO "+ Seeking to %ld position\n, ", (long)testpos);

    return testpos;
}

/**
 * Определяем структура для файловых операций,
 * в которую поместим указатели на созданные файловые функции
 */
static const struct file_operations mycdev_fops = {

   .owner = THIS_MODULE,
   .read = mychrdev_read,
   .write = mychrdev_write,
   .open = mychrdev_open,
   .release = mychrdev_release,
   .llseek = mychrdev_lseek
};


/**
 * функция инициализации
 */
static int __init init_chrdev( void ) {
    printk( KERN_INFO " + Hello, loading!\n" );

    /**
     * @TODO: проверка на наличие ошибок при веделении памяти
     */

    //Инициализируем первое устройство
    //Макрос MKDEV используется для создание inode в файловой системе
    first = MKDEV (my_major, my_minor);

    //Регистрируем регион - множество идентифиаторов для возможных
    //экземпляров нашего устройства или нашего модуля
    register_chrdev_region(first, count, MYDEV_NAME);

    /**
     * @TODO: проверка на наличие ошибок при регистрации устройств
     */

    //Выдялем память под структуру содержащую все аттрибуты устройства
    my_cdev = cdev_alloc();

    //Инициализация структуры связанной с файловыми операциями
    //&mycdev_fops - указатель на структуру с файловыми операциями
    cdev_init(my_cdev, &mycdev_fops);

    //Добавляем дерево устройств (1 устройство)
    cdev_add(my_cdev, first, count);

    //Динамическое создание файла устройства
    my_class = class_create(THIS_MODULE, "my_class");
    /**
     * @TODO: проверка возвращаемого значения class_create
     */
    device_create(my_class, NULL, first, "%s", "my_chrdev");
    printk(KERN_INFO "+ Creating device class %s\n", MYDEV_NAME);

    return 0;
}

static void __exit cleanup_chrdev( void ) {

    printk(KERN_INFO "+ Leaving!\n" );

    //Разрегистрирование устройства
    device_destroy(my_class, first);
    class_destroy(my_class);

    //Деинициализируем устройство
    if(my_cdev){
        cdev_del(my_cdev);
    }
    unregister_chrdev_region(first, count);
}

module_init( init_chrdev );
module_exit( cleanup_chrdev );

/**
 * Лицензия
 */
MODULE_LICENSE( "GPL" );

