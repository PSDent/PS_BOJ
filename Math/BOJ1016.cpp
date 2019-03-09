#include <iostream>
#include <cstring>

using ll = long long;
bool check[1000002];

int main()
{
	ll cnt = 0, min, max;
	std::cin >> min >> max;
	std::memset(check, true, sizeof(check));

	for (ll i = 2; i * i <= max; ++i)
	{
		ll sp;
		if (min % (i * i) == 0) sp = min / (i * i) * (i * i);
		else if (min <= (i * i)) sp = i * i;
		else sp = min + ((i*i) - (min % (i * i)));
		for (ll j = sp; j <= max; j += i * i)
			check[j - min + 1] = false;
	}

	for (int i = 1; i <= max - min + 1; ++i)
		if (check[i]) ++cnt;
	std::cout << cnt;

	return 0;
}
