#include <iostream>
#include <string>

class Queue
{
public:
	int arr[10000];
	int front = 0;
	int back = -1;
	bool isEmpty = true;

public:
	void Push()
	{
		int val;
		isEmpty = false;
		std::cin >> val;
		arr[++back] = val;
	}

	void Pop()
	{
		if (front > back) {
			std::cout << -1 << '\n';
			isEmpty = true;
		}
		else 
		{
			std::cout << arr[front] << '\n';
			++front;
			if (front > back) isEmpty = true;
		}
	}

	void Size()
	{
		std::cout << back - front + 1 << '\n';
	}

	void Empty()
	{
		std::cout << isEmpty << '\n';
	}

	void Front()
	{
		if (isEmpty) std::cout << -1 << '\n';
		else std::cout << arr[front] << '\n';
	}

	void Back()
	{
		if (isEmpty) std::cout << -1 << '\n';
		else std::cout << arr[back] << '\n';
	}

	void Command(std::string str)
	{
		if (str == "push") Push();
		else if (str == "pop") Pop();
		else if (str == "size") Size();
		else if (str == "empty") Empty();
		else if (str == "front") Front();
		else Back();
	}

private:
};

int main()
{
	int N;
	Queue q;
	std::string str;

	std::cin >> N;
	while (N--)
	{
		std::cin >> str;
		q.Command(str);
	}

	return 0;
}