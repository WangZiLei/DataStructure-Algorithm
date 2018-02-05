#include <iostream>
#include <stdlib.h>
using namespace std;

//�ʺ�����
const int QUEEN_NUM = 8;
//ÿ���ʺ��λ��
int *queen;

//�ж��¼���Ļʺ󣨱��Ϊi���Ƿ�����лʺ��ͻ
bool conflict(int index){
    for(int i=0;i<index;i++){
		if(queen[index] == queen[i])
			return true;
		if(index-i == abs(queen[index]-queen[i]))
			return true;
    }
    return false;
}

void solve(){
	queen = new int[QUEEN_NUM];
    for(int i=0;i<QUEEN_NUM;i++)
		queen[i] = 0;

	//i��ʾ��ǰ�Ļʺ�
	int i = 0,counts = 0;
	while(i >= 0){
        if(conflict(i)){
			queen[i]++;
        }else{
        	if(i == QUEEN_NUM-1){
				counts++;
				cout<<"�ⷨ"<<counts<<"��";
				//�����ǰ�ⷨ
				for(int x=0;x<QUEEN_NUM;x++)
					cout<<queen[x]<<" ";
				cout<<endl;

				queen[i]++;
        	}else{
        		i++;
        	}
        }
        //�����ǰ�ʺ�ûλ�÷��ˣ��ͻ���
        while(queen[i] >= QUEEN_NUM){
			queen[i] = 0;
			i--;
			if(i<0)
				break;
			queen[i]++;
        }
        /*
        for(int i=0;i<QUEEN_NUM;i++)
			cout<<queen[i]<<" ";
		cout<<endl;
		*/
	}
	cout<<"һ���нⷨ:"<<counts<<endl;
}

int main(){
	solve();
	return 0;
}
