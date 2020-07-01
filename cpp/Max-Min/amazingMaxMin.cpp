// Code by AnonymousPlayer

#include <iostream>

template<typename T, typename R>
T amazingMax(T a, R b)
{
    T i = 0;
    
    for(;i < a; i++);
    for(;i < b; i++);
    
    return i;
}

template<typename T, typename R>
T amazingMin(T a, Rint b)
{
    T i = 0;
    
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