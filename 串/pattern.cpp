#include <iostream>
#include <stdio.h>
using namespace std;

class Pattern{
public:
	Pattern(string str,string pattern):p(pattern),s(str){};
	void print(int pos);
	int match();
private:
	string s;
	string p;
};

void Pattern::print(int pos){
	for(int i=0;i<this->s.size();i++)
		printf("%-3d",i);
	printf("\n");
	for(int i=0;i<this->s.size();i++)
		printf("%-3c",this->s[i]);
	printf("\n");
	if(pos<0){
		printf("\n");
		return;
	}

	for(int i=0;i<pos;i++)
		printf("%-3s"," ");
	for(int i=0;i<this->p.size();i++)
		printf("%-3c",this->p[i]);
	printf("\n");
}

int Pattern::match(){
    int s_len = this->s.size();
    int p_len = this->p.size();
    if(s_len<p_len)
		return -1;
    for(int i=0;i<s_len-p_len+1;i++){
		int j;
		for(j=0;j<p_len;j++)
			if(this->s[i+j]!=this->p[j])
				break;
		if(p_len == j)
			return i;
    }
    return -1;
}



int match(){
}

int main(){
    string s="vbahkjdbbsasbaart",p="sask";

	auto obj = new Pattern(s,p);
    obj->print(obj->match());

    return 0;
}
