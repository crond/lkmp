#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>

int myint =3;
module_param(myint,int,S_IRUSR | S_IWUSR | S_IRGRP);

int myintarray[2];
module_param_array(myintarray,int, NULL,0000);
MODULE_PARM_DESC(myintarray,"A int array");

int myarray[4];
int count;
module_param_array(myarray,int,&count,0000);

static int __init ofd_init(void)
{
    int i=0;
    printk(KERN_INFO "WELCOME: OFD Regostered");
    printk(KERN_INFO "int:%d",myint);
    for(i=0;i< (sizeof(myintarray)/sizeof(int));i++)
        printk(KERN_INFO "int arr:%d: %d\n",i,myintarray[i]);
    
    printk(KERN_INFO "Got :%d as arg for array\n",count);

    for(i=0;i< count;i++)
        printk(KERN_INFO "int arr:%d: %d\n",i,myarray[i]);
    return 0; 
}
static void __exit ofd_exit(void)
{
    printk(KERN_INFO "EXIT: ofd unregisterwed");
}

module_init(ofd_init);
module_exit(ofd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("crond");
MODULE_DESCRIPTION("First LFY LDD");
