
#include "vec.h"



vec3 v3_init(float x, float y, float z) {
  return (vec3) {
    .x = x,
    .y = y,
    .z = z,
  };
}
    

vec4 v4_init(float x, float y, float z, float w) {
  return (vec4) {
    .x = x,
    .y = y,
    .z = z,
    .w = w,
  };
}
    
