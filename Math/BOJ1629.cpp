#include <iostream>

using ll = long long;

ll mul(ll base, ll exp, ll mod)
{
	if (exp == 0) return 1;
	if (exp == 1) return base % mod;

	ll cache = mul(base, exp / 2, mod);

	if (exp % 2 == 0)
		return (cache * cache) % mod;
	else
		return (((cache * cache) % mod) * (base % mod)) % mod;
}

int main()
{
	ll A, B, C;

	std::cin >> A >> B >> C;
	std::cout << mul(A, B, C);

	return 0;
}
