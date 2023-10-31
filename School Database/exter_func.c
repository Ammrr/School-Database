#include <stdio.h>
#include <stdlib.h>
#include "school.h"


extern int sch_currentStudentNumber;
extern int sch_currentsize;
extern int sch_count;
extern sch_student school [1000];
int string_CompareNotCaseSenstive (char* str1,char* str2)
{
    int i;
    for(i=0; ( str1[i] || str2[i] ); i++)
    {
        if( str1[i]>='A' && str1[i]<='Z' )
        {
            str1[i]=str1[i]-'A'+'a';
        }
        if( str2[i]>='A' && str2[i]<='Z' )
        {
            str2[i]=str2[i]-'A'+'a';
        }
        if(str1[i]!=str2[i])
        {
            return 0;
        }
    }
    return 1;
}
void string_print (char* str)
{
    int i ;
    for (i=0; str[i]; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}
void string_scan (char* str)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);
    for (; str[i]!='\n';)
    {
        // fflush(stdin);
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}

//int school_DetectStudentByName_Id (char* name,char* id)
//{
//    int i;
//    for(i=0; i<sch_currentsize; i++)
//    {
//        if(string_CompareNotCaseSenstive(school[i].name,name))
//        {
//            if(string_CompareNotCaseSenstive(school[i].id,id))
//            {
//                return i;
//            }
//        }
//    }
//    return -1;
//}

//to return if the student is found or not
// and if found return its index in school array
int school_DetectStudentByName_Id (char* name,char* id)
{
    int i;
    for(i=0; i<sch_currentsize; i++)
    {
        if(string_CompareNotCaseSenstive(school[i].name,name))
        {
            if(string_CompareNotCaseSenstive(school[i].id,id))
            {
                return i;
            }
        }
    }
    return -1;
}
int school_IdCheck(char* id_new)
// this function to make sure that id can use only with one student
// to make it easy to detect student's data later
{
    int i;
    for (i=0; i<sch_currentsize; i++)
    {
        if(string_CompareNotCaseSenstive(school[i].id,id_new))
        {
            return 0;
        }
    }
    return 1;
}

