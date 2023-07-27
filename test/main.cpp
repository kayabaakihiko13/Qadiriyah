#include<iostream>
#include "../libs/math/math.hh"
#include "../libs/math/trigonometric.hh"
#include "../libs/math/static.hh"
#include <cmath>
#include <vector>

int main() {
    std::vector<int>data={1,2,4,1,2,2};
    std::cout<<"mode:"<<_mode(data)<<std::endl;
    return 0;
}