#include <stdio.h>

main()
{
	int a,ret;
	ret = scanf("%d",&a);
	printf("%d",ret);
	while(ret != 1)								/*Ñ­»·1*/ 
	{
		while(getchar() != '\n');				/*Ñ­»·2*/ 
		printf ("plese enter:\n");
		ret = scanf("%d",&a);
	}
	
 } 
