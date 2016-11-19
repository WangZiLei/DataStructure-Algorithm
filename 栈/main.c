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


int main(){
	Node *stack;
	stack=InitStack();
	Push(&stack,5);
	Push(&stack,2);
	Push(&stack,35);
	Push(&stack,66);
	Pop(&stack);
	Travel(stack);
	printf("%d\n",GetTopElem(stack));
	return 0;
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



