#include "Array.h"


/**
 * @brief  insert element at the specified index but in sequential order
 * @tparam ELEMENT_TYPE 
 * @param index 
 * @param element 
 * @return true 
 * @return false  
 * @access public
 */
template<typename ELEMENT_TYPE>
bool Array<ELEMENT_TYPE>::insert(int index, ELEMENT_TYPE element)
{

	// if full then return false
	if (full())
		return false;
	// if not full then check for the last index
	if (0 <= index && index <= __last_index + 1)
	{
		// shift all the elements to right starting from the given index

		for (int i = __last_index; i >= index; i--)
		{

			__arr[i + 1] = __arr[i];
		}

		__arr[index] = element;
		__last_index += 1;
		return true;
	}
	return false;
}

/**
 * @brief remove the element from the specified index
 * @tparam ELEMENT_TYPE 
 * @param index 
 * @return true 
 * @return false 
 * @access public
 */
template<typename ELEMENT_TYPE>
bool Array<ELEMENT_TYPE>::remove(int index)
{

	if (empty())
		return false;

	if (0 <= index && index <= __last_index)
	{

		for (int i = index + 1; i <= __last_index; i++)

			__arr[i - 1] = __arr[i];
		__last_index -= 1;
		return true;
	}

	return false;
}

/**
 * @brief check if the array is already sorted or not
 * @tparam ELEMENT_TYPE 
 * @return true 
 * @return false 
 * @access private
 */
template<typename ELEMENT_TYPE>
bool Array<ELEMENT_TYPE>::__check_if_sorted()
{

	bool is_sorted = false;
	int length = __last_index+1;
	for (int i = 0; i < 1; i++)
	{
		int count = 0;
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (__arr[j] > __arr[j + 1])
			{
				ELEMENT_TYPE temp = __arr[j];
				__arr[j] = __arr[j + 1];
				__arr[j + 1] = temp;
				count += 1;
			}
		}
		if (count == 0)
		{
			is_sorted = true;
		}
	}

	return is_sorted;
}


/**
 * @brief calculate the index of the pivot element
 * @tparam ELEMENT_TYPE 
 * @param low 
 * @param high 
 * @return int 
 * @access private
 */
template<typename ELEMENT_TYPE>
int Array<ELEMENT_TYPE>::__partition(int low, int high)
{

	ELEMENT_TYPE pivot_element = __arr[low];

	int j = high;
	int i = low + 1;

	while (i <= j)
	{

		//if element is less increment  i
		while (__arr[i] <= pivot_element && i <= j)
		{

			i++;
		}

		if (i > j)
			break;

		// if element is greator decrement j
		while (__arr[j] > pivot_element && j > i)
		{

			j--;
		}

		// swap i and j
		ELEMENT_TYPE temp = __arr[j];
		__arr[j] = __arr[i];
		__arr[i] = temp;
		i++;
		j--;
	}

	// swap j with the pivot element
	__arr[low] = __arr[j];
	__arr[j] = pivot_element;
	return j;
}

/**
 * @brief actual recursive  implementation of quick sort
 * @tparam ELEMENT_TYPE 
 * @param low 
 * @param high 
 * @access private
 */
template<typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::__quick_sort_recursive(int low, int high)
{

	if (low < high)
	{

		int partition_index = __partition(low, high);

		// call to left side
		__quick_sort_recursive(low, partition_index - 1);
		//call to right side
		__quick_sort_recursive(partition_index + 1, high);
	}
}

/**
 * @brief public api for quick sort
 * @tparam ELEMENT_TYPE 
 * @access public
 */
template<typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::quick_sort()
{	

	if(!__check_if_sorted())
		__quick_sort_recursive(0, __last_index);

}

/**
 * @brief print the array 
 * @tparam ELEMENT_TYPE
 * @access public 
 */
template<typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::print()
{
	cout << "[ ";
	for (int i = 0; i <= __last_index; i++)
		cout << __arr[i] << " ";
	cout << "]";
}


/**
 * @brief bubble sort implementation
 * @tparam ELEMENT_TYPE
 * @access public
 */
template<typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::bubble_sort()
{

	int length = __last_index+1;
	for (int i = 0; i < length; i++)
	{
		int count = 0;
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (__arr[j] > __arr[j + 1])
			{
				ELEMENT_TYPE temp = __arr[j];
				__arr[j] = __arr[j + 1];
				__arr[j + 1] = temp;
				count += 1;
			}
		}
		if (count == 0)
		{

			break;
		}
	}
}

/**
 * @brief insertion sort implementation
 * @tparam ELEMENT_TYPE 
 * @access public
 */
template<typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::insertion_sort()
{	

	if(__check_if_sorted())return;  

	int length = __last_index+1;
	for (int i = 1; i < length; i++)
	{
		int temp = __arr[i]; // 2  --> // 1
		int j = i - 1;
		while (temp < __arr[j] && j >= 0)
		{
			__arr[j + 1] = __arr[j];
			j -= 1;
		}
		__arr[j + 1] = temp;
	}
}



/**
 * @brief selection sort implementation
 * @tparam ELEMENT_TYPE 
 * @access public
 */
template<typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::selection_sort()
{	

	if(__check_if_sorted())return;  


	int length = __last_index+1;
	for (int i = 0; i < length; i++)
	{
		int mini = i;
		for (int j = i; j < length; j++)
		{
			if (__arr[j] < __arr[mini])
			{
				mini = j;
			}
		}
		ELEMENT_TYPE temp = __arr[mini];
		__arr[mini] = __arr[i];
		__arr[i] = temp;
	}
}
