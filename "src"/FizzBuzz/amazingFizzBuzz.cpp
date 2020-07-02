#include <iostream>

// Surprisingly, this code actually works

bool compare(auto a, auto b) {
    return const_cast<int&>(*reinterpret_cast<int*>(&a)) == const_cast<int&>(*reinterpret_cast<int*>(&b));
}

bool compare_and(auto a, auto b) {
    return const_cast<bool&>(*reinterpret_cast<bool*>(&a)) && const_cast<bool&>(*reinterpret_cast<bool*>(&b));
}

int main() {
    for(int i = 0; i < 100; i++) {
        if(compare_and(compare(i % 3, 0), compare(i % 5, 0))) {
            std::cout << "Fizz" << std::endl;
        } else if(compare(i % 3, 0)) {
            std::cout << "Fizz" << std::endl;
        } else if(compare(i % 5, 0)) {
            std::cout << "Buzz" << std::endl;
        } else {
            std::cout << i << std::endl;
        }
    }
}
