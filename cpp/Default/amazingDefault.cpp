// Code by DeKrain

#include <utility>
#include <tuple>
#include <cstdio>

struct default_t {};
template <typename F, typename Result, typename... Args>
struct defaultcall_t;

template <std::size_t Id, typename F, typename Result, typename... Args, typename T>
constexpr auto default_cast(defaultcall_t<F, Result, Args...> const&, T&& x);
template <std::size_t Id, typename F, typename Result, typename... Args>
constexpr auto default_cast(defaultcall_t<F, Result, Args...> const& c, default_t);

template <typename F, typename Result, typename... Args>
struct defaultcall_t {
  std::tuple<Args...> default_args;
  F func;
  constexpr defaultcall_t(F&& func, Args&&... args) : default_args(std::forward<Args>(args)...), func(std::forward<F>(func)) {}
  
  private:
  template <typename... U, std::size_t... Seq>
  constexpr Result operator()(std::index_sequence<Seq...>, U&&... args) const {
    return func(default_cast<Seq, F, Result, Args...>(*this, std::forward<U>(args))...);
  }

  public:
  template <typename... U>
  constexpr Result operator()(U&&... args) const {
    return operator()(std::index_sequence_for<Args...>(), std::forward<U>(args)...);
  }

};


template <std::size_t Id, typename F, typename Result, typename... Args, typename T>
constexpr auto default_cast(defaultcall_t<F, Result, Args...> const&, T&& x) {return std::forward<T>(x); }
template <std::size_t Id, typename F, typename Result, typename... Args>
constexpr auto default_cast(defaultcall_t<F, Result, Args...> const& c, default_t) {return std::get<Id>(c.default_args); }

//=====================

int bop(int a, int b) noexcept
{
    return a + b;
}

static defaultcall_t<int(*)(int, int), int, int, int> bopper(&bop, 3, 4);

int main() {
    printf("%d\n", bopper(default_t(), default_t()));
    printf("%d\n", bopper(default_t(), 1));
    printf("%d\n", bopper(2, default_t()));
    printf("%d\n", bopper(2, 1));

    return 0;
}