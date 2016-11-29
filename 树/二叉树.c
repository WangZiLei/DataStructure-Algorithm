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
BiTree* GetParent(BiTree *root,BiTree *node); //��ȡ���ڵ�
BiTree* GetLeftChild(BiTree *node);
BiTree* GetRightChild(BiTree *node);
bool InsertChild(BiTree *parent,int position,BiTree *obj);
/*��obj���뵽parent�ĺ��ӽڵ��ϣ�position��ʾ���뵽�����Һ��ӽڵ���*/

void InOrderTravel(BiTree *tree); //�������
void PreOrderTravel(BiTree *tree); //�������
void PostOrderTravel(BiTree *tree); //��������
int GetNodeCount(BiTree *tree); //ȡ�ڵ���Ŀ
int GetDeepth(BiTree *tree); //ȡ���������

/* TODO
void CreateBiTree(BiTree *p){
//�����ַ� ���������� ̫���ˣ�����ʵ��
	cin>>ch;
}

CopyBiTree(); //���ƶ�����

*/

int main(){
	//�����������ԡ����ݽṹ��p115
	BiTree *pRoot,*pa,*pb,*p1,*tmp;
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
	tmp=CreateBiTree();
	Assign(tmp,'e');
	pb=CreateBiTree();
	Assign(pb,'f');
	InsertChild(p1,LEFTCHILD,tmp);
	InsertChild(p1,RIGHTCHILD,pb);

	PostOrderTravel(pRoot);
	printf("�ܽڵ���Ϊ��%d\n",GetNodeCount(pRoot));
	printf("�������Ϊ:%d\n",GetDeepth(pRoot));
	tmp=GetParent(pRoot,tmp);
	printf("Ԫ��e��parent��%c \n",tmp->value);
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
void PreOrderTravel(BiTree *tree){
	if(tree==NULL)
		return;
	printf("%c ",tree->value);
	PreOrderTravel(tree->leftChild);
	PreOrderTravel(tree->rightChild);
}

void PostOrderTravel(BiTree *tree){
	if(tree==NULL)
		return;
	PostOrderTravel(tree->leftChild);
	PostOrderTravel(tree->rightChild);
	printf("%c ",tree->value);
}

int GetNodeCount(BiTree *tree){
	int i=0;
	if(tree==NULL)
		return 0;
	return GetNodeCount(tree->rightChild)+GetNodeCount(tree->leftChild)+1;
}

int GetDeepth(BiTree *tree){
	int left=0,right=0;
	if(tree==NULL)
		return 0;
	left=GetDeepth(tree->leftChild);
	right=GetDeepth(tree->rightChild);
	if(left>right)
		return left+1;
	else
		return right+1;
}

BiTree* GetParent(BiTree *root,BiTree *node){
	if(node==NULL||root==NULL)
		return NULL;
	if(root->leftChild==node||root->rightChild==node)
		return root;
	GetParent(root->leftChild,node);
	GetParent(root->rightChild,node);
}









