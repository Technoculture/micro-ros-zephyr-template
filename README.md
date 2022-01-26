## TODO
- [x] Enable RTT Tracing using Jtrace/SystemViewer
- [ ] Add a UART-to-USB converter to `USART1`
- [ ] Add threads to `main.c` file
- [ ] Add [SMF](https://docs.zephyrproject.org/latest/guides/smf/index.html) (or some other hierarchical state machine library)
- [ ] Add CANopen module
- [x] Add a docker compose file for interactive exploration of the micro-ros node


# Template for a MicroROS node on Zephyr RTOS
[![PlatformIO CI](https://github.com/TechnocultureResearch/micro-ros-zephyr-template/actions/workflows/main.yml/badge.svg)](https://github.com/TechnocultureResearch/micro-ros-zephyr-template/actions/workflows/main.yml)

# Setup
## Hardware
- [Olimex E407](https://docs.zephyrproject.org/latest/boards/arm/olimex_stm32_e407/doc/index.html)
- Jtag debugging probe for tracing
- UART-to-USB converter (For a serial connection, refer the [reference](https://github.com/NicHub/STM32-E407-BLINK). Requires `libusb`, `lsusb`, and `dfu-util`)

## Dependencies
Must install `PlatformIO`, and `Docker` in order to use this template.

| Component                    | Rationale                                                 |
|------------------------------|-----------------------------------------------------------|
| PlatformIO                   | Simplified dependency management for Embedded development |
| ZephyrRTOS                   | Modern real time operating system with a vast ecosystem   |

### Optional dependencies
| Component                    | Rationale                                            |
|------------------------------|------------------------------------------------------|
| Docker (and docker-compose)  | For working with ROS interactively                   |
| SystemView                   | Tracing using Jtag Interface                         |
| Renode                       | Hardware-Software-Network emulation and testing      |


# Build
## PlatformIO

``` sh
# Build project
$ pio run

# Upload firmware
$ pio run --target upload
# or,
$ pio run -t upload -e olimex_e407

# Clean build files
$ pio run --target clean

# Debug (run through VS Code)
$ pio debug

# Monitor (UART)
$ pio device monitor
# or,
$ pio device monitor -p /dev/ttyUSB0
# or, (requires, `minicom` to be installed)
$ minicom -D /dev/ttyUSB0 -b 115200 -c on
```

## Renode Emulation
```sh
$ renode

(monitor) mach create
(machine-0) machine LoadPlatformDescription @platforms/boards/stm32f4_discovery.repl
(machine-0) sysbus LoadELF @.pio/build/f4_disco/firmware.elf
(machine-0) start
```

- [Working with machines](https://renode.readthedocs.io/en/latest/basic/machines.html)
- [Basic Execution Control](https://renode.readthedocs.io/en/latest/basic/control.html)


# References
## PlatformIO
- This repo is a minor change on the template: [start-bluepill-zephyr](https://github.com/TechnocultureResearch/start-bluepill-zephyr)
- [Enabling PlatformIO and Zephyr on custom hardware](https://www.zephyrproject.org/enabling-platformio-and-zephyr-on-custom-hardware/)
- [Custom Embedded Boards](https://docs.platformio.org/en/latest/platforms/creating_board.html)

## SMF 
- [State Machine Framework](https://github.com/zephyrproject-rtos/zephyr/tree/main/tests/lib/smf/src)

## CANopen
- [Zephyr CANopen documentation](https://docs.zephyrproject.org/latest/samples/modules/canopennode/README.html)
- [CANopen Editor](https://github.com/CANopenNode/CANopenEditor)
- [zephyr CANopen node](https://github.com/zephyrproject-rtos/zephyr/tree/main/samples/modules/canopennode)

## Installation
| Component      | Installation Hint                                                                   |
|----------------|-------------------------------------------------------------------------------------|
| docker         | Follow instruction on their website                                                 |
| docker-compose | `sudo pip install docker-compose` ([ref](https://docs.docker.com/compose/install/)) |
| platformio     | VS Code Extension Hub                                                               |
| zephyr-rtos    | Don't have to install (platformio takes care of this)                               |
| renode         | Download the installer from the release section of their github folder              |
| Systemview     | Installer from their website                                                        |
