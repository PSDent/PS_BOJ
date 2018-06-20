#include <iostream>
#include <string>

long long colorVal[3];
const char* colorStr[] =
{ "black", "brown", "red", "orange", "yellow",
"green", "blue", "violet", "grey", "white" };

void decideVal(std::string color, long long& val)
{
	for (int i = 0; i < 10; ++i)
	{
		if (color == colorStr[i])
		{
			val = i;
			break;
		}
	}
}

int main()
{
	long long mul = 1;
	std::string color[3];

	std::cin >> color[0] >> color[1] >> color[2];
	for (int i = 0; i < 3; ++i)
		decideVal(color[i], colorVal[i]);

	for (int i = 0; i < colorVal[2]; ++i)
		mul *= 10;

	std::cout << (colorVal[0] * 10 + colorVal[1]) * mul;


	return 0;
}
