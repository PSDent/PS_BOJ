#include <iostream>
#include <string>
#include <stack>

using namespace std;

void VFS(string a)
{
	stack<char> st;
	char prevCh = 0, topCh = 0;
	int i = 0;

	st.push(a[i++]);

	while (i <= a.size())
	{
		if (!st.empty())
			topCh = st.top();
		else
			topCh = 0;

		if (prevCh == '(' && topCh == ')')
		{
			st.pop(); st.pop();
			prevCh = 0;
		}
		else if (i < a.size())
		{
			prevCh = topCh;
			st.push(a[i++]);
		}
		else
			++i;
	}

	if (st.empty())
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return;
}

int main()
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		VFS(str);
	}

	return 0;
}
