#pragma once

// TinyUSB configuration for RP2040 (device)

#define CFG_TUSB_RHPORT0_MODE   (OPT_MODE_DEVICE)
#define CFG_TUSB_OS             OPT_OS_PICO

// ---- DEVICE ----
#define CFG_TUD_ENABLED         1

// Enable HID
#define CFG_TUD_HID             1

// Disable others
#define CFG_TUD_CDC             0
#define CFG_TUD_MSC             0
#define CFG_TUD_MIDI            0
#define CFG_TUD_VENDOR          0

// HID endpoint size
#define CFG_TUD_HID_EP_BUFSIZE  64
