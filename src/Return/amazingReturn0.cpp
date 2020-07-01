#include <memory>

class Test {
public:
    constexpr virtual inline void deleteThis(void) const volatile {
        delete (void*)const_cast<Test*>(this);
    }
};

int main() {
    std::auto_ptr<Test> test(std::unique_ptr<Test>(new Test).get());
    test->deleteThis();
}
