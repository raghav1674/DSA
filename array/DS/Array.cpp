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
template <typename ELEMENT_TYPE>
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
template <typename ELEMENT_TYPE>
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
template <typename ELEMENT_TYPE>
bool Array<ELEMENT_TYPE>::__check_if_sorted()
{

	int length = __last_index + 1;
	for (int j = 0; j < length - 1; j++)
	{
		if (__arr[j] > __arr[j + 1])
		{
			return false;
		}
	}
	return true;
}

/**
 * @brief calculate the index of the pivot element
 * @tparam ELEMENT_TYPE 
 * @param low 
 * @param high 
 * @return int 
 * @access private
 */
template <typename ELEMENT_TYPE>
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
template <typename ELEMENT_TYPE>
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
template <typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::quick_sort()
{

	if (!__check_if_sorted())
		__quick_sort_recursive(0, __last_index);
}

/**
 * @brief print the array 
 * @tparam ELEMENT_TYPE
 * @access public 
 */
template <typename ELEMENT_TYPE>
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
template <typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::bubble_sort()
{

	int length = __last_index + 1;
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
template <typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::insertion_sort()
{

	if (__check_if_sorted())
		return;

	int length = __last_index + 1;
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
template <typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::selection_sort()
{

	if (__check_if_sorted())
		return;

	int length = __last_index + 1;
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
template <typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::__merge(int low, int mid, int high)
{

	const int left_arr_size = mid - low + 1;
	const int right_arr_size = high - mid;

	int left_arr[left_arr_size];
	int right_arr[right_arr_size];

	// copy the element to left
	for (int i = 0; i < left_arr_size; i++)
	{

		left_arr[i] = __arr[low+i];
	}
	// copy right array
	for (int i = 0; i < right_arr_size; i++)
	{

		right_arr[i] = __arr[mid+1+i];
	}

	int i = 0;
	int j =0;
	int k = low;
	// cout<<"#i:"<<i<<" #j: "<<j<<" #k:"<<k<<" #left_arr_size: "<<left_arr_size<<" #right_arr_size: "<<right_arr_size<<'\n';
	while (i < left_arr_size && j < right_arr_size)
	{


		

		if (left_arr[i] <= right_arr[j])
		{

			__arr[k] = left_arr[i];
			i++;
		}
		else
		{

			__arr[k] = right_arr[j];
			j++;
		}

		k++;
	}
	while (i < left_arr_size)
	{

		__arr[k] = left_arr[i];
		i++;
		k++;
	}
	while (j < right_arr_size)
	{

		__arr[k] = right_arr[j];
		j++;
		k++;
	}

	
}
template <typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::__merge_sort_recursive(int low, int high)
{

	if (low < high)
	{

		int mid = (high + low) / 2;          // 2    0   2

		__merge_sort_recursive(low, mid);     // 0   1   // 0  0   

		__merge_sort_recursive(mid+1, high); // 2  3   // 2  2    //

		__merge(low, mid, high);
	}
}

template <typename ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::merge_sort()
{

	if (!__check_if_sorted())
		__merge_sort_recursive(0, __last_index);
}