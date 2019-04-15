#include <iostream>
using namespace std;
template<class type>
struct Node
{
	type value;
	Node* next = NULL;

};
template<class type>
class Queue
{
public:

	int Front = 0;
	Node<type>* head = NULL;
	Node<type>* rear = NULL;
	int Size = 0;
	Queue()
	{
		Size = 0;
	}
	~Queue()
	{
		delete (head);
		delete (rear);
	}
	Queue(type val, int intial_size)
	{
		int v;

		for (v = 0; v<intial_size; v++)
		{
			Node <type> *newnode = new Node<type>;


			newnode->value = val;
			if (head == NULL)
			{
				head = rear = newnode;
				rear->next = NULL;
				Size++;
				continue;

			}
			rear->next = newnode;
			rear = newnode;
			rear->next = NULL;
			++Front;
			Size++;
		}


	}
	void Push(type a)
	{
		Node <type> *newnode = new Node<type>;


		newnode->value = a;
		if (head == NULL)
		{
			head = rear = newnode;
			rear->next = NULL;
			Size++;
			return;

		}
		rear->next = newnode;
		rear = newnode;
		rear->next = NULL;
		++Front;
		Size++;
	}
	type pop()
	{
		Node<type>*Delete = head;
		int v;
		if (head == NULL)
		{
			cout << "the queue is empty " << endl;
			return 0;
		}
		if (head != NULL)
		{
			v = Delete->value;
			head = head->next;

			delete (Delete);



			--Front;
			Size--;
		}
		return v;
	}
	type& F_Front()
	{
		if (head != NULL)
			return head->value;

	}
	void print()
	{
		Node<type>*Curr = head;
		while (Curr != NULL)
		{
			cout << Curr->value << "    ";
			Curr = Curr->next;
		}

		cout << endl;
	}
	int F_Size()
	{
		return Size;
	}



};

int main()
{
	Queue<int>  s1;

	s1.Push(1);
	s1.Push(2);
	s1.Push(6);
	s1.Push(4);
	s1.Push(5);
	s1.print();
	cout << s1.pop() << "  ";
	cout << s1.pop() << endl;
	s1.print();

	cout << "front is " << s1.F_Front() << endl;
	cout << "Size is " << s1.F_Size() << endl << endl;
	Queue <int>s2(1, 5);

	s2.print();
	cout << "top is" << s2.F_Front() << endl;
	cout << "Size is " << s2.F_Size() << endl << endl;
	s2.Push(5);
	s2.Push(4);
	s2.Push(3);
	s2.print();
	cout << "top is" << s2.F_Front() << endl;
	cout << "Size is " << s2.F_Size() << endl;

	system("pause");
	return 0;
}

