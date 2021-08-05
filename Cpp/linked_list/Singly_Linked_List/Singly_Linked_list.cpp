#include <iostream>

template <typename ELEMENT_TYPE>
struct Node
{

	ELEMENT_TYPE data;
	Node *next;
	Node(ELEMENT_TYPE data, Node *next = nullptr)
	{

		this->data = data;
		this->next = next;
	}
};
template <typename ELEMENT_TYPE>
class SinglyLinkedList
{

	Node<ELEMENT_TYPE> *head;
	int lastIndex;

public:
	SinglyLinkedList()
	{

		this->head = nullptr;
		this->lastIndex = -1;
	}

	bool insert(int index, int data)
	{
		// check if the index is valid or not
		if (index >= 0 && index <= lastIndex + 1)
		{
			Node<ELEMENT_TYPE> *newNode = new Node<ELEMENT_TYPE>(data);

			// if head is null
			if (head == nullptr)
			{
				head = newNode;
			}
			else if (index == 0)
			{

				newNode->next = head;
				head = newNode;
			}
			else
			{
				// traverse till one less than the index given
				Node<ELEMENT_TYPE> *temp = head;
				int curr = 0;
				while (temp->next != nullptr && curr != index)
				{

					temp = temp->next;
					curr++;
				}
				if (temp != nullptr)
					newNode->next = temp->next;
				temp->next = newNode;
			}
			lastIndex++;
			return true;
		}
		return false;
	}

	void print()
	{

		Node<ELEMENT_TYPE> *temp = head;
		std::cout << "[ ";
		while (temp != nullptr)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << " ]\n";
	}
};

int main()
{

	SinglyLinkedList<int> mylist;
	mylist.insert(0, 10);
	mylist.insert(1, 20);
	mylist.insert(0, 5);

	mylist.print();

	return 0;
}