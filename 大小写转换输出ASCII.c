#include <stdio.h> 
 
main()
{
	char a;
	printf("Plese enter a character:\n");
	scanf("%c",&a);
	if (a>=65 && a<=90 || a>=97 && a<=122)
	{
		if (a>=65 && a<=90) printf("%c %d\n",a+32,a+32);
		else printf("%c %d\n",a-32,a-32);
	}
	else printf("%c %d\n",a,a);
	
} 
