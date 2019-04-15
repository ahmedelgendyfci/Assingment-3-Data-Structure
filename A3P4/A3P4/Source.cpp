#include <iostream>
#include<string>
#include<stack>

using namespace std;
bool Stack(string str)
{
	stack<char> s1;
	bool b = true;
	for (int i = 0; i < sizeof(str); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			s1.push(str[i]);

		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{

			if (str[i] == ')'&&s1.top() == '(')
			{
				s1.pop();

			}

			else if (str[i] == ']'&&s1.top() == '[')
			{
				s1.pop();

			}


			else if (str[i] == '}'&&s1.top() == '{')
			{
				s1.pop();

			}
			else
				b = false;




		}
		else if (str[i] == '/')
		{
			if (str[i + 1] == '*')
			{
				s1.push(str[i]);
				s1.push(str[i + 1]);
				continue;
			}
		}
		else if (str[i] == '*')
		{
			char c1, c2;
			if (str[i + 1] == '/')
			{
				c1 = s1.top();
				c2 = s1.top();
				s1.pop();
				s1.pop();
				if (c1 = '*', c2 = '/')
					continue;
				else
					b = false;

			}
		}

	}
	return b;
}

int main()
{
	string s;
	cout << "please enter your string " << endl;
	cin >> s;
	string s5 = "([{}])(){}[]{[]}";
	string s1 = "({)}";
	string s2 = "({/*)}]]]]]]}*/})";
	string s3 = "({/*[][[]]]]]})";
	string s4 = "[{/*******/}]";
	bool b;
	b = Stack(s);
	if (b == true)
		cout << "valid\n";
	else
		cout << "in valid\n";

	system("pause");
	return 0;
}
