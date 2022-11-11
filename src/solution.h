#ifndef WEEK6_TREE_H

#include <iostream>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int _key) : key(_key), left(nullptr), right(nullptr) {}
};

int countElements(Node*);
int countLeafs(Node*);
int sumElements(Node*);
int sumElementsAtLevel(Node*, unsigned);
int height(Node*);
bool isBST(Node*);
bool isSymmetric(Node*, Node*);
bool isSymmetric(Node*);
void Inorder(Node*, std::vector<int>&);
void PreOrder(Node*, std::vector<int>&);
void PostOrder(Node*, std::vector<int>&);

#define WEEK6_TREE_H

#endif //WEEK6_TREE_H
