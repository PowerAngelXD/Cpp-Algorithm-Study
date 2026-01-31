#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include "ADT/BinaryHeap.h"

int main() {
    std::vector<int> tmp = {1,2,3,5,7,9,4,11};
    Heap heap;
    heap.build(tmp);
    heap.print();
}