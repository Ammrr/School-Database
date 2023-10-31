#include <stdio.h>
#include <stdlib.h>
#include "school.h"
#include "exter_fun.h"

int sch_currentsize=0;
sch_student school [1000];

void school_AddStudent ()
{
    if(sch_currentsize==1000)
    {
        printf("Sorry ... School is full \n");
    }
    else
    {
        school[sch_currentsize]=school_ScanStudent();
        sch_currentsize++;
    }
}

void school_PrintStudent (char* name,char* id)
{
    int r;
    r=school_DetectStudentByName_Id (name,id);
    if(r==-1)
    {
        printf("This data is invalid\n");
    }
    else
    {
        school_PrintStudentByIndex (r);
    }
}

void school_PrintAllStudent ()
{
    int i;
    for(i=0; i<sch_currentsize; i++)
    {
        printf("Student %d\n",i+1);
        school_PrintStudentByIndex (i);
    }
    if (sch_currentsize==0)
    {
        printf("No Student's Data To Print \n");
    }
//    FILE *fp;
//    fp=fopen("SchoolData.bin","a+ b");
//    sch_student s;
//    while(fread(&s,sizeof(s),1,fp)==1)
//    {
//        school_PrintStudentHistory(s);
//    }
//    fclose(fp);
}


int school_EditStudent(char* name,char* id)
{
    int r;
    r=school_DetectStudentByName_Id(name,id);
    if(r==-1)
    {
        printf("This data is invalid...\n");
        return 0;
    }
    else
    {
        printf("Editing a Student...\n\n");
        school_EditStudentByIndex (r);
    }
    return 1;
}

int school_DeleteStudent (char* name,char* id)
{
    int r;
    r=school_DetectStudentByName_Id(name,id);
    if(r==-1)
    {
        printf("This data is invalid...\n");
        return 0;
    }
    else
    {
        school_DeleteStudentByIndex (r);
    }
    return 1;
}

int scool_CallStudent(char* name,char* id)
{
    int r;
    r=school_DetectStudentByName_Id(name,id);
    if(r==-1)
    {
        printf("This data is invalid...\n");
        return 0;
    }
    else
    {
        school_CallStudentByIndex (r);
    }
    return 1;
}

