#include <iostream>
#include <stdlib.h>
using namespace std;

//皇后总数
const int QUEEN_NUM = 8;
//每个皇后的位置
int *queen;

//判断新加入的皇后（编号为i）是否和已有皇后冲突
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

	//i表示当前的皇后
	int i = 0,counts = 0;
	while(i >= 0){
        if(conflict(i)){
			queen[i]++;
        }else{
        	if(i == QUEEN_NUM-1){
				counts++;
				cout<<"解法"<<counts<<"：";
				//输出当前解法
				for(int x=0;x<QUEEN_NUM;x++)
					cout<<queen[x]<<" ";
				cout<<endl;

				queen[i]++;
        	}else{
        		i++;
        	}
        }
        //如果当前皇后没位置放了，就回溯
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
	cout<<"一共有解法:"<<counts<<endl;
}

int main(){
	solve();
	return 0;
}
