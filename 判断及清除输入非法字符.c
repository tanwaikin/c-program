#include <stdio.h>

main()
{
	int a,ret;
	ret = scanf("%d",&a);
	printf("%d",ret);
	while(ret != 1)								/*ѭ��1*/ 
	{
		while(getchar() != '\n');				/*ѭ��2*/ 
		printf ("plese enter:\n");
		ret = scanf("%d",&a);
	}
	
 } 
