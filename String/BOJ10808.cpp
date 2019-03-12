#include <iostream>
#include <string>

int cnt[27];

int main()
{
    std::string str;
    std::cin >> str;
    for(int i = 0; i < str.size(); ++i)
        ++cnt[str[i] - 'a'];
    for(int i = 0; i < 26; ++i)
        std::cout << cnt[i] << ' ';
    return 0;
}
