/*
 * week4_1_dynamic_array.c
 * Author: Emre Elaziz
 * Student ID: 251ADB139
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Allocate memory for n integers, read them from the user,
 *   print their sum and average, and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    int n;
    long long sum = 0;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    /* Check the allocation size before multiplying to prevent overflow. */
    if ((size_t)n > SIZE_MAX / sizeof(int)) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int *array = malloc((size_t)n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &array[i]) != 1) {
            /* Release the array even if reading fails partway through. */
            free(array);
            printf("Invalid input.\n");
            return 1;
        }
        sum += array[i];
    }

    printf("Sum = %lld\n", sum);
    /* Convert before division so the fractional part is retained. */
    printf("Average = %.2f\n", (double)sum / n);
    free(array);
    return 0;
}
