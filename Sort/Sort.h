#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdlib.h>
#include <time.h>

class Sort{
public:
	Sort(int a[],int n);
	void quick_sort();
	void insert_sort();
	void select_sort();
	bool is_sorted();
	//rand number is in (min,max]
	static int *generate_rand_array(int min,int max,int n);
	void shell_sort();
	void print_array();

private:
	int* array;
	int length;
};

Sort::Sort(int a[],int n){
	array = a;
	length = n;
}

bool Sort::is_sorted(){
    for(int i=0;i<length-1;i++)
		if(array[i]>array[i+1])
			return false;
    return true;
}

void Sort::select_sort(){
	int min_index,tmp;
	for(int i=0;i<length-1;i++){
		min_index = i;
        for(int j=i+1;j<length;j++)
			if(array[min_index]>array[j])
				min_index = j;

		if(min_index != i){
			tmp = array[min_index];
			array[min_index] = array[i];
			array[i] = tmp;
		}
	}
}

void Sort::insert_sort(){
    for(int i=1;i<length;i++){
		//array[current_position] is the element to be inserting into previous array
		//also the element selected currently
		int current_position = i;
		int insert_position = current_position;
		//we can also use binary-find to specify the insert_position
        for(int j=current_position;j>=0;j--)
			if(array[j]>array[current_position])
				insert_position = j;

		//insert element
        int tmp = array[current_position];
        for(int j=current_position-1;j>=insert_position;j--)
			array[j+1] = array[j];
		array[insert_position] = tmp;
    }
}

int* Sort::generate_rand_array(int min,int max,int n){
	int *a = new int[n];
	if(a==0)
		return nullptr;
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++)
		a[i] = rand()%(max-min)+min+1;
	return a;
}

void Sort::print_array(){
	std::cout<<"The array is:";
	for(int i=0;i<length;i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}

void Sort::shell_sort(){
    //interval_sequence = 3n+1;
    int interval_sequence = 1;
    while(interval_sequence<length/3)
		interval_sequence = interval_sequence*3+1;
    while(interval_sequence>=1){
		//divide array into the parts of the same interval
		for(int i=0;i<interval_sequence;i++){
			//for each part,using insert_sort
			for(int j=i+interval_sequence;j<length;j+=interval_sequence){
				//specify insert position
				int insert_position = j;
				for(int k=j-interval_sequence;k>=0;k-=interval_sequence)
					if(array[j]<=array[k])
						insert_position = k;
				//insert element
				int tmp = array[j];
				for(int k=j;k!=insert_position;k-=interval_sequence)
					array[k] = array[k-interval_sequence];
				array[insert_position] = tmp;
			}
		}
		interval_sequence = interval_sequence/3;
    }

}

#endif // SORT_H_INCLUDED
