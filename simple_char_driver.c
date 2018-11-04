#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

int n_open(struct inode *pinode, struct file *pfile){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    return 0;
}
ssize_t n_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offet){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    return 0;
}
ssize_t n_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    return length;
}
int n_close(struct inode *pinode, struct file *pfile){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    return 0;
}

struct file_operations file_operations_n = {
    .owner = THIS_MODULE,
    .open = n_open,
    .read = n_read,
    .write = n_write,
    .release = n_close,
};

int simple_module_init(void){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    register_chrdev(240, "torack", &file_operations_n);
    return 0;
}
void simple_module_exit(void){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    unregister_chrdev(240, "charDrvTorack");
}
module_init(simple_module_init);
module_exit(simple_module_exit);