#include <utility>
#include <memory>
#include <cstdio>

template <typename Type>
void amazingSwap(Type& a, Type& b)
{
    std::auto_ptr<Type> buffer(reinterpret_cast<Type*>((void*)(uint8_t*)std::addressof(a)));
    a = *reinterpret_cast<Type*>((void*)(uint8_t*)std::addressof(b));
    b = *reinterpret_cast<Type*>((void*)(uint8_t*)std::addressof(*buffer));
}

int main()
{
    int a = 0, b = 1;
    amazingSwap(a, b);
    printf("a = %d\nb = %d\n", a, b);
    return 0;
}