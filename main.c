

/*
  TODO: Define a 3D vertex representation containing position (x, y, z)
  and implement a transformation system that can translate, rotate, and scale vertices in 3D space.
*/

#include <stdio.h>

#include "sdl_init.h"
#include "mat.h"

// we should test our functions and
// mat_mul_mat they both are working so
// final test is we need a point test if this test pass our task is complete we will do this in the another stream

int main()
{
  vec4 point = {1, 2, 3, 1};
  matrix scale = make_scaling_matrix(2, 3, 4);
  matrix rotation = make_rotation_matrix(0, 0, 90);
  matrix res = mat_mul_mat(rotation, scale);
  matrix translation = make_translation_matrix(5, 6, 7);
  matrix model_matrix = mat_mul_mat(translation, res);

  create_sdl_window();
}
