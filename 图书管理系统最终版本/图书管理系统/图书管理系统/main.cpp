#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>

#define CLEAR char CH;while((CH = getchar()) != '\n' && CH != EOF);	//清除缓存区
#define ENTER int enter;while ((enter = _getch()) != 13);	//按下enter后继续

void menu();

//数据
typedef struct book
{
	long int ID;		//编号
	char name[30];		//书名
	char author[20]; 	//作者
	char amount[6];		//数量
}BOOK;

//结点
typedef struct node
{
	BOOK data;			//数据域
	struct node *next;	//结点域
}NODE, *pNODE;

//创建表头
pNODE createList()
{
	//申请一块动态内存，并返回这块内存的地址
	pNODE headNode = new NODE;
	//指针初始化指向空，指针域置空
	headNode->next = NULL;
	//返回头地址 
	return headNode;
}

//创建链表表头list
pNODE list = createList();

//创建节点
pNODE createNode(BOOK data)
{
	pNODE Node = new NODE;
	Node->data = data;
	Node->next = NULL;
	return Node;
}



void insertNodeByHead(BOOK data)		//头插法插入结点
{
	//插入前首先创建插入的结点
	pNODE newNode = createNode(data);
	newNode->next = list->next;
	list->next = newNode;
}
void addBookInfo()		//获取书本信息
{
	CLEAR	//清除缓存区
		struct book data;
	printf("请输入图书编号：");
	scanf_s("%ld", &data.ID); getchar();
	printf("请输入书名：");
	gets_s(data.name);
	printf("请输入作者：");
	gets_s(data.author);
	printf("请输入数量：");
	gets_s(data.amount);
	insertNodeByHead(data);
}


void printBookInfo()		//图书总览
{

	if (list->next == NULL)
	{

		puts("暂无信息，请添加");
		puts("按下回车返回主菜单");
		ENTER CLEAR
			menu();
	}
	else
	{

		printf("编号			");
		printf("姓名			");
		printf("作者			");
		printf("数量\n");


		pNODE p = list->next;
		while (p)
		{
			printf("%d			", p->data.ID);
			printf("%s			", p->data.name);
			printf("%s			", p->data.author);
			printf("%s\n", p->data.amount);

			p = p->next;//指针指向下一个
		}
		puts("按下回车返回主菜单");
		ENTER CLEAR
			menu();
	}
}

pNODE searchNodeByID(long int ID)		//通过ID查找结点
{
	pNODE p = list;
	pNODE pNext = p->next;
	while (pNext != NULL && pNext->data.ID != ID)
	{
		p = pNext;
		pNext = p->next;
	}
	if (pNext != NULL)	//如果不是空表则return pNext
		return pNext;
	return NULL;
}

void searchInfoByID()			//通过ID查找书本并打印信息
{
	CLEAR
		printf("请输入要查询的图书编号：");
	long int searchID;
	scanf_s("%ld", &searchID);

	if (searchNodeByID(searchID) == NULL)
	{
		printf("没有此图书信息");

		//按回车回到主菜单
		printf("按下Enter键返回主菜单");
		ENTER CLEAR
			menu();
	}
	else
	{
		//打印查找到的数据
		printf("图书编号：%d\n", searchNodeByID(searchID)->data.ID);
		printf("书名：%s\n", searchNodeByID(searchID)->data.name);
		printf("作者：%s\n", searchNodeByID(searchID)->data.author);
		printf("价格：%s\n", searchNodeByID(searchID)->data.amount);

		//按回车回到主菜单
		printf("按下Enter键回到主菜单");
		ENTER CLEAR
			menu();
	}

}

pNODE searchNodeByName(char *searchName)		//通过Name查找结点
{
	pNODE p = list;
	pNODE pNext = p->next;
	while (pNext != NULL && strcmp(pNext->data.name, searchName))
	{
		p = pNext;
		pNext = p->next;
	}
	if (pNext != NULL)	//如果不是空表则retun pNext
		return pNext;
	return NULL;
}

void searchInfoByName()			//通过Name查找图书并打印信息
{
	CLEAR
		printf("请输入要查询的书名：");
	char searchName[30];
	gets_s(searchName);

	if (searchNodeByName(searchName) == NULL)
	{
		printf("没有此图书信息");

		//按回车回到主菜单
		printf("按下Enter键返回主菜单");
		ENTER CLEAR
			menu();
	}
	else
	{
		//打印查找到的数据
		printf("图书编号：%d\n", searchNodeByName(searchName)->data.ID);
		printf("书名：%s\n", searchNodeByName(searchName)->data.name);
		printf("作者：%s\n", searchNodeByName(searchName)->data.author);
		printf("价格：%s\n", searchNodeByName(searchName)->data.amount);

		//按回车回到主菜单
		printf("按下Enter键回到主菜单");
		ENTER CLEAR
			menu();
	}

}

