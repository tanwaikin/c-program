#include "stdio.h"

typedef struct BOOK
{
	int m;
	int n;
}book,*pbook;
			//�ṹ������ָ�������ָ��ṹ�����ͱ��� 
				//book �ȼ��� sturct BOOK
				//pbook �ȼ��� sturct BOOK *
					
				//pbook a �ȼ��� book *a 

main()
{
	book a;				//a��BOOK�ṹ�����
	a.m = 1;
	a.n = 9;
	printf("book a	\na�ǽṹ�����	\na.m = %d\n",a.m);
	printf("a.n = %d\n",a.n);
	pbook b = NULL;		//b��BOOK�ṹ�����͵�ָ�����
	b = &a;				//bָ���˽ṹ�����a���׵�ַ 
	printf("pbook b  \nb��ָ��a�Ľṹ��ָ��  \nb->m = %d\n",b->m);
	printf("b->n = %d\n",b->n);
	printf("(*b).m = %d\n",(*b).m);
	printf("(*b).n = %d\n",(*b).n);
	book *c = NULL;
	c = &a;
	printf("book *c  \nc��ָ��a�Ľṹ��ָ��  \nc->m=%d\n",c->m);
	printf("c->n = %d\n",c->n);
	printf("(*c).m = %d\n",(*c).m);
	printf("(*c).n = %d\n",(*c).n);
}
