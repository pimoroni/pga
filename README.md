# Pimoroni PGA Boilerplate

This repository is intended to provide a baseline MicroPython build for PGA2040
and PGA2350, in addition to being a minimal example of how you might set up your
own custom MicroPython flavour to support your PGA-based project.

Use this repository as a boilerplate to set up your own project, and GitHub actions
should automatically handle building MicroPython for you.

## Contents

* pga2040 - MicroPython and Pico SDK board definitions for PGA2040
* pga2350 - MicroPython and Pico SDK board definitions for PGA2350, with PSRAM variant
* modules/c/example - An example MicroPython C++ module, demonstrating C class bindings
* modules/py_frozen - Python files intended to be frozen into the firmware
* modules/py_littlefs - Python files intended to be visible/editable in the LittleFS user filesystem