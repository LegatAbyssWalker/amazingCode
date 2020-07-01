#include <iostream>

int amazingMax(int a, int b)
{
    int i = 0;
    
    for(;i < a; i++);
    for(;i < b; i++);
    
    return i;
}

int amazingMin(int a, int b)
{
    int i = 0;
    
    for(;i < a; i++);
    for(;i > b; i--);
    
    return i;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << "Max: " << amazingMax(a, b) 
              << "\nMin: " << amazingMin(a, b) << '\n';

    return 0;
}