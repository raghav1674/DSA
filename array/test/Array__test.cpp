#include "../DS/Array.cpp"



int main()
{

	Array<string>arr = Array<string>(10);

	arr.insert(0, "Hhello");
	arr.insert(1, "Ram");
	arr.insert(2, "Raj");
	arr.insert(3, "Rakesh");
	// arr.insert(4, 1);
	// arr.insert(5, 1);

	// arr.bubble_sort();
	arr.quick_sort();

	arr.quick_sort();

	// cout<<"isEmpty: "<<arr.empty()<<'\n'; // 1 -> true

	// cout<<"max size: "<<arr.get_max_size()<<endl;// 10

	// cout<<"current size: "<<arr.get_size()<<endl; // 0

	arr.print();

	return 0;
}
