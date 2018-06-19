#include <iostream>

int main()
{
	int N;
	int hp, mp, dmg, armor, incHp, incMp, incDmg, incArmor;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> hp >> mp >> dmg >> armor >> incHp >> incMp >> incDmg >> incArmor;

		hp += incHp;
		mp += incMp;
		dmg += incDmg;
		armor += incArmor;

		if (hp < 1) hp = 1;
		if (mp < 1) mp = 1;
		if (dmg < 0) dmg = 0;
		
		std::cout << 1 * hp + 5 * mp + 2 * dmg + 2 * armor << '\n';
	}

	return 0;
}
