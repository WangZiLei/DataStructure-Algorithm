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

BiTree* CreateBiTree(); //创建一个空的二叉树，value默认为‘\0’，左右孩子为NULL
bool Assign(BiTree *node,char value);
char GetValue(BiTree *node);
BiTree* GetParent(BiTree *root,BiTree *node); //获取父节点
BiTree* GetLeftChild(BiTree *node);
BiTree* GetRightChild(BiTree *node);
bool InsertChild(BiTree *parent,int position,BiTree *obj);
/*吧obj插入到parent的孩子节点上，position表示插入到左还是右孩子节点上*/

void InOrderTravel(BiTree *tree); //中序遍历
void PreOrderTravel(BiTree *tree); //先序遍历
void PostOrderTravel(BiTree *tree); //后续遍历
int GetNodeCount(BiTree *tree); //取节点数目
int GetDeepth(BiTree *tree); //取二叉树深度

/* TODO
void CreateBiTree(BiTree *p){
//输入字符 构建二叉树 太难了，改天实现
	cin>>ch;
}

CopyBiTree(); //复制二叉树

*/

int main(){
	//测试数据来自《数据结构》p115
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
	printf("总节点数为：%d\n",GetNodeCount(pRoot));
	printf("树的深度为:%d\n",GetDeepth(pRoot));
	tmp=GetParent(pRoot,tmp);
	printf("元素e的parent是%c \n",tmp->value);
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









