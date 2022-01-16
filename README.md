## TODO
- [x] Enable RTT Tracing using Jtrace/SystemViewer
- [ ] Add a UART-to-USB converter to `USART1`
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

## Build

``` sh
# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Clean build files
$ pio run --target clean
```

## Dependencies
Must install `PlatformIO`, and `Docker` in order to use this template.

| Component                    | Rationale                                                 |
|------------------------------|-----------------------------------------------------------|
| PlatformIO                   | Simplified dependency management for Embedded development |
| ZephyrRTOS                   | Modern real time operating system with a vast ecosystem   |
| MicroROS (*A Zephyr Module*) | Microcontroller Robot Operating System Middleware         |
| Docker (and docker-compose)  | For working with ROS interactively                        |
| SystemViewer (*Optional*)    | Tracing using Jtag Interface                              |
| Renode (*Optional*)          | Hardware-Software-Network Co-simulation and Testing       |


## ROS
This section modified from [here](https://github.com/TechnocultureResearch/micro_ros_stm32_template).

``` sh
$ cd zephyr
$ docker-compose up
# This will fail if docker is not been installed properly, with it running in the background

$ docker ps

$ docker exec -t bash
# Runs docker in interactive mode

root@f2c457f245bf:/# source /opt/ros/$ROS_DISTRO/setup.bash
root@f2c457f245bf:/# ros2 node list
/zephyr_node
/linux_node
root@f2c457f245bf:/# ros2 node info /zephyr_node
/zephyr_node
  Subscribers:

  Publishers:
    /chatter: std_msgs/msg/String
  Service Servers:

  Service Clients:

  Action Servers:

  Action Clients:

root@f2c457f245bf:/# ros2 topic echo /chatter 
data: 'Hello World: 6, sys_clk: 9000'
---
data: 'Hello World: 7, sys_clk: 9000 '
---
data: 'Hello World: 8, sys_clk: 9000'
---
data: 'Hello World: 9, sys_clk: 9000'
---
```

# References
- This repo is a minor change on the template: [start-bluepill-zephyr](https://github.com/TechnocultureResearch/start-bluepill-zephyr)
- [Enabling PlatformIO and Zephyr on custom hardware](https://www.zephyrproject.org/enabling-platformio-and-zephyr-on-custom-hardware/)
- [Custom Embedded Boards](https://docs.platformio.org/en/latest/platforms/creating_board.html)
- [First micro-ROS Application on Zephyr RTOS](https://www.zephyrproject.org/first-micro-ros-application-on-zephyr-rtos/)

# Installation

| Component      | Installation Hint                                                                   |
|----------------|-------------------------------------------------------------------------------------|
| docker         | Follow instruction on their website                                                 |
| docker-compose | `sudo pip install docker-compose` ([ref](https://docs.docker.com/compose/install/)) |
| platformio     | VS Code Extension Hub                                                               |
| zephyr-rtos    | Don't have to install (platformio takes care of this)                               |
| renode         | Download the installer from the release section of their github folder              |
| Systemviewer   | Installer from their website                                                        |
