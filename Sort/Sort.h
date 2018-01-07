#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <time.h>

class Sort{
public:
	Sort(int a[],int n);
	void quick_sort();
	void insert_sort();
	void select_sort();
	void _merge_sort_up2bottom(int a[],int low,int high);
	void _merge_array(int low,int high,int mid);
	void merge_sort();
	bool is_sorted();
	//rand number is in (min,max]
	static int *generate_rand_array(int min,int max,int n);
	void shell_sort();
	void my_quick_sort();
	void _quick_array(int low,int high);
	int _quick_sort_partition1(int low,int high);
	int _quick_sort_partition2(int low,int high);
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

void Sort::merge_sort(){
	this->_merge_sort_up2bottom(array,0,length-1);
}

void Sort::_merge_sort_up2bottom(int a[],int low,int high){
	//from up to bottom
	if(a==nullptr || low>=high)
		return;
	if(high==low+1)
		//swap
		if(a[low]>a[high]){
			int tmp = a[low];
			a[low] = a[high];
			a[high] = tmp;
			return;
		}

	//array1 [low,mid)
	//array2 [mid,high]
	int mid = (low+high)/2;
    _merge_sort_up2bottom(a,low,mid);
    _merge_sort_up2bottom(a,mid+1,high);
    //printf("low:%d,mid:%d,mid+1:%d,high:%d\n",low,mid,mid+1,high);
	_merge_array(low,high,mid);

}

void Sort::_merge_array(int low,int high,int mid){
	//merge
	//array1 [low,mid)
	//array2 [mid,high]
	/*
    int *b = new int[high-low+1];
	if(b==nullptr)
		return;
		*/
	std::vector<int> b(high-low+1);
	int m=low,n=mid;
	for(int i=0;i<=high;i++){
		if(m<mid && n<=high){
			if(array[m]>array[n])
				b[i] = array[n++];
			else
				b[i] = array[m++];
		}else{
			if(m>=mid)
				b[i] = array[n++];
			else if(n>high)
				b[i] = array[m++];
		}
	}
	for(int i=0;i<high-low+1;i++)
		this->array[low+i] = b[i];
	printf("low%d,high%d,mid%d\n",low,high,mid);
	this->print_array();
	//delete []b;
}

void Sort::my_quick_sort(){
	int j = this->_quick_sort_partition2(0,this->length-1);
	printf("The divided element index is %d\n",j);
}

void Sort::_quick_array(int low,int high){
}

int Sort::_quick_sort_partition1(int low,int high){
	//This partition way in <<Algorithms>> 4th Edition
	//page 187

	if(high<=low)
		return high-low;
	int v = this->array[low];
	int i=low,j=high+1;

	//swap the elements not in place constantly until all elements have been compared
	while(true){
		while(i<high && this->array[++i]<=v);
		while(j>low && this->array[--j]>=v);
		if(j<=i)
			break;
		//swap
		int tmp = this->array[i];
		this->array[i] = this->array[j];
		this->array[j] = tmp;
	}
	//swap
	int tmp = this->array[low];
	this->array[low] = this->array[j];
	this->array[j] = tmp;
	return j;
}

int Sort::_quick_sort_partition2(int low,int high){
	//This partition way in <<Data Structure In C Program>> 2th Edition
	//ISBN 978711537950
	//page 245
    int pivotkey = this->array[low];
    while(high>low){
		while(this->array[high]>=pivotkey && high>low)
			high--;
		this->array[low] = this->array[high];
		while(this->array[low]<=pivotkey && high>low)
			low++;
		this->array[high] = this->array[low];
    }
    this->array[low] = pivotkey;
    return low;
}



#endif // SORT_H_INCLUDED
