#include <stdio.h> 
 
main()
{
	int n,m;
	printf("Plese enter n:\n");
	scanf("%d",&n);
	for(m = 1 ;m <= n ;m = m+1)			/* 循环控制表达式为  真 =1  时执行循环 ， 假则退出循环 */
	{ //初始化表达式 ； 控制表达式 ； 增值表达式 
		printf("%d.\n",m);
	}
	printf("%d",m);
} 
