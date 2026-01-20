#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include "ADT/AVL.h"

int main() {
    std::vector<int> tmp = {1,2,3,5,7,9,4,11};
    AVLNode* tree = nullptr;

    for (size_t i = 0; i < tmp.size(); ++i) {
        tree = AVLNode::insert(tree, tmp[i]);
    }

    tree->print();

    auto start1 = std::chrono::high_resolution_clock::now();
    std::cout << tree->has(4) << std::endl;
    auto end1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);


    auto start2 = std::chrono::high_resolution_clock::now();
    for (auto i: tmp) {
        if (i == 4) {
            std::cout << "1" << std::endl;
            break;
        }
    }
    auto end2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

    std::cout << "AVL: " << duration1.count() << " us" << std::endl;
    std::cout << "Normal: " << duration2.count() << " us" << std::endl;
}