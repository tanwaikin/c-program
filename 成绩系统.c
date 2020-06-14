#include "stdio.h"
#define N 50
int scan_student(int n,int num[],int score[]);
int number_sort(int n,int num[],int score[]);
main()
{
	int n;
	int num[N];
	int score[N];
	printf("请输入学生数目:");
	scanf("%d",&n);
	scan_student(n,num,score);
	//number_sort(n,num,score);
 } 
 int scan_student(int n,int num[],int score[])
 {
 	
	 int i = -1;
	 printf("学号  成绩\n");
	 do{
	 	i++;
	 	printf("%d\n",i);				//做到这里// 
	 	printf("%d\n",n);				//
	 	scanf("%d %d",&num[i],&score[i]);			//
	 } while(i<n-1);
 }
 
int number_sort(int n,int num[],int score[])
{
	int i=0,m=0;
	for(i=0;i<n-1;i++)
	{
	}
}
