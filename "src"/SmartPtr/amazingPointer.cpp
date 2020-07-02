#include <memory>
#include <iostream>

using namespace std; // to avoid namespace pollution

template<typename T>
struct AmazingPointer {
    AmazingPointer(const AmazingPointer& other) {
        (*this) = other;
    }

    AmazingPointer& operator=(const AmazingPointer& other) {
        (*this) = std::move(const_cast<AmazingPointer&>(other));
        return *this;
    }

    AmazingPointer(AmazingPointer&& other) {
        (*this) = other;
    }

    AmazingPointer& operator=(AmazingPointer&& other) {
        pointer = auto_ptr<T>(reinterpret_cast<T*>(other.pointer.get()));
        return *this;
    }

    AmazingPointer(): pointer{} {}
    AmazingPointer(void* t): pointer(reinterpret_cast<T*>(t)){}

    void* GETDAPOINTER() {
        return reinterpret_cast<void*>(pointer.get());
    }

private:
    auto_ptr<T> pointer;
};

struct PtrableType {
    PtrableType(const PtrableType&) {
        cout << "I'm being copied!" << endl;
    }

    PtrableType& operator=(const PtrableType&) {
        cout << "I'm being copied!" << endl;
        return *this;
    }

    PtrableType(PtrableType&&) {
        cout << "I'm being moved!" << endl;
    }

    PtrableType& operator=(PtrableType&&) {
        cout << "I'm being moved!" << endl;
        return *this;
    }

    PtrableType() {
        cout << "I'm being constructed!" << endl;
    }

    ~PtrableType() {
        cout << "I'm being destructed!" << endl;
    }
};

void DoStuff(AmazingPointer<PtrableType>&& stuff) {
    std::cout << reinterpret_cast<unsigned long long int>(stuff.GETDAPOINTER()) << std::endl;
}

int main() {
    AmazingPointer<PtrableType> ptr(new PtrableType);
    for(int i = 0; i < 20; i++) {
        AmazingPointer<PtrableType> ptr(reinterpret_cast<AmazingPointer<PtrableType>&>(ptr));
        DoStuff(std::move(ptr));
    }
}
