#include "stdio.h" 
			//ͨ��ָ�뽻�������� 

void swap(int *a,int *b);  //�������� 

main(){
	int a,b;
	printf("������a b:");
	scanf("%d %d",&a,&b);
	printf("����ǰ:a=%d b=%d\n",a,b);
	swap(&a,&b);									//�����ǵ�ַ 
	printf("������:a=%d b=%d",a,b);
}

void swap(int *a,int *b){
	int temp;
	temp=*a;					//  ֱ���޸�ָ�������ָ��ĵı�����ֵ
	*a=*b;						//   
	*b=temp;					// 
}
