# Entrance Counter Application for PSoC™ 6

This code example demonstrates how to deploy the Entrance Counter application on the PSoC™ 6 MCU using Infineon’s XENSIV™ 60GHz radar sensor. The application accurately counts people entering (IN) and exiting (OUT) a designated area by detecting and classifying human movement in real-time. It leverages radar-based features like range, velocity, and Doppler for robust, privacy-preserving occupancy monitoring on low-power edge devices.

## Overview
The Application for Entrance Counter is designed to accurately count the number of people entering and exiting a room or designated area. Leveraging Infineon’s XENSIV™ 60 GHz radar sensor and optimized for low-power edge devices, this model enables real-time people counting for applications such as smart buildings, retail stores, offices, and public spaces. It provides a robust, privacy-preserving solution by processing data locally without cloud dependency, reducing development time and expertise needed for deployment.

### Key Features
- **Accurate People Counting**: Detects and classifies human movement to increment a counter when a person enters (IN) and decrement when a person exits (OUT) a room area.
- **Radar-Based Detection**: Utilizes Infineon’s XENSIV™ 60GHz radar sensor for high-precision detection of human presence and direction, robust against environmental variations like lighting or temperature.
- **Low Resource Usage**: Optimized for low memory footprint and fast inference time, ideal for resource-constrained embedded systems such as PSoC™ 6, PSoC™ Edge microcontrollers.
- **Privacy-Focused**: Processes all data locally on the edge device, ensuring no personal data is sent to the cloud.
- **Easy Integration**: Seamlessly integrates with Infineon’s ModusToolbox™ software and supported hardware kits.
- **Versatile Applications**: Suitable for smart buildings, retail occupancy monitoring, conference room management, and restroom availability tracking.

### Use Cases
- **Smart Buildings**: Monitor occupancy in meeting rooms or offices to optimize space usage and prevent overcrowding.
- **Retail Stores**: Track customer foot traffic to analyze peak hours and manage store capacity.
- **Public Facilities**: Indicate restroom or venue availability by displaying real-time occupancy status.
- **Safety and Compliance**: Ensure adherence to occupancy limits in restaurants, theatres, or other public spaces.

### Specification and Compatibility
#### Sensor Settings – Radar
- **Sample Rate**: 200000 Hz
- **Features**: Range, velocity, Doppler

#### Supported Devices
- Infineon PSoC™ 6
- Infineon XENSIV™ BGT60TR13C

## Licenses
Source Model: https://github.com/Infineon/entrance-counter-model/blob/main/LICENSE  
Sample Application and Deployable Binaries: https://github.com/Infineon/entrance-counter-app-for-psoc/blob/main/LICENSE.txt  
Model: https://github.com/Infineon/entrance-counter-app-for-psoc/blob/main/licenses/MODEL_LICENSE.txt  
Dataset: https://creativecommons.org/publicdomain/zero/1.0/

### High-Level Flow Diagram
<img src="readme_assets/ENTRANCE_COUNTER_FLOWCHART.png" alt="Entrance Counter Flow Diagram" width="500" height="300">

## Pre-requisites
1. Setup ModusToolbox™ software environment and supported hardware kit (e.g., PSoC™ 6 with XENSIV™ BGT60TR13C radar sensor). Refer to the [ModusToolbox™ User Guide](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/) for installation and kit configuration.
2. Install necessary libraries via ModusToolbox Library Manager (e.g., Radar Sensing SDK).
3. This code example assumes UART/USB connection for output visualization; optional host app for GUI display (e.g., Python-based counter viewer).

