#include "stdio.h"
#define nameSize 20		//�������ֵĳ��� 

main()
{
	char name[nameSize];
	fgets(name,nameSize,stdin);		 
	puts(name);
 } 
