struct student2 {
    char name[20];
    int age ;
    char grade;
};

void student_print (struct student2 s);
void student_printByref (struct student2 *ps);
struct student student_scan (void);
void student_scanByref (struct student2 *ps);
void student_printAll (struct student2 *arr,int size);

