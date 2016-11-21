#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;

typedef struct{
	int elem;
	struct Node* next;
}Node;


Node* CreateList();
bool GetValue(Node *L,int index);
bool ReviseValue(Node *L,int index,int value);
void Travel(Node *L);
int Find(Node *L,int value);
bool Insert(Node *L,int index,int value);
bool Delete(Node *L,int index);
Node* ReturnPoint(Node *L,int index); //返回链表中第index个元素的地址
bool Pop(Node *L,int value);
int GetLength(Node *L);

int main(){
	Node *HeadPoint=CreateList();
	Pop(HeadPoint,1);
	Pop(HeadPoint,2);
	Insert(HeadPoint,2,50);
	GetValue(HeadPoint,2);
	ReviseValue(HeadPoint,2,60);
	GetValue(HeadPoint,2);
	Travel(HeadPoint);
	printf("%d",Find(HeadPoint,1));
	printf("length:%d\n",GetLength(HeadPoint));
	return 0;
}

Node* CreateList(){
	//第一个元素是指针头，不能用来存放元素
	Node *HeadPoint;
	HeadPoint=(Node*)malloc(sizeof(Node));
	if(HeadPoint==NULL)
		return NULL;
	else{
		HeadPoint->next=NULL;
		return HeadPoint;
	}
}

bool Pop(Node *L,int value){
	Node *NodeAdd,*tmp=L;
	NodeAdd=(Node*)malloc(sizeof(Node));
	if(NodeAdd==NULL)
		return false;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	NodeAdd->elem=value;
	NodeAdd->next=NULL;
	tmp->next=NodeAdd;
	return true;
}

bool GetValue(Node *L,int index){
	Node *tmp=ReturnPoint(L,index);
	if(tmp==NULL)
		return false;
	else{
		printf("%d ",tmp->elem);
		return true;
	}
}

Node* ReturnPoint(Node *L,int index){
	Node *tmp=L;
	int i=0;
	if(index<1)
		return NULL;
	while(i!=index&&tmp->next!=NULL){
		tmp=tmp->next;
		i++;
	}
	if(i<index)
		return NULL;
	else
		return tmp;
}

bool Insert(Node *L,int index,int value){
	Node *tmp=ReturnPoint(L,index-1),*nodeInsert;
	nodeInsert=(Node*)malloc(sizeof(Node));
	if(tmp==NULL)
		return false;
	if(nodeInsert==NULL)
		return false;
	nodeInsert->elem=value;
	nodeInsert->next=tmp->next;
	tmp->next=nodeInsert;
	return true;
}

bool Delete(Node *L,int index){
	Node *a=ReturnPoint(L,index-1),*b;
	if(a==NULL)
		return false;
	b=a->next;
	b=b->next;
	free(a->next);
	a->next=b;
	return true;
}

bool ReviseValue(Node *L,int index,int value){
	Node *a=ReturnPoint(L,index);
	if(a==NULL)
		return false;
	a->elem=value;
	return true;
}

void Travel(Node *L){
	Node *tmp=L;
	printf("\n遍历链表：");
	while(tmp->next!=NULL){
		tmp=tmp->next;
		printf("%d ",tmp->elem);
	}
	printf("\n");
}

int Find(Node *L,int value){
	Node *tmp=L;
	int i=0;
	while(tmp->next!=NULL&&tmp->elem!=value){
		tmp=tmp->next;
		i++;
	}
	return i;
}

int GetLength(Node *L){
	int i=0;
	while(L->next!=NULL){
		L=L->next;
		i++;
	}
	return i;
}
