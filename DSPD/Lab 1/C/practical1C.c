#include <stdio.h>
struct Student {
    int rollno;
    char name[30];
    int marks1, marks2, marks3;
    float avg;
};

int main() {
    struct Student s[50], temp;
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].rollno);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Enter marks in 3 subjects: ");
        scanf("%d %d %d", &s[i].marks1, &s[i].marks2, &s[i].marks3);
        s[i].avg = (s[i].marks1 + s[i].marks2 + s[i].marks3) / 3.0;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].avg < s[j + 1].avg) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted in descending order of average marks:\n");
    printf("RollNo\tName\tAvgMarks\n");
    for (i = 0; i < n; i++)
        printf("%d\t%s\t%.2f\n", s[i].rollno, s[i].name, s[i].avg);

    return 0;
}
