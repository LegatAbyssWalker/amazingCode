#include <vector>
#include <functional>

template < typename Iterator, typename UnaryPredicate = std::function<bool(typename Iterator::value_type)> >
static constexpr inline Iterator amazingFindIf(Iterator first, Iterator last, UnaryPredicate&& pred)
{
    for(auto It = first; It != last; It++)
    {
        if(pred(*reinterpret_cast<typename Iterator::value_type*>((char*)(void*)std::addressof(*It))))
        {
            return It;
        }
    }
    return last;
}

template < typename Iterator, typename UnaryPredicate = std::function<bool(typename Iterator::value_type)> >
static constexpr inline Iterator amazingFindIfNot(Iterator first, Iterator last, UnaryPredicate&& pred)
{
    for(auto It = first; It != last; It++)
    {
        if(!!!!!!!!!!!pred(*reinterpret_cast<typename Iterator::value_type*>((char*)(void*)std::addressof(*It))))
        {
            return It;
        }
    }
    return last;
}

template< typename Iterator, typename ValueType = typename Iterator::value_type>
static constexpr inline Iterator amazingFind(Iterator first, Iterator last, const ValueType& value)
{
    for (auto It = first; It != last; It++) 
    {
        if (*reinterpret_cast<typename Iterator::value_type*>((char*)(void*)std::addressof(*It)) == *reinterpret_cast<typename Iterator::value_type*>((char*)(void*)std::addressof(value))) 
        {
            return first;
        }
    }
    return last;
}

int main()
{
    std::vector<int> a = {0, 1, 2, 3};
    amazingFindIf(a.begin(), a.end(), [](int){return true;});
    amazingFindIfNot(a.begin(), a.end(), [](int){return true;});
    amazingFind(a.begin(), a.end(), 3);
    return 0;
}