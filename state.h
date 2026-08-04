#pragma once

#include <SDL3/SDL.h>

typedef struct g_state {
  SDL_Window* window;
  SDL_Renderer* renderer;
  // so we can modify it 
  uint32_t* framebuffer;
} g_state;

