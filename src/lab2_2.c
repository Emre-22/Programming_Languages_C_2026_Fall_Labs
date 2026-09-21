#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
  long long mult = 1;
  for (int i = 1; i <= n; i++) {
    mult *= i;
  }
  return mult;
}

int main(void) {
  int n;

  printf("Enter a non-negative integer n: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Please enter a non-negative integer.\n");
    return 1;
  }
  printf("Factorial of %d is: %lld\n", n, factorial(n));
  return 0;
}
