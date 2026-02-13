# Switching the Boot Flow to External QSPI Flash – Radar Segmentation and Tracking

The PSoC™ 6 AI Evaluation Kit (CY8CKIT-062S2-AI) by default boots applications from **internal flash** (up to 2 MB), which is sufficient for most radar-based demos, including the **Radar Tracking and Segmentation** application.  
However, the platform also supports booting from **external QSPI flash** (512 Mb S25FL512S) using **Execute-In-Place (XIP)** mode. This option is useful when the application firmware size increases significantly due to advanced signal processing pipelines, clustering logic, or future AI/ML-based tracking extensions.

The Radar Tracking and Segmentation application is typically deployed using **internal flash booting**, similar to standard examples such as *Hello World*. Switching to external QSPI flash is an **advanced configuration** intended for large-scale or feature-rich builds.

For detailed background, refer to **AN228571 – Getting started with PSoC™ 6 MCU on ModusToolbox™ software (v08_00 or later)**, specifically the *QSPI XIP* section.

---

## Standard Deployment: Flashing .hex to Internal Flash
For the Radar Segmentation and Tracking application, the recommended and default deployment flow is internal flash booting.

1. Build the project in **ModusToolbox™** to generate the application `PSOC6_AI_fw_binary/Radar_Tracking_and_hex.hex` file. 

2. Connect the **CY8CKIT-062S2-AI** to the host PC using the USB Type-C cable (J2 port).

3. Launch **ModusToolbox™ Programmer**:
   - Select **Auto-detect Device** (CY8C62x6 family).
   - Load the generated `.hex` file.
   - Choose **Erase All + Program**.
   - Click **Program**.

4. After programming, the device automatically boots from internal flash.

5. Monitor runtime outputs (segmentation results, target IDs, range/velocity data) via **UART**:
   - Virtual COM port
   - 115200 baud
   - Terminal tools such as Tera Term or PuTTY

This deployment method is simple, fast, and sufficient for most Radar Segmentation and Tracking use cases.

---

## Boot from External QSPI Flash (Advanced)
If the Radar Tracking and Segmentation firmware grows beyond internal flash limits (for example, when adding AI-based behavior analysis, complex tracking filters, or larger buffers), booting from external QSPI flash can be enabled.

### Prerequisites
- ModusToolbox™ software **v3.6 or later**
- Latest **BSP for CY8CKIT-062S2-AI** (update via Library Manager)
- External QSPI flash (S25FL512S) available on the kit  
- Reference example:  
  [mtb-example-psoc6-qspi-xip](https://github.com/Infineon/mtb-example-psoc6-qspi-xip)

### Configure QSPI XIP
1. Open **QSPI Configurator** in ModusToolbox™  
   *(Tools → QSPI Configurator)*.

2. Enable **XIP (Execute-In-Place)** mode:
   - Configure QSPI clock (up to 133 MHz).
   - Map the external flash address space correctly.

3. Update the project **Makefile**:
   ```makefile
   CY_BOOT_USE_EXTERNAL_FLASH=1
