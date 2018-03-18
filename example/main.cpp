
#include "platform/platform.hpp"

#include <iostream>

int main() {
    std::cout << "compiler_id of current translation: " << platform::compiler << '\n'
              << "compiler_id of link target:         " << platform::link::compiler << '\n';
}
