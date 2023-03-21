# NV-H5B

NV-H5B is a [S-COM](https://www.mtb-model.com/elektro/s-com.htm) receiver based
on [NV-7B](https://www.mtb-model.com/elektro/s-com-nav.htm). It is mounted
to the socket of a signal and displays signal code according to the received code
on data wire.

This repository contains Eagle schematics & layout design as well as main mcu
firmware source code.

## Basic features

 * 5 V power voltage.
 * Mechanical compatibility with NV-7D.
 * Receives standard S-COM protocol.
 * Resistor for each LED to set brightness properly.
 * ATtiny13A main MCU.
 * Opensource & openhardware design.

## Recommended resistor values

### AŽD 70 signals by Josef Němeček

* Yellow: 4k7
* Red: 10k
* White: 22k
* Green: 2k2

## Authors

 * [Jan Horacek](mailto:jan.horacek@kmz-brno.cz)
