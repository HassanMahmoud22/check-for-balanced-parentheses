#include<iostream>
#include<stack>
using namespace std;

// function to check if balanced
bool isBalanced(string TestedString)
{
	stack<char> s;
	char x;

	for (int i = 0; i < TestedString.length(); i++)
	{
		if (TestedString[i] == '(' || TestedString[i] == '[' || TestedString[i] == '{')
		{
			// Push the element in the stack 
			s.push(TestedString[i]);
			continue;
		}

		// IF current current character is not opening bracket, then it must be closing.
		switch (TestedString[i])
		{
		case ')':

			// Store the top element in a 
			x = s.top();
			s.pop();
			if (x == '{' || x == '[')
				return false;
			break;


		case '}':

			// Store the top element in b 
			x = s.top();
			s.pop();
			if (x == '(' || x == '[')
				return false;
			break;


		case ']':

			// Store the top element in c 
			x = s.top();
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;

		}
	}

	return (s.empty()); // Check If the stack is Empty 
}


int main()
{
	string Test ;
	cout << "Enter The string You want to check" << endl;
	cin >> Test;

	if (isBalanced(Test))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}
