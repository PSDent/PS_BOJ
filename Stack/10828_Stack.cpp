//================================================
// Filename : 10828_Stack
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/10828
//================================================
#include <iostream>
#include <string>

class stack {
public:
	stack();

	void push(const int x);
	void pop();
	void size();
	void empty();
	void top();
	void cmd(const std::string command);

private:
	int data[10000];
	int topIndex;
};

stack::stack()
{
	topIndex = -1;
}

void stack::cmd(const std::string command)
{
	if (command == "push") {
		int val;
		std::cin >> val;
		this->push(val);
	}

	else if (command == "pop")
		this->pop();

	else if (command == "size")
		this->size();

	else if (command == "empty")
		this->empty();

	else if (command == "top")
		this->top();
}

void stack::push(const int x)
{
	data[++topIndex] = x;
	return;
}

void stack::pop()
{
	if (topIndex < 0) {
		std::cout << -1 << std::endl;
		return;
	}

	std::cout << data[topIndex] << std::endl;
	data[topIndex--] = 0;
	return;
}

void stack::size()
{
	std::cout << topIndex + 1 << std::endl;
	return;
}

void stack::empty()
{
	if (topIndex > -1)
		std::cout << false << std::endl;
	else
		std::cout << true << std::endl;
	return;
}

void stack::top()
{
	if (topIndex > -1)
		std::cout << data[topIndex] << std::endl;
	else
		std::cout << -1 << std::endl;
	return;
}

int main()
{
	stack st;
	std::string str;
	int N,val;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> str;
		st.cmd(str);
	}

	return 0;
}