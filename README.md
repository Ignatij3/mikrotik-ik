# Example C++ code for MikroTik

What you find in subfolders is a selection of code pieces (full or partial) that has<br>
been written by me at different years, including code I have written while studying how<br>
to code and C++ itself. I would advise to only visit folder `0_2026` to see my current<br>
style and language articulation. I decided to include another folder which contains one<br>
of the first structured pieces of C++ code I have written.

### Disclaimer

I have never used AI to write code or documentation. My code is 100% written by hand<br>
and problems are solved without AI assistance.

# Folder tree

- `0_2026`. This folder contains the most recent code I have written. The code itself<br>
is representative of my coding style in the last couple of months. Parts of the code<br>
are a recreation of my work at the previous employer. I made sure to not use any of their<br>
intellectual property in my code snippets. Some snippets contain references to non-existent<br>
instances. I decided not to recreate those due to time investment required.
Technology/concepts present:
  - preprocessor magic for logger
  - hardware communication via GPIO
  - data structure embedded-safe implementation
  - sensor implementation

- `1_2021`. This folder contains the "bouncy squares" program which I wrote for fun while<br>
studying C++ and Qt. In the folder `./2_2021/bin/` you will find a compiled program<br>
"`bouncy_square`", which is compiled for ubuntu. It should open on other distributions<br>
as well, including computers without Qt installed (it worked on my PC when I opened it).<br>
It was written around 2021-2022, when I just learned C++. QT part of the code was excluded<br>
for brevity of the code example.<br>
Technology/concepts present:
  - CMake
  - Qt/QML
  - vector graphics
  - simple physics engine (works a bit weird when moving objects collide, but I decided not to fix that)
  - OOP applied