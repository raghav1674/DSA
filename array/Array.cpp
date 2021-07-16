#include<iostream> 
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

int main(){


	Array arr = Array(10);

	arr.insert(0,19);
	arr.insert(1,100);
	arr.insert(2,300);
	arr.insert(3,100);
	arr.insert(5,1002);
	arr.remove(1);


	cout<<"isEmpty: "<<arr.empty()<<'\n'; // 1 -> true 

	cout<<"max size: "<<arr.get_max_size()<<endl;// 10

	cout<<"current size: "<<arr.get_size()<<endl; // 0 

	arr.print();

	return 0;
}










