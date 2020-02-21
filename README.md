# LEDMatrix
This is the Arduino program that controls the 8x8 LED matrix. This repository serves as a tutorial for how to alter the program.

## Setting Up the Arduino IDE
First, install the [Arduino IDE](https://www.arduino.cc/en/main/software). Once that is set up, move the [led_matrix](led_matrix) folder into the Arduino folder (default location is your Documents folder). After that, you should be able to edit [led_matrix.ino](led_matrix/led_matrix.ino) and upload to the Arduino Nano.

## Changing the Light Show
### Piskel "Integration"
The easiest way to add your own 8x8 drawing is by using [Piskel](https://www.piskelapp.com/), a free online pixel-art editor. Once you've created your 8x8 masterpiece, go to "Export" on the right-hand menu and select "Download C File". Some drawing notes:
* Black translates to an off LED so it might not translate well to the matrix
* Moreover, since the LEDs are circular lights spaced far apart, drawings may not translate well in general
* The program is set up to handle one frame. If you want to use multiple frames, it gets more complicated.

![Export Piskel to C File](documents/images/piskel_tutorial.PNG)

The next step is to open that C file. It should look something like this (example file ([documents/New Piskel.c](documents/"New Piskel.c") is the [Kirby drawing](https://www.pixilart.com/art/kirby-in-8x8-pixels-e32a65af67f1eb1) I stole:

```c
#include <stdint.h>

#define NEW_PISKEL_FRAME_COUNT 1
#define NEW_PISKEL_FRAME_WIDTH 8
#define NEW_PISKEL_FRAME_HEIGHT 8

/* Piskel data for "New Piskel" */

static const uint32_t new_piskel_data[1][64] = {
{
0xffefa55c, 0xffefa55c, 0xffefa55c, 0xffefa55c, 0xffefa55c, 0xffefa55c, 0xffefa55c, 0xffefa55c, 
0xffefa55c, 0xffefa55c, 0xffd0beef, 0xffd0beef, 0xffd0beef, 0xffd0beef, 0xffefa55c, 0xffefa55c, 
0xffefa55c, 0xffd0beef, 0xffd0beef, 0xffd0beef, 0xffd0beef, 0xffd0beef, 0xffd0beef, 0xffefa55c, 
0xffefa55c, 0xffb195e7, 0xffd0beef, 0xff79271a, 0xffd0beef, 0xff79271a, 0xffd0beef, 0xffefa55c, 
0xffb195e7, 0xffd0beef, 0xffd0beef, 0xff79271a, 0xffd0beef, 0xff79271a, 0xffd0beef, 0xffb195e7, 
0xffb195e7, 0xffb195e7, 0xff926ce0, 0xffd0beef, 0xffd0beef, 0xffd0beef, 0xff926ce0, 0xffb195e7, 
0xffefa55c, 0xff572a9f, 0xffb195e7, 0xffb195e7, 0xffd0beef, 0xffd0beef, 0xff572a9f, 0xffefa55c, 
0xff5cac67, 0xff572a9f, 0xff5b2fb3, 0xff5b2fb3, 0xff5cac67, 0xff572a9f, 0xff5b2fb3, 0xff5cac67
}
};
```

Copy just the 2D array (`new_piskel` might vary depending on what you name the drawing):
```c
static const uint32_t new_piskel_data[1][64] = {
...
};
```
and, in the `led_matrix.ino` file, replace the 2D array that is found directly under a comment saying `// CUSTOM PISKEL DRAWING HERE`. The next step is to paste this line:

```c
uint8_t* new_piskel = (uint8_t*) new_piskel_data[0];
```

under the comment saying `// PISKEL DRAWING POINTER`. **NOTE:** if the name of your Piskel in the 2D array is ANYTHING OTHER THAN `new_piskel`, you need to replace all occurences of `new_piskel` with the drawing name (Command + F should suffice).

After that, upload the code and switch to pickup position 2 (bridge + middle) to see your drawing!
 





Dedicated to G-Dawg. Special thanks to Brian for helping with the programming.
