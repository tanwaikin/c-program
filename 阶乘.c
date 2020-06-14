#include <stdio.h>
main()
{
	long p = 1;
	int n;
	int i;
	printf("Plese enter n:");
	scanf("%d",&n);
	for(i = 1; i<= n ; i = i+1)
	{
		p = p * i ;
		printf("%d!=%d\n",i,p);
	}
}
