# fract-ol
Fractol is a small fractal exploration program designed for rendering and exploring the Julia set and the Mandelbrot set. This project adheres to certain rules and requirements to ensure proper functionality and compliance with the specified guidelines.

# Project Files
Makefile: The Makefile for compiling the source files.  
*.h: Header files containing declarations of functions and structures.  
*.c: Source files containing the implementation of the fractal exploration program.  

# Makefile Commands
```make or make all``` Compiles the source files.  
```make clean``` Removes object files.  
```make fclean``` Removes object files and the executable.  
```make re``` Performs a clean rebuild of the project.  

# Usage
The program takes command line arguments to specify the type of fractal to display and any additional rendering options. If no parameter is provided or if the parameter is invalid, the program displays a list of available parameters and exits gracefully.

# Example:

```
./fractol mandelbrot
```
# External Functions
The program utilizes the following external functions:

- open
- close
- read
- write
- malloc
- free
- perror
- strerror
- exit
- All functions from the math library (-lm compiler option, refer to man man 3 math)
- All functions of the MiniLibX
- ft_printf or any equivalent implemented by the coder
  
# Requirements
The program must use the MiniLibX, either the version available on school machines or by installing it using its sources.  
A Makefile must be provided for compiling the source files without relinking.  
Global variables are forbidden.  

# Functionality

## Rendering (V.1)
The program must offer rendering of the Julia set and the Mandelbrot set.  
Mouse wheel zooms in and out, allowing infinite exploration within the limits of the computer.  
Different Julia sets can be created by passing parameters to the program.  
Additional parameters can be used for rendering options.  
Use at least a few colors to depict the depth of each fractal, with the option for psychedelic effects.  
## Graphic Management (V.2)
The program displays the image in a window.  
Window management remains smooth, allowing tasks like changing to another window and minimizing.  
Pressing ESC closes the window and exits the program cleanly.  
Clicking on the cross on the window's frame also closes the window and exits the program cleanly.  
The use of MiniLibX images is mandatory for graphic management.  
