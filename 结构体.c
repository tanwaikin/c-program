#include "stdio.h"
#include "string.h"

struct student{
	int num;
	char name[10];
	char sex;
};
typedef struct student stu;
typedef struct student *pstu;

main()
{
	stu stu1,stu2;
	strcpy(stu1.name, "ahahah");
	stu1.num = 1234;
	stu1.sex= 'a';
	printf("%s",stu1.sex);
	pstu stu3;
	strcpy(stu3->name, "ahahah");
	printf("%s",stu3->name);
} 

