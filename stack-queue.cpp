#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;
bool isOperator(char c)
{
	return (!(isdigit(c) or isalpha(c)));
}
string prefixToPostfix(string prefix = "*+AB - CD")
{
	stack < string > s;
	// int might cause possible loss of data
	size_t length = prefix.size();
	//to read from right to left
	for (int i = length - 1; i >= 0; i--)
	{
		if (isOperator(prefix[i]))
		{
			string operand1 = s.top();
			s.pop();
			string operand2 = s.top();
			s.pop();
			s.push(operand1 + operand2 + prefix[i]);
		}
		else
		{
			//type conversion from character to string
			s.push(string(1, prefix[i]));
		}
	}
	return s.top();
}
int
evaluate_postfix(string postfix)
{
	stack < int >s2;
	size_t length = postfix.size();
	for (int i = 0; i < length; i++)
	{
		if (isdigit(postfix[i]))
			// converting string to integer
			s2.push(postfix[i] - '0');
		if (isOperator(postfix[i]))
		{
			int operand1 = s2.top();
			s2.pop();
			int operand2 = s2.top();
			s2.pop();
			switch (postfix[i])
			{
			case '+':
				s2.push(operand1 + operand2);
				break;
			case '-':
				s2.push(operand1 - operand2);
				break;
			case '/':
				s2.push(operand1 / operand2);
				break;
			case '*':
				s2.push(operand1 * operand2);
				break;
			}
		}
	}
	return s2.top();
}
size_t students_deprived(int* std, int* swich, int size)
{
	stack < int >sandwich;
	queue < int >student;
	for (int i = 0; i < size; i++)
	{
		sandwich.push(swich[size - i - 1]);
		student.push(std[i]);
	}
	int deprive = 0;
	while (student.size() != deprive)
	{
		if (sandwich.top() != student.front())
		{
			auto leaver = student.front();
			student.pop();
			student.push(leaver);
			deprive++;
		}
		else
		{
			sandwich.pop();
			student.pop();
			deprive = 0;
		}
	}
	return student.size();
}
int
josephus(int n, int m)
{
	queue < int >q;
	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}
	while (q.size() > 1)
	{
		for (int i = 1; i <= m; ++i)
		{
			int front = q.front();
			q.pop();
			q.push(front);
		}
		q.pop();
	}
	return q.front();
}
int main()
{
	int question;
	int choice;
	bool exitProgram = false;

	while (!exitProgram)
	{
		system("cls");		
		cout << "\n\tSelect Task: \n";
		cout << "\n\tQuestion (1)\tQuestion (2)\t(0) Exit\n\n\t";
		cin >> question;
		switch (question)
		{
		case 1:
			
		{
			cout << "\n\t (1) Conversion from prefix to postfix\n\t (2) Evaluation of Postfix Expression\n\t";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				string infix;
				cout<<"Enter a prefix expression: '*+AB - CD'\n\t";
				cin >> infix;
				cout<<"\n\tPostfix of "<<infix<< " is: "<< prefixToPostfix(infix);
				
				
				break;
			}
			case 2:
			{	string postfix;
				cout << "\n\tEnter a postfix expression: '234*+'\n\t";
				cin >> postfix;
				cout<<"\n\t"<<postfix << " = " <<evaluate_postfix(postfix);
				
				break;
			}
			default:
				break;
			}
			Sleep(3000);
			
			break;
		}
		case 2:
			
		{
			cout << "\n\t (1) Number of Students Unable to Eat Lunch \n\t (2) Josephus Problem through Queue\n\t";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				
				int size = 6;
				int students[6] = {0}; int p;
				int sandwiches[6] = {0}; int sw;
				cout << "\n\tEnter array for students' preference: { 1,1,1,0,0,1 }\n\t";
				for (int i = 0; i < size; i++) {
					cin >> p;
					cout << endl << "\t";
					students[i] = p;
				}
				cout << "\n\tEnter array for sandwich types: { 1,0,0,0,1,1 }\n\t";
				for (int i = 0; i < size; i++) {
					cin >> sw;
					cout << endl << "\t";
					sandwiches[i] = sw;
				}

				cout << "\n\tOut of " << size << " students, " <<
					students_deprived(students, sandwiches, size)
					<< " will not eat their preferred sandwich.\n\t";
	
				break;
			}
			case 2:
			{
				int n, m;
				cout << "\n\tEnter the number of people (N): ";
				cin >> n;
				cout << "\n\tEnter the number of passes (M): ";
				cin >> m;
				int survivor = josephus(n, m);
				cout << "\n\tPerson saved from execution is " << survivor << endl;
				break;
			}
			default:
				break;
			}
			Sleep(3000);
			break;
		}
		case 0:
			cout << "\n\n\tSee you next time. Goodbye!\n\n\t";
			exitProgram = true;
			break;
		}
	}

	return 0;
}


