#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define true 1
#define false 0
typedef int bool;

typedef struct{
	char *elem;
	int length;
}Str;

//所有的pos都是以0开始
bool StrAssign(Str *str,char *ch); //用ch的元素代替str中的元素
bool StrCopy(Str *a,Str *b); //吧b拷贝到a中来
bool IsEmpty(Str *str);
int GetLength(Str *str);
char* StrConcat(Str *a,Str *b); //返回由a和b链接而成的新的字符串
char* StrSub(Str *str,int position,int length); //从pos位置，取出length个字符
bool Replace(Str *str,int pos,char ch); //替换掉位置为pos上的字符
bool Delete(Str *str,int pos);
bool Insert(Str *str,int pos,char ch);
char GetELem(Str *str,int pos);
void StrPrint(Str *str);


int main(){
	Str str,a;
	char *tmp;
	char ch[]="123456789";
	StrAssign(&str,ch);
	StrAssign(&a,ch);

	tmp=StrConcat(&str,&a);

	printf("%d\n",GetLength(&str));
	StrPrint(&str);
	return 0;
}

bool StrAssign(Str *str,char *ch){
	int len=strlen(ch),i;
	str->elem=(char*)malloc(sizeof(char)*len);
	if(str->elem==NULL)
		return false;
	str->length=len;

	for(i=0;i<len;i++){
		str->elem[i]=ch[i];
	}
	return true;
}

void StrPrint(Str *str){
	int i;
	for(i=0;i<str->length;i++){
		printf("%c ",str->elem[i]);
	}
	printf("\n");
}

bool Delete(Str *str,int pos){
	//删除元素的时候，为了效率，直接把length减小1，然后把相应的元素向前移动一个单位
	int i;
	if(pos>str->length-1||pos<0)
		return false;
	for(i=pos-1;i<str->length;i++)
		str->elem[i]=str->elem[i+1];
	str->length--;
	return true;
}

bool Insert(Str *str,int pos,char ch){
	char *tmp=(char*)malloc(sizeof(char)*(str->length+1));
	int i;

	if(pos>str->length-1||pos<0)
		return false;
	if(tmp==NULL)
		return false;

	for(i=0;i<pos-1;i++)
		tmp[i]=str->elem[i];
	tmp[pos-1]=ch;
	for(i=pos-1;i<str->length;i++)
		tmp[i+1]=str->elem[i];

	free(str->elem);
	str->elem=tmp;
	str->length++;
	return true;

}

char GetELem(Str *str,int pos){
	if(pos>str->length-1||pos<0)
		return '\0';
	return str->elem[pos];
}

bool StrCopy(Str *a,Str *b){
	char *tmp;
	int i;
	tmp=(char*)malloc(sizeof(char)*b->length);
	if(tmp==NULL)
		return false;
	a->length=b->length;
	free(a->elem);
	a->elem=tmp;
    for(i=0;i<a->length;i++)
		a->elem[i]=b->elem[i];
	return true;
}

bool IsEmpty(Str *str){
	if(str->length==0)
		return true;
	return false;
}

int GetLength(Str *str){
	return str->length;
}

char* StrConcat(Str *a,Str *b){
	char *tmp,i;
	tmp=(char*)malloc(sizeof(char)*(a->length+b->length));
	if(tmp==NULL)
		return NULL;
	for(i=0;i<a->length;i++)
		tmp[i]=a->elem[i];
	for(i=0;i<b->length;i++)
		tmp[i+a->length]=b->elem[i];
	return tmp;
}

char* StrSub(Str *str,int position,int length){
	char *tmp;
	int i=0;
	if(position+length-1>str->length||position<0)
		return NULL;
    tmp=(char*)malloc(sizeof(char)*length);
    if(tmp==NULL)
		return NULL;
	for(i=0;i<length;i++)
		tmp[i]=str->elem[position+i];
	return tmp;
}

bool Replace(Str *str,int pos,char ch){
	if(pos>str->length-1||pos<0)
		return false;
	str->elem[pos]=ch;
	return true;
}



