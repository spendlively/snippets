#include <linux/init.h> 
#include <linux/module.h> 

MODULE_LICENSE( "GPL" ); 

static int __init test_init( void ) { 
   printk( "+ module test start!\n" ); 
   return 0; 
} 

static void __exit test_exit( void ) { 
   printk( "+ module test unloaded!\n" ); 
} 

module_init( test_init ); 
module_exit( test_exit );