//void school_ScanIdentity(struct sch_identity s)
//{
//
//    printf("Enter the name : ");
//    string_scan(s.name);
//    printf("Enter the ID : ");
//    string_scan(s.id);
//   // return s;
//
//}
sch_student school_ScanStudent()
{
//    FILE *fp;
//    fp= fopen("SchoolData.bin","a+ b");
// here i tried to store the input data in file ...
//but i can not use it to delete or edit

    sch_student s;
    char id_temp[8];
    char id_flag=1;
    printf("Adding a new Student...\n\n");
    printf("Student's\n");
    printf("Name : ");
    string_scan(s.name);
    printf("ID : ");
    string_scan(id_temp);//to check if this id is available...
    // to avoid null id
    while(id_temp[0] == 0)
    {
        printf("Enter id : \n");
        string_scan(id_temp);
    }
    int i;
    while(id_flag==1)
    {
        // if the id is unique
        if(school_IdCheck(id_temp)==1)
        {
            for( i=0; id_temp[i]; i++)
            {
                //restore in struct id
                s.id[i]=id_temp[i];
            }
            s.id[i]=0;
            id_flag=0;
        }
        else
        {
            printf("This ID is invalid ,Try another one... \n");
            printf("Enter valid ID : ");
            string_scan(id_temp);
        }
    }
    printf("Age : ");
    scanf("%d",&s.age);
    printf("Grade %% : ");
    scanf("%d",&s.grade);//no sol
    printf("Phone  : ");
    string_scan(s.phone);
    printf("Address : ");
    string_scan(s.address);
    // No.Brothers
    printf("No.brothers : ");
    scanf("%d",&s.no_brothers);
    s.brother=malloc(s.no_brothers * sizeof(sch_person));
    char* p=s.brother;
    int size=sizeof(sch_person);

    //Father
    printf("\nFather's\n");
    printf("Name : ");
    string_scan(s.father.name);
    printf("Phone  : ");
    string_scan(s.father.phone);
    printf("Age : ");
    scanf("%d",&s.father.age);

    //Mother
    printf("\nMother's\n");
    printf("Name : ");
    string_scan(s.mother.name);
    printf("Phone  : ");
    string_scan(s.mother.phone);
    printf("Age : ");
    scanf("%d",&s.mother.age);

    //Brothers
    if(s.no_brothers>0)
    {
        printf("\nBrother's \n");
        printf("Name : ");
        string_scan(&p[0]);
        printf("Phone  : ");
        string_scan(&p[10]);
        printf("Age : ");
        scanf("%d",(int*)&p[22]);
    }
    int j;
    for( j=1; j<s.no_brothers; j++)
    {
        printf("\nBrother's %d\n",j+1);
        printf("Name : ");
        string_scan(&p[0+(j)*size]);
        printf("Phone  : ");
        string_scan(&p[10+(j)*size]);
        printf("Age : ");
        scanf("%d",(int*)&p[22+(j)*size]);
    }
//    fwrite(&s,sizeof(s),1,fp);
//    fclose(fp);
    printf("\n\n");
    return s;

}
void school_PrintStudentByIndex(int i)
{
    //student
    printf("\nStudent's Data\n");
    printf("Name : ");
    string_print(school[i].name);
    printf("ID : ");
    string_print(school[i].id);
    printf("Grade : %%");
    printf("%d\n",school[i].grade);
    printf("Age : ");
    printf("%d\n",school[i].age);
    printf("Address : ");
    string_print(school[i].address);
    printf("Phone : ");
    string_print(school[i].phone);
    printf("No.Brothers : ");
    printf("%d\n",school[i].no_brothers);
    printf("\n");

    //father
    printf("Father's Data\n");
    printf("Name : ");
    string_print(school[i].father.name);
    printf("Age : ");
    printf("%d\n",school[i].father.age);
    printf("Phone : ");
    string_print(school[i].father.phone);
    printf("\n");

    //mother
    printf("Mother's Data\n");
    printf("Name : ");
    string_print(school[i].mother.name);
    printf("Age : ");
    printf("%d\n",school[i].mother.age);
    printf("Phone : ");
    string_print(school[i].mother.phone);
    printf("\n");

    //brothers
    char* p=school[i].brother;
    char size=sizeof(sch_person);

    if(school[i].no_brothers>0)
    {
        printf("Brother's Data\n");
        printf("Name : ");
        string_print(p);
        printf("Phone : ");
        string_print(&p[10]);
        printf("Age : ");
        printf("%d\n",(p[22]));
        printf("\n");
    }
    int j;
    for(j=1; j<school[i].no_brothers; j++)
    {
        printf("Brother %d\n",j+1);
        printf("Name : ");
        string_print(&p[(j)*size]);
        printf("Phone : ");
        string_print(&p[10+(j)*size]);
        printf("Age : ");
        printf("%d\n",(p[22+(j)*size]));
        printf("\n");
    }
    printf("\n");
    printf("\n");
}


