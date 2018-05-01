#include <iostream>
#include "vector.h"

vector<int> fill(std::istream& is) {
    vector<int> vector1;
    for(int x; is>>x;) vector1.push_back(x);
    return vector1;
}

int main() {
    vector<int> vector12(2);
   
    // move 
    vector<int> vector42 = fill(std::cin);
    std::cout <<  vector42 << std::endl;

    return 0;
}