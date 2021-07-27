#include <iostream>
#include <climits>

using namespace std;

/**
 * @brief Array class decl.
 * @tparam ELEMENT_TYPE 
 */
template<typename ELEMENT_TYPE>
class Array
{

private:
	int __max_size;
	int __last_index;
	ELEMENT_TYPE *__arr;

	void __quick_sort_recursive(int, int);

	int __partition(int, int);

	bool __check_if_sorted();

	void __merge_sort_recursive(int,int);
	void __merge(int,int,int);

public:
	Array(int given_size)
	{

		this->__max_size = given_size;
		this->__last_index = -1;
		this->__arr = new ELEMENT_TYPE[given_size];
	}

	int get_max_size()
	{

		return this->__max_size;
	}

	bool insert(int, ELEMENT_TYPE);

	bool remove(int);

	bool empty()
	{

		return this->__last_index == -1 ? true : false;
	}

	bool full()
	{

		return this->__last_index + 1 == this->__max_size ? true : false;
	}

	int get_size()
	{

		return this->__last_index + 1;
	}

	void print();

	void bubble_sort();

	void insertion_sort();

	void selection_sort();

	void quick_sort();

	void merge_sort();

	

	
};