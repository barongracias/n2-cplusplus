#include <iostream>
using namespace std;

#define ASSERT(x) if( !(x) )\
{\
    cout << "Test " << #x << " failed at line " \
    << __LINE__ \
    << " in " << __FILE__ << endl; \
}

int main(void) {
    int a=5;
    ASSERT(a == 5);
    ASSERT(a == 6);

    return 0;
}