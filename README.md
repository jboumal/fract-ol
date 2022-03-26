# 19 fract-ol

## Introduction
This project is about to create fractals, using Minilibx.  
It was designed to run only on mac, and displays Mandelbrot, Julia and burning ship fractals.

## Compile and run
Use makefile rule to compile sources
```
make
```
Then, execute the program as follow to display respectively Mandelbrot, Julia, and burning ship
```
./fractol M
./fractol J
./fractol B
```
Use <kbd>esc</kbd> to exit.

## Mouse and keyboard input

### Explore the fractal

Use <kbd>↑</kbd><kbd>↓</kbd><kbd>→</kbd><kbd>←</kbd> to move.  
Use scroll wheel to zoom and unzoom, zoom will follow mice position.  
Use <kbd>+</kbd><kbd>-</kbd> to zoom and unzoom at the center of the window.  

### Change colors

There are 5 colors sets available, use <kbd>C</kbd> to go to next color set.  
Set 0 is random color.  
Set 1 is shades of grey color.  
Set 2 is graduation of hue from HSV color.  
Set 3 is shades of blue + green.  
Set 4 is a color set made of repeating encoded colors.  

### Julia parameter

Julia set depends of a complex parameter.  
Move mouse around the window to change this parameter.  
Use <kbd>L</kbd> to lock the parameter.  
When locked, use <kbd>Q</kbd> and <kbd>W</kbd> to decrease and increase real part of the parameter
use <kbd>O</kbd> and <kbd>P</kbd> to decrease and increase real part of the parameter.

## Header constants

There are 3 constants that are defined in *fractol.h*:  
WIDTH is the width of the window.  
HEIGHT is the height of the window.  
MAX\_ITER is number of iteration before we condiser that the fractal sequence is bounded.
Increasing this number will result in a higher quality image, iand deeper fractal, but at the cost of performance.
