#include<stdio.h>
#include<malloc.h>
#include <cassert>
#include<string.h>
#pragma warning(disable:4996)
#define ListInitSize 128							

typedef struct EL
{

	char *name;
	int n = strlen(name);											//��¼���ֳ���
	EL *next;
}EL, * ELL;



typedef struct List
{
	int lengh;
	ELL first;
}List, * ListL;

void InitList(ListL PList);
void DestroyList(ListL PList);
void DestroyList(ListL PList);
void ClearList(ListL PList);
bool ListEmpty(List PList);
int ListLengh(List PList);
void GetElem(List PList, int i, char* e);
int compare(char* elem, char* target);
int locatedelem(ListL list, char* elem, int (*compare)(char* elem, char* target));
void ListInsert(List* PList, int i, char* e);
void ListPrint(ListL PList);
void List_push(ListL PList, char* str);
void ListSwap(List* PList, int i, int j);

//ͨ���ṹ��ָ��Ϳ��Է��ʽṹ��ĳ�Ա��������->��.   �ṹ�������ڿ���ʹ�õ�ַָ���Ա
void InitList(ListL PList)														//��ʼ����Ҫ��ɣ�1��Ϊ�׸��ڵ㿪�ٿռ�2����ֵ�͵�ַ����ʼ��
{
	PList->first = (ELL)malloc(sizeof(EL));										//�׸��ڵ�Ŀռ�
	assert(PList->first);														//���ϳ�������
	PList->lengh = 0;
	PList->first->name = NULL;
	PList->first->next = NULL;
	PList->first->n = 0;
}

void DestroyList(ListL PList)													//������Ҫ�ͷ�����Ŀռ䣬��ͷ�ڵ㿪ʼȫ���ͷ�ͬʱ��С�����lengh
{
	while (PList->first->next != NULL)
	{
		ELL temp = PList->first->next;
		PList->first->next = temp->next;
		free(temp);																//free�ͷŵ��ǵ�ַָ��Ŀռ䣬���Ǳ�������
		temp = NULL;
		PList->lengh--;

	}
}

void ClearList(ListL PList)														//�������գ���Ҫѯ��
{
	ELL temp = PList->first;

	while (temp != NULL)
	{
		ELL current = temp;
		temp = temp->next;
		current->next = NULL;
	}
	PList->lengh = 0;

}

bool ListEmpty(List PList)
{
	if (PList.first == NULL) return true;
	else return false;
}

int ListLengh(List PList)
{
	return PList.lengh;
}

void GetElem(List PList, int i, char* e)											//��e��ֵΪ�����i��Ԫ�ص�ֵ	
{
	if (i > PList.lengh)
	{
		printf("error");
		return;
	}
	ELL current = PList.first;
	for (int j = 1; j < i; j++)
	{
		current = current->next;
	}
	e = current->next->name;
}

int compare(char *elem, char* target) {
	return elem == target;
}

int locatedelem(ListL list, char* elem, int (*compare)(char* elem, char* target)) {
	ELL currentNode = list->first;
	int position = 1;

	while (currentNode) {
		if (compare(currentNode->next->name, elem)) {
			return position;
		}
		currentNode = currentNode->next;
		position++;
	}

	return -1;
}

void ListInsert(List* PList, int i, char* e) {
	if (i > PList->lengh + 1) return;
	if (i == 1) {
		ELL newnode = (ELL)malloc(sizeof(EL));
		assert(newnode);
		newnode->name = e;
		newnode->n = strlen(e);
		newnode->next = PList->first->next;

		PList->first->next = newnode;
		PList->lengh++;
	}
	else {
		ELL newnode = (ELL)malloc(sizeof(EL));
		assert(newnode);
		ELL p = (ELL)malloc(sizeof(EL));
		assert(p);
		p = PList->first;
		int j = 1;
		while (j < i)
		{
			p = p->next;
			j++;
		}
		newnode->name = e;
		newnode->n = strlen(newnode->name);
		newnode->next = p->next;
		
		p->next = newnode;
		PList->lengh++;
	}
}

void ListPrint(ListL PList) {
	if (PList->lengh == 0) printf("errpr");
	ELL temp = PList->first;
	while (temp->next !=NULL) {
		printf("%s\n", temp->next->name);
		temp = temp->next;
	}
}

