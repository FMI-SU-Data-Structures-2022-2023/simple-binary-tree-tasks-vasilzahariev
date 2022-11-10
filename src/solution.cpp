#include "solution.h"

int countElements(Node* tree) {
    if (!tree)
        return 0;

    return 1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node* tree) {
    if (!tree)
        return 0;
    else if (!tree->left && !tree->right)
        return 1;

    return (tree->left ? countLeafs(tree->left) : 0) + (tree->right ? countLeafs(tree->right) : 0);
}

int height(Node* tree) {
    if (!tree)
        return 0;

    return std::max(1 + height(tree->left), 1 + height(tree->right));
}

int sumElements(Node* tree) {
    if (!tree)
        return 0;

    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) {
    if (!tree)
        return 0;
    else if (level == 0)
        return tree->key;

    return sumElementsAtLevel(tree->left, level - 1) + sumElementsAtLevel(tree->right, level - 1);
}

bool isSymmetric(Node* left, Node* right) {
    if (!left && !right)
        return true;
    else if ((!left || !right) || left->key != right->key)
        return false;

    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

bool isSymmetric(Node* tree) {
    if (!tree)
        return true;

    return isSymmetric(tree->left, tree->right);
}

bool isBST(Node* tree) {
    std::vector<int> elements;

    Inorder(tree, elements);

    for (std::size_t index = 1; index < elements.size(); ++index) {
        if (elements[index - 1] > elements[index]) {
            return false;
        }
    }

    std::cout << std::endl;

    return true;
}

void Inorder(Node* tree, std::vector<int>& result) {
    if (!tree)
        return;

    Inorder(tree->left, result);
    result.push_back(tree->key);
    Inorder(tree->right, result);
}

void PreOrder(Node* tree, std::vector<int>& result) {
    if (!tree)
        return;

    PreOrder(tree->left, result);
    result.push_back(tree->key);
    PreOrder(tree->right, result);
}

void PostOrder(Node* tree, std::vector<int>& result) {
    if (!tree)
        return;

    PostOrder(tree->left, result);
    PostOrder(tree->right, result);
    result.push_back(tree->key);
}
