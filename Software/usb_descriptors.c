#include "buttons.h"
#include "tusb_config.h"
#include "tusb.h"
#include "class/hid/hid.h"
#include <stdint.h>

#define USB_VID   0xCafe
#define USB_BCD   0x0200

//Devie Descriptor
static tusb_desc_device_t const desc_device = {

    .bLength            = sizeof(tusb_desc_device_t), //Rozmiar Device descriptor'a, wyrażony w bajtach
    .bDescriptorType    = TUSB_DESC_DEVICE,           //Identyfikator typu deskryptora. Dla Device descriptor'a to pole zawsze przyjmuje wartość 0x01
    .bcdUSB             = USB_BCD,                     //Identyfikator wersji specyfikacji USB, z którą zgodne jest urządzenie i jego deskryptory. Jeżeli urządzenie USB Full Speed lub Low Speed ma ustawione to pole na wartość 0x0200.

    .bDeviceClass       = TUSB_CLASS_MISC,            //To pole identyfikuje klasę do której przynależy urządzenie USB.
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,       //To pole identyfikuje subklasę, do której przynależy urządzenie. 
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,          //To pole identyfikuje protokół. Kody protokołów są definiowane przez USB-IF, oraz determinowane przez wartości pól: bDeviceClass i bDeviceSubClass.
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,     //Maksymalny rozmiar pakietu (podawany w bajtach) dla endpoint'u 0 (endpoint kontrolny). Poprawne są tylko wartości: 8, 16, 32, 64.Jedyną poprawną wartością dla USB High Speed jest 64.  

    .idVendor           = USB_VID,                    //Identyfikator producenta. Wartość przyznawana przez USB-IF. 
    .idProduct          = 0x4000,                    //Identyfikator produktu. Wartość definiowana przez producenta. 
    .bcdDevice          = 0x0100,                     //Numer wersji urządzenia. Sposób kodowania taki sam jak pola bcdUSB. 

    .iManufacturer      = 0x01,                       //Indeks String descriptor'a zawierający etykietę z opisem producenta
    .iProduct           = 0x02,                       //Indeks String descriptor'a zawierający etykietę z opisem produktu. 
    .iSerialNumber      = 0x03,                       //Indeks String descriptor'a zawierający etykietę z numerem seryjnym urządzenia. 

    .bNumConfigurations = 0x01                        //Liczba możliwych konfiguracji urządzenia. 
};

//Kiedy TinyUSB pyta o device descriptor
uint8_t const * tud_descriptor_device_cb(void)
{
  return (uint8_t const *) &desc_device;
};

//HID Report Descriptor
uint8_t const desc_hid_report[] = {
  TUD_HID_REPORT_DESC_KEYBOARD()
};

//Funkcja do HID Report Callback
uint8_t const * tud_hid_descriptor_report_cb(uint8_t instance)
{
  (void) instance;
  return desc_hid_report;
};

//Jeszcze Configuration Descriptor i String Descriptor i callbacki
