
// Created by saad on 8/4/26.
//

#include <stdint.h>
#include <stdlib.h>
#include "constant.h"

uint32_t* create_framebuff() {
  uint32_t* framebuff = (uint32_t*)malloc(WIDTH * HIEGHT * sizeof(uint32_t));
  return framebuff;
}



void put_pixel(int x, int y, uint32_t color) {
  if (x > WIDTH || x < 0 || y > HIEGHT || y < 0) {
    return;
  }
  

}


