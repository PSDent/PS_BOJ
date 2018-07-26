#include <iostream>

int Max(int a, int b)
{
    return a >= b ? a : b;
}

int main()
{
    int input;
    int sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < 4; ++i)
    {
        std::cin >> input;
        sum1 += input;
    }
    
    for(int i = 0; i < 4; ++i)
    {
        std::cin >> input;
        sum2 += input;
    }
    
    std::cout << Max(sum1, sum2);
}
