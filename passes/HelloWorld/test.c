#include <stdio.h>

void sayHelloHoney() {
    printf("Ooooh, hello!!!\n");
}

void putSmile() {
    printf(":)");
}

int main() {
    printf("Hello, world!\n");
    sayHelloHoney();
    int i = 0;
    for (int i = 0; i < 10; i++) {
        putSmile();
    }
}
