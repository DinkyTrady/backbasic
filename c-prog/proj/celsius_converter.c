#include <stdio.h>
#include <stdlib.h> // change 0 to EXIT_SUCCESS

#define FREEZE_PT 32.0f
#define KELVIN_PT 273.15f
#define SCALE_FACTOR (9.0f / 5.0f)

float kelvin_calculate(float c) { return c + KELVIN_PT; }
float fahrenheit_calculate(float c) { return (c * SCALE_FACTOR) + FREEZE_PT; }

int main(int argc, char *argv[]) {
  // define to be float
  float celsius, kelvin, fahrenheit;
  int choose;

  printf("Welcome to celcius converter\n");

  printf("Input celcius: ");
  scanf("%f", &celsius);

  printf("Convert to from celcius to\n");
  printf("1. Kelvin\n");
  printf("2. fahrenheit\n");
  printf("3. All\n");
  printf("Input number: ");
  scanf("%d", &choose);

  if (choose != 1 && choose != 2 && choose != 3) {
    printf("Only avaiable to choose 1, 2, and 3");
    return EXIT_FAILURE;
  }

  if (choose == 1) {
    kelvin = kelvin_calculate(celsius);
    printf("Celcius %.2f converted to kelvin %.2f", celsius, kelvin);
  }

  else if (choose == 2) {
    fahrenheit = fahrenheit_calculate(celsius);
    printf("Celcius %.2f converted to fahrenheit %.2f", celsius, fahrenheit);
  }

  else if (choose == 3) {
    kelvin = kelvin_calculate(celsius);
    fahrenheit = fahrenheit_calculate(celsius);
    printf("Celcius %.2f converted to fahrenheit %.2f and kelvin %.2f", celsius,
           fahrenheit, kelvin);
  }

  return EXIT_SUCCESS;
}
