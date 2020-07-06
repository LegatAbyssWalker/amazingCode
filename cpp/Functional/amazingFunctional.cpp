// Code by Anonymous

#include <tuple>
#include <stdexcept>

template<typename> class amazingFunction;

template<typename Result,typename... Arguments>
class amazingFunction<Result(Arguments...)> 
{
protected:
    Result(*FuncImpl)(Arguments...)=nullptr;

    struct Useless{};

    std::tuple<Arguments...> FuncArgs;
public:
    amazingFunction(){}

    template<typename Func,typename std::enable_if<!std::is_integral<Func>{},Useless>::type=Useless()>
    amazingFunction(Func&& Function)
    {
        FuncImpl=Function;
    }

    amazingFunction(const amazingFunction& Other)
    {
        FuncImpl=Other.FuncImpl;
    }

    amazingFunction& operator=(const amazingFunction& Other)
    {
        FuncImpl=Other.FuncImpl;
    }

    template<typename Func,typename std::enable_if<!std::is_integral<Func>{},Useless >::type=Useless()>
    amazingFunction& operator=(Func&& Function)
    {
        FuncImpl=Function;
    }

    void bind(Arguments&&... Args)
    {
        FuncArgs=std::make_tuple(Args...);
    }

    Result operator()(Arguments&&... Args)
    {
        if(FuncImpl==nullptr)
            throw std::runtime_error("Bad function");
        return FuncImpl(Args...);
    }

    template<typename std::enable_if<(sizeof...(Arguments)!=0),Useless>>
    Result operator()()
    {
        if(FuncImpl==nullptr)
            throw std::runtime_error("Bad function");
        auto [Args]=std::apply([](auto&&... Args){return std::forward_as_tuple(Args...);}, FuncArgs);
        return FuncImpl(Args);
    }
};

int main()
{
    amazingFunction<int()> f=[]{return 4;};
    auto var=f();
    return 0;
}