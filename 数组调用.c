#include <stdio.h>
#define N 40

int main()
{	int score[N], aver, n;
	n = ReadScore(score);     //���ú��� �������**�׵�ַ**��Ϊ��������ȥ
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
	}while (score[i] >= 0);  		/*������Ϊ����ʱ �˳����� */ 
	return i;     /*��������*/            
}

