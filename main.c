#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

 
  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = 0;
  
  clear_screen(s);
  /*
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
    }*/
  int delta = XRES / 2 / 40; //interval length
  
  int i = 0;
  
  while (i <= XRES / 2 / delta) {
    draw_line(1 + i * delta, 1, 1, YRES/2 - i * delta, s, c); //out lower left
    draw_line(i * delta + XRES / 2 , 1, YRES-1, 1 + i * delta, s, c); //out lower right
    draw_line(1, YRES / 2 + delta * i, i * delta , YRES - 1, s, c); //out upper left
    draw_line(i * delta + XRES / 2 , YRES - 1, XRES - 1, YRES - 1 - delta * i, s, c); //out upper right

    draw_line(XRES/2, YRES/2 + delta * i, XRES - 1 - delta * i, YRES/2, s, c); //in upper right
    draw_line(XRES/2, YRES/2 + delta * i, 1 + delta * i, YRES/2, s, c); //in upper left
    draw_line(XRES/2, YRES/2 - delta * i, 1 + delta * i, YRES/2, s, c); //in lower left
    draw_line(XRES/2, YRES/2 - delta * i, XRES - 1 - delta * i, YRES/2, s, c);//in lower right

    draw_line(XRES/2 + delta * i, YRES/2 + delta * i, 1 + delta * i, YRES - 1 - delta * i, s, c); //in open up
    draw_line(XRES/2 - delta * i, YRES/2 - delta * i, 1 + delta * i, YRES - 1 - delta * i, s, c); //in open left
    draw_line(XRES/2 - delta * i, YRES/2 - delta * i, XRES - 1 - delta * i, 1 + delta * i, s, c); //in open down
    draw_line(XRES/2 + delta * i, YRES/2 + delta * i, XRES - 1 - delta * i, 1 + delta * i, s, c); //in open right

    i++;
  }

  //octant 1
  //  draw_line( 0, 0, XRES-1, YRES - 75, s, c);

  printf("GOT HERE\n");
  //display(s);
  save_extension(s, "lines.png");
}  
