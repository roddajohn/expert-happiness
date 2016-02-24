#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;

  if (x > x1 || (x == x1 && y > y1)) {
    int temp;
    temp = x1;
    x1 = x;
    x = temp;

    temp = y1;
    y1 = y;
    y = temp;
  }
  printf("x0: %d, y0: %d, x1: %d, y1: %d\n", x, y, x1, y1);

  float m = 0;
  int v = 1;
  if (x1 - x != 0) {
    m = (float)(y1 - y) / (float)(x1 - x);
    v = 0;
  }

  int octant = 0;
  if (m >= 0 && m <= 1) {
    octant = 0;
  }
  else if (m > 1) {
    octant = 1;
  }
  else if (m < 0 && m >= -1) {
    octant = 7;
  }
  else if (m < -1) {
    octant = 6;
  }

  printf("%f\n", m);
  printf("Octant: %d\n", octant);
  if (v) {
    while (y < y1) {
      plot(s, c, x, y++);
    }
  }
  else {
    if (octant == 1) {
      int temp = x;
      x = y;
      y = temp;

      temp = x1;
      x1 = y1;
      y1 = temp;
    }
    else if (octant == 7) {
      y = -1 * y;
      y1 = -1 * y1;
    }
    else if (octant == 6) {
      int temp = x;
      x = y;
      y = temp * -1;

      temp = x1;
      x1 = y1;
      y1 = temp * -1;
    }
    if (x > x1 || (x == x1 && y > y1)) {
      int temp;
      temp = x1;
      x1 = x;
      x = temp;
      
      temp = y1;
      y1 = y;
      y = temp;
    }
    printf("x0: %d, y0: %d, x1: %d, y1: %d\n", x, y, x1, y1);
    
    //Octant 1
    int A = y1 - y;
    int B = -1 * (x1 - x);
    
    int d = A + (.5 * B);
    while (x <= x1) {
      if (octant == 0) {
	plot(s, c, x, y);
      }
      else if (octant == 1) {
	plot(s, c, y, x);
      }
      else if (octant == 6) {
	plot(s, c, y * -1, x);
      }
      else if (octant == 7) {
	plot(s, c, x, y * -1);
      }
      if (d > 0) {
	y += 1;
	d += B;
      }
      x += 1;
      d += A;
    } 
  }
  /*  else if (m >= 1) {
    // Octant 2
    int d = A + (2 * B);
    while (x < x1 || y < y1) {
      plot(s, c, x, y);
      if (d > 0) {
	x += 1;
	d += B;
      }
      y += 1;
      d += 2 * A;
    }
  }
  else if (m < 0 && m > -1) {

  }
  else if (m <= -1) {

  }*/
}

