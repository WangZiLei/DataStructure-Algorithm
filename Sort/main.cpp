#include <iostream>
#include "Sort.h"

using namespace std;



int main(){
	const int ARRAY_LENGTH = 70000;
	int *a = Sort::generate_rand_array(0,156,ARRAY_LENGTH);
	auto s = Sort(a,ARRAY_LENGTH);
	//s.print_array();
	//s._merge_array(0,ARRAY_LENGTH-1,ARRAY_LENGTH/2);
	//s.print_array();

	auto time_begin = clock();
	//s.insert_sort();
	//s.select_sort();
	//s.shell_sort();
	//s.merge_sort();
	s.my_quick_sort();
	//s.print_array();
	auto time_end = clock();
	cout<<"Running time: "<<(double)(time_end-time_begin)<<"ms"<<endl;

	if(s.is_sorted())
		cout<<"Sorted!"<<endl;
	else
		cout<<"Not Sorted!"<<endl;
	/*
	for(int i=0;i<ARRAY_LENGTH;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	*/
	return 0;
}
