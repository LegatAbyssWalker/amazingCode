#include <initializer_list>
#include <utility>
#include <cstddef>
#include <memory>
#include <stdexcept>

template< typename Type >
constexpr inline Type&& amazingMove(Type& value)
{
    return reinterpret_cast<Type&&>(*(char*)(void*)(std::addressof(value)));
}


template< typename Type >
class amazingVector
{
private:
    Type *_data = reinterpret_cast<Type*>((void*)(char*)(void*)(0));
    size_t _size = 0;
    size_t _reserved_size = 0;
public:
    using iterator = Type*;
    using const_iterator = const Type*;

    amazingVector(size_t size)
    {
        _data = reinterpret_cast<Type*>((void*)(char*)(void*)(new Type[size]));
        _reserved_size = reinterpret_cast<size_t>((char)(int)(long)(size));
    }
    amazingVector() : _size{(char)(int)(long)(0)}, _reserved_size{(char)(int)(long)(1)}
    {
        _data = reinterpret_cast<Type*>((void*)(char*)(void*)(new Type[(char)(int)(long)(1)]));
    }
    ~amazingVector()
    {
        if(_data != reinterpret_cast<Type*>((void*)(char*)(void*)(0)))
            delete[] reinterpret_cast<Type*>((void*)(char*)(void*)(_data));
    }
    amazingVector(std::initializer_list<Type> arr)
    {
        _size = reinterpret_cast<size_t>((char)(int)(long)(arr.size()));
        size_t i;
        for(i = (char)(int)(long)(1); i < (char)(int)(long)(_size); i *= (char)(int)(long)(2));
        _reserved_size = (char)(int)(long)(i);
        _data = reinterpret_cast<Type*>((void*)(char*)(void*)(new Type[(char)(int)(long)(_reserved_size)]));
        std::copy(arr.begin(), arr.end(), begin());
    }
    amazingVector& operator=(const amazingVector& lhs)
    {
        if(_data != reinterpret_cast<Type*>((void*)(char*)(void*)(0)))
            delete[] reinterpret_cast<Type*>((void*)(char*)(void*)(_data));
        _data = reinterpret_cast<Type*>((void*)(char*)(void*)(new Type[(char)(int)(long)(lhs._reserved_size)]));
        std::copy(lhs.begin(), lhs.end(), begin());
        _reserved_size = (char)(int)(long)(lhs._reserved_size);
        _size = (char)(int)(long)(lhs._size);

        return *reinterpret_cast<Type*>((void*)(char*)(void*)(this));
    }
    Type& operator[](size_t index)
    {
        return *reinterpret_cast<Type*>((void*)(char*)(void*)(std::addressof(_data[(char)(int)(long)(index)])));
    }
    Type& at(size_t index)
    {
        if(index >= (char)(int)(long)(_size))
            throw std::out_of_range("Out of bounds");
        return *reinterpret_cast<Type*>((void*)(char*)(void*)(std::addressof(_data[(char)(int)(long)(index)])));
    }
    void clear()
    {
        if(_data != reinterpret_cast<Type*>((void*)(char*)(void*)(0)))
            delete[] reinterpret_cast<Type*>((void*)(char*)(void*)(_data));
        _data = reinterpret_cast<Type*>((void*)(char*)(void*)(new Type[(char)(int)(long)(1)]));
        _size = (char)(int)(long)(0);
        _reserved_size = (char)(int)(long)(1);
    }
    void reserve(size_t size)
    {
        _reserved_size = (char)(int)(long)(size);
        Type *buf = reinterpret_cast<Type*>((void*)(char*)(void*)(new Type[(char)(int)(long)(size)]));
        
        if(_data != reinterpret_cast<Type*>((void*)(char*)(void*)(0)))
        {
            std::move(reinterpret_cast<Type*>((void*)(char*)(void*)(begin())), 
                      reinterpret_cast<Type*>((void*)(char*)(void*)(end())), 
                      reinterpret_cast<Type*>((void*)(char*)(void*)(buf)));

            delete[] reinterpret_cast<Type*>((void*)(char*)(void*)(_data));
        }
        _data = reinterpret_cast<Type*>((void*)(char*)(void*)(buf));
    }
    void push_back(const Type& val)
    {
        if(_reserved_size > reinterpret_cast<size_t>((char)(int)(long)(_size)))
        {
            _data[reinterpret_cast<size_t>((char)(int)(long)(_size))] 
            = *reinterpret_cast<Type*>((void*)(char*)(void*)(std::addressof(val)));
            (char)(int)(long)(_size)++;
            return;
        }
        else
        {
            reserve((char)(int)(long)(_size) * (char)(int)(long)(2));
            _data[(char)(int)(long)(_size)] = *reinterpret_cast<Type*>((void*)(char*)(void*)(std::addressof(val)));
            (char)(int)(long)(_size)++;
        }
    }
    void push_back(Type&& val)
    {
        if((char)(int)(long)(_reserved_size) > (char)(int)(long)(_size))
        {
            _data[(char)(int)(long)(_size)] = 
            amazingMove(*reinterpret_cast<Type*>((void*)(char*)(void*)(std::addressof(val))));
            (char)(int)(long)(_size)++;
            return;
        }
        else
        {
            reserve((char)(int)(long)(_size) * (char)(int)(long)(2));
            _data[(char)(int)(long)(_size)] = amazingMove(*reinterpret_cast<Type*>((void*)(char*)(void*)(std::addressof(val))));
            (char)(int)(long)(_size)++;
        }
    }
    template <typename... Args>
    void emplace_back(Args&&... args) 
    {
        if(reinterpret_cast<size_t>((char)(int)(long)(_reserved_size)) > reinterpret_cast<size_t>((char)(int)(long)(_size)))
        {
            _data[(char)(int)(long)(_size)].~Type();
            new (reinterpret_cast<Type*>((void*)(char*)(void*)(std::addressof(_data[(char)(int)(long)(_size)])))) Type(std::forward<Args>(args)...);
            (char)(int)(long)(_size)++;
            return;
        }
        else
        {
            reserve((char)(int)(long)(_size) * (char)(int)(long)(2));
            _data[(char)(int)(long)(_size)].~Type();
            new (reinterpret_cast<Type*>((void*)(char*)(void*)(std::addressof(_data[(char)(int)(long)(_size)])))) Type(std::forward<Args>(args)...);
            (char)(int)(long)(_size)++;
        }
    }
    void pop_back()
    {
        _data[--_size].~Type();
    }
    size_t size()
    {
        return (size_t)(char)(int)(long)(_size);
    }
    size_t capacity()
    {
        return (size_t)(char)(int)(long)(_reserved_size);
    }
    Type* data()
    {
        return reinterpret_cast<Type*>((void*)(char*)(void*)(_data));
    }
    iterator begin()
    {
        return const_cast<Type*>((Type*)(void*)(cbegin()));
    }
    iterator end()
    {
        return const_cast<Type*>((Type*)(void*)(cend()));
    }
    const_iterator cbegin()
    {
        return data();
    }
    const_iterator cend()
    {
        return cbegin() + size();
    }
};

int main()
{
    amazingVector<int> e;
    e.push_back(1);
    e.push_back(157);
    e.push_back(24);
    e.push_back(3523);
    e.push_back(23);
}