#include <iostream>
#include <cstdio>

void f() {
    std::cout << "Hijacked!\n";
}

void vulnerable() {
    std::cout << "Leaked f() address: " << (void*)f << "\n";
    char buffer[16];
    std::cout << "Enter input: ";
    fgets(buffer, 200, stdin); // overflow
    printf("Input: %s\n", buffer);
}

int main() {
    vulnerable();
    std::cout << "Returned from vulnerable()\n";
    return 0;
}
