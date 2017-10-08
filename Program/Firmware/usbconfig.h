/*
 * This is prepared by Prakash Gautam For specific purpose and doesn't 
 * hold the copyright and the file may be from other source not known 
 * to the author. 
 */

#ifndef __usbconfig_h_included__
#define __usbconfig_h_included__


#define USB_CFG_IOPORTNAME      	D
#define USB_CFG_DMINUS_BIT      	4
#define USB_CFG_DPLUS_BIT       	2

#define USB_CFG_CLOCK_KHZ       	(F_CPU/1000 * 16)




#define  USB_CFG_VENDOR_ID       	0xc0, 0x16
#define  USB_CFG_DEVICE_ID       	0xe8, 0x03
#define USB_CFG_DEVICE_VERSION  	0x00, 0x01

#define USB_CFG_VENDOR_NAME     	'P', 'R', 'A', 'N', 'P', 'H', 'Y', '-', \
									'C', 'O', 'R', 'R', 'U', 'P', 'T'
#define USB_CFG_VENDOR_NAME_LEN 	15

#define USB_CFG_DEVICE_NAME     	'O','S','C','I','L','L','O','S','C','O','P','E'
#define USB_CFG_DEVICE_NAME_LEN 	12


#define USB_CFG_IS_SELF_POWERED     0
#define USB_CFG_MAX_BUS_POWER       50


#define USB_CFG_CHECK_CRC       			0
#define USB_CFG_HAVE_INTRIN_ENDPOINT    	1
#define USB_CFG_HAVE_INTRIN_ENDPOINT3   	0
#define USB_CFG_EP3_NUMBER              	3
#define USB_CFG_IMPLEMENT_HALT          	0
#define USB_CFG_SUPPRESS_INTR_CODE      	0
#define USB_CFG_INTR_POLL_INTERVAL      	100

#define USB_CFG_IMPLEMENT_FN_WRITE      	0
#define USB_CFG_IMPLEMENT_FN_READ       	0
#define USB_CFG_IMPLEMENT_FN_WRITEOUT   	0
#define USB_CFG_HAVE_FLOWCONTROL        	0
#define USB_CFG_DRIVER_FLASH_PAGE       	0
#define USB_CFG_LONG_TRANSFERS          	0

#define USB_COUNT_SOF                   	0
#define USB_CFG_CHECK_DATA_TOGGLING     	0

#define USB_CFG_HAVE_MEASURE_FRAME_LENGTH   0

#define USB_USE_FAST_CRC                	0


#define USB_CFG_DEVICE_CLASS        			0
#define USB_CFG_DEVICE_SUBCLASS     			0
#define USB_CFG_INTERFACE_CLASS     			3
#define USB_CFG_INTERFACE_SUBCLASS  			0
#define USB_CFG_INTERFACE_PROTOCOL  			0
#define USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH    52

#define USB_CFG_DESCR_PROPS_DEVICE              	0
#define USB_CFG_DESCR_PROPS_CONFIGURATION       	0
#define USB_CFG_DESCR_PROPS_STRINGS             	0
#define USB_CFG_DESCR_PROPS_STRING_0            	0
#define USB_CFG_DESCR_PROPS_STRING_VENDOR       	0
#define USB_CFG_DESCR_PROPS_STRING_PRODUCT      	0
#define USB_CFG_DESCR_PROPS_STRING_SERIAL_NUMBER 	0
#define USB_CFG_DESCR_PROPS_HID                     0
#define USB_CFG_DESCR_PROPS_HID_REPORT              0
#define USB_CFG_DESCR_PROPS_UNKNOWN                 0


#define usbMsgPtr_t unsigned short

#endif
