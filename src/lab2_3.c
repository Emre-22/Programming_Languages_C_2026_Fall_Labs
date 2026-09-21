#include <stdio.h>

/*
    Task:
    Write a function `int is_prime(int n)` that returns 1 if n is prime,
    0 otherwise.

    In main():
      - Ask user for an integer n (>= 2)
      - If invalid, print an error
      - Otherwise, print all prime numbers up to n
*/

int is_prime(int n) {
  if (n < 2) {
    return 0;
  }

  for (int divisor = 2; divisor <= n / divisor; divisor++) {
    if (n % divisor == 0) {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  int n;

  printf("Enter an integer n (>= 2): ");
  if (scanf("%d", &n) != 1 || n < 2) {
    printf("Please enter an integer greater than or equal to 2.\n");
    return 1;
  }

  printf("Prime numbers up to %d are:", n);
  for (int number = 2; number <= n; number++) {
    if (is_prime(number)) {
      printf(" %d", number);
    }
  }
  printf("\n");

  return 0;
}
