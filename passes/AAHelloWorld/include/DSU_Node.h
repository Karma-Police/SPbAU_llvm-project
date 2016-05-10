#ifndef DSU_NODE_H
#define DSU_NODE_H

#include <string>

class DSU_Node {
public:
    const int   id;

private:
    DSU_Node *  parent;
    int         size;

public:
    static DSU_Node * unionSets(DSU_Node * a, DSU_Node * b);
    static bool areUnited(DSU_Node * a, DSU_Node * b);
    DSU_Node(int id);
    DSU_Node *  getRoot();
    std::string toString();

};

#endif
