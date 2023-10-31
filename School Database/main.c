#include <stdio.h>
#include <stdlib.h>
#include "school.h"
#include "exter_fun.h"
int main()
{
    int s;
    char name_s [10];
    char id_s [8];

    while (1)
    {
        printf("\nOperations : \n\n");
        printf("(1) To Add student \n");
        printf("(2) To Edit data \n");
        printf("(3) To Delete student \n");
        printf("(4) To Print student's data \n");
        printf("(5) To Print all student's data \n");
        printf("(6) To Call student \n");
        printf("\n\n");

        printf("Enter the number of the operation : \n");
        scanf("%d",&s);

        switch (s)
        {
        case 1:
            system("cls");
            school_AddStudent();
            system("cls");
            break;
        case 2:
            system("cls");
            printf("Editing  Student...\n\n");
            printf("Name : ");
            string_scan(name_s);
            printf("ID : ");
            string_scan(id_s);
            system("cls");
            school_EditStudent(name_s,id_s);
            break;
        case 3:
            system("cls");
            printf("Deleting  Student...\n\n");
            printf("Name : ");
            string_scan(name_s);
            printf("ID : ");
            string_scan(id_s);
            system("cls");
            school_DeleteStudent(name_s,id_s);
            printf("Student's Data is Deleted...\n");
            break;
        case 4:
            system("cls");
            printf("Printing  Student...\n\n");
            printf("Name : ");
            string_scan(name_s);
            printf("ID : ");
            string_scan(id_s);
            system("cls");
            school_PrintStudent(name_s,id_s);
            break;
        case 5:
            system("cls");
            school_PrintAllStudent ();
            break;
        case 6:
            system("cls");
            printf("Calling  Student...\n\n");
            printf("Name : ");
            string_scan(name_s);
            printf("ID : ");
            string_scan(id_s);
            system("cls");
            scool_CallStudent(name_s,id_s);
            break;
        default:
            break;
        }
    }
}
