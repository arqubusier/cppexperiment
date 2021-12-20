// See chapter 14 of Jason Turner's C++ best practises
#include <type_traits>
#include <iostream>
const int *e1() {return nullptr;};
const int i{1};
const int &e2() {return i;};

int main() {
    {
        const auto val = e1();
        std::cout << "e1 " <<std::is_same_v<decltype(val), int const* const> << std::endl;
    }
    {
        const auto val = e2();
        std::cout << "e2 " <<std::is_same_v<decltype(val), const int> << std::endl;
    }
    {
        const auto *val = e1();
        std::cout << "e3 " <<std::is_same_v<decltype(val), int const*> << std::endl;
    }
    {
        const auto &val = e2();
        std::cout << "e4 " <<std::is_same_v<decltype(val), int const&> << std::endl;
    }
    {
        const auto &val = e1();
        std::cout << "e5 " <<std::is_same_v<decltype(val), int const* const&> << std::endl;
    }
    {
        // const auto &&val = e2(); // cannot bind l-value to r-value
    }
}