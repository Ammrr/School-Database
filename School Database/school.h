#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    char phone[12];
    int age ;

}sch_person;

typedef struct {
    char name[10];
    char address [10];
    char id[8];
    char phone[12];
    int grade;
    int no_brothers;
    int age;
    sch_person father;
    sch_person mother;
    char *brother;
} sch_student;

void school_AddStudent ();
void school_PrintStudent (char* name,char* id);
void school_PrintAllStudent ();
void test1();
int school_EditStudent (char* name,char* id);
int school_DeleteStudent (char* name,char* id);
int scool_CallStudent(char* name,char* id);
void school_PrintStudentHistory( sch_student s);
void school_EditStudentByIndex (int r);



