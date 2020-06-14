#include <stdio.h>

main()
{
	int counter,i,a;
	printf("1  2  3  4  5  6  7  8  9\n");
	printf("-  -  -  -  -  -  -  -  -\n");
	
	for(counter=1;counter<=9;counter++)		/* ¼ÆÊýÆ÷(³Ë9´Î) */
		{
			for(i=1;i<=9;i++)
			{
				printf("%d  ",counter*i);
			}
			printf("\n");
		}
	
 } 
