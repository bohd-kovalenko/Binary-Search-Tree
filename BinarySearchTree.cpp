#include <iostream>
#include "BInarySearchTree.h"

void BinarySearchTree::insert(const Data &data) {
    if (size() == 0) {
        head = new Node();
        head->data = data;
        elementsCount++;
        return;
    }
    Node *prev = head, *curr = prev->data > data ? prev->left : prev->right;
    if (!find(data)) {
        while (true) {
            if (curr == nullptr) {
                curr = new Node();
                curr->data = data;
                if (prev->data > data) prev->left = curr;
                else prev->right = curr;
                elementsCount++;
                return;
            }
            prev = curr;
            if (curr->data > data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
}

bool BinarySearchTree::find(const Data &data) {
    Node *currNode = head;
    while (currNode != nullptr) {
        if (currNode->data == data) {
            return true;
        } else if (currNode->data > data) {
            currNode = currNode->left;
        } else {
            currNode = currNode->right;
        }
    }
    return false;
}


int BinarySearchTree::size() {
    return elementsCount;
}

int BinarySearchTree::height() {
    return internalHeightFinder(head);
}

void BinarySearchTree::print() {
    internalInorderTraversal(head);
}

vector<Data> BinarySearchTree::findInRange(Data minObject, Data maxObject) {
    vector<Data> result;
    internalFindInRange(head, minObject, maxObject, result);
    return result;
}


BinarySearchTree::BinarySearchTree() {
    elementsCount = 0;
}

void BinarySearchTree::erase(const Data &data) {
    head = internalErase(head, data);
}

Node *BinarySearchTree::internalErase(Node *node, const Data &data) {
    if (node == nullptr) {
        return nullptr;
    } else if (data < node->data) {
        node->left = internalErase(node->left, data);
    } else if (data > node->data) {
        node->right = internalErase(node->right, data);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
            elementsCount--;
        } else if (node->left == nullptr) {
            Node *temp = node;
            node = node->right;
            delete temp;
            elementsCount--;
        } else if (node->right == nullptr) {
            Node *temp = node;
            node = node->left;
            delete temp;
            elementsCount--;
        } else {
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = internalErase(node->right, temp->data);
        }
    }
    return node;
}

Node *BinarySearchTree::findMin(Node *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

int BinarySearchTree::internalHeightFinder(Node *biggerSubtree) {
    if (biggerSubtree == nullptr) return 0;
    else {
        int leftHeight = internalHeightFinder(biggerSubtree->left);
        int rightHeight = internalHeightFinder(biggerSubtree->right);
        return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
}

void BinarySearchTree::internalFindInRange(Node *subtree, Data minObject, Data maxObject, vector<Data> &result) {
    if (subtree == nullptr) return;
    else if (minObject > subtree->data) internalFindInRange(subtree->right, minObject, maxObject, result);
    else if (maxObject < subtree->data) internalFindInRange(subtree->left, minObject, maxObject, result);
    else {
        result.push_back(subtree->data);
        internalFindInRange(subtree->right, minObject, maxObject, result);
        internalFindInRange(subtree->left, minObject, maxObject, result);
    }
}

void BinarySearchTree::internalInorderTraversal(Node *currNode) {
    if (currNode == nullptr) return;
    else {
        internalInorderTraversal(currNode->left);
        cout << currNode->data << endl;
        internalInorderTraversal(currNode->right);
    }
}

Node::~Node() {
    right = nullptr;
    left = nullptr;
}