### Deployment Steps
1. Import the Entrance Counter application project into ModusToolbox™ via File > Import > ModusToolbox Application.
2. Go to [Entrance Counter FW Artifacts](https://github.com/Infineon/entrance-counter-app-for-psoc/tree/main/fw) and copy all the .h and .a files to `<application_workspace>/ml_pipeline_libs` directory (or equivalent for radar pipeline).
3. Open `Makefile` (or `proj_cm0p/Makefile` if dual-core) and update the following variables for the Entrance Counter application:
   - `NN_TYPE=int8x8` (if ML components are used; adjust for pure radar processing)
   - `NN_MODEL_NAME=ENTRANCE_COUNTER`
   - `LDLIBS+=../ml_pipeline_libs/ENTRANCE_COUNTER_pipeline.a`
   - `DEFINES+=ML_RADAR_CM0P MODEL_NAME=$(NN_MODEL_NAME) CY_RADAR_SENSOR=BGT60TR13C`
4. Connect the supported hardware kit (PSoC™ 6 + BGT60TR13C) via USB and ensure radar sensor is powered/configured.
5. Build the full project: Right-click project > Build Project.
6. Program the application to the PSoC™ 6 hardware: Right-click project > Program.
7. Once the application hex is successfully flashed to the PSoC™ 6 hardware, the Entrance Counter use-case will start running by default, outputting counts via UART.
   <img src="readme_assets/ENTRANCE_COUNTER_RUNNING.png" alt="Entrance Counter Running" width="640" height="480">

### Pre-Built Binaries
There is a pre-built FW binary available for this use-case under the `binaries/` directory (e.g., `psoc6_entrance_counter_fw.hex`) that can be directly flashed onto PSoC™ 6 MCU using ModusToolbox™ Programmer tool.  
For detailed flashing instructions, refer to [**ModusToolbox™ Programmer Documentation (Section 5.14)**](https://www.infineon.com/row/public/documents/30/44/infineon-modustoolbox-gui-user-guide-usermanual-en.pdf). Same steps applicable for external flash configurations.

For host-side output visualization (e.g., real-time counter display), download and run the pre-built `.exe` from `binaries/output_viewer.exe` (Windows) or build from `host_app/` sources. Connect via serial port (e.g., COM3) post-flash.

---------------------------------------------------------
© Cypress Semiconductor Corporation, 2024-2025. This document is the property of Cypress Semiconductor Corporation, an Infineon Technologies company, and its affiliates ("Cypress"). This document, including any software or firmware included or referenced in this document ("Software"), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide. Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights. If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress's patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products. Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.  
<br>  
TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. No computing device can be absolutely secure. Therefore, despite security measures implemented in Cypress hardware or software products, Cypress shall have no liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. CYPRESS DOES NOT REPRESENT, WARRANT, OR GUARANTEE THAT CYPRESS PRODUCTS, OR SYSTEMS CREATED USING CYPRESS PRODUCTS, WILL BE FREE FROM CORRUPTION, ATTACK, VIRUSES, INTERFERENCE, HACKING, DATA LOSS OR THEFT, OR OTHER SECURITY INTRUSION (collectively, "Security Breach"). Cypress disclaims any liability relating to any Security Breach, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any Security Breach. In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes. It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product. "High-Risk Device" means any device or system whose failure could cause personal injury, death, or property damage. Examples of High-Risk Devices are weapons, nuclear installations, surgical implants, and other medical devices. "Critical Component" means any component of a High-Risk Device whose failure to perform can be reasonably expected to cause, directly or indirectly, the failure of the High-Risk Device, or to affect its safety or effectiveness. Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any use of a Cypress product as a Critical Component in a High-Risk Device. You shall indemnify and hold Cypress, including its affiliates, and its directors, officers, employees, agents, distributors, and assigns harmless from and against all claims, costs, damages, and expenses, arising out of any claim, including claims for product liability, personal injury or death, or property damage arising from any use of a Cypress product as a Critical Component in a High-Risk Device. Cypress products are not intended or authorized for use as a Critical Component in any High-Risk Device except to the limited extent that (i) Cypress's published data sheet for the product explicitly states Cypress has qualified the product for use in a specific High-Risk Device, or (ii) Cypress has given you advance written authorization to use the product as a Critical Component in the specific High-Risk Device and you have signed a separate indemnification agreement.  
<br>  
Cypress, the Cypress logo, and combinations thereof, ModusToolbox, PSoC, CAPSENSE, EZ-USB, F-RAM, and TRAVEO are trademarks or registered trademarks of Cypress or a subsidiary of Cypress in the United States or in other countries. For a more complete list of Cypress trademarks, visit www.infineon.com. Other names and brands may be claimed as property of their respective owners.
