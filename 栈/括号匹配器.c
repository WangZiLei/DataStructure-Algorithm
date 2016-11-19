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

	char str[100000];
	int i;
	gets(str);
	printf("%s",str);

	Node *stack;
	stack=InitStack();

	for(i=0;str[i]!='\0';i++){
			//printf("%c",str[i]);
        if(str[i]=='{'||str[i]=='('||str[i]=='[')
			Push(&stack,str[i]);

		if(str[i]=='}'&&GetTopElem(stack)=='{')
			Pop(&stack);
		if(str[i]==']'&&GetTopElem(stack)=='[')
			Pop(&stack);
		if(str[i]==')'&&GetTopElem(stack)=='(')
			Pop(&stack);
	}

	if(IsEmpty(stack))
		printf("符号配对成功");
	else
		printf("符号配对失败");

	return 0;
}

Node* InitStack(){
	//这里有栈底头结点，是为了以后遍历栈更加方便
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

bool IsEmpty(Node *stack){
	if(stack->next==NULL)
		return true;
	return false;
}

int GetTopElem(Node *stack){
	if(stack->next==NULL)
		return 0;
	return stack->elem;
}