void searchInfo()	//图书查询
{

	system("cls");//清屏
	char t;
	printf("\n"); printf("\n");
	printf("-------------------------------------------------图书查询-------------------------------------------------\n");
	printf("\n");
	printf("                                               |1.编号查找|\n");
	printf("                                               |2.书名查找|\n\n                                                  ");
	CLEAR
		t = getchar();
	switch (t)
	{
	case'1':searchInfoByID();
	case'2':searchInfoByName();
	default:menu();
	}
}


void modifyInfoByID()		//通过ID修改书本信息 
{
	CLEAR
		printf("请输入要修改的图书编号：");
	long int modifyID;
	scanf_s("%ld", &modifyID);
	if (searchNodeByID(modifyID) != NULL)
	{
		CLEAR	//清除缓存区
			printf("请输入书名：");
		gets_s(searchNodeByID(modifyID)->data.name);
		printf("请输入作者：");
		gets_s(searchNodeByID(modifyID)->data.author);
		printf("请输入数量：");
		gets_s(searchNodeByID(modifyID)->data.amount); getchar();

		//按回车回到主菜单
		puts("修改成功！");
		puts("按下Enter键回到主菜单");
		ENTER
			menu();
	}
	else
	{
		puts("没有此图书信息");
		//按回车回到主菜单

		puts("按下Enter键返回主菜单");
		ENTER CLEAR
			menu();
	}

}


int deleteNodeByID(long int deleteID)	// 通过ID删除结点 
{
	pNODE p = list;
	pNODE pNext = p->next;
	while (pNext != NULL && pNext->data.ID != deleteID)
	{
		p = pNext;
		pNext = p->next;
	}
	if (pNext == NULL)
		return 0;
	else
	{
		p->next = pNext->next;
		free(pNext);
		return 1;
	}

}

void deleteInfoByID()		//通过ID删除书本信息 
{
	CLEAR
		printf("请输入要删除的图书编号：");
	long int deleteID;
	scanf_s("%ld", &deleteID);
	if (searchNodeByID(deleteID) != NULL)
	{
		deleteNodeByID(deleteID);

		//按回车回到主菜单
		puts("删除成功！");
		puts("按下Enter键回到主菜单");
		ENTER CLEAR
			menu();
	}
	else
	{
		puts("没有此图书信息");
		//按回车回到主菜单

		puts("按下Enter键返回主菜单");
		ENTER CLEAR
			menu();
	}

}


void saveFile()		//文件保存 
{
	FILE *fp;
	pNODE pr = list->next;
	if ((fp = fopen("bookInfo", "w")) == NULL)
	{
		printf("不能打开文件\n");
		puts("按下Enter键回到主菜单");
		ENTER CLEAR
			menu();
	}

	while (pr)
	{
		fwrite(pr, sizeof(NODE), 1, fp);
		pr = pr->next;
	}
	printf("保存成功");
	fclose(fp);
	puts("按下Enter键回到主菜单");
	ENTER CLEAR
		menu();
}

void loadFile()		//文件载入 
{
	FILE *fp;
	pNODE p;
	pNODE pr;
	pr = list;

	if ((fp = fopen("bookInfo", "r")) == NULL)
	{
		printf("不能打开文件\n");
		puts("按下Enter键回到主菜单");
		ENTER CLEAR
			menu();
	}

	while (!feof(fp))
	{
		p = new NODE;
		if (!p)
		{
			printf("memory malloc fail\n");
			puts("按下Enter键回到主菜单");
			ENTER CLEAR
		}

		if (fread(p, sizeof(NODE), 1, fp) != 1)

			break;
		else
		{
			if (list == NULL)
			{
				list = p;
				pr = p;
				pr->next = NULL;
			}
			else
			{
				pr->next = p;
				pr = p;
				pr->next = NULL;
			}

		}

	}
	printf("载入成功\n");
	puts("按下Enter键回到主菜单");
	ENTER CLEAR
		fclose(fp);


}

void menu()    //主菜单 
{
	do
	{
		system("cls");//清屏
		char t;
		printf("\n"); printf("\n"); printf("\n");
		printf("-------------------------------------------------图书信息管理系统-------------------------------------------------\n");
		printf("\n"); printf("\n");
		printf("                                                |1.图书信息录入|\n");
		printf("                                                |2.修改图书信息|\n");
		printf("                                                |3.删除图书信息|\n");
		printf("                                                |4.图书信息查询|\n");
		printf("                                                |5.图书信息总览|\n");
		printf("                                                |6.图书信息保存|\n");
		printf("                                                |7.图书信息载入|\n");
		printf("                                                |8.退出软件|\n\n                                                 ");
		t = getchar();
		switch (t)
		{
		case '1':addBookInfo(); break;
		case '2':modifyInfoByID(); break;
		case '3':deleteInfoByID(); break;
		case '4':searchInfo(); break;
		case '5':printBookInfo(); break;
		case '6':saveFile(); break;
		case '7':loadFile(); break;
		case '8':exit(0); break;
		default:break;
		}
	} while (1);
}


int main()			//主函数
{
	menu();
}