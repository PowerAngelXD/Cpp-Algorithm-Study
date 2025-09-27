#ifndef BALL_TREE_H
#define BALL_TREE_H

#include <iostream>
#include <vector>

struct TreeNode {
    int val = 0;
    std::vector<TreeNode*> subs;

    TreeNode()=default;
    TreeNode(int v): val(v) {}

    TreeNode& addChild(int v) {
        subs.push_back(new TreeNode(v));
    }

    void preorderTraversal() {
        if (subs.empty())
            std::cout <<"("<< val <<")";
        else
            std::cout << val << ":{" ;

        for (auto node: subs) {
            node->preorderTraversal();
        }

        if (!subs.empty()) {
            std::cout << "}";
        }
    }

    void postorderTraversal() {
        for (auto node: subs) {
            node->postorderTraversal();
        }

        std::cout << val << std::endl;
    }
};

void test_normal_tree() {
    auto root = TreeNode();

    root.subs.push_back(new TreeNode(1));
    root.subs.push_back(new TreeNode(2));
    root.subs.push_back(new TreeNode(3));
    root.subs.push_back(new TreeNode(4));

    root.subs.at(0)->subs.push_back(new TreeNode(10));
    root.subs.at(0)->subs.push_back(new TreeNode(11));
    root.subs.at(0)->subs.push_back(new TreeNode(12));
    root.subs.at(1)->subs.push_back(new TreeNode(13));
    root.subs.at(1)->subs.push_back(new TreeNode(14));
    root.subs.at(3)->subs.push_back(new TreeNode(15));

    root.preorderTraversal();
    std::cout << std::endl;
    root.postorderTraversal();
}

struct BinaryNode {
    int val;
    BinaryNode* left = nullptr;
    BinaryNode* right = nullptr;

    BinaryNode(int v): val(v) {}

    void preorderTraversal() {
        if (this == nullptr) return;
        
        std::cout << "[" << val;

        left->preorderTraversal();
        right->preorderTraversal();
        std::cout<< "]";
    }
};

void BSTinsert(BinaryNode*& bin_tree, int element) {
    if (!bin_tree) {
        bin_tree = new BinaryNode(element);
        return;
    }

    if (bin_tree->val > element) {
        BSTinsert(bin_tree->left, element);
    }
    else {
        BSTinsert(bin_tree->right, element);
    }
}

void test_BST() {
    // 按照书p80的二叉搜寻树进行构造
    auto root = new BinaryNode(6);
    root->left = new BinaryNode(2);
    root->left->left = new BinaryNode(1);
    root->left->right = new BinaryNode(4);
    root->left->right->left = new BinaryNode(3);

    root->right = new BinaryNode(8);
    //
    BSTinsert(root, 19);
    BSTinsert(root, 5);
    root->preorderTraversal();
}

#endif