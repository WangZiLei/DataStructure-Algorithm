#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

typedef struct{
	int elem;
	struct Node *next;
}Node;

Node* InitStack();
bool Push(Node **stack,int elem);
int Pop(Node **stack);
bool Travel(Node *stack);
int GetTopElem(Node *stack);
bool IsEmpty(Node *stack);


int main(){
	int dec,jinzhi=2;
	Node *stack=InitStack();
	printf("������һ��ʮ������:");
	scanf("%d",&dec);
	while(dec){
		printf("dec:%d tmp:%d\n",dec,dec%jinzhi);
		Push(&stack,dec%jinzhi);
		dec=dec/jinzhi;
	}
	printf("ת��Ϊ%d����Ϊ:",jinzhi);
	Travel(stack);
}

Node* InitStack(){
	//������β�ͽ�㣬��Ϊ���Ժ����ջ���ӷ���
	Node *stack=(Node*)malloc(sizeof(Node));
	if(stack==NULL)
		return NULL;
	stack->next=NULL;
	return stack;
}

bool Push(Node **stack,int elem){
	Node *tmp;
	tmp=(Node*)malloc(sizeof(Node));
	if(tmp==NULL)
		return false;
	tmp->next=*stack;
	tmp->elem=elem;
	*stack=tmp;
	return true;
}

int Pop(Node **stack){
	int elem;
	if((*stack)->next==NULL)
		return 0;
	elem=(*stack)->elem;
	*stack=(*stack)->next;
	return elem;
}

bool Travel(Node *stack){
	while(stack->next!=NULL){
		printf("%d ",stack->elem);
		stack=stack->next;
	}
	printf("\n");
	return true;
}

int GetTopElem(Node *stack){
	if(stack->next==NULL)
		return 0;
	return stack->elem;
}

bool IsEmpty(Node *stack){
	if(stack->next==NULL)
		return true;
	return false;
}


