// Code by AnonymousPlayer

#include <iostream>

template<typename T, typename R>
constexpr inline auto amazingMax(T a, R b)
{
    T i = 0;
    
    for(;i < a; i++);
    for(;i < b; i++);
    
    return i;
}

template<typename T, typename R>
constexpr inline auto amazingMin(T a, R b)
{
    T i = 0;
    
    for(; i < a; i++);
    for(; i > b; i--);
    
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