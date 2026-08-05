//
// Created by saad on 8/3/26.
//

#include "sdl_init.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <stdint.h>
#include <stdio.h>
#include "constant.h"
#include "draw.h"
#include <stdlib.h>



static bool running = true;


int create_sdl_window() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("sdl init failed %s\n", SDL_GetError());
    return -1;
  }
  // here using sdl window resizable will cancel 
  // our width and hieght 
  SDL_Window*  window = SDL_CreateWindow("renderer window", WIDTH, HIEGHT,0);
  if (!window) {
    printf("window creation error %s\n", SDL_GetError());
    return -1;
  }
  // we will be back soon // 
  SDL_Renderer* renderer = SDL_CreateRenderer(window,NULL);   
  if (!renderer) {
    printf("renderer creation error %s\n", SDL_GetError());
    return -1;
  }

  SDL_SetWindowResizable(window,true);
  uint32_t* frame_buffer = create_framebuff();
  SDL_Texture* texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_XRGB8888,SDL_TEXTUREACCESS_STREAMING,WIDTH,HIEGHT);

  SDL_Event event;
   while (running == true) {
    while(SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_EVENT_QUIT:
          running = false;
          break;
        case SDL_EVENT_WINDOW_RESIZED:
        case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
          break;
      } 

    }


     clear_framebuffer(frame_buffer,0x000000);
     draw_line(frame_buffer, 10, 10, 200, 200,0xFF0000);

    SDL_UpdateTexture(texture,NULL,frame_buffer,WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
  }  return 0;
}
