#include <stdio.h>

void f1(void) {
    for(int i = 0; i >= 0; i++) {
    }
}

void f2(void) {
    puts("Formatting /dev/sda1...");
}

void (*p1)(void) = f1;
void (*p2)(void) = f2;

int main(void) {
    p1();
    return 0;
}

// empty output without O2 optim
// with O2 optim:
// [1]    50923 trace trap  ./IntOverflow2