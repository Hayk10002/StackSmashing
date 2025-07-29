#include <iostream>
#include <cstdio>

void f() {
    std::cout << "Hijacked!" << std::endl;
}

void vulnerable() {
    std::cout << "Leaked f() address: " << (void*)f << std::endl;
    char buffer[16];
    std::cout << "Enter input: ";
    fgets(buffer, 200, stdin); // overflow
    std::cout << "Done" << std::endl;
}

int main() {
    vulnerable();
    std::cout << "Returned from vulnerable()\n";
    return 0;
}
