#include<stdio.h>
add(int b)							/* b���β�  */ 
{
	int sum = 0;
	while(b>=0)
	{
		sum = sum + b;
		b--;
	}
	return sum;						/*   *2  sum ��Ϊ����ֵ ���ݸ� add(a) */ 
}

main()
{
	int a,sum;
	printf("plese enter:");
	scanf("%d",&a);
	sum = add(a);					/*  *1  a��ʵ��  a ���ݸ��β� b*/ 
	printf("%d",sum);
	
}
