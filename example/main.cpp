
#include "platform/platform.hpp"

#include <iostream>

int main() {
    std::cout << "build: " << platform::compiler << '\n'
              << "dependency: " << platform::link::compiler << '\n';
}
