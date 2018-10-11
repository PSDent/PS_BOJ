#include <string>
#include <vector>

using namespace std;

char arr[3] = { '4', '1', '2' };
std::vector<char> v;

string solution(int n) {
	string answer = "";

	while (n > 0)
	{
		v.push_back(arr[n % 3]);
		int a = n % 3 == 0 ? 1 : 0;
		n = n / 3 - a;
	}

	for (int i = v.size() - 1; i >= 0; --i)
		answer.push_back(v[i]);

	return answer;
}