#include <iostream>

int main()
{
    int input;
    int sum = 0;
    
    for(int i = 0; i < 4; ++i)
    {
        std::cin >> input;
        sum += input;
    }
    
    std::cout << sum / 60 << '\n' << sum % 60;
}
