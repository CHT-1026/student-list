#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)

#define namemax 50
#define broaden_num 100
#define maxnums 100

enum gender
{
	empty_gender,											
	Male,											
	Female											
};

enum major
{
	empty_major,
	wang_gong,
	jing_guan,
	tong_xin,
	xin_kang,
	dian_gong
};

typedef struct
{
	char name[namemax];
	char student_ID[14];
	enum gender stu_gender;
	enum major stu_major;
}Elem, * Eleml;



typedef struct
{
	int maxnum;
	Elem *arr;
	int length;
	
}Sqlist, * Sqlistl;



char* read_major(enum major a);
char* read_gender(enum gender a);
void Init_sqlist(Sqlistl list);
void broaden_room(Sqlist* list);
void pop_delete(Sqlistl list);
void push_insert(Sqlistl list, Elem el);
void InsertSqlist_choose(Sqlistl list, int pos, Elem el);
void DeSqlist(Sqlistl list, int pos);
void PrintSqlist(Sqlistl list);
int* Find_name(Sqlistl list, char* tar);
int* Find_ID(Sqlistl list, char* tar);
int* Find_gender(Sqlistl list, int tar);
int* Find_major(Sqlistl list, int tar);
int areStringsEqual(char* a, char* b);


int main()
{
	Sqlist list;
	Init_sqlist(&list);
	while (1)
	{
		
		system("cls");
		int path;
		printf("1�������ѧ��\n");
		printf("2��ɾ�����һ�����ѧ��\n");
		printf("3��ɾ��ָ��λ�õ�ѧ��\n");
		printf("4��ָ��λ�����ѧ��\n");
		printf("5���鿴ѧ������\n");
		printf("6��Ѱ������������ѧ��\n");
		printf("7�������б�\n");
		printf("������ѡ�0�˳���\n");
		scanf("%d" ,& path);
		if (path == 0) break;
		switch (path)
		{
		case 1:
		{
			Elem el{};
			system("cls");
			printf("������ѧ������\n");
			scanf("%s", el.name);
			system("cls");
			printf("������ѧ��ѧ��\n");
			scanf("%s", el.student_ID);
			system("cls");
			printf("������ѧ���Ա�1�����У�2����Ů��\n");
			scanf("%d", &el.stu_gender);
			system("cls");
			printf("������ѧ��רҵ\n(1-5�ֱ�������������ܣ�ͨ�ţ��ſ����繤)\n");
			scanf("%d", &el.stu_major);
			system("cls");
			push_insert(&list, el);
			break;
		}
		case 2:
		{
			system("cls");
			pop_delete(&list);
			printf("ɾ���ɹ�!");
			getchar();
			getchar();
			system("cls");
			break;

		}
		case 3:
		{
			int pos;
			system("cls");
			printf("������ϣ��ɾ����λ�ã�\n");
			scanf("%d", &pos);
			DeSqlist(&list, pos);
			printf("ɾ���ɹ�");
			getchar();
			getchar();
			system("cls");
			break;
		}
		case 4:
		{
			Elem el{};
			int pos;
			system("cls");
			printf("������ϣ����ӵ�λ�ã�\n");
			scanf("%d", &pos);
			system("cls");
			printf("������ѧ������\n");
			scanf("%s", el.name);
			system("cls");
			printf("������ѧ��ѧ��\n");
			scanf("%s", el.student_ID);
			system("cls");
			printf("������ѧ���Ա�1�����У�2����Ů��\n");
			scanf("%d", &el.stu_gender);
			system("cls");
			printf("������ѧ��רҵ\n(1-5�ֱ�������������ܣ�ͨ�ţ��ſ����繤)\n");
			scanf("%d", &el.stu_major);
			system("cls");
			InsertSqlist_choose(&list,pos,el);
			printf("��ӳɹ�");
			getchar();
			getchar();
			system("cls");
			break;

		}
		case 5:
		{
			system("cls");
			PrintSqlist(&list);
			getchar();
			getchar();
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			int type;
			printf("��ѡ��ϣ�����ҵ�����\n1������\n2��ѧ��\n3���Ա�\n4��רҵ\n");
			scanf("%d", &type);
			switch (type)
			{
			case 1:
			{
				system("cls");
				printf("�������ѯ������\n");
				char* tar;
				tar = (char*)malloc(sizeof(char) * 100);
				int* ans;
				ans = (int*)malloc(sizeof(int) * 100);
				memset(ans, -1, sizeof(int) * 100);
				scanf("%s", tar);
				ans = Find_name(&list, tar);
				system("cls");
				printf("�����������:\n");
				for (int i = 0; i < list.length; i++)
				{
					if (ans[i] != -1)
					{
						printf("%d     ", ans[i] + 1);
						printf("%s    ", list.arr[ans[i]].name);
						printf("%s    ", list.arr[ans[i]].student_ID);
						printf("%s    ", read_gender(list.arr[ans[i]].stu_gender));
						printf("%s\n", read_major(list.arr[ans[i]].stu_major));
					}
				}
				getchar();
				getchar();
				break;

			}
			case 2:
			{

				system("cls");
				printf("�������ѯ��ѧ��\n");
				char* tar;
				tar = (char*)malloc(sizeof(char) * 100);
				int* ans;
				ans = (int*)malloc(sizeof(int) * 100);
				memset(ans, -1, sizeof(int) * 100);
				scanf("%s", tar);
				ans = Find_ID(&list, tar);
				system("cls");
				printf("�����������:\n");
				for (int i = 0; i < list.length; i++)
				{
					if (ans[i] != -1)
					{
						printf("%d     ", ans[i] + 1);
						printf("%s    ", list.arr[ans[i]].name);
						printf("%s    ", list.arr[ans[i]].student_ID);
						printf("%s    ", read_gender(list.arr[ans[i]].stu_gender));
						printf("%s\n", read_major(list.arr[ans[i]].stu_major));
					}
				}
				getchar();
				getchar();
				break;
			}
			case 3:
			{
				system("cls");
				printf("�������ѯ���Ա�\n��1Ϊ�У�2ΪŮ��\n");
				int tar;
				int* ans;
				ans = (int*)malloc(sizeof(int) * 100);
				memset(ans, -1, sizeof(int) * 100);
				scanf("%d", &tar);
				ans = Find_gender(&list, tar);
				system("cls");

				printf("�����������:\n");
				for (int i = 0; i < list.length; i++)
				{
					if (ans[i] != -1)
					{
						printf("%d     ", ans[i] + 1);
						printf("%s    ", list.arr[ans[i]].name);
						printf("%s    ", list.arr[ans[i]].student_ID);
						printf("%s    ", read_gender(list.arr[ans[i]].stu_gender));
						printf("%s\n", read_major(list.arr[ans[i]].stu_major));
					}
				}
				getchar();
				getchar();
				break;
			}
			case 4:
			{
				system("cls");
				printf("�������ѯ��רҵ\n��1-5�ֱ�Ϊ:����,���ܣ�ͨ�ţ��ſ����繤��\n");		
				int tar;
				int* ans;
				ans = (int*)malloc(sizeof(int) * 100);
				memset(ans, -1, sizeof(int) * 100);
				scanf("%d", &tar);
				ans = Find_major(&list, tar);
				system("cls");
				printf("�����������:\n");
				for (int i = 0; i < list.length; i++)
				{
					if (ans[i] != -1)
					{
						printf("%d     ", ans[i] + 1);
						printf("%s    ", list.arr[ans[i]].name);
						printf("%s    ", list.arr[ans[i]].student_ID);
						printf("%s    ", read_gender(list.arr[ans[i]].stu_gender));
						printf("%s\n", read_major(list.arr[ans[i]].stu_major));
					}
				}
				getchar();
				getchar();
				break;
			}
			}
			break;
		}
		case 7:
		{
			char* ID = (char*)malloc(sizeof(char) * 20);
			assert(ID);
			char* name = (char*)malloc(sizeof(char) * 20);
			assert(name);
			char* gen = (char*)malloc(sizeof(char) * 10);
			assert(gen);
			char* major = (char*)malloc(sizeof(char) * 10);
			assert(major);

			FILE* fp;
			fp = fopen("ѧ������.txt", "w");

			if (fp == NULL) {
				perror("Error opening file");
				return -1;
			}

			if (&list == NULL) {
				printf("Error: hash table is empty\n");
				fclose(fp);
				return -1;
			}

			for (int i = 0; i < list.length; i++) 
			{
					
					name = list.arr[i].name;
					ID = list.arr[i].student_ID;
					gen = read_gender(list.arr[i].stu_gender);
					major = read_major(list.arr[i].stu_major);
					fprintf(fp, "%d    %s   %s    %s    %s\n", i+1,name,ID,gen,major);
				
			}

			fclose(fp);
			printf("����ɹ�(�ļ�������project1�ļ���)\n");
			getchar();
			getchar();

			break;
		}
		}

	}




	/*¼��Ԫ�صĹ���*/
	
	
	/*strcpy(el.name, "sdfasdf");
	strcpy(el.student_ID, "2022010909001");
	el.stu_gender = Female;
	el.stu_major = jing_guan;*/
	
	//push_insert(&list, el);
	//PrintSqlist(&list);
	return 0;
}




