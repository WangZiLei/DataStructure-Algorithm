#include <iostream>
#include "Sort.h"

using namespace std;

int main(){
	int a[] = {6,5,8,9,1,57,27,45,5,16,6,666};

	auto s = Sort(a,12);

	s.insert_sort();
	if(s.is_sorted())
		cout<<"Sorted!"<<endl;
	else
		cout<<"Not Sorted!"<<endl;
	for(int i=0;i<12;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
