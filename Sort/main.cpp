#include <iostream>
#include "Sort.h"

using namespace std;

int main(){
	const int array_length = 50000;
	int *a = Sort::generate_rand_array(0,156,array_length);
	auto s = Sort(a,array_length);

	auto time_begin = clock();
	//s.insert_sort();
	s.select_sort();
	auto time_end = clock();
	cout<<"Running time: "<<(double)(time_end-time_begin)<<"ms"<<endl;

	if(s.is_sorted())
		cout<<"Sorted!"<<endl;
	else
		cout<<"Not Sorted!"<<endl;
	/*
	for(int i=0;i<array_length;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	*/
	return 0;
}
