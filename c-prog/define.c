// define is key to indicate
#include <stdio.h>

// define is key to create
// constant variable so it can't
// be redifne or change the value
#define PHI 3.14f

int main(int argc, char *argv[]) {
  // to give output i need to
  // use format `%f` to print float
  printf("%f\n", PHI); // Output: 3.140000

  // in this one i use %.2f it mean
  // it will just print 2 decimal after number
  printf("%.2f\n", PHI); // Output: 3.14
  return 0;
}
