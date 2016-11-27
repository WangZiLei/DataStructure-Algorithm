#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
#define LEFTCHILD 0
#define RIGHTCHILD 1
typedef int bool;

typedef struct{
	char value;
	struct BiTree *leftChild,*rightChild;
}BiTree;

BiTree* CreateBiTree(); //����һ���յĶ�������valueĬ��Ϊ��\0�������Һ���ΪNULL
bool Assign(BiTree *node,char value);
char GetValue(BiTree *node);

BiTree* GetParent(BiTree *node);

BiTree* GetLeftChild(BiTree *node);
BiTree* GetRightChild(BiTree *node);
bool InsertChild(BiTree *parent,int position,BiTree *obj);
/*��obj���뵽parent�ĺ��ӽڵ��ϣ�position��ʾ���뵽�����Һ��ӽڵ���*/

void InOrderTravel(BiTree *tree); //�������
//���ǰ������ͺ������

/* TODO
void CreateBiTree(BiTree *p){
	cin>>ch;
}
//�����ַ� ���������� ̫���ˣ�����ʵ��
CopyBiTree(); //���ƶ�����
GetDeepth(); //ȡ���������
GetNodeCount(); //ȡ�ڵ���Ŀ

*/

int main(){
	//�����������ԡ����ݽṹ��p115
	BiTree *pRoot,*pa,*pb,*p1;
	pRoot=CreateBiTree();
	Assign(pRoot,'-');

	pa=CreateBiTree();
	Assign(pa,'+');
	pb=CreateBiTree();
	Assign(pb,'/');
	InsertChild(pRoot,LEFTCHILD,pa);
	InsertChild(pRoot,RIGHTCHILD,pb);


	p1=pa;
	pa=CreateBiTree();
	Assign(pa,'a');
	pb=CreateBiTree();
	Assign(pb,'*');
	InsertChild(p1,LEFTCHILD,pa);
	InsertChild(p1,RIGHTCHILD,pb);

	p1=pb;
	pa=CreateBiTree();
	Assign(pa,'b');
	pb=CreateBiTree();
	Assign(pb,'-');
	InsertChild(p1,LEFTCHILD,pa);
	InsertChild(p1,RIGHTCHILD,pb);

	p1=pb;
	pa=CreateBiTree();
	Assign(pa,'c');
	pb=CreateBiTree();
	Assign(pb,'d');
	InsertChild(p1,LEFTCHILD,pa);
	InsertChild(p1,RIGHTCHILD,pb);

	p1=pRoot->rightChild;
	pa=CreateBiTree();
	Assign(pa,'e');
	pb=CreateBiTree();
	Assign(pb,'f');
	InsertChild(p1,LEFTCHILD,pa);
	InsertChild(p1,RIGHTCHILD,pb);

	InOrderTravel(pRoot);
	return 0;
}

BiTree* CreateBiTree(){
	BiTree *p;
	p=(BiTree*)malloc(sizeof(BiTree));
	if(p==NULL)
		return p;
	p->leftChild=NULL;
	p->rightChild=NULL;
	p->value='\0';
	return p;
}

bool Assign(BiTree *node,char value){
	if(node==NULL)
		return false;
	node->value=value;
	return true;
}

char GetValue(BiTree *node){
	if(node==NULL)
		return '\0';
	return node->value;
}

BiTree* GetLeftChild(BiTree *node){
	if(node==NULL)
		return node;
	return node->leftChild;
}

BiTree* GetRightChild(BiTree *node){
	if(node==NULL)
		return node;
	return node->rightChild;
}

bool InsertChild(BiTree *parent,int position,BiTree *obj){
	if(parent==NULL)
		return false;
	if(position!=RIGHTCHILD&&position!=LEFTCHILD)
		return false;
	if(position==LEFTCHILD)
		parent->leftChild=obj;
	else
		parent->rightChild=obj;
    return true;
}

void InOrderTravel(BiTree *tree){
	if(tree==NULL)
		return;
	InOrderTravel(tree->leftChild);
	printf("%c ",tree->value);
	InOrderTravel(tree->rightChild);
}









