#ifndef LAB2_4_BINARYSEARCHTREE_H
#define LAB2_4_BINARYSEARCHTREE_H

#endif //LAB2_4_BINARYSEARCHTREE_H

#include <vector>
#include "Data.h"

struct Node {
    Data data;
    Node *left;
    Node *right;

    virtual ~Node();
};

struct BinarySearchTree {
private:
    Node *head;
    int elementsCount;

public:
    BinarySearchTree();

    void insert(const Data &data);

    bool find(const Data &data);

    void erase(const Data &data);

    int size();

    int height();

    void print();

    vector<Data> findInRange(Data minObject, Data maxObject);

    Node *findMin(Node *node);

private:
    Node *internalErase(Node *node, const Data &data);

    int internalHeightFinder(Node *biggerSubtree);

    void internalFindInRange(Node *subtree, Data minObject, Data maxObject, vector<Data> &result);
    void internalInorderTraversal(Node* currNode);

};
