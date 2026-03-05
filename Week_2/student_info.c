#include <stdio.h>

struct student_info
{
    char name[81];
    char roll_no[21];
    int age;
};
typedef struct student_info stud;

int main()
{
	int n,i;
	
	printf("Enter the no. of students : ");
	scanf("%d",&n);
	stud s[n];
	
	for(i=0;i<n;i++)
	{
	
		getchar();
	    printf("\nEnter name of (%d) student : ",i+1);
	    fgets(s[i].name, 81, stdin);
	
	    printf("Enter the roll no. : ");
	    fgets(s[i].roll_no, 21, stdin);
	
	    printf("Enter age : ");
	    scanf("%d", &s[i].age);
	
	    printf("\nName- %sRoll no.- %sAge- %d\n", s[i].name, s[i].roll_no, s[i].age);
	}
}
