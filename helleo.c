#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

//probe function
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "[*] Pasiron Linux Pen Drive (%O4dX:%O4dX) plugged\n", id ->idVendor,id ->idProduct);
    return 0; 
};

//disconnect

static void pen_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "[*] Pasiron Linux Pen drive removed")
};


//usb_device_id
static struct usb_device_id pen_table =
{
    { USB_DEVICE{0x0781, 0x5406} }
    {}
};
MODULE_DEVICE_TABLE {usb, pen_table};

//usb driver
static struct usb_driver pen_driver =
{
    .name = "Pasiron Linux-USB Stick-Driver",
    .id_table = pen_table,
    .probe = pen_probe,
    .disconnect = pen_disconnect,
};
 


static int __init pen_init(void){
    int ret = -1;
    printk(KERN_INFO "[*]Pasiron Linux Constructor of driver ");
    printk(KERN_INFO "\t Registering Driver With Kernel");
    ret = usb_register(&pen_driver);
    printk(KERN_INFO "\t Registration is complate");
    return ret;
}

static void __exit pen_exit(void){
    //dergister
    printk(KERN_INFO "[*] Pasiron Linux Desttructor of driver");
    usb_deregister(&pen_driver);
    printk(KEY_INFO "\tunregestration complate!");

}

module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Morphy Kutay")
MODULE_DESCRIPTION("USB Pen Registration Driver") 
