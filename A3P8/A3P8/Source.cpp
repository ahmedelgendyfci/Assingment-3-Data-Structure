#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
class Stack
{
	queue<int>q;
public:
	void push(int val);
	void pop();
	int top();

};
void Stack::push(int val)
{
	int s = q.size();
	q.push(val);
	for (int i = 0; i<s; i++)
	{
		// this will add front element into rear of queue
		q.push(q.front());
		// this will delete front element
		q.pop();
	}
}
int  Stack::top()
{
	if (q.empty())
	{
		cout << "TOP::stack is empty\n";
	}
	else
		cout << "the top is :";
	return q.front();

}
// Removes the top element
void Stack::pop()
{
	if (q.empty())
		cout << "POP::stack is empty\n";
	else

		q.pop();
}
int main()
{
	Stack s;
	int value;
	int size1;
	cout << "enter your size of your stack : ";
	cin >> size1;
	cout << "enter your values of your stack : " << endl;

	for (int i = 0; i<size1; i++)
	{
		cin >> value;
		s.push(value);
	}
	cout << s.top() << endl;
	s.pop();
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	system("pause");
	return 0;
}
