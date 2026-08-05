
// Created by saad on 8/4/26.
//

#include "draw.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "constant.h"

//  i think our task is complete 

uint32_t* create_framebuff() {
  uint32_t* framebuff = (uint32_t*)malloc(WIDTH * HIEGHT * sizeof(uint32_t));
  return framebuff;
}

// function will put a single pixel with specified color in the 
// framebuffer
void put_pixel(uint32_t* framebuffer,int x, int y, uint32_t color) {
  if (x >= WIDTH || x <= 0 || y >= HIEGHT || y <= 0) {
    return;
}
  
  framebuffer[y * WIDTH + x] = color;
}

void clear_framebuffer(uint32_t* framebuffer,uint32_t color) {
  for (int r = 0; r < HIEGHT; ++r) {
    for (int c = 0; c < WIDTH; ++c) {
      framebuffer[r * WIDTH + c] = color;  
    }
  }
}


void draw_line(uint32_t* framebuffer,float x1,float y1,
              float x2, float y2, uint32_t color) {
  float xdiff = x2 - x1;
  float ydiff = y2 - y1;

  if(xdiff == 0.0f && ydiff == 0.0f) {
		put_pixel(framebuffer,x1, y1,color);
		return;
	}

  //
  if (fabsf(xdiff)  > fabsf(ydiff)) {
    float xmin; 
    float xmax ; 
    if (x2 > x1) {
      xmax = x2;
      xmin = x1;
    }else {
      xmin = x2;
      xmax = x1;
    }

    float slop = ydiff / xdiff;
    for (float x = xmin;x <= xmax; x+= 1.0f) {
      // calculate how much we need to increase y 
      float y = y1 + (x - x1) * slop;
      put_pixel(framebuffer, x, y, color);      
    }
  }else {
    float ymin;
    float ymax ;
    if (y2 > y1) {
      ymax = y2;
      ymin = y1;
    }else {
      ymax = y1;
      ymin = y2;
    }

    float slop = xdiff / ydiff;
    for (float y = ymin;y <= ymax; y+= 1.0f) {
      float x = x1 + (y - y1) * slop;
      put_pixel(framebuffer, x, y, color);
    }
  }
}

void draw_triangle(float x1, float y1, float x2, float y2, float x3, float y3,
                  uint32_t *framebuffer, uint32_t color) {
  
    draw_line(framebuffer, x1, y1, x2, y2,color);
    draw_line(framebuffer, x2, y2, x3, y3,color);
    draw_line(framebuffer, x3, y3, x1, y1,color);
}
