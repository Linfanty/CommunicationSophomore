#include<bits/stdc++.h>
using namespace std;

// TMP


template<int n>
struct fac{
    enum{ value = n * fac<n-1>::value };
};

template<>
struct fac<0> {
    enum{ value = 1};
};

void outOfMem() {
    cout << "memory error" << endl;
    abort();
}

int main() {
    //cout << fac<10>::value << endl;

    set_new_handler( outOfMem );
    int* p = new int[10000000000];
}
