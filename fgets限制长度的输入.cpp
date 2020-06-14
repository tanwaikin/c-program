#include "stdio.h"
#define nameSize 20		//定义名字的长度 

main()
{
	char name[nameSize];
	fgets(name,nameSize,stdin);		 
	puts(name);
 } 
