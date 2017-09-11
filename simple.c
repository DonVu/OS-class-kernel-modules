#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/* The initial calling function */
int simple_init(void)
{
	printk(KERN_INFO "Loading Module\n");

	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void)
{
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
