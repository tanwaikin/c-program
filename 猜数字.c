#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

main()
{
	char ch;
	do{
	
		int magic , guess , counter = 0 ;
		
		srand(time(NULL));
		magic = rand() % 100 + 1;		/* rand() % 100 + 1 	����1��100�������*/ 
		do {
			printf("Plese enter guess:");
			scanf("%d",&guess);
			if(guess > magic)	
			{
				printf("Too big\n");
				counter++;
			}
			else if(guess < magic)
			{
				printf("Too small\n");
				counter++;
			}
			else
			{
				printf("Correct!\n");
				counter++;
			}
			
		}while(guess != magic);
		printf("counter = %d\n",counter);
		printf("Do you want to play again? Y/N or y/n\n");
		scanf(" %c",&ch);							/*%cǰ��һ�ո� ���Ի������еĻس���*/ 
	}while(ch == 'y' || ch == 'Y');l
}
