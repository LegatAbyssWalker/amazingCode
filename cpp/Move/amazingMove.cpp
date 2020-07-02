#include <cstdio>
#include <utility>

template< typename Type >
constexpr inline Type&& amazingMove(Type& value)
{
    return reinterpret_cast<Type&&>(*(char*)(void*)(std::addressof(value)));
}

class movable
{};

class test
{
public:
    test(movable&& val)
    {
        printf("%s\n", (char*)(void*)("moved"));
    }
};

int main()
{
    movable mov;
    test t(amazingMove(mov));
    return 0;
}