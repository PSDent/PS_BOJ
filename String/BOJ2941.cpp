#include <iostream>
#include <string>
#include <set>

using namespace std;

string chList[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main()
{
	int cnt = 0;
	set<string> croatiaCh;
	string str;
	cin >> str;

	for (int i = 0; i < 8; ++i)
		croatiaCh.insert(chList[i]);

	for (int i = 0; i < str.size(); )
	{
		cnt += 1;

		if (i + 2 < str.size())
		{
			string sub = str.substr(i, 3);
			if (croatiaCh.find(sub) != croatiaCh.end())
			{
				i += 3; continue;
			}
		}
		
		if (i + 1 < str.size())
		{
			string sub = str.substr(i, 2);
			if (croatiaCh.find(sub) != croatiaCh.end())
			{
				i += 2; continue;
			}
		}
		i++;
	}

	cout << cnt; 

	return 0;
}
