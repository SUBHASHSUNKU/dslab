#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

// Define the structure student
typedef struct {
    char name[50];
    int rollNo;
    char grade;
    char branch[10];
} student;

// Function to write student records to a text file
void writeRecords(student students[], int n) {
    FILE *fp = fopen("student_records.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %d %c %s\n", students[i].name, students[i].rollNo, students[i].grade, students[i].branch);
    }
    fclose(fp);
}

// Function to read student records from a text file and store branch-wise
void readAndStoreRecords() {
    FILE *fp = fopen("student_records.txt", "r");
    student s;
    while (fscanf(fp, "%s %d %c %s", s.name, &s.rollNo, &s.grade, s.branch) != EOF) {
        FILE *branchFile = fopen(s.branch, "a");
        fprintf(branchFile, "%s %d %c\n", s.name, s.rollNo, s.grade);
        fclose(branchFile);
    }
    fclose(fp);
}

int main() {
    student students[MAX_STUDENTS];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter roll number of student %d: ", i + 1);
        scanf("%d", &students[i].rollNo);
        printf("Enter grade of student %d: ", i + 1);
        scanf(" %c", &students[i].grade);
        printf("Enter branch of student %d: ", i + 1);
        scanf("%s", students[i].branch);
    }

    writeRecords(students, n);
    readAndStoreRecords();

    return 0;
}

