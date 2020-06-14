#include "stdio.h"

exchange1(int x,int y){			//值传递 
	int temp=x;
	x=y;
	y=temp;
	printf("in exchange1\nx=%d\ny=%d\n",x,y);
}

exchange2(int *x,int *y){		//地址传递 
	int temp=*x;
	*x=*y;
	*y=temp;
	printf("in exchange2\nx=%d\ny=%d\n",*x,*y);
} 

exchange3(int &x,int &y){		//引用传递 
	int temp=x;
	x=y;
	y=temp;
	printf("in exchange3\nx=%d\ny=%d\n",x,y);
}

main(){
	int a=5;
	int b=9;
	printf("int a=%d; int b=%d\n",a,b);
	exchange1(a,b);
	printf("out exchange1\na=%d\nb=%d\n",a,b);
	a=5;b=9;
	printf("int a=%d; int b=%d\n",a,b);
	exchange2(&a,&b);
	printf("out exchange2\na=%d\nb=%d\n",a,b);
	a=5;b=9;
	printf("int a=%d; int b=%d\n",a,b);
	exchange3(a,b);
	printf("out exchange3\na=%d\nb=%d\n",a,b);
}
