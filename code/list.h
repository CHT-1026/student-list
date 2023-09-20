#pragma once
#ifndef __list_h
#define __list_h

typedef struct EL
{

	char* name;
	int n = 0;											//记录名字长度
	struct EL* next;
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
void List_push(List* PList, char* str);
void read_file(const char* file_path, char* ans, ListL L);
void enter_list(char* ans, ListL L);
void ListDelete(List* PList, int i);
void ListSwap(List* PList, int i, int j);
#endif