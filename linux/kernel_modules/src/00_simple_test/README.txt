
//Сборка модуля ядра
make

//Удаление ненужных файлов
make clean

//Запуск мониторинга лога (в новом окне)
dmesg -w
//или
tail -n0 -f /var/log/syslog

//Загрузка модуля ядра test.ko
sudo insmod test.ko

//Выгрузка модуля ядра test.ko
sudo rmmod test.ko

//В логе появится информация о загрузке/выгрузке модуля
