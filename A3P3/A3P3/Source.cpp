#include <iostream>
using namespace std;
template<class type>
struct node
{
	type value;
	node* next = null;

};
template<class type>
class stack
{
public:

	int top = 0;
	node<type>* head = null;
	int size;
	stack()
	{
		size = 0;
	}
	~stack()
	{
		delete (head);
	}
	stack(type val, int intial_size)
	{
		int v;

		for (v = 0; v < intial_size; v++)
		{
			node<type>*newnode = new node<type>;
			newnode->value = val;
			if (head == null)
			{
				head = newnode;

				continue;

			}
			newnode->next = head;
			head = newnode;
			++top;

			size = intial_size;
		}


	}
	void push(type a)
	{
		node <type> *newnode = new node<type>;
		newnode->value = a;
		if (head == null)
		{
			head = newnode;
			size++;
			return;

		}
		newnode->next = head;
		head = newnode;
		++top;
		size++;
	}
	type pop()
	{
		node<type>*delete = head;
		int v;
		if (head != null)
		{
			head = head->next;

			v = delete->value;
			delete (delete);
			--top;
			size--;
		}
		return v;
	}
	type& top()
	{
		if (head != null)
			return head->value;

	}
	void print()
	{
		node<type>*curr = head;
		while (curr != null)
		{
			cout << curr->value << "    ";
			curr = curr->next;
		}

		cout << endl;
	}
	int f_size()
	{
		return size;
	}



};

int main()
{
	stack<int>  s1;

	s1.push(5);
	s1.push(4);
	s1.push(3);
	s1.push(2);
	s1.push(1);
	s1.print();

	cout << "top is " << s1.top() << endl;
	cout << "size is " << s1.f_size() << endl << endl;
	stack <int>s2(1, 5);

	s2.print();
	cout << "top is" << s2.top() << endl;
	cout << "size is " << s2.f_size() << endl << endl;
	s2.push(5);
	s2.push(4);
	s2.push(3);
	s2.print();
	cout << "top is" << s2.top() << endl;
	cout << "size is " << s2.f_size() << endl;


	system("pause");
	return 0;
}

