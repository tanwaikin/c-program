#include<stdio.h>
scan()
{
	int ab,ret;
	ret = scanf("%d",&ab);
	printf("%d\n",ret);
	while(ret != 1)								/*循环1*/ 
	{
		while(getchar() != '\n');				/*循环2*/ 
		printf ("plese enter:\n");
		ret = scanf("%d",&ab);
		printf("%d\n",ret);
	}
	return ab;									/* 注意； return 语句不能放在循环内 否则将跳出函数 */
}
main()
{	
	int a,ad;
	printf("plese enter:\n");
	ad = scan();								/* 不带参数的调用-- */ 
	printf("%d",ad);
}
