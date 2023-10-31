//#include "student.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//void student_printByval (struct student2 s)
//{
//    string_print(s.name);
//    printf("%d",s.age);
//    printf("\n");
//    printf("%c",s.grade);
//    printf("\n");
//}
//void student_printByref (struct student2 *ps)
//{
//    string_print(ps->name);
//    printf("%d",ps->age);
//    printf("\n");
//    printf("%c",ps->grade);
//    printf("\n");
//}
//struct student2 student_scan (void)
//{
//    struct student2 s;
//    printf("enter name : ");
//    string_scan(s.name,20);
//    printf("enter age : ");
//    scanf("%d",&s.age);
//    fflush(stdin);
//    printf("enter grade : ");
//    scanf("%c",&s.grade);
//    return s;
//}
//void student_scanByref (struct student2 *ps)
//{
//    printf("enter name : ");
//    string_scan(ps->name,20);
//    printf("enter age : ");
//    scanf("%d",&ps->age);
//    fflush(stdin);
//    printf("enter grade : ");
//    scanf("%c",&ps->grade);
//}
//void student_printAll (struct student2 *arr,int size)
//{
//    printf("   name   |    age    |    grade     \n");
//    int i;
//    for(i=0;i<size;i++)
//    {
//
//    printf("   %-8s    %d            %c       \n",arr[i].name,arr[i].age,arr[i].grade);
//    }
//    printf("\n");
//}
//
