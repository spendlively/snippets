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
 * Буфер устройства
 */
static char *kbuf;

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
 * Прототип для файловой операции open
 */
static int mychrdev_open(struct inode *inode, struct file *file){

   printk(KERN_INFO "+ Opening device %s\n", MYDEV_NAME);
   return 0;
}

/**
 * Прототип для файловой операции освобождения устройства
 */
static int mychrdev_release(struct inode *inode, struct file *file){

    printk(KERN_INFO "+ Releasing device %s\n", MYDEV_NAME);
    return 0;
}

/**
 * Прототип для файловой операции read.
 * Макрос __user маркирует параметр buf как пришедший из user space (требующий доп проверки)
 * lbuf - длина буфера
 * ppos - смещение внутри буфера по которому мы будем читать данные
 */
static ssize_t mychrdev_read(struct file *file, char __user *buf, size_t lbuf, loff_t *ppos){

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

    int nbytes = lbuf - copy_from_user(kbuf + *ppos, buf, lbuf);
    *ppos += nbytes;

    printk(KERN_INFO "+ Writing into device %s nbytes = %d, ppos = %d \n", MYDEV_NAME, nbytes, (int)*ppos);

    return nbytes;
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
   .release = mychrdev_release
};


/**
 * функция инициализации
 */
static int __init init_chrdev( void ) {
   printk( KERN_INFO " + Hello, loading!\n" );

   //Выделяем память из специального пуля ядра GFP_KERNEL
   kbuf = kmalloc(KBUF_SIZE, GFP_KERNEL);

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

   return 0;
}

static void __exit cleanup_chrdev( void ) {
   printk( "+ module test unloaded!\n" );
}

module_init( init_chrdev );
module_exit( cleanup_chrdev );

/**
 * Лицензия
 */
MODULE_LICENSE( "GPL" );
