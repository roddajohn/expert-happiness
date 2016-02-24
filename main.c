#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = 0;
  c.blue = 0;
  
  clear_screen(s);
  
  int counter = 0;

  while (counter < XRES) {
    draw_line(counter, 0, 200, 200, s, c);
    c.green = counter % MAX_COLOR;
    counter = counter + 1;
  }

  c.green = 0;
  counter = 0;
  while (counter < XRES) {
    draw_line(counter, YRES - 1, 200, 200, s, c);
    c.red = counter % MAX_COLOR;
    counter = counter + 1;
  }

  c.red = 0;
  counter = 0;
  while (counter < YRES) {
    draw_line(XRES - 1, counter, 200, 200, s, c);
    c.blue = counter % MAX_COLOR;
    counter = counter + 1;
  }

  c.blue = 0;
  counter = 0;
  while (counter < YRES) {
    draw_line(0, counter, 200, 200, s, c);
    c.blue = counter % MAX_COLOR;
    c.red = counter % MAX_COLOR;
    counter = counter + 1;
  }

  //octant 1
  //  draw_line( 0, 0, XRES-1, YRES - 75, s, c);

  printf("GOT HERE\n");
  //display(s);
  save_extension(s, "lines.png");
}  
