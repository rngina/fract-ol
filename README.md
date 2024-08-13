# fract-ol
Fractol is a small program designed for exploring the Mandelbrot set, Julia set, and the Burning ship. For graphics rendering, this project utilizes the [MiniLibX](https://github.com/42Paris/minilibx-linux).

![Julia set](/julia_set.png)<br>Julia set with c = -0.835 -0.2321i

# Project Files
Makefile: The Makefile for compiling the source files.  
*.h: Header files containing declarations of functions and structures.  
*.c: Source files containing the implementation of the fractal exploration program.  

# Usage
The program takes command line arguments to specify the type of fractal to display and any additional rendering options.

To run Mandelbrot set
```
./fractol mandelbrot
```

To run Julia set
```
./fractol julia <complex constant>
```
To run Burning ship
```
./fractol ship
```
  
