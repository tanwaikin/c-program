#include <stdio.h>
int a,b,op;
main()
{
	printf("plese enter an expression :\n");
	scanf("%d %c%d",&a,&op,&b);				/* %c前有一个空格 */
	switch(op)
	{
		case '+':
			printf("%d+%d=%d\n",a,b,a+b);
			break;							/*break; 也是一条语句  需要加分号  */ 
		case '-':
			printf("%d-%d=%d\n",a,b,a-b);
			break;
		case '*':
			printf("%d*%d=%d\n",a,b,a*b);
			break;
		case '/':
			if (b == 0)
				printf("Division by zero\n");
			else
				printf("%d/%d=%d\n",a,b,a/b);
			break;
		default:
			printf("Invalid oprator!\n");
	}
	
}
