// avl.h
// Zachary Friedland
// K-AVL Tree header file

#ifndef AVL_H
#define AVL_H

#include <tuple>
using namespace std;

class AVL {
    public:
        AVL();
        ~AVL();
        bool insert();
        bool remove();
        bool search();
        bool approximateSearch();
        void preOrderPrint();
        void inOrderPrint();

    
    private:
        struct Node {
            tuple<int, int> data;

            Node* left;
            Node* right;
            Node* parent;

            Node(tuple<int,int> num = make_tuple(0, 0)) :
                         data(num), left(nullptr), right(nullptr), parent(nullptr) { }
        };
        
        Node* root;
        void clear(Node* n);
        bool insert(int whole, int fraction);
        Node* getPredecessorNode();
        Node* getSuccessorNode();

};




#endif