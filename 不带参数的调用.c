#include<stdio.h>
scan()
{
	int ab,ret;
	ret = scanf("%d",&ab);
	printf("%d\n",ret);
	while(ret != 1)								/*ѭ��1*/ 
	{
		while(getchar() != '\n');				/*ѭ��2*/ 
		printf ("plese enter:\n");
		ret = scanf("%d",&ab);
		printf("%d\n",ret);
	}
	return ab;									/* ע�⣻ return ��䲻�ܷ���ѭ���� ������������ */
}
main()
{	
	int a,ad;
	printf("plese enter:\n");
	ad = scan();								/* ���������ĵ���-- */ 
	printf("%d",ad);
}
