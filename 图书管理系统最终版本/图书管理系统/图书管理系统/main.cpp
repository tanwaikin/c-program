#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>

#define CLEAR char CH;while((CH = getchar()) != '\n' && CH != EOF);	//���������
#define ENTER int enter;while ((enter = _getch()) != 13);	//����enter�����

void menu();

//����
typedef struct book
{
	long int ID;		//���
	char name[30];		//����
	char author[20]; 	//����
	char amount[6];		//����
}BOOK;

//���
typedef struct node
{
	BOOK data;			//������
	struct node *next;	//�����
}NODE, *pNODE;

//������ͷ
pNODE createList()
{
	//����һ�鶯̬�ڴ棬����������ڴ�ĵ�ַ
	pNODE headNode = new NODE;
	//ָ���ʼ��ָ��գ�ָ�����ÿ�
	headNode->next = NULL;
	//����ͷ��ַ 
	return headNode;
}

//���������ͷlist
pNODE list = createList();

//�����ڵ�
pNODE createNode(BOOK data)
{
	pNODE Node = new NODE;
	Node->data = data;
	Node->next = NULL;
	return Node;
}



void insertNodeByHead(BOOK data)		//ͷ�巨������
{
	//����ǰ���ȴ�������Ľ��
	pNODE newNode = createNode(data);
	newNode->next = list->next;
	list->next = newNode;
}
void addBookInfo()		//��ȡ�鱾��Ϣ
{
	CLEAR	//���������
		struct book data;
	printf("������ͼ���ţ�");
	scanf_s("%ld", &data.ID); getchar();
	printf("������������");
	gets_s(data.name);
	printf("���������ߣ�");
	gets_s(data.author);
	printf("������������");
	gets_s(data.amount);
	insertNodeByHead(data);
}


void printBookInfo()		//ͼ������
{

	if (list->next == NULL)
	{

		puts("������Ϣ�������");
		puts("���»س��������˵�");
		ENTER CLEAR
			menu();
	}
	else
	{

		printf("���			");
		printf("����			");
		printf("����			");
		printf("����\n");


		pNODE p = list->next;
		while (p)
		{
			printf("%d			", p->data.ID);
			printf("%s			", p->data.name);
			printf("%s			", p->data.author);
			printf("%s\n", p->data.amount);

			p = p->next;//ָ��ָ����һ��
		}
		puts("���»س��������˵�");
		ENTER CLEAR
			menu();
	}
}

pNODE searchNodeByID(long int ID)		//ͨ��ID���ҽ��
{
	pNODE p = list;
	pNODE pNext = p->next;
	while (pNext != NULL && pNext->data.ID != ID)
	{
		p = pNext;
		pNext = p->next;
	}
	if (pNext != NULL)	//������ǿձ���return pNext
		return pNext;
	return NULL;
}

void searchInfoByID()			//ͨ��ID�����鱾����ӡ��Ϣ
{
	CLEAR
		printf("������Ҫ��ѯ��ͼ���ţ�");
	long int searchID;
	scanf_s("%ld", &searchID);

	if (searchNodeByID(searchID) == NULL)
	{
		printf("û�д�ͼ����Ϣ");

		//���س��ص����˵�
		printf("����Enter���������˵�");
		ENTER CLEAR
			menu();
	}
	else
	{
		//��ӡ���ҵ�������
		printf("ͼ���ţ�%d\n", searchNodeByID(searchID)->data.ID);
		printf("������%s\n", searchNodeByID(searchID)->data.name);
		printf("���ߣ�%s\n", searchNodeByID(searchID)->data.author);
		printf("�۸�%s\n", searchNodeByID(searchID)->data.amount);

		//���س��ص����˵�
		printf("����Enter���ص����˵�");
		ENTER CLEAR
			menu();
	}

}

pNODE searchNodeByName(char *searchName)		//ͨ��Name���ҽ��
{
	pNODE p = list;
	pNODE pNext = p->next;
	while (pNext != NULL && strcmp(pNext->data.name, searchName))
	{
		p = pNext;
		pNext = p->next;
	}
	if (pNext != NULL)	//������ǿձ���retun pNext
		return pNext;
	return NULL;
}

void searchInfoByName()			//ͨ��Name����ͼ�鲢��ӡ��Ϣ
{
	CLEAR
		printf("������Ҫ��ѯ��������");
	char searchName[30];
	gets_s(searchName);

	if (searchNodeByName(searchName) == NULL)
	{
		printf("û�д�ͼ����Ϣ");

		//���س��ص����˵�
		printf("����Enter���������˵�");
		ENTER CLEAR
			menu();
	}
	else
	{
		//��ӡ���ҵ�������
		printf("ͼ���ţ�%d\n", searchNodeByName(searchName)->data.ID);
		printf("������%s\n", searchNodeByName(searchName)->data.name);
		printf("���ߣ�%s\n", searchNodeByName(searchName)->data.author);
		printf("�۸�%s\n", searchNodeByName(searchName)->data.amount);

		//���س��ص����˵�
		printf("����Enter���ص����˵�");
		ENTER CLEAR
			menu();
	}

}