void read_file(const char* file_path, char* ans, ListL L) {
	FILE* file = fopen(file_path, "r");

	if (file != NULL) {
		
		fgets(ans, 1000, file);
		fclose(file);
	}
	int n = strlen(ans);
	int rows = 0;
	int cols = 0;

	// ͳ������������
	const char* ptr = ans;
	while (*ptr != '\0') {
		if (*ptr == ' ') {
			rows++;
		}
		ptr++;
	}
	rows++;
	cols = 100;  // �ų��ո񣬼���ÿ�е��ַ�����

	// ������ά���󲢴洢����
	char** matrix = (char**)malloc(rows * sizeof(char*));
	assert(matrix);
	for (int i = 0; i < rows; i++) {
		matrix[i] = (char*)malloc((cols + 1) * sizeof(char));   //����ĩβ�ġ�\0��
	}

	char* str_copy = strdup(ans);
	char* token = strtok(str_copy, " ");            //ֻ�Ը��Ƶı������в�������Ϊstrtok������ı�ԭ�������ʽ
	int i = 0;
	while (token != NULL) {
		strcpy(matrix[i], token);
		i++;
		token = strtok(NULL, " ");                  //��ʾ������ԭ�ַ������в���
	}

	// �洢��ά��������
	for (int i = 0; i < rows; i++) {
		List_push(L, matrix[i]);
	}


}


void enter_list(char* ans, ListL L) {
	int rows = 0;
	int cols = 0;

	// ͳ������������
	const char* ptr = ans;
	while (*ptr != '\0') {
		if (*ptr == ' ') {
			rows++;
		}
		ptr++;
	}
	rows++;
	cols = 100;  // �ų��ո񣬼���ÿ�е��ַ�����

	// ������ά���󲢴洢����
	char** matrix = (char**)malloc(rows * sizeof(char*));
	assert(matrix);
	for (int i = 0; i < rows; i++) {
		matrix[i] = (char*)malloc((cols + 1) * sizeof(char));   //����ĩβ�ġ�\0��
	}

	char* str_copy = strdup(ans);
	char* token = strtok(str_copy, " ");            //ֻ�Ը��Ƶı������в�������Ϊstrtok������ı�ԭ�������ʽ
	int i = 0;
	while (token != NULL) {
		strcpy(matrix[i], token);
		i++;
		token = strtok(NULL, " ");                  //��ʾ������ԭ�ַ������в���
	}

	// �洢��ά��������
	for (int i = 0; i < rows; i++) {
		List_push(L, matrix[i]);
	}


}

void List_push(ListL PList, char *str)
{
		
		ELL newnode = (ELL)malloc(sizeof(EL));
		assert(newnode);
		ELL p = (ELL)malloc(sizeof(EL));
		p = PList->first;
		int j = 0;
		while (j < PList->lengh)
		{
			p = p->next;
			j++;
		}
		PList->lengh++;
		newnode->next =NULL;
		newnode->name = str;
		newnode->n = strlen(str);
		p->next = newnode;
		
	
}

void ListDelete(List* PList, int i) {
	if (i <= 0 || i > PList->lengh) {
		return;
	}

	ELL p = PList->first;
	int j = 0;
	while (j < i - 1) {
		p = p->next;
		j++;
	}

	ELL deleteNode = p->next;
	p->next = deleteNode->next;
	PList->lengh--;

	free(deleteNode);
}

void ListSwap(List* PList, int i, int j) {
	if (i <= 0 || i > PList->lengh || j <= 0 || j > PList->lengh || i == j) {
		return;
	}

	ELL prevNode1 = NULL; // ��һ���ڵ��ǰ���ڵ�
	ELL currNode1 = PList->first; // ͷ�ڵ�
	int k = 0;
	while (k < i ) {
		prevNode1 = currNode1;
		currNode1 = currNode1->next;
		k++;
	}

	ELL prevNode2 = NULL; // �ڶ����ڵ��ǰ���ڵ�
	ELL currNode2 = PList->first; // �ڶ����ڵ�
	int l = 0;
	while (l < j) {
		prevNode2 = currNode2;
		currNode2 = currNode2->next;
		l++;
	}

	// �����ڵ�
	if (k != 1) {
		prevNode1->next = currNode2;
	}
	else if(k == 1){
		PList->first->next = currNode2;
	}

	if ( l != 1) {
		prevNode2->next = currNode1;
	}
	else if(l==1){
		PList->first->next = currNode1;
	}

	ELL temp;
	temp = currNode2->next;
	currNode2->next = currNode1->next;
	currNode1->next = temp;
}