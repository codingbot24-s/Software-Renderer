

/*
  TODO: Define a 3D vertex representation containing position (x, y, z) 
  and implement a transformation system that can translate, rotate, and scale vertices in 3D space.
*/

#include "sdl_init.h"
#include "vec.h"
#include "mat.h"
#include <stdio.h>

int main () {
  vec4 v4 = v4_init(6, 5, 4,1);
  matrix t_matrix = make_translation_matrix(1, 2, 3);
  vec4 res = matrix_mul_vec4(t_matrix, v4);
  printf("res x is %f\n",res.x);
  printf("res y is %f\n",res.y);
  printf("res z is %f\n",res.z);
  printf("res w is %f\n",res.w);

  create_sdl_window();
}
