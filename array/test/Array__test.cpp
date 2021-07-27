#include "../DS/Array.cpp"



int main()
{

	Array<int>arr = Array<int>(10);

	arr.insert(0, 4);
	arr.insert(1, 3);
	arr.insert(2, 2);
	arr.insert(3, 1);

	// arr.insert(4, 1);
	// arr.insert(5, 1);

	// arr.bubble_sort();
	// arr.quick_sort();

	// arr.quick_sort();

	// cout<<"isEmpty: "<<arr.empty()<<'\n'; // 1 -> true

	// cout<<"max size: "<<arr.get_max_size()<<endl;// 10

	// cout<<"current size: "<<arr.get_size()<<endl; // 0 
	arr.merge_sort();
	arr.print();

	return 0;
}