void broaden_room(Sqlist* list ) {
	Elem* newarr = (Elem*)realloc(list->arr, sizeof(Elem) * list->maxnum+broaden_num);
	if (newarr != NULL) {
		list->arr = newarr;
		list->maxnum = list->maxnum + broaden_num;
	}
	else {
		printf("�ڴ����ʧ��\n");
	}
}

//�������һ��Ԫ��
void pop_delete(Sqlistl list)
{
	int i = list->length - 1;
	strcpy(list->arr[i].name, "");
	strcpy(list->arr[i].student_ID, "0");
	list->arr[i].stu_gender = empty_gender;
	list->arr[i].stu_major = empty_major;
	list->length--;
}

//������һ��Ԫ��
void push_insert(Sqlistl list, Elem el)
{
	if (list->length == list->maxnum)
	{
		broaden_room(list);
		list->arr[list->length] = el;
		list->length++;
	}
	else
	{
		list->arr[list->length] = el;
		list->length++;
	}
}

void InsertSqlist_choose(Sqlistl list,int pos,Elem el)								//��posλ��֮ǰ����һ��Ԫ��
{
	if (pos <= 0 || pos > list->length) return;
	else if(list->length== list->maxnum){													//�����ڴ�ռ�
		broaden_room(list);	
		for (int i = list->length - 1; i >= pos - 1; i--)
		{
			list->arr[i + 1] = list->arr[i];
		}
		list->arr[pos - 1] = el;
		list->length++;
	}												
	else
	{
		for (int i = list->length-1; i >=pos-1; i--)
		{
			list->arr[i + 1] = list->arr[i];
		}
		list->arr[pos - 1] = el;
		list->length++;
	}
}

