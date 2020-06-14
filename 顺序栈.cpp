/*-------------------------------------
&表示的是引用，







-------------------------------------*/


#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define NO 0
#define ture 1
#define false 0
#define MAXSIDE 100		//顺序栈存储空间的初始 
typedef char ElemType;

//顺序栈的存储结构
typedef struct
{
	ElemType data[MAXSIDE];	//字符串（或者是一维数组）类型数据
	/* 用来存放栈顶元素的下标 */
	int top;		//栈顶指针 此变量用来记录栈顶位置
}SqStack;			//声明顺序栈类型 
//入栈原理




//初始化顺序栈
void InitStack(SqStack *&s)		//形参是指针
{
	s = new SqStack;	//申请内存	s指向此块内存
	s->top = -1;		//初始化top为-1	即为空栈
}

//销毁顺序栈
void DestoryStack(SqStack *&s)	//形参是指针
{
	free(s);
}

//判断是否空栈
bool StackEmpty(SqStack *&s) 
{
	return(s->top == -1);	//判断是否为-1	-1则为空栈
}

//进栈
bool Push(SqStack *&s,ElemType e)
{
	if (s->top == MAXSIDE - 1)
		return false;
	s->top++;	//有数据进栈 top+1
	s->data[s->top] = e; //存放数据
	return ture;
}

//出栈 后进先出
bool Pop(SqStack *&s, ElemType &e)	//两个形参都需要直接修改实参 所以地址
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;	//数据出栈 top-1
	return ture;
}

//取栈顶元素 没有数据出栈 不需要 top-1
bool GetTop(SqStack *s, ElemType &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return ture;
}

void main()
{
	ElemType e;
	SqStack *s;		//定义指针结构体变量s 此时s没有指向内存

	InitStack(s);	//初始化栈	申请内存存放s
	Push(s, 'a');
	Push(s, 'a');
	Pop(s, e);
	printf("%c\n", e);
	puts(s->data);
	getchar();
	exit(0);
}
