#include <iostream>
#include <memory>

// Surprisingly, this code actually works

bool compare(auto a, auto b) {
    return const_cast<int&>(*reinterpret_cast<int*>(&a)) == const_cast<int&>(*reinterpret_cast<int*>(&b));
}

bool compare_and(auto a, auto b) {
    return const_cast<bool&>(*reinterpret_cast<bool*>(&a)) && const_cast<bool&>(*reinterpret_cast<bool*>(&b));
}

void Print(std::shared_ptr<std::string>&& thing2print) {
    std::cout << *(thing2print.get()) << std::endl;
}

int main() {
    for(int i = 0; i < 100; i++) {
        if(compare_and(compare(i % 3, 0), compare(i % 5, 0))) {
            Print(std::move(std::make_shared<std::string>("Fizz")));
        } else if(compare(i % 3, 0)) {
            Print(std::move(std::make_shared<std::string>("Buzz")));
        } else if(compare(i % 5, 0)) {
            Print(std::move(std::make_shared<std::string>("FizzBuzz")));
        } else {
            Print(std::move(std::make_shared<std::string>(std::to_string(i))));
        }
    }
}
