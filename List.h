#ifndef BALL_LIST_H
#define BALL_LIST_H

#include <iostream>
#include <chrono>

struct ListNode {
    int val = 0;
    ListNode* nextPtr = nullptr;
};

bool isCircle_fsPtr(ListNode head) {
    auto fast_ptr = &head;
    auto slow_ptr = &head;
    while (fast_ptr && fast_ptr->nextPtr) {
        fast_ptr = fast_ptr->nextPtr->nextPtr;
        slow_ptr = slow_ptr->nextPtr;

        if (fast_ptr == slow_ptr) return true;
    }
    return false;
}


void print(ListNode head) {
    if (isCircle_fsPtr(head)) {
        std::cout<<"CircularList!"<<std::endl;
        return;
    }

    std::cout<<"value: "<<head.val<<std::endl;
    if (head.nextPtr) {
        print(*head.nextPtr);
    }
}

void printA(ListNode head) {
    if (isCircle_fsPtr(head)) {
        std::cout<<"CircularList!"<<std::endl;
        return;
    }

    std::cout << "value: " << head.val << std::endl;
    auto ptr = head.nextPtr;
    while(ptr) {
        std::cout<<"value: "<<ptr->val<<std::endl;
        ptr = ptr->nextPtr;
    }
}

void insert(ListNode &begin, int element) {
    auto after = begin.nextPtr;
    begin.nextPtr = new ListNode {element};
    begin.nextPtr->nextPtr = after;
}

ListNode* del(ListNode *begin, int target) {
    if (begin->val == target) {
        ListNode* temp = begin->nextPtr;
        delete begin;
        return temp;
    }
    auto prev = begin;
    auto ptr = begin->nextPtr;
    while (ptr) {
        if (ptr->val == target) {
            if (ptr->nextPtr == nullptr) {
                // 是尾节点
                delete ptr;
                return begin;
            }
            else {
                prev->nextPtr = ptr->nextPtr;
                delete ptr;
                return begin;
            }
        }
        prev = ptr;
        ptr = ptr->nextPtr;
    }

    return begin;
}

void test_list() {
    ListNode head;
    head.val = 1;
    ListNode* cur = &head;
    for (int i = 2; i <= 10; ++i) {
        cur->nextPtr = new ListNode{i};
        cur = cur->nextPtr;
    }
    std::cout << "T1:" << std::endl;
    auto begin = std::chrono::system_clock::now();
    print(head);
    auto end = std::chrono::system_clock::now();
    std::cout << "cost: " << std::chrono::duration<double, std::micro>(end - begin).count() << std::endl;

    std::cout << "T2: " << std::endl;
    auto begin1 = std::chrono::system_clock::now();
    printA(head);
    auto end1 = std::chrono::system_clock::now();
    std::cout << "cost: " << std::chrono::duration<double, std::micro>(end1 - begin1).count() << std::endl;

    del(&head, 4);
    printA(head);
}

#endif