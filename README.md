# LYRA-Macropad-Work-in-Progress-

Macropad on custom PCB 

# Overview

A compact 9-key macropad featuring a clickable rotary encoder and a 1-inch monochrome OLED display for mode indication and visual feedback.
Originally based on Seeed Xiao RP2040, the final version integrates the RP2040 directly onto a custom PCB.

# Features

* 9 mechanical keys arranged in a 3×3 layout

* Rotary encoder with a clickable knob for mode switching

* Three programmable modes, for example:

   * Music control (volume, play/pause, next/prev)

   * Program shortcuts (e.g., Photoshop, CAD, or IDE macros)

   * Media / general desktop shortcuts

* 1-inch OLED display for mode display and live status

Designed for QMK/VIA or custom firmware (in the making)

# Planned Improvements

* Integrated ATmega32U4 or RP2040 MCU directly on PCB

* Optional USB-C connector

* Support for battery operation and low-power sleep modes

* Case design refinements for 3D printing or CNC milling

# Schematic

<img width="1778" height="1177" alt="image" src="https://github.com/user-attachments/assets/cd180d5d-ebee-4933-8e6d-74324922af25" />

# PCB Top Side View

This PCB is only for prototyping purposes. The final build will feature MCU directly on the PCB without the development board.

<img width="841" height="1080" alt="image" src="https://github.com/user-attachments/assets/c8f6be52-8c69-4657-b88e-8e80c2456e7e" />

# PCB Bottom Side View

<img width="856" height="1097" alt="image" src="https://github.com/user-attachments/assets/7d2ac949-f14a-4330-ae81-ade45182466d" />

# Update - 04.11.2025

Moved diodes from top layer to the bottom. Added diode to the encoder. Added hotswap sockets to switches for quick and easy replacement. Added mounting holes for case. (Below is the bottom side of the board)

<img width="1273" height="1184" alt="image" src="https://github.com/user-attachments/assets/fd10bc57-435f-4a0a-95c3-5d14a696481f" />

# Update - 11.11.2025

Replaced Arduino Micro with Seeed Xiao RP2040. Upgrading to this microcontroller led to smaller board size and lower cost. Board will be sent to production soon.

# Update - 27.11.2025

Boards are finally here! Started the process of soldering and assembly. Still waiting for the Xiao Seeed microcontroller.

![20251126_154215 (1)](https://github.com/user-attachments/assets/b03aa974-47b0-4ead-8dac-3359985919a2)

Bottom View

![20251126_154226 (1)](https://github.com/user-attachments/assets/03d9bc9f-2c4b-40f6-acfe-eafb62b8a6da)

# Update - 13.01.2026

Unfortunately there's been a mistake in schematic and switch built in the rotary encoder and top left corner switch are connected between the same row and column, therefore the computer will be unable to tell which is which, so they act like the same button. Fortunately, the rotary action of the encoder is wired correctly. Started working on software.

# Update - 24.01.2026

Updated schematics as well as the production files so that the encoder works properly and is now connected between ROW_-1 and COL_0. Moved the OLED and the encoder a bit higher since they are getting in the way a little bit. Still working on writing USB HID firmware, but because of my finals it may take some time...
