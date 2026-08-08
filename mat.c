

#include "mat.h"
#include "vec.h"

matrix make_translation_matrix(float tx,float ty,float tz) {
  return (matrix) {
    .mat = {
      {1.0,0.0,0.0,tx},
      {0.0,1.0,0.0,ty},
      {0.0,0.0,1.0,tz},
      {0.0,0.0,0.0,1},
    }
  };
}


vec4 matrix_mul_vec4(matrix matrix, vec4 vec) {
  vec4 res;
  res.x = matrix.mat[0][0]*vec.x + matrix.mat[0][1]*vec.y + matrix.mat[0][2]*vec.z + matrix.mat[0][3]*vec.w; 
  res.y = matrix.mat[1][0]*vec.x + matrix.mat[1][1]*vec.y + matrix.mat[1][2]*vec.z + matrix.mat[1][3]*vec.w; 
  res.z = matrix.mat[2][0]*vec.x + matrix.mat[2][1]*vec.y + matrix.mat[2][2]*vec.z + matrix.mat[2][3]*vec.w; 
  res.w = matrix.mat[3][0]*vec.x + matrix.mat[3][1]*vec.y + matrix.mat[3][2]*vec.z + matrix.mat[3][3]*vec.w;

  return res;
}

