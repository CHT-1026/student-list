#include"list.h"
#include<stdio.h>
#include <cassert>
#include<malloc.h>
#include<string.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)


void my_sort(ListL A);
void compare(ListL A, ListL B);
char* removeCarriageReturn(const char* str);
int main()
{
	
	//��ȡtxt�ļ�
	List L{};
	InitList(&L);
    List L1{};
    InitList(&L1);
	
	//���ļ�
    char ans[1000];
	read_file("test.txt", ans, &L);	
	my_sort(&L);
	
	int i;
	char* ent = (char*)malloc(sizeof(char) * 1000);
	assert(ent);
	printf("������Ҫ��ӵ�Ԫ��:\n");
	fgets(ent,1000, stdin);
	ent = removeCarriageReturn(ent);
	enter_list(ent, &L1);
	
	//���մ洢������
	List FL1{};
	InitList(&FL1);
	compare(&L1, &L);
	my_sort(&L1);
	ListPrint(&L1);
	return 0;
}



void compare(ListL A, ListL B) {
	int i;
	int n = B->lengh;
	ELL p = B->first;
	for (i = 0; i < n; i++) {
		List_push(A, p->next->name);
		p = p->next;
	}
}

void my_sort(ListL A) {
	if (A->lengh == 0 || A->lengh == 1) {
		printf("error\n");
		return;
	}
	else {
		ELL p = A->first->next;
		int i, j;
		for (i = 1; i < A->lengh ; i++) {

			ELL q = p->next;
			for (j = i+1; j < A->lengh+1; j++) {
				if (p->n > q->n) {
					ListSwap(A, i, j);
					ELL temp = p;
					p = q;
					q = temp;

				}
				else {
					q = q->next;
					if (q == NULL) {
						break;
					}
				}
				
			}
			p = p->next;
			if (p == NULL) break;
		}
	}

}


char* removeCarriageReturn(const char* str) {
	int len = strlen(str);
	char* result = (char*)malloc(len + 1); // �����㹻���ڴ����洢����ַ�����ע��+1 Ϊ����ӽ�β�� null �ַ�
	int j = 0; // ά������ַ����ĵ�ǰ����

	for (int i = 0; i < len; i++) {
		if (str[i] != '\r' && str[i] != '\n') {
			result[j] = str[i]; // ���ǻس������ַ�����������ַ�����
			j++;
		}
	}

	result[j] = '\0'; // ����ַ����� null �ַ���β
	return result;
}