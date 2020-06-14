#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

main()
{
	srand(time(NULL));
	printf("%ld\n",rand()%100+1);
	printf("%ld",time(NULL));
	
	
}
