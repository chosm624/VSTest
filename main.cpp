#include <iostream>
#include "sum.h"
using namespace std;

int main(int, char**){
    cout << "Hello, from VSTest!\n";
    int resualt = sum(1,1);
    cout << "Sum: " << resualt << endl;
    resualt = nus(1,1);
    cout << "Nus: " << resualt << endl;
    return 0;
}
