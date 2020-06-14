#include "stdio.h" 
			//通过指针交换两个数 

void swap(int *a,int *b);  //函数声明 

main(){
	int a,b;
	printf("请输入a b:");
	scanf("%d %d",&a,&b);
	printf("交换前:a=%d b=%d\n",a,b);
	swap(&a,&b);									//传的是地址 
	printf("交换后:a=%d b=%d",a,b);
}

void swap(int *a,int *b){
	int temp;
	temp=*a;					//  直接修改指针变量所指向的的变量的值
	*a=*b;						//   
	*b=temp;					// 
}
