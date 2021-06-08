#ifndef CASO_7_NODE_H
#define CASO_7_NODE_H

#include <map>

struct Node {

public:
    int nodeNumber;
    std::map<char, Node*> relations;

    explicit Node(int pNodeNumber): nodeNumber(pNodeNumber) {}

    void insert(Node* node, const char& relation) {
        this->relations[relation] = node;
    }


};

#endif //CASO_7_NODE_H
