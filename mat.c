

#include "mat.h"
#include "vec.h"
#include <math.h>



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

matrix make_rotation_matrix(float yaw,float pitch,float roll) {
  
  float alpha = yaw * DAG_TO_RADIANS;
  float beta  = pitch * DAG_TO_RADIANS;
  float gamma = roll * DAG_TO_RADIANS;
  
  float ca = cosf(alpha);
  float sa = sinf(alpha);
  
  float cb = cosf(beta);
  float sb = sinf(beta);
  
  float cg = cosf(gamma);
  float sg = sinf(gamma);

   return (matrix) {
    .mat = {
        {ca*cb, ca*sb*sg-sa*cg,  ca*sb*cg+sa*sg,  0.0},
        {sa*cb, sa*sb*sg+ca*cg,  sa*sb*cg-ca*sg,  0.0},
        {  -sb,          cb*sg,  cb*cg,           0.0},
        {  0.0,              0.0,  0.0,           1.0},
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

