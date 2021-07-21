#include<iostream> 
#include<climits>
using namespace std; 

class Array{

	private:
		int max_size;
		int last_index; 
		int *arr; 

	public:

		Array(int given_size){

			max_size = given_size;
			last_index = -1; 
			arr = new int[given_size];
		}

		int get_max_size(){

			return max_size;
		}

		bool insert(int,int); 

		bool remove(int);

		bool empty(){

			return last_index == -1 ? true : false; 
		}

		bool full(){

			return last_index +1  == max_size ? true : false; 
		}

		int get_size(){

			return last_index +1;
		}

		void print();

		void bubble_sort();

		void insertion_sort();

		void selection_sort();


		


};

bool Array::insert(int index,int element){

	// if full then return false 
	if(full())
		return false; 
	// if not full then check for the last index 
	if(0<= index  &&  index <= last_index+1 ){
		// shift all the elements to right starting from the given index

		for(int i=last_index;i>=index;i--){

			arr[i+1] = arr[i]; 
		}

		arr[index] = element; 
		last_index += 1;
		return true; 
	} 
	return false;
}

bool Array::remove(int index){


	if(empty())return false; 

	if(0<= index  &&  index <= last_index){

		for(int i=index+1;i<=last_index;i++)

			arr[i-1] = arr[i];
		last_index -=1;
		return true; 
	}

	return false; 

}

void Array::print(){
	cout<<"[";
	for(int i=0;i<=last_index;i++)
		cout<<arr[i]<<" ";
	cout<<"]";
}

void Array::bubble_sort(){
	int length = get_size();
	for(int i=0; i<length; i++){
        int count = 0;
        for(int j=0; j<length-1-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count += 1;
            }
        }
        if (count == 0){
            break;
        }
    }
}

// 3 2 1 5 6 8
// ^ ^
// j i

//---

// 2 3 1 5 6 8
//   ^ ^
//   j i

//---

// 2 2 3 5 6 8
//   ^ ^
//   j i

//---

// 1 2 3 5 6 8
//   ^ ^
//   j i

//....................

void Array::insertion_sort(){
	int length = get_size();
	for(int i=1; i<length; i++){    
		int temp = arr[i];    // 2  --> // 1
		int j = i - 1;
		while (temp < arr[j] && j>=0){
			arr[j+1] = arr[j];
			j -= 1;
		
		}
		arr[j+1] = temp;
	}
}

void Array::selection_sort(){
	int length = get_size();
	for(int i=0; i<length; i++){  
		int mini = i;
		// cout << INT_MIN;
		for(int j=i; j<length; j++){
			if (arr[j] < arr[mini]){
				mini = j;
			}
		}
		int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
	}

}
int main(){


	Array arr = Array(10);

	arr.insert(0,19879);
	arr.insert(1,10);
	arr.insert(2,300);
	arr.insert(3,18);
	arr.insert(4,1);
	// arr.bubble_sort();
	arr.selection_sort();


	// cout<<"isEmpty: "<<arr.empty()<<'\n'; // 1 -> true 

	// cout<<"max size: "<<arr.get_max_size()<<endl;// 10

	// cout<<"current size: "<<arr.get_size()<<endl; // 0 

	arr.print();

	return 0;
}










