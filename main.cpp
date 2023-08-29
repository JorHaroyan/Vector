#include "vector.h"

#include <iostream>

int main() {
    Vector<int> v;
    
    v.PushBack(19);
    v.PushBack(34);
    v.PushBack(787);
    Vector<int> v2 = std::move(v);
    
    v2.PrintVector();

    Vector<int> v3;
    v3.PushBack(444);
    Vector<int> v4;
    v4 = std::move(v3);

    v4.PrintVector();
    /*
    v.PrintVector();
    v.PushBack(10);
    v.PrintVector();
    std::cout << v.PopBack() << std::endl;
    v.PrintVector();
    */
    return 0;
}




















