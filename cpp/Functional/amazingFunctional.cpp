// Code by Anonymous

#include <tuple>
#include <utility>
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

    typename std::enable_if<(sizeof...(Arguments)!=0),Result>::type operator()()
    {
        if(FuncImpl==nullptr)
            throw std::runtime_error("Bad function");

        return std::apply([this](auto&&... args)
        { 
            return FuncImpl(args...); 
        }, FuncArgs);
    }
};

int main()
{
    amazingFunction<int(int, int)> f=[](int a, int b){return a + b;};
    f.bind(3, 4);
    auto var = f();
    return 0;
}