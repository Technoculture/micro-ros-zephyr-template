## TODO
- [ ] Enable RTT Tracing using Jtrace/SystemViewer
- [ ] Add a UART-to-USB converter to USART1
- [ ] Add threads to `main.c` file
- [ ] Add a micro-ros node to `main.c` file
- [ ] Add a docker compose file for interactive exploration of the micro-ros node


# Template for a MicroROS node on Zephyr RTOS
[![PlatformIO CI](https://github.com/TechnocultureResearch/micro-ros-zephyr-template/actions/workflows/main.yml/badge.svg)](https://github.com/TechnocultureResearch/micro-ros-zephyr-template/actions/workflows/main.yml)

## Hardware
- [Olimex E407](https://docs.zephyrproject.org/latest/boards/arm/olimex_stm32_e407/doc/index.html)
- Jtag debugging probe for tracing
- UART-to-USB converter (For a serial connection, refer the [reference](https://github.com/NicHub/STM32-E407-BLINK). Requires `libusb`, `lsusb`, and `dfu-util`)
- Ethernet connection for ROS communication

## Dependencies
Must install `PlatformIO`, and `Docker` in order to use this template.

| Component                     | Rationale |
| ----------------------------- | ---------------------------------------------------------------- |
| PlatformIO                    | Simplified dependency management for Embedded development        |
| ZephyrRTOS                    | Modern real time operating system with a vast ecosystem          |
| MicroROS (*A Zephyr Module*)  | Microcontroller Robot Operating System Middleware                |
| Docker                        | For working with ROS interactively                               |
| SystemViewer (*Optional*)     | Tracing using Jtag Interface                                     |
| Renode (*Optional*)           | Hardware-Software-Network Co-simulation and Testing              |


# References
- This repo is a minor change on the template: [start-bluepill-zephyr](https://github.com/TechnocultureResearch/start-bluepill-zephyr)
- [Enabling PlatformIO and Zephyr on custom hardware](https://www.zephyrproject.org/enabling-platformio-and-zephyr-on-custom-hardware/)
- [Custom Embedded Boards](https://docs.platformio.org/en/latest/platforms/creating_board.html)
- [First micro-ROS Application on Zephyr RTOS](https://www.zephyrproject.org/first-micro-ros-application-on-zephyr-rtos/)
