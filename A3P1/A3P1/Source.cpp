#include <iostream>
#include<string>
using namespace std;
class Exception
{
protected:
	string massage;
public:
	Exception(const string &m)    //constructor
	{
		massage = m;
	}
	void print()
	{
		cout << massage << endl;
	}
};

//template<class type>

template<typename type>
class myList
{

protected:
	struct Node
	{
		type value;
		Node*next;
		Node*prev;
		Node(type v = type(), Node *p = NULL, Node *n = NULL)
		{
			value = v;
			prev = p;
			next = n;
		}

	};
	typedef Node *nodeptr;



public:

	class Iterator
	{
		friend class myList;
		// our code for the iterator class here
	private:
		nodeptr ptr;    //an ordinary pointer  (refere to my current)
	public:
		//        iter(int)

		//----------------------------------------//
		Iterator(Node *p = NULL) : ptr(p)          //constructor
		{

		}
		Iterator(Node &pt) :ptr(pt)          //constructor
		{

		}
		Iterator& operator++()
		{
			if (ptr->next == NULL)
				throw Exception();
			ptr = ptr->next;
			return *this;

		}
		Iterator& operator--()
		{
			if (ptr->next = NULL)
				throw Exception();
			ptr = ptr->prev;
			return*this;

		}
		type& operator*()
		{
			return ptr->value;
		}
		bool operator == (const Iterator &iter)
		{
			if (ptr == iter.ptr)
				return true;
			else
				return false;

		}




	};
	////////*************************/////////////
	// our code for the list class here
protected:
	int sz;
	nodeptr first;
	nodeptr last;
public:
	myList()
	{
		first = new Node;
		last = new Node;
		first->next = last;
		last->prev = first;
		sz = 0;
	}
	myList(type val, int initial_size)
	{
		for (int i = 0; i<initial_size; i++)
		{
			Node *newnode = new Node;
			newnode->value = val;
			newnode->next = NULL;
			newnode->prev = NULL;
			Node *Curr = first;
			while (Curr)
			{
				if (Curr = NULL)
				{
					Node *p;
					p = Curr->prev;
					newnode->next = Curr;
					Curr->prev = newnode;
					newnode->prev = p;
					continue;


				}
				Curr = Curr->next;
				sz++;
			}
		}


	}
	~myList()
	{
		delete (first);
		delete (last);
	}
	int Size()  const
	{
		return sz;
	}
	void Insert(type val, Iterator position)
	{
		nodeptr newnode = new Node(val, position.ptr, position.ptr->next);


		cout << "insert after enter(1)..\n insert before enter(2)..\n";
		char c;
		cin >> c;
		if (c == '1')
		{


			position.ptr->next = newnode;
			position.ptr->next->prev = newnode;

		}
		if (c == '2')
		{
			position.ptr->prev->next = newnode;
			position.ptr->prev = newnode;
		}

		sz++;
	}




	Iterator Erase(Iterator position)
	{
		if (position.ptr->prev == first)     //delete from first
		{
			first = position.ptr->next;
			position.ptr->next->prev = first;


		}
		else if (position.ptr->next == last)     //delete from first
		{
			position.ptr->prev->next = last;
			last = position.ptr->prev;


			throw Exception("no last node to match");
		}
		else
		{
			position.node->prev->next = position.node->next;
			position.node->next->prev = position.node->prev;

		}
		return *this;
	}
	bool Empty() const
	{
		return Size() == 0;
	}
	Iterator Begin() const
	{
		if (Empty())
		{
			throw Exception("no first for empty list");
		}
		return Iterator(first->next);
	}
	Iterator End()
	{

		if (Empty())
		{
			throw Exception("no last for empty list");
		}
		return Iterator(last);

	}
	void print()
	{
		cout << " is Size" << Size() << endl;
		if (Size()>0)
		{
			nodeptr Curr = first->next;
			while (Curr != last)
			{
				cout << Curr->value << "  " << endl;
				Curr = Curr->next;
			}

			cout << endl;
		}
	}



};



typedef myList<int>List;
int main()
{
	int argc;
	char** argv;
	List l1;
	List::Iterator Begin = l1.Begin();
	List::Iterator End = l1.End();
	List::Iterator it = Begin;

	for (int i = 0; i != 10; i++)
	{
		l1.Insert(5, it);
		cout << *it << "  ";
		l1.print();

	}

	system("pause");
	return 0;
}
