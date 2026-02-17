# Radar Tracking and Segmentation – PSoC™ 6 Infineon Radar Sensor

This code example demonstrates how to deploy a Radar Tracking and Segmentation application on the PSoC™ 6 platform using the XENSIV™ BGT60TR13C 60 GHz radar sensor. The application processes radar reflections to segment objects and track their movement over time, enabling real-time people counting and occupancy monitoring on edge devices.

## Overview

The Radar Tracking and Segmentation application is an Edge AI solution designed to detect, segment, and track multiple objects or people using radar sensors connected to a PSoC™ 6 platform. By processing radar signals and grouping reflections into tracked objects, the system enables accurate movement detection and occupancy analysis.

This solution is optimized for real-time performance on embedded edge hardware and supports applications such as smart occupancy monitoring, security systems, and movement analytics.

## Key Features

- **Radar Signal Processing** – Processes 60 GHz radar reflections to segment objects and track motion
- **Object Segmentation & Tracking** – Detects and follows multiple moving objects in real time
- **Unsupervised Learning Approach** – Uses unsupervised techniques for radar-based object grouping
- **Edge-Optimized Performance** – Designed for efficient execution on embedded hardware
- **Real-Time Monitoring** – Enables continuous tracking and occupancy analysis

## Key Benefits

- Accurate movement detection across indoor environments
- Low-latency real-time processing
- Scalable and adaptable design
- Efficient resource usage for embedded systems
- Easy integration into existing workflows

## Key Use Cases

- **People Counting**
- **Movement Detection**
- **Room Occupancy Monitoring**
- **Security Monitoring**

## Specification and Compatibility

### Sensor Settings – Radar

- **Sensor:** 60 GHz Radar (BGT60TR13C)
- **Workflow:** Radar signal processing and object segmentation

### Supported Hardware

- PSoC™ 6 AI Kit
- Radar Sensor Module (BGT60TR13C)

## High-Level Flow Diagram

<img src="./readme_assets/Flowchart.png" alt="Radar Tracking and Segmentation" width="500" height="1000">

## Pre-requisites

1. Install **ModusToolbox™ Programmer** on your computer.
2. Connect the PSoC™ 6 AI Kit to your system via USB.
3. Ensure a working USB/UART connection for programming and visualization.


## Deployment Steps

1. Download **Box_application_hex.hex** and **Radar_Box_Application.exe** from the `PSOC6_AI_binaries (PSOC6_AI_fw_binaries/)` directory.
2. Open ModusToolbox Programmer and load the required firmware `.hex` file.
3. Configure programmer settings:
   - Programmer: KitProg3 CMSIS-DAP
   - Board: CY8CKIT-062S2-AI
4. Click **Connect**, then **Program** to flash the firmware.
5. After programming completes, disconnect the board and press the reset button.
6. Run **Radar_Box_Application.exe** and connect to the appropriate serial port (e.g., COM3) for real-time visualization.

<img src="readme_assets/Dashboard.png" alt="Range Detection Running" width="640" height="480">

## Pre-Built Binaries

Pre-built binaries are available in the `PSOC6_AI_binaries (PSOC6_AI_fw_binaries/)` directory:

- `Box_application_hex.hex` — Firmware binary for flashing onto the PSoC™ 6 MCU
- `Radar_Box_Application.exe` — Windows application for real-time tracking visualization

## Licenses

This sample application and deployable binaries are licensed under the terms in the LICENSE file.

See: [LICENSE](license/license.txt) for full details.

---

## Copyrights

© 2025 WG Tech Solutions Pvt Ltd. All rights reserved.

This project is licensed under the MIT License — see the [LICENSE](license/license.txt) file for details.

PSoC™, ModusToolbox™, and XENSIV™ are trademarks of Infineon Technologies AG. Other names and brands may be claimed as property of their respective owners.
