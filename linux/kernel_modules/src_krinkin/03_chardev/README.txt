
//Сборка модуля ядра
make

//Удаление ненужных файлов
make clean

//Запуск мониторинга лога (в новом окне)
dmesg -w
//или
tail -n0 -f /var/log/syslog

//Создать ноду устройства символьного (с) устройства
sudo mknod /dev/chrdev c 500 0

//Для удобства даем права на запись и чтение
sudo chmod a+rw /dev/chrdev

//Загрузка модуля ядра test.ko
sudo insmod chrdev.ko

//Проверка наличия модуля
lsmod | grep chrdev

//Проверка чтоб модуль загружен и жив в системе ядра
cat /proc/modules | grep chrdev

//Запись в устройство
echo "!" > /dev/chrdev

//Выгрузка модуля ядра test.ko
sudo rmmod chrdev.ko
//либо
sudo rmmod chrdev

//Удаление ноды
sudo rm /dev/chrdev

//В логе появится информация о загрузке/выгрузке модуля
