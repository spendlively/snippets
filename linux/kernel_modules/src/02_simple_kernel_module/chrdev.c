#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/cdev.h>

static int __init init_chrdev(void)
{
	printk(KERN_INFO "Hello, loading"); //Без запятой
	return 0;
}

static int __exit cleanup_chrdev(void)
{
	printk(KERN_INFO "Leaving, loading"); //Без запятой
	return 0;
}

module_init(init_chrdev);
module_exit(cleanup_chrdev);

MODULE_LICENSE("GPL");
