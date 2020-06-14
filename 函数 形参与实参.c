#include<stdio.h>
add(int b)							/* b是形参  */ 
{
	int sum = 0;
	while(b>=0)
	{
		sum = sum + b;
		b--;
	}
	return sum;						/*   *2  sum 作为返回值 传递给 add(a) */ 
}

main()
{
	int a,sum;
	printf("plese enter:");
	scanf("%d",&a);
	sum = add(a);					/*  *1  a是实参  a 传递给形参 b*/ 
	printf("%d",sum);
	
}
