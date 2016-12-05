#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

typedef struct{
	int elem;
	struct Node *next;
}Node;

Node* InitStack(){
	//这里有尾巴结点，是为了以后遍历栈更加方便
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



#endif // STACK_H
