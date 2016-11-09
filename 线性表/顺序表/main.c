#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;
typedef struct{
	int length;
	char *element;
}SqList;

void InitList(SqList *list);
void ClearList(SqList *list);
bool IsEmptyList(SqList *list);
char GetElement(SqList *list,int index);
bool InsertElement(SqList *list,int index,char element);
void TraverseList(SqList *list);
void DeleteElement(SqList *list,int index);
int LocateElement(SqList *list,char c);

int main(){
	SqList list;
	InitList(&list);
	if(IsEmptyList(&list))
		printf("List is empty!\n");
	InsertElement(&list,1,'a');
	InsertElement(&list,2,'b');
	InsertElement(&list,3,'c');
	InsertElement(&list,4,'d');
	InsertElement(&list,5,'e');

	printf("%c\n",GetElement(&list,2));

	DeleteElement(&list,1);

	TraverseList(&list);

	printf("\nelement d location is %d",LocateElement(&list,'d'));

	return 0;
}

void InitList(SqList *list){
	list->length=0;
	list->element=NULL;
}

void ClearList(SqList *list){
	list->length=0;
	free(list->element);
}

bool IsEmptyList(SqList *list){
	if(list->length==0)
		return true;
	return false;
}

char GetElement(SqList *list,int index){
	if(index>list->length-1)
		return 0;
	return list->element[index];
}

bool InsertElement(SqList *list,int index,char element){
	char *pTemp;
	int i;
	pTemp=malloc(sizeof(char)*(list->length+1));
	if(pTemp==NULL)
		return false;

	for(i=0;i<index-1;i++)
		pTemp[i]=list->element[i];
	pTemp[index-1]=element;
	for(i=index;i<list->length;i++)
		pTemp[i+1]=list->element[i];

	free(list->element);
	list->element=pTemp;
	list->length++;
	return true;
}

void TraverseList(SqList *list){
	int i;
	for(i=0;i<list->length;i++)
		printf("%c ",list->element[i]);
}

void DeleteElement(SqList *list,int index){
	int i;
	for(i=index-1;i<list->length;i++)
		list->element[i]=list->element[i+1];
	list->length--;
}

int LocateElement(SqList *list,char c){
	int i;
	for(i=0;i<list->length;i++)
		if(list->element[i]==c)
			return i+1;
	return 0;
}



