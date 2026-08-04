//
// Created by saad on 8/4/26.
//

#ifndef C_DRAW_H
#define C_DRAW_H
#include <SDL3/SDL_stdinc.h>
#include <stdint.h>

uint32_t* create_framebuff();


void put_pixel(uint32_t* framebuffer,int x, int y, uint32_t color);


#endif //C_DRAW_H
