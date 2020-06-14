#include "stdio.h"
#define N 20
main()
{
	int n;
	int num[N];
	printf("enter n:");//获得数目 n
	scanf("%d",&n); 
	
	get_number(n,num[N]);//获得数字 
	sort(n,num[N]);//排序

 } 
 
 
int get_number(int n,int num[])
{
	int i=0;
	do{
		i++;
	 	printf("%d\n",i);			
	 	printf("%d\n",n);				
	 	scanf(" %d",&num[i]);
		printf("%d",&num[i]);
	 } while(i<n-1);
}


int sort(int n,int num[])
{
	int i,m;
	for(i=1;i<n-1;i++)
	{
		
		for(m=1;m<n-i;m++)
		{
			
		}
	}
}
