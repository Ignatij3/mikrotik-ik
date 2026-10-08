# Codebase extract from Insyte Technology

### Introduction

This code is intended as only a demonstration of my coding style and knowledge<br>
of embedded C++. Thus, it is not expected for this code to compile or work in<br>
any environment. The code recreation gets as close as it can to demonstrating my<br>
coding skills and knowledge of the language. It barely demonstrates any problem<br>
solving skills.

### Structure

In the folders you will find:
- `./lib/`. Redefines of integer types and implementation of some of the standard<br>
library containers. You will also find a base error class and some helpful macros.
- `./logger/`. Logger design and implementation. To avoid specifying function name,<br>
file and line those are captured automatically with some tricks on the logger side.
- `./pin/`. Low-level GPIO interfacing.
- `./smt50/`. Approximate implementation of the SMT50 sensor.