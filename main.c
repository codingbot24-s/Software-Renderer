
// TODO: we need to organize our code

   /*
      Implement a function that fills a solid triangle so every pixel inside the triangle is colored,
      regardless of the triangle's orientation or vertex order.
   */

// we will be doing this with scanline algo
// 1. bring a on the top by sorting
// 2. bring b on the middle 
// 3. first check if the triangle is not flat
//    then because we have y get the two x of the
//    triangle by interpolation
// 4. then check if the triangle is not the flat bottom
//    do the same thing there 
#include "sdl_init.h"

int main () {
   create_sdl_window();
}
