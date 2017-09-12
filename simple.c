#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday {
	int day;
	int month;
	int year;
	struct list_head list; /* kernel's list structure */
};

/* The initial calling function */
int simple_init(void)
{
	static LIST_HEAD(birthday_list); 	
	int init_day = 1;
	int init_month = 1;
	int init_year = 1900;
	int i;
	struct birthday *ptr;

	printk(KERN_INFO "Loading Module\n");
	
	// Define and initialize birthday_list


	// Initialize & add five birthday structs
	for (i = 0; i < 5; ++i){
		struct birthday *person;

		person = kmalloc(sizeof(*person), GFP_KERNEL);
		person->day = init_day * i;
		person->month = init_month + i;
		person->year = init_year + i;
		INIT_LIST_HEAD(&person->list); //Initialize list member

		// Add new struct to list
		list_add_tail(&person->list, &birthday_list);
	}

	// Traverse the linked list
	list_for_each_entry(ptr, &birthday_list, list){
		printk(KERN_INFO "day = %d, month = %d, year = %d\n ", ptr->day, ptr->month, ptr->year);
	}
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
