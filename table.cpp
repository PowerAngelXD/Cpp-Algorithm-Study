#include <iostream>
#include <chrono>

struct ListNode {
    int val = 0;
    ListNode* nextPtr = nullptr;
};

void print(ListNode head) {
    std::cout<<"value: "<<head.val<<std::endl;
    if (head.nextPtr) {
        print(*head.nextPtr);
    }
}

void printA(ListNode head) {
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

void test_list() {
    ListNode head;
    head.val = 1;
    ListNode* cur = &head;
    for (int i = 2; i <= 10; ++i) {
        cur->nextPtr = new ListNode{i};
        cur = cur->nextPtr;
    }
    cur->nextPtr = &head;
    std::cout << "T1:" << std::endl;
    printA(head);
    
    insert(head, 9999);

    std::cout << "T2: " << std::endl;
    printA(head);

    std::cout << isCircle_fsPtr(head) << std::endl;
}

// ----------------------------

int main() {
    test_list();

}