#include <stdio.h> 
 
main()
{
	int n,m;
	printf("Plese enter n:\n");
	scanf("%d",&n);
	for(m = 1 ;m <= n ;m = m+1)			/* ѭ�����Ʊ��ʽΪ  �� =1  ʱִ��ѭ�� �� �����˳�ѭ�� */
	{ //��ʼ�����ʽ �� ���Ʊ��ʽ �� ��ֵ���ʽ 
		printf("%d.\n",m);
	}
	printf("%d",m);
} 
