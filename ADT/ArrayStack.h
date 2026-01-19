#ifndef BALL_ARRSTACK_H
#define BALL_ARRSTACK_H
#include <iostream>
#include <array>

template<std::size_t size>
struct Stack {
    std::array<int, size> array;
    int counter = 0;

    Stack() {
        array.fill(-1);
    }

    void Push(int element) {
        // 检查有没有超过数组上限
        if (counter >= array.size()) {
            std::cout << "Space enough!" << std::endl;
            return;
        }
        array[counter ++] = element;
    }

    int Top() {
        return array[counter];
    }

    void Pop() {
        counter --;
        array[counter] = -1;
    }

    void PrintAll() {
        for (auto e: array) {
            std::cout << e << std::endl;
        }
    }
};

#endif