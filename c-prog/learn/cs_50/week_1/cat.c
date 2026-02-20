#include <cs50.h>
#include <stdio.h>

// prototype of function
void meow(int n);
// void parameters in function it mean
// the function don't need parameters
int get_positive_number(void);

int main(void)
{
  int times = get_positive_number();
  meow(times);
}

// define the function what it do in here
int get_positive_number(void)
{
  int n;
  do 
  {
    n = get_int("Number: ");
  } while (n < 1);
  return n;
}

// define the function what it do in here
void meow(int times)
{
  for (int i = 0; i < times; i++) {
    printf("meow\n");
  }
}