void searchInfo()	//ͼ���ѯ
{

	system("cls");//����
	char t;
	printf("\n"); printf("\n");
	printf("-------------------------------------------------ͼ���ѯ-------------------------------------------------\n");
	printf("\n");
	printf("                                               |1.��Ų���|\n");
	printf("                                               |2.��������|\n\n                                                  ");
	CLEAR
		t = getchar();
	switch (t)
	{
	case'1':searchInfoByID();
	case'2':searchInfoByName();
	default:menu();
	}
}


void modifyInfoByID()		//ͨ��ID�޸��鱾��Ϣ 
{
	CLEAR
		printf("������Ҫ�޸ĵ�ͼ���ţ�");
	long int modifyID;
	scanf_s("%ld", &modifyID);
	if (searchNodeByID(modifyID) != NULL)
	{
		CLEAR	//���������
			printf("������������");
		gets_s(searchNodeByID(modifyID)->data.name);
		printf("���������ߣ�");
		gets_s(searchNodeByID(modifyID)->data.author);
		printf("������������");
		gets_s(searchNodeByID(modifyID)->data.amount); getchar();

		//���س��ص����˵�
		puts("�޸ĳɹ���");
		puts("����Enter���ص����˵�");
		ENTER
			menu();
	}
	else
	{
		puts("û�д�ͼ����Ϣ");
		//���س��ص����˵�

		puts("����Enter���������˵�");
		ENTER CLEAR
			menu();
	}

}


int deleteNodeByID(long int deleteID)	// ͨ��IDɾ����� 
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

void deleteInfoByID()		//ͨ��IDɾ���鱾��Ϣ 
{
	CLEAR
		printf("������Ҫɾ����ͼ���ţ�");
	long int deleteID;
	scanf_s("%ld", &deleteID);
	if (searchNodeByID(deleteID) != NULL)
	{
		deleteNodeByID(deleteID);

		//���س��ص����˵�
		puts("ɾ���ɹ���");
		puts("����Enter���ص����˵�");
		ENTER CLEAR
			menu();
	}
	else
	{
		puts("û�д�ͼ����Ϣ");
		//���س��ص����˵�

		puts("����Enter���������˵�");
		ENTER CLEAR
			menu();
	}

}


void saveFile()		//�ļ����� 
{
	FILE *fp;
	pNODE pr = list->next;
	if ((fp = fopen("bookInfo", "w")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		puts("����Enter���ص����˵�");
		ENTER CLEAR
			menu();
	}

	while (pr)
	{
		fwrite(pr, sizeof(NODE), 1, fp);
		pr = pr->next;
	}
	printf("����ɹ�");
	fclose(fp);
	puts("����Enter���ص����˵�");
	ENTER CLEAR
		menu();
}

void loadFile()		//�ļ����� 
{
	FILE *fp;
	pNODE p;
	pNODE pr;
	pr = list;

	if ((fp = fopen("bookInfo", "r")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		puts("����Enter���ص����˵�");
		ENTER CLEAR
			menu();
	}

	while (!feof(fp))
	{
		p = new NODE;
		if (!p)
		{
			printf("memory malloc fail\n");
			puts("����Enter���ص����˵�");
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
	printf("����ɹ�\n");
	puts("����Enter���ص����˵�");
	ENTER CLEAR
		fclose(fp);


}

void menu()    //���˵� 
{
	do
	{
		system("cls");//����
		char t;
		printf("\n"); printf("\n"); printf("\n");
		printf("-------------------------------------------------ͼ����Ϣ����ϵͳ-------------------------------------------------\n");
		printf("\n"); printf("\n");
		printf("                                                |1.ͼ����Ϣ¼��|\n");
		printf("                                                |2.�޸�ͼ����Ϣ|\n");
		printf("                                                |3.ɾ��ͼ����Ϣ|\n");
		printf("                                                |4.ͼ����Ϣ��ѯ|\n");
		printf("                                                |5.ͼ����Ϣ����|\n");
		printf("                                                |6.ͼ����Ϣ����|\n");
		printf("                                                |7.ͼ����Ϣ����|\n");
		printf("                                                |8.�˳����|\n\n                                                 ");
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


int main()			//������
{
	menu();
}