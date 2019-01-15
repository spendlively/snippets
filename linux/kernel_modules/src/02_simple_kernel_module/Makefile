obj-m += chrdev.o

# make -C /lib/modules/$(uname -r)/build M=$PWD modules_install

all:
	make -C /lib/modules/$(shell uname -r)/build modules

clean:
	make -C /lib/modules/$(shell uname -r)/build clean

load: all
	sudo insmod chrdev.ko
	sudo dmesg -c 

unload:
	sudo rmmod chrdev.ko
	sudo dmesg -c 

