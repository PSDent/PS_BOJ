#include <iostream>
#include <string>

class Node
{
public:
	Node(int val) 
	{ 
		next = NULL;
		prev = NULL;
		data = val;
	};

	~Node() {};

	Node *next;
	Node *prev;
	int data;
};

class Deque
{
public:
	Deque() 
	{
		frontNode = NULL;
		rearNode = NULL;
		dq_size = 0;
	}
	~Deque() {}

	void Command(std::string cmd)
	{
		if (cmd == "push_front")
		{
			int val;
			std::cin >> val;
			push_front(val);
		}
		else if (cmd == "push_back")
		{
			int val;
			std::cin >> val;
			push_back(val);
		}
		else if (cmd == "pop_front") pop_front();
		else if (cmd == "pop_back") pop_back();
		else if (cmd == "size") size();
		else if (cmd == "empty") empty();
		else if (cmd == "front") front();
		else if (cmd == "back") back();
	}

	void push_front(int val)
	{
		if (frontNode)
		{
			Node *temp = frontNode;
			frontNode->prev = new Node(val);
			frontNode = frontNode->prev;
			frontNode->next = temp;
		}
		else
		{
			frontNode = new Node(val);
			if (!rearNode)
				rearNode = frontNode;
		}
		++dq_size;
	}	

	void push_back(int val)
	{
		if (rearNode)
		{
			Node *temp = rearNode;
			rearNode->next = new Node(val);
			rearNode = rearNode->next;
			rearNode->prev = temp;
		}
		else
		{
			rearNode = new Node(val);
			if (!frontNode)
				frontNode = rearNode;
		}
		++dq_size;
	}

	void pop_front()
	{
		if (frontNode)
		{
			std::cout << frontNode->data << '\n';
			Node *temp = frontNode->next;
			delete frontNode;
			frontNode = temp;
			
			--dq_size;

			if (!dq_size)
				frontNode = rearNode = NULL;
		}
		else
			std::cout << -1 << '\n';
	}

	void pop_back()
	{
		if (rearNode)
		{
			std::cout << rearNode->data << '\n';
			Node *temp = rearNode->prev;
			delete rearNode;
			rearNode = temp;
			--dq_size;

			if (!dq_size)
				frontNode = rearNode = NULL;
			/*else
				rearNode->next = NULL;*/
		}
		else
			std::cout << -1 << '\n';
	}

	void size()
	{
		std::cout << dq_size << '\n';
	}

	void empty()
	{
		std::cout << ((dq_size > 0) ? 0 : 1) << '\n';
	}

	void front()
	{
		std::cout << ((frontNode == NULL) ? -1 : frontNode->data) << '\n';
	}

	void back()
	{
		std::cout << ((rearNode == NULL) ? -1 : rearNode->data) << '\n';
	}

private:
	Node *frontNode;
	Node *rearNode;
	int dq_size;
};

int main()
{
	std::string str;
	Deque dq;
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> str;
		dq.Command(str);
	}

	return 0;
}