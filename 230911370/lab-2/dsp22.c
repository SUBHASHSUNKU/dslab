#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define the structure student
typedef struct {
    char name[50];
    int rollNo;
    char grade;
} student;

// Function to read student information
void readStudents(student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter roll number of student %d: ", i + 1);
        scanf("%d", &students[i].rollNo);
        printf("Enter grade of student %d: ", i + 1);
        scanf(" %c", &students[i].grade);
    }
}

// Function to display student information
void displayStudents(student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Grade: %c\n", students[i].name, students[i].rollNo, students[i].grade);
    }
}

// Function to sort student information according to roll number
void sortStudents(student students[], int n) {
    student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].rollNo > students[j].rollNo) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    student students[MAX_STUDENTS];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    readStudents(students, n);
    printf("\nStudent Information:\n");
    displayStudents(students, n);

    sortStudents(students, n);
    printf("\nSorted Student Information (by Roll No):\n");
    displayStudents(students, n);

    return 0;
}


