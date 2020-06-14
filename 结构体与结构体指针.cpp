#include "stdio.h"

typedef struct BOOK
{
	int m;
	int n;
}book,*pbook;
			//结构体类型指针变量能指向结构体类型变量 
				//book 等价于 sturct BOOK
				//pbook 等价于 sturct BOOK *
					
				//pbook a 等价于 book *a 

main()
{
	book a;				//a是BOOK结构体变量
	a.m = 1;
	a.n = 9;
	printf("book a	\na是结构体变量	\na.m = %d\n",a.m);
	printf("a.n = %d\n",a.n);
	pbook b = NULL;		//b是BOOK结构体类型的指针变量
	b = &a;				//b指向了结构体变量a的首地址 
	printf("pbook b  \nb是指向a的结构体指针  \nb->m = %d\n",b->m);
	printf("b->n = %d\n",b->n);
	printf("(*b).m = %d\n",(*b).m);
	printf("(*b).n = %d\n",(*b).n);
	book *c = NULL;
	c = &a;
	printf("book *c  \nc是指向a的结构体指针  \nc->m=%d\n",c->m);
	printf("c->n = %d\n",c->n);
	printf("(*c).m = %d\n",(*c).m);
	printf("(*c).n = %d\n",(*c).n);
}
