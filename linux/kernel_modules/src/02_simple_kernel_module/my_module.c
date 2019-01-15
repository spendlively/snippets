#include <linux/module.h>

int init_module(void)
{
	printk(KERN_INFO "Hello, loading"); //Без запятой
}

int cleanup_module(void)
{
	printk(KERN_INFO "Leaving, loading"); //Без запятой
}

MODULE_LICENSE("GPL");