void school_EditStudentDataByIndex(int r)
{
    int s;
    printf("Edit...\n\n");
    printf("1.Age\n");
    printf("2.Grade\n");
    printf("3.Phone\n");
    printf("4.Address\n");
    printf("\n");
    printf("Enter the number : \n");
    scanf("%d",&s);
    system("cls");

    switch (s)
    {
    case 1:
        printf("Enter the new age : ");
        scanf("%d",&school[r].age);
        system("cls");
        break;
    case 2:
        printf("Enter the new grade %% : ");
        scanf("%d",&school[r].grade);
        system("cls");
        break;
    case 3:
        printf("Enter the new phone  : ");
        string_scan(school[r].phone);
        system("cls");
        break;
    case 4:
        printf("Enter the new address : ");
        string_scan(school[r].address);
        system("cls");
        break;
    default:
        printf("Please enter a valid choice  \n");
        break;
    }
}
void school_EditFatherDataByIndex(int r)
{
    int s;
    scanf("%d",&s);
    system("cls");

    switch (s)
    {
    case 1:
        printf("Enter the new phone  : ");
        string_scan(school[r].father.phone);
        system("cls");
        break;
    case 2:
        printf("Enter the new age : ");
        scanf("%d",&school[r].father.age);
        system("cls");
        break;
    default:
        printf("Please enter a valid choice  \n");
        break;
    }
}
void school_EditMotherDataByIndex(int r)
{
    int s;
    scanf("%d",&s);
    system("cls");

    switch (s)
    {
    case 1:
        printf("Enter the new phone  : ");
        string_scan(school[r].mother.phone);
        system("cls");
        break;
    case 2:
        printf("Enter the new age : ");
        scanf("%d",&school[r].mother.age);
        system("cls");
        break;
    default:
        printf("Please enter a valid choice  \n");
        break;
    }
}

void school_EditBrotherDataByIndex(int r)
{
    int s,c=1;
    char* p=school[r].brother;
    int size=sizeof(sch_person);
    if(school[r].no_brothers>1)
    {
        printf("Which brother ?\n");
        printf("Enter the number of the brother : \n");
        scanf("%d",&c);
    }
    if(c>school[r].no_brothers)
    {
        printf("wrong choice...\n");
    }
    else
    {
        printf("Edit...\n\n");
        printf("1.Phone\n");
        printf("2.Age\n");
        printf("\n");
        printf("Enter the number : \n");
        scanf("%d",&s);
        system("cls");
        switch (s)
        {
        case 1:
            printf("Enter the new phone  : ");
            string_scan(&p[10+(c-1)*size]);
            system("cls");
            break;
        case 2:
            printf("Enter the new age : ");
            scanf("%d",(int*)&p[22+(c-1)*size]);
            system("cls");
            break;
        default:
            printf("Please enter a valid choice  \n");
            break;
        }
    }
}
void school_EditStudentByIndex (int r)
{
    int c;
    printf("Edit...\n\n");
    printf(" 1.Student's Data\n");
    printf(" 2.Father's Data\n");
    printf(" 3.Mother's Data\n");
    if(school[r].no_brothers>0)
    {
        printf(" 4.Brother's Data\n");
    }
    printf("\n");
    printf("Enter the number : \n");
    scanf("%d",&c);
    system("cls");
    if(c==2 || c==3)
    {
        printf("Edit...\n\n");
        printf("1.Phone\n");
        printf("2.Age\n");
        printf("\n");
        printf("Enter the number : \n");
    }
    switch (c)
    {
    case 1:
        school_EditStudentDataByIndex(r);
        break;
    case 2:
        school_EditFatherDataByIndex(r);
        break;
    case 3:
        school_EditMotherDataByIndex(r);
        break;
    case 4:
        school_EditBrotherDataByIndex(r);
        break;
    default:
        printf("Please enter a valid choice  \n");
        break;
    }
}

void school_DeleteStudentByIndex (int r)
{
    free(school[r].brother);
    int i;
    for(i=r; i<sch_currentsize; i++)
    {
        school[i]=school[i+1];
    }
    sch_currentsize--;
}

void school_CallStudentByIndex (int r)
{
    int s;
    printf("Call...\n");
    printf("1.Student\n");
    printf("2.Father\n");
    printf("3.Mother\n");
    scanf("%d",&s);
    system("cls");
    switch (s)
    {
    case 1:
        printf("Student's phone \n");
        printf("%s\n",school[r].phone);
        break;
    case 2:
        printf("Father's phone \n");
        printf("%s\n",school[r].father.phone);
        break;
    case 3:
        printf("Mother's phone \n");
        printf("%s\n",school[r].mother.phone);
        break;
    default :
        printf("wrong choice\n\n");
    }
}












