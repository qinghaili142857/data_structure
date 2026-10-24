#include "hello_world.hh"
namespace hello_world {

template <typename T>
void HelloWorld<T>::sayHello() {
    std::cout << "Hello, World!" << '\n';
}

template <typename T>
void HelloWorld<T>::sayGoodbye() {
    std::cout << "Goodbye, World!" << '\n';
}

}  // namespace hello_world

int main() {
    hello_world::HelloWorld<int> hello;
    hello.sayHello();
    hello.sayGoodbye();
    return 0;
}