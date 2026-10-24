#ifndef HELLO_WORLD_HH
#define HELLO_WORLD_HH

#include <iostream>

namespace hello_world {

template <typename T>
class HelloWorld {
public:
    void sayHello();
    void sayGoodbye();
};

}  // namespace hello_world

#endif  // HELLO_WORLD_HH