char* read_gender(enum gender a)  //���Ա�
{
	char* er = (char*)malloc(sizeof(char) * 10);
	assert(er);
	strcpy(er, "error");
	char* ma = (char*)malloc(sizeof(char) * 10);
	assert(ma);
	strcpy(ma, "Male");
	char* fe = (char*)malloc(sizeof(char) * 10);
	assert(fe);
	strcpy(fe, "Female");
	
	
	if (a == empty_gender) return er;
	else if (a == Male) return ma;
	else if (a == Female) return fe;
	return er;
}

char* read_major(enum major a)//��רҵ
{
	char* b = (char*)malloc(sizeof(char) * 10);
	assert(b);
	strcpy(b, "error");
	char* c = (char*)malloc(sizeof(char) * 10);
	assert(c);
	strcpy(c, "wang_gong");
	char* d = (char*)malloc(sizeof(char) * 10);
	assert(d);
	strcpy(d, "jing_guan");
	char* e = (char*)malloc(sizeof(char) * 10);
	assert(e);
	strcpy(e, "tong_xin");
	char* f = (char*)malloc(sizeof(char) * 10);
	assert(f);
	strcpy(f, "xin_kang");
	char* g = (char*)malloc(sizeof(char) * 10);
	assert(g);
	strcpy(g, "dian_gong");
	if (a == empty_major) return b;
	else if (a == wang_gong) return c;
	else if (a == jing_guan) return d;
	else if (a == tong_xin) return e;
	else if (a == xin_kang) return f;
	else if (a == dian_gong) return g;
	return b;
}

