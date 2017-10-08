
#include<usb.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<iomanip>

using namespace std;

#define USB_LED_OFF 				0
#define USB_LED_ON  				1

#define READ_CHANNEL_ONE			5

static int usbGetDescriptorString(usb_dev_handle*, int, int,char*,int);
static usb_dev_handle* usbOpenDevice(int,char*,int,char*);



int main(int argc, char **argv) 
{
    usb_dev_handle *Handle = NULL;
	char Buffer[256];
	Handle = usbOpenDevice(0x16C0, const_cast<char*>("PRANPHY-CORRUPT"), 0x03E8,const_cast<char*>("OSCILLOSCOPE"));
	if(!Handle)
	{
		cout<<"Didn't find device specified "<<endl;
		return 0;
	}
	cout<<" Hello Boys I am here "<<endl;
	int NumberOfBytesRead=0;
	for(;;){
		NumberOfBytesRead = usb_control_msg(Handle,USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN,READ_CHANNEL_ONE, 0, 0, (char *)Buffer, sizeof(Buffer), 5000);
		if(NumberOfBytesRead<0)
			cout<<"Did not read any data from teh Microcontroller"<<endl;
		cout<<" Number of bytes read is "<<NumberOfBytesRead<<endl;
		cout<<" Now printing the read buffer"<<endl;
		
		for(int Cnt=0;Cnt<NumberOfBytesRead;Cnt++)
			cout<<static_cast<unsigned short>(Buffer[Cnt])<<" ";
		cout<<endl;
	}	
	cout<<" Buffer printing finished "<<endl;
	usb_close(Handle);
    return 0;
}



static int usbGetDescriptorString(usb_dev_handle *dev, int index, int langid,char *buf, int buflen) 
{
    char buffer[256];
    int rval, i;

    // make standard request GET_DESCRIPTOR, type string and given index 
    // (e.g. dev->iProduct)
    rval = usb_control_msg(dev,USB_TYPE_STANDARD | USB_RECIP_DEVICE | USB_ENDPOINT_IN,USB_REQ_GET_DESCRIPTOR, (USB_DT_STRING << 8) + index, langid,buffer, sizeof(buffer), 1000);
    if(rval < 0) // error
        return rval;

    // rval should be bytes read, but buffer[0] contains the actual response size
    if((unsigned char)buffer[0] < rval)
        rval = (unsigned char)buffer[0]; // string is shorter than bytes read

    if(buffer[1] != USB_DT_STRING) // second byte is the data type
        return 0; // invalid return type

    // we're dealing with UTF-16LE here so actual chars is half of rval,
    // and index 0 doesn't count
    rval /= 2;

    /* lossy conversion to ISO Latin1 */
    for(i = 1; i < rval && i < buflen; i++) 
    {
        if(buffer[2 * i + 1] == 0)
            buf[i-1] = buffer[2 * i];
        else
            buf[i-1] = '?'; /* outside of ISO Latin1 range */
    }
    buf[i-1] = 0;

    return i-1;
}



static usb_dev_handle * usbOpenDevice(int vendor, char *vendorName, int product, char *productName) 
{
    struct usb_bus *bus;
    struct usb_device *dev;
    char devVendor[256], devProduct[256];

    usb_dev_handle * handle = NULL;

    usb_init();
    usb_find_busses();
    usb_find_devices();

    for(bus=usb_get_busses(); bus; bus=bus->next) 
    {
        for(dev=bus->devices; dev; dev=dev->next) 
        {                     
            if(dev->descriptor.idVendor != vendor || dev->descriptor.idProduct != product)
                continue;
            if(!(handle = usb_open(dev))) 
            {
                fprintf(stderr, "Warning: cannot open USB device: %sn", usb_strerror());
                continue;
            }
            if(usbGetDescriptorString(handle, dev->descriptor.iManufacturer,0x0409, devVendor, sizeof(devVendor)) < 0) 
            {
                fprintf(stderr,"Warning: cannot query manufacturer for device: %sn",usb_strerror());
                usb_close(handle);
                continue;
            }
            if(usbGetDescriptorString(handle, dev->descriptor.iProduct,0x0409, devProduct, sizeof(devVendor)) < 0)
            {
                fprintf(stderr,"Warning: cannot query product for device: %sn", usb_strerror());
                usb_close(handle);
                continue;
            }
            if(strcmp(devVendor, vendorName) == 0 && strcmp(devProduct, productName) == 0)
                return handle;
            else
                usb_close(handle);
        }
    }
    return NULL;
}

