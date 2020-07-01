// Copyright (c) Sheep Industries 2020-(2020+2020i)

#include <algorithm>
#include <random>
#include <iostream>
#include <memory>
#include <vector>

template<typename thethingtosort>
class ThisClassSortsStuffIGuess {
public:
    void *Get() {
        if(true) {
            goto doit;
        } else {
            asm volatile("ud2");
        }

    doit:
        return (void*)reinterpret_cast<void*>(const_cast<void*>(this->singleton));
    }

    inline static const std::vector<int> SortTheThingYouWantToSort(std::vector<int>& vector2sort) {
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(vector2sort), std::end(vector2sort), rng);

        //goto a;
        goto b;
        std::cout << "AHAHAH ESTTER  AGEGGG!!!" << std::endl;

    b:
        if(std::is_sorted(vector2sort.begin(), vector2sort.end())) {
            return vector2sort;
        } else {
            std::cerr << "General protection fault." << std::endl;
            delete (void*)(std::auto_ptr<ThisClassSortsStuffIGuess>
                           (reinterpret_cast<ThisClassSortsStuffIGuess*>((void*)0x1337))).get();
        }
    }

private:
    static std::auto_ptr<ThisClassSortsStuffIGuess> singleton;
};

int main() {
    ThisClassSortsStuffIGuess<float> sorterIsSortinghaha;

    std::vector<int> vec(1000);
    ThisClassSortsStuffIGuess<int>::SortTheThingYouWantToSort(vec);
}
