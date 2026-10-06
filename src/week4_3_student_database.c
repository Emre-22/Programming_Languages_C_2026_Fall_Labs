#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void)
{
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    /* Ensure the requested byte count fits before allocating records. */
    if ((size_t)n > SIZE_MAX / sizeof(struct Student)) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    struct Student *student = malloc((size_t)n * sizeof(struct Student));
    if (student == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("Enter data for student %d: ", i + 1);
        /* Limit names to 49 characters, leaving room for the terminator. */
        if (scanf("%49s %d %f", student[i].name,
                  &student[i].id, &student[i].grade) != 3) {
            free(student);
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("\n");
    printf("%-6s %-11s %s\n", "ID", "Name", "Grade");
    for (int i = 0; i < n; ++i) {
        printf("%-6d %-11s %.1f\n",
               student[i].id, student[i].name, student[i].grade);
    }

    /* The database is no longer needed after printing. */
    free(student);
    return 0;
}
