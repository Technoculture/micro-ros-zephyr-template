## TODO
- [x] Enable RTT Tracing using Jtrace/SystemViewer
- [x] Add a UART-to-USB converter to `USART1`
- [x] Add threads to `main.c` file
- [ ] Add [SMF](https://docs.zephyrproject.org/latest/guides/smf/index.html) (or some other hierarchical state machine library)
- [ ] Add a standalone library and link it to the zephyr application in manner standard to platfromio
- [ ] Add a unit test for library functions
- [ ] Add a unit test for application - what is the best approach here?
- [ ] Add CANopen module

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
| Tracealyzer                  | Tracing using Jtag Interface                         |
| Renode                       | Hardware-Software-Network emulation and testing      |


# Build Instructions
Use the following commands or use the platformIO UI in vscode to build and upload frmware.
``` sh
# Build project
$ pio run

# Upload firmware
$ pio run --target upload
# or,
$ pio run -t upload -e olimex_e407
```

If needed, one can delete the contents of the build directory to compile everything from scratch. Use the following command or the platformIO UI to `clean` or `clean all`.
```sh
# Clean build files
$ pio run --target clean
```

It is recommended to **not use the command line** in this case. Prefer the debug UI in VS Code.
```sh
# Debug (run through VS Code)
$ pio debug
```

Use the UI to `monitor` using platformIO. It might be easier sometimes to use `minicom`, `putty`, or other such standalone tools for UART interaction.
```sh
# Monitor (UART)
$ pio device monitor
# or,
$ pio device monitor -p /dev/ttyUSB0
# or, (requires, `minicom` to be installed)
$ minicom -D /dev/ttyUSB0 -b 115200 -c on
```

It is sometimes usefull to use a `compile_commands.json` to get better intellisense. This can be done easily by runnning the following command. PlatformIO tab also provides an build option in their advanced section to build a compilation database.
```sh
$ pio run -t compiledb
# For building this for just one of the targets, use
$ pio run -t compiledb -e olimex_e407
```

Similary, there are other "advanced" targets made available by platformio which are useful: specifically: `Test` and `Check` (Runs static analysis)

## Renode Emulation
Renode can be useful when developing systems with more complexity i.e, involving multiple nodes in a network configuration, or involving custom hardware (build on FPGAs), or custom boards requiring emulation for testability. Lots to explore here.

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
| Tracealyzer    | Installer from their website                                                        |
