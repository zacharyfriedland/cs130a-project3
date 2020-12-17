// avl.h
// Zachary Friedland
// K-AVL Tree header file

#ifndef AVL_H
#define AVL_H

#include <tuple>
#include <string>
using namespace std;

class AVL {
    public:
        AVL();      // constructor
        ~AVL();     // destructor
        bool insert(tuple<int, int> target);
        bool remove(tuple<int, int> target);
        bool search(tuple<int, int> target);
        void approximateSearch(tuple<int, int> target);
        void printPreOrder();
        void printInOrder();

    
    private:
        struct Node {
            tuple<int, int> data;
            int height;

            Node* left;
            Node* right;
            Node* parent;

            Node(tuple<int,int> num = make_tuple(0, 0)) :
                         data(num), height(1), left(nullptr), right(nullptr), parent(nullptr) { }
        };
        
        Node* root;
        void clear(Node* n);
        bool insert(tuple<int, int> target, Node* n);
        bool search(tuple<int, int> target, Node* n);
        void approximateSearch(tuple<int, int> target, Node* n, double &minDiff, tuple<int, int> &minDiffNodeValue);
        Node* getNode(tuple<int, int> target, Node* n);
        Node* getPredecessorNode(tuple<int, int> target);
        Node* getSuccessorNode(tuple<int, int> target);
        void printPreOrder(Node* n);
        void printInOrder(Node* n);
        void rotate(Node* n);

};




#endif