void Init_sqlist(Sqlistl list)
{
	list->maxnum = maxnums;
	list->arr = (Eleml)malloc(sizeof(Elem) * list->maxnum);
	assert(list->arr);
	
	for (int i = 0; i < list->maxnum; i++)
	{
		strcpy(list->arr[i].name, "");
		strcpy(list->arr[i].student_ID, "0");
		list->arr[i].stu_gender = empty_gender;
		list->arr[i].stu_major = empty_major;

	}
	list->length = 0;
}

void DeSqlist(Sqlistl list, int pos)  //ɾ���ض�λ�õ�Ԫ��
{
	if (pos <= 0 || pos > list->maxnum)
	{
		printf("error");
		return;
	}
	else
	{
		for (int i = pos; i < list->length ; i++)
		{
			list->arr[i - 1] = list->arr[i];
		}
		list->length--;
	}
}

void PrintSqlist(Sqlistl list)
{
	for (int i = 0; i < list->length; i++)
	{
		printf("%d     ", i+1);
		printf("%s    ",  list->arr[i].name);
		printf("%s    ", list->arr[i].student_ID);
		printf("%s    ", read_gender(list->arr[i].stu_gender));
		printf("%s\n", read_major(list->arr[i].stu_major));
	}
}


int* Find_name(Sqlistl list, char* tar)
{
	int j = 0;
	int* ans;
	ans = (int*)malloc(sizeof(int) *100);
	assert(ans);
	for (int i = 0; i < list->length; i++)
	{
		if (areStringsEqual(list->arr[i].name, tar) == 1)
		{
			ans[j] = i;
			j++;
		}
	}
	return ans;
}

int* Find_ID(Sqlistl list, char* tar)
{
	int j = 0;
	int* ans;
	ans = (int*)malloc(sizeof(int) * 100);
	assert(ans);
	for (int i = 0; i < list->length; i++)
	{
		if (areStringsEqual(list->arr[i].student_ID, tar) == 1)
		{
			ans[j] = i;
			j++;
		}
	}
	ans = (int*)realloc(ans, sizeof(int) * j+1);
	return ans;
}

int* Find_gender(Sqlistl list, int tar)
{
	int j = 0;
	int* ans;
	ans = (int*)malloc(sizeof(int) * 100);
	assert(ans);
	for (int i = 0; i < list->length; i++)
	{
		if (list->arr[i].stu_gender == tar)
		{
			ans[j] = i;
			j++;
		}
	}
	ans = (int*)realloc(ans, sizeof(int) * j+1);
	return ans;
}
int* Find_major(Sqlistl list, int tar)
{
	int j = 0;
	int* ans;
	ans = (int*)malloc(sizeof(int) * 100);
	assert(ans);
	for (int i = 0; i < list->length; i++)
	{
		if (list->arr[i].stu_major == tar)
		{
			ans[j] = i;
			j++;
		}
	}
	ans = (int*)realloc(ans, sizeof(int) * j+1);
	return ans;
}

int areStringsEqual(char* a, char* b)
{
	if (strcmp(a, b) != 0||a==NULL||b==NULL) return 0;
	else
	{
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] != b[i]) return 0;
		}
		return 1;
	}
}