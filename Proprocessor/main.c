#include <stdio.h>

// this is a constant
#define PI 3.1415

// this is a macro
#define square(x) ((x) * (x))

// inline provides same efficiency as macro depending on the compiler
inline float square2(float num) {
  return num * num;
}

int main(int argc, char const *argv[]) {
  printf("%f\n", square(2.0));
  printf("%f\n", square2(2.0));
  return 0;
}
