#ifndef CASO_7_NODEINITIALIZER_H
#define CASO_7_NODEINITIALIZER_H

#include "iostream"
#include "NodeInitializerInterface.h"
#define AMOUNT_OF_NODES 27

class NodeInitializer: public NodeInitializerInterface {

public:
    std::vector<Node*> nodes;

public:
    ~NodeInitializer() {
        for(auto &current: nodes)
            delete current;
    }

    std::vector<Node*> createNodes() override {

        nodes.reserve(AMOUNT_OF_NODES); // preallocate space

        for (int i = 0; i < AMOUNT_OF_NODES; ++i)
            nodes.push_back(new Node(i));

        return nodes;
    }

    void linkNodes(std::vector<Node*> &pNodes) override {
        auto firstElement = pNodes.begin();

        // not proud of this :,)
        {
            (*(firstElement+0))->insert(*(firstElement + 1), 'A');
            (*(firstElement+0))->insert(*(firstElement + 3), '2');
            (*(firstElement+0))->insert(*(firstElement + 9), 'K');
            (*(firstElement+2))->insert(*(firstElement + 5), '2');
            (*(firstElement+2))->insert(*(firstElement + 1), 'B');
            (*(firstElement+2))->insert(*(firstElement + 11), 'K');
            (*(firstElement+4))->insert(*(firstElement + 3), 'A');
            (*(firstElement+4))->insert(*(firstElement + 1), '2');
            (*(firstElement+4))->insert(*(firstElement + 7), '1');
            (*(firstElement+4))->insert(*(firstElement + 5), 'B');
            (*(firstElement+4))->insert(*(firstElement + 13), 'K');
            (*(firstElement+6))->insert(*(firstElement + 3), '1');
            (*(firstElement+6))->insert(*(firstElement + 7), 'A');
            (*(firstElement+6))->insert(*(firstElement + 15), 'K');
            (*(firstElement+8))->insert(*(firstElement + 7), 'B');
            (*(firstElement+8))->insert(*(firstElement + 5), '1');
            (*(firstElement+8))->insert(*(firstElement + 17), 'K');
            (*(firstElement+10))->insert(*(firstElement + 1), 'K');
            (*(firstElement+10))->insert(*(firstElement + 9), 'A');
            (*(firstElement+10))->insert(*(firstElement + 11), 'B');
            (*(firstElement+10))->insert(*(firstElement + 19), 'F');
            (*(firstElement+10))->insert(*(firstElement + 13), '2');
            (*(firstElement+12))->insert(*(firstElement + 9), '2');
            (*(firstElement+12))->insert(*(firstElement + 3), 'K');
            (*(firstElement+12))->insert(*(firstElement + 15), '1');
            (*(firstElement+12))->insert(*(firstElement + 13), 'A');
            (*(firstElement+12))->insert(*(firstElement + 21), 'F');
            (*(firstElement+14))->insert(*(firstElement + 13), 'B');
            (*(firstElement+14))->insert(*(firstElement + 11), '2');
            (*(firstElement+14))->insert(*(firstElement + 5), 'K');
            (*(firstElement+14))->insert(*(firstElement + 17), '1');
            (*(firstElement+14))->insert(*(firstElement + 23), 'F');
            (*(firstElement+16))->insert(*(firstElement + 17), 'B');
            (*(firstElement+16))->insert(*(firstElement + 15), 'A');
            (*(firstElement+16))->insert(*(firstElement + 7), 'K');
            (*(firstElement+16))->insert(*(firstElement + 13), '1');
            (*(firstElement+16))->insert(*(firstElement + 25), 'F');
            (*(firstElement+18))->insert(*(firstElement + 19), 'A');
            (*(firstElement+18))->insert(*(firstElement + 21), '2');
            (*(firstElement+18))->insert(*(firstElement + 9), 'F');
            (*(firstElement+20))->insert(*(firstElement + 19), 'B');
            (*(firstElement+20))->insert(*(firstElement + 23), '2');
            (*(firstElement+20))->insert(*(firstElement + 11), 'F');
            (*(firstElement+22))->insert(*(firstElement + 23), 'B');
            (*(firstElement+22))->insert(*(firstElement + 19), '2');
            (*(firstElement+22))->insert(*(firstElement + 13), 'F');
            (*(firstElement+22))->insert(*(firstElement + 21), 'A');
            (*(firstElement+22))->insert(*(firstElement + 25), '1');
            (*(firstElement+24))->insert(*(firstElement + 15), 'F');
            (*(firstElement+24))->insert(*(firstElement + 25), 'A');
            (*(firstElement+24))->insert(*(firstElement + 21), '1');
            (*(firstElement+26))->insert(*(firstElement + 17), 'F');
            (*(firstElement+26))->insert(*(firstElement + 25), 'B');
            (*(firstElement+26))->insert(*(firstElement + 23), '1');

        }

        for(auto &current: pNodes) // insert in both direcctions
            for (auto &arc: current->relations)
                arc.second->insert(current, arc.first);
    }


};

#endif //CASO_7_NODEINITIALIZER_H
