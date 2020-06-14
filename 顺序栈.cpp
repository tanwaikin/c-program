/*-------------------------------------
&��ʾ�������ã�







-------------------------------------*/


#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define NO 0
#define ture 1
#define false 0
#define MAXSIDE 100		//˳��ջ�洢�ռ�ĳ�ʼ 
typedef char ElemType;

//˳��ջ�Ĵ洢�ṹ
typedef struct
{
	ElemType data[MAXSIDE];	//�ַ�����������һά���飩��������
	/* �������ջ��Ԫ�ص��±� */
	int top;		//ջ��ָ�� �˱���������¼ջ��λ��
}SqStack;			//����˳��ջ���� 
//��ջԭ��




//��ʼ��˳��ջ
void InitStack(SqStack *&s)		//�β���ָ��
{
	s = new SqStack;	//�����ڴ�	sָ��˿��ڴ�
	s->top = -1;		//��ʼ��topΪ-1	��Ϊ��ջ
}

//����˳��ջ
void DestoryStack(SqStack *&s)	//�β���ָ��
{
	free(s);
}

//�ж��Ƿ��ջ
bool StackEmpty(SqStack *&s) 
{
	return(s->top == -1);	//�ж��Ƿ�Ϊ-1	-1��Ϊ��ջ
}

//��ջ
bool Push(SqStack *&s,ElemType e)
{
	if (s->top == MAXSIDE - 1)
		return false;
	s->top++;	//�����ݽ�ջ top+1
	s->data[s->top] = e; //�������
	return ture;
}

//��ջ ����ȳ�
bool Pop(SqStack *&s, ElemType &e)	//�����βζ���Ҫֱ���޸�ʵ�� ���Ե�ַ
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;	//���ݳ�ջ top-1
	return ture;
}

//ȡջ��Ԫ�� û�����ݳ�ջ ����Ҫ top-1
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
	SqStack *s;		//����ָ��ṹ�����s ��ʱsû��ָ���ڴ�

	InitStack(s);	//��ʼ��ջ	�����ڴ���s
	Push(s, 'a');
	Push(s, 'a');
	Pop(s, e);
	printf("%c\n", e);
	puts(s->data);
	getchar();
	exit(0);
}
