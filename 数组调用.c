#include <stdio.h>
#define N 40

int main()
{	int score[N], aver, n;
	n = ReadScore(score);     //调用函数 将数组的**首地址**作为参数传过去
	printf("Total students are %d\n",n);
	
	printf("Average score is %d\n",aver);
	return 0;
}
int ReadScore(int score[])  
{	int i = -1;         
	do{
		i++;
		printf("Input score:");
		scanf("%d", &score[i]);
	}while (score[i] >= 0);  		/*当输入为负数时 退出计数 */ 
	return i;     /*返回人数*/            
}

