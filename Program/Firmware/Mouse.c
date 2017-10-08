

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>  
#include <util/delay.h>     

#include <avr/pgmspace.h>   
#include "usbdrv.h"
#include "oddebug.h"        

PROGMEM const char usbHidReportDescriptor[52] =
{
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x02,                    // USAGE (Mouse)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x09, 0x01,                    //   USAGE (Pointer)
    0xA1, 0x00,                    //   COLLECTION (Physical)
    0x05, 0x09,                    //     USAGE_PAGE (Button)
    0x19, 0x01,                    //     USAGE_MINIMUM
    0x29, 0x03,                    //     USAGE_MAXIMUM
    0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
    0x95, 0x03,                    //     REPORT_COUNT (3)
    0x75, 0x01,                    //     REPORT_SIZE (1)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0x95, 0x01,                    //     REPORT_COUNT (1)
    0x75, 0x05,                    //     REPORT_SIZE (5)
    0x81, 0x03,                    //     INPUT (Const,Var,Abs)
    0x05, 0x01,                    //     USAGE_PAGE (Generic Desktop)
    0x09, 0x30,                    //     USAGE (X)
    0x09, 0x31,                    //     USAGE (Y)
    0x09, 0x38,                    //     USAGE (Wheel)
    0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
    0x25, 0x7F,                    //     LOGICAL_MAXIMUM (127)
    0x75, 0x08,                    //     REPORT_SIZE (8)
    0x95, 0x03,                    //     REPORT_COUNT (3)
    0x81, 0x06,                    //     INPUT (Data,Var,Rel)
    0xC0,                          //   END_COLLECTION
    0xC0,                          // END COLLECTION
};

typedef struct{
    uchar   buttonMask;
    char    dx;
    char    dy;
    char    dWheel;
}report_t;

static report_t reportBuffer;
static int      sinus = 7 << 6, cosinus = 0;
static uchar    idleRate;   

static void advanceCircleByFixedAngle(void)
{
	char    d;

	#define DIVIDE_BY_64(val)  (val + (val > 0 ? 32 : -32)) >> 6 
    reportBuffer.dx = d = DIVIDE_BY_64(cosinus);
    sinus += d;
    reportBuffer.dy = d = DIVIDE_BY_64(sinus);
    cosinus -= d;
}

usbMsgLen_t usbFunctionSetup(uchar data[8])
{
	usbRequest_t    *rq = (void *)data;
	if((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS)
	{ 
        DBG1(0x50, &rq->bRequest, 1);   
        if(rq->bRequest == USBRQ_HID_GET_REPORT)
        {
            usbMsgPtr = (void *)&reportBuffer;
            return sizeof(reportBuffer);
        }
        else if(rq->bRequest == USBRQ_HID_GET_IDLE)
        {
            usbMsgPtr = &idleRate;
            return 1;
        }
        else if(rq->bRequest == USBRQ_HID_SET_IDLE)
            idleRate = rq->wValue.bytes[1];
    }
    return 0;
}

int __attribute__((noreturn)) main(void)
{
	uchar   i;

    wdt_enable(WDTO_1S);
    odDebugInit();
    DBG1(0x00, 0, 0);  
    usbInit();
    usbDeviceDisconnect();
    i = 0;
    while(--i)
    {
        wdt_reset();
        _delay_ms(1);
    }
    usbDeviceConnect();
    sei();
    DBG1(0x01, 0, 0);
    for(;;)
    {
        DBG1(0x02, 0, 0);
        wdt_reset();
        usbPoll();
        if(usbInterruptIsReady())
        {
            advanceCircleByFixedAngle();
            DBG1(0x03, 0, 0);
            usbSetInterrupt((void *)&reportBuffer, sizeof(reportBuffer));
        }
    }
}
