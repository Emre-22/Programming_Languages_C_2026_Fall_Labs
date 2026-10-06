/*
 * week4_2_struct_student.c
 * Author: Emre Elaziz
 * Student ID: 251ADB139
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Define a 'Student' struct with name, id and grade, create two
 *   instances with the values from the instructions, and print them.
 *
 *   This program reads no input. Output must match the format in the
 *   Week 4 instructions exactly (it is checked by the autograder).
 */

#include <stdio.h>
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void)
{
    /* Initializers assign all fields, including the name arrays. */
    struct Student student1 = {"Alice Johnson", 1001, 9.1f};
    struct Student student2 = {"Bob Smith", 1002, 8.7f};

    /* The dot operator accesses fields of each structure variable. */
    printf("Student 1: %s, ID: %d, Grade: %.1f\n",
           student1.name, student1.id, student1.grade);
    printf("Student 2: %s, ID: %d, Grade: %.1f\n",
           student2.name, student2.id, student2.grade);
    return 0;
}
