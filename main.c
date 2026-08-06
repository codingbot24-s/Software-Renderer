
// TODO: we need to organize our code

  /*
      Implement a depth (Z) buffer, clear it every frame, and use it so that overlapping triangles are 
      rendered correctly based on depth instead of draw order.
  */


/*
  we need to interpolate z also for completing this task
  1. sort z also in our sort function
  2. get the depth of left right edge by same interpolation
  3. and each pixel between them by same interpolation
  4. check the z in the z buffer and then draw pixel 
*/

#include "sdl_init.h"

int main () {
   create_sdl_window();
}
