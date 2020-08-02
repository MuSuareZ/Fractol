# Fractol

Discovering 2D programming and the psychedelic universe of fractals.
The program is supposed to take one argument as one of the available fractals (Mandelbrot, Julia, Ship) and display it
in a new window.

# How to use it?

***REALLY IMPORTANT: You MUST have the graphical library used in the whole project called MinilibX installed and a MacOS in order to
use the keys to interact with the shapes!***

***If you would like to know how to install MinilibX, check this https://github.com/gcamerli/minilibx for clear instructions and system requirements***

> git clone "my repo URL" "your folder path"

You can compile it through a Makefile in the root of my Repo
> make

This will compile my library with useful C functions, the graphical library MiniLibX and my Fractol files,
creating an executable called **fractol**

In order to run the executable, type:
> ./fractol "fractal name"

**The fractals name is case-sensitive, so in order to make sure you are typing it correctly, try running ./fractol without
any arguments to see its usage!**

**Buttons**
- Arrow Keys -------->"Move the drawing around in the window"
- W Key --------------->"Increase the number of iterations"
- S Key ---------------->"Decrease the number of iterations"
- 1 Key --------------->"Set to a palette of colors"
- 2 Key --------------->"Set to rainbow colors"
- 3 Key --------------->"Set to greyscale colors"
- K Key --------------->"Activate / Deactivate Julia Variation (does not work with other fractals"
- Mouse Scroll Up ------>"Zoom in"
- Mouse Scroll Down ------>"Zoom out"
- ESC Key ----------->"Close Program"

Once Julia Variation is active, you can move the mouse inside the screen and change its real and imaginary values according
to the mouse position.

![Image of Subject](https://github.com/MuSuareZ/Fractol/blob/master/img/mandelbrot.png)
![Image of Subject](https://github.com/MuSuareZ/Fractol/blob/master/img/julia.png)
![Image of Subject](https://github.com/MuSuareZ/Fractol/blob/master/img/ship.png)

***PS: You should always ignore the quotation marks, they are just comments of what you should input***
