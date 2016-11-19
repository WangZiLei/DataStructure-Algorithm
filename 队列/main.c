#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

typedef struct{
	int elem;
	struct Node *next;
}Node;

typedef struct{
	Node *front;
	Node *tail;
}Queue;

bool InitQueue(Queue *queue);
void DestroyQueue(Queue *queue);
int GetQueueLength(Queue *queue);
bool IsQueueEmpty(Queue *queue);
bool PushQueue(Queue *queue,int elem);
void PopQueue(Queue *queue,int *elem);
bool GetFrontElem(Queue *queue,int *elem);
bool GetTailElem(Queue *queue,int *elem);
void TravelQueue(Queue *queue);

//����������

int main(){
	int elem=0;
	Queue queue;
	InitQueue(&queue);
	PushQueue(&queue,2);
	PopQueue(&queue,&elem);
	printf("��Ԫ��Ϊ%d ",elem);
	/*PushQueue(&queue,6);
	PushQueue(&queue,5);
	PushQueue(&queue,87);
	PushQueue(&queue,45);
	PushQueue(&queue,19);

	GetFrontElem(&queue,&elem);
	printf("��Ԫ��Ϊ%d ",elem);
	GetTailElem(&queue,&elem);
	printf("βԪ��Ϊ%d\n",elem);*/

	printf("���г���Ϊ%d\n",GetQueueLength(&queue));

	//TravelQueue(&queue);
	//DestroyQueue(&queue);
	printf("���г���Ϊ%d ",GetQueueLength(&queue));


	return 0;
}

bool InitQueue(Queue *queue){
	//��ͷ ���Ԫ�ز�����Ԫ�أ�ֻ����Ϊͷ�ڵ�
	Node *tmp=(Node*)malloc(sizeof(Node));
	if(tmp==NULL)
		return false;
	queue->front=tmp;
	queue->tail=tmp;
	tmp->next=NULL;
	return true;
}

bool PushQueue(Queue *queue,int elem){
	Node *tmp=(Node*)malloc(sizeof(Node));
	if(tmp==NULL)
		return false;
    tmp->elem=elem;
    tmp->next=NULL;
    queue->tail->next=tmp;
    queue->tail=tmp;
    return true;
}

void TravelQueue(Queue *queue){
	Node *tmp=queue->front;
	while(tmp->next!=NULL){
		tmp=tmp->next;
		printf("%d ",tmp->elem);
	}
	printf("\n");
}

void PopQueue(Queue *queue,int *elem){
	Node *tmp,*frontP=queue->front->next;
	if(queue->front==queue->tail)
		return;
	tmp=queue->front->next;
	*elem=tmp->elem;
	if(frontP->next==queue->tail){
		//������һ��Ԫ��Ҳ��pop��
		frontP=NULL;
	}else{
		queue->front->next=tmp->next;
	}
	//printf("����free %d",*elem);
	free(tmp);
}

bool GetFrontElem(Queue *queue,int *elem){
	Node *tmp=queue->front->next;
	if(queue->front==queue->tail)
		return false;
	*elem=tmp->elem;
	return true;
}

bool GetTailElem(Queue *queue,int *elem){
	if(queue->front==queue->tail)
		return false;
	*elem=queue->tail->elem;
	return true;
}

int GetQueueLength(Queue *queue){
	int i=0;
	Node *tmp=queue->front;
	while(tmp!=queue->tail){
		tmp=tmp->next;
		i++;
	}
	return i;
}

void DestroyQueue(Queue *queue){
	int i;
	while(queue->front!=queue->tail){
		PopQueue(queue,&i);
		printf("%d ",i);
	}
}

bool IsQueueEmpty(Queue *queue){
	if(GetQueueLength(queue)==0)
		return true;
	return false;
}


