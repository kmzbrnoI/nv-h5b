NV-H5B
======

NV-H5B is a [S-COM](https://www.mtb-model.com/elektro/s-com.htm) receiver based
on [NV-7B](https://www.mtb-model.com/elektro/s-com-nav.htm). It is mounted
to the socket of a signal and displays signal code according to the received code
on data wire.

This repository contains KiCad schematics & pcb layout design as well as MCU
firmware source code.

## Basic features

 * 5 V power supply.
 * Mechanical compatibility with [NV-7D](https://www.mtb-model.com/elektro/s-com-nav.htm).
 * Receives [standard S-COM protocol](https://www.mtb-model.com/elektro/s-com.htm).
 * Separate resistor for each LED to unify brightness.
 * ATtiny25 main MCU.
 * Opensource & openhardware design.

## Recommended resistor values

### AŽD 70 signals by Josef Němeček

* Yellow: 4k7
* Red: 10k
* White: 22k
* Green: 2k2

## Authors

 * [Jan Horacek](mailto:jan.horacek@kmz-brno.cz)

## License

PCBs are provided under [Creative Commons Attribution-ShareAlike 4.0
License](https://creativecommons.org/licenses/by-sa/4.0/) as openhardware
project. You may download any data, contribute to the project, create PCB
yourself or even sell it yourself.

Source code is provided under the [Apache License v2.0
](https://www.apache.org/licenses/LICENSE-2.0).
