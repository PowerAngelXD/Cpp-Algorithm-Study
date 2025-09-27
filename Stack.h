#ifndef BALL_STACK_H
#define BALL_STACK_H

#include <iostream>

struct Node {
    int val;
    Node* next = nullptr;

    Node(int v): val(v) {}
    void append(int v) {
        next = new Node(v);
    }
};

struct Stack {
    Node* root = nullptr; // 栈底

    Stack(int root_val) {
        root = new Node(root_val);
    }
    Stack()=default;

    int Top() {
        Node* ptr = root;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void Pop() {
        Node* ptr = root;
        while (ptr->next->next != nullptr) {
            ptr = ptr->next;
        }
        delete ptr->next;
        ptr->next = nullptr;
    }

    Stack& Push(int v) {
        Node* ptr = root;

        if (!ptr) {
            ptr = new Node(v);
            root = ptr;
            return *this;
        }

        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new Node(v);

        return *this;
    }

    void PrintAll() {
        Node* ptr = root;
        if (!ptr) {
            std::cout << "EMPTY STACK!!!" <<std::endl;
            return;
        }
        while (ptr != nullptr) {
            std::cout << "Stack Element: " << ptr->val << std::endl;
            ptr = ptr->next;
        }
    }
};

void test_stack() {
    std::cout<< "NOW STACK TEST-------------------"<<std::endl;
    Stack stack;
    stack.PrintAll();
    std::cout<<"test sep----------"<<std::endl;
    stack.Push(2).Push(3).Push(10).Push(99);
    stack.PrintAll();
    std::cout<<"test sep----------"<<std::endl;
    stack.Pop();
    stack.PrintAll();
}

#endif