#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

class Sort{
public:
	Sort(int a[],int n);
	void quick_sort();
	void insert_sort();
	void select_sort();
	bool is_sorted();

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
		int current_position=i;

		for(int k=0;k<length;k++)
			std::cout<<array[k]<<" ";
		std::cout<<std::endl;

		int insert_position = current_position;
		//we can use binary-find to specify the insert_position
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

#endif // SORT_H_INCLUDED
