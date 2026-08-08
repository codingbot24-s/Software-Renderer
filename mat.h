
#include "vec.h"

typedef struct matrix {
  float mat[4][4];
} matrix;



matrix make_translation_matrix(float tx,float ty,float tz);
vec4   matrix_mul_vec4(matrix matrix, vec4 vec);
