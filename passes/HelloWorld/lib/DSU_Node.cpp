#include "DSU_Node.h"
#include <cassert>
#include <algorithm>

DSU_Node * DSU_Node::unionSets(DSU_Node * a, DSU_Node * b) {
    DSU_Node * A = a->getRoot();
    DSU_Node * B = b->getRoot();
    assert((A != NULL) && (B != NULL));
    if (A == B) {
        return NULL;
    }
    if (B->size < A->size) {
        std::swap(A, B);
    }
    A->parent = B;
    B->size += A->size;
    return B;
}

bool DSU_Node::areUnited(DSU_Node * a, DSU_Node * b) {
    DSU_Node * A = a->getRoot();
    DSU_Node * B = b->getRoot();
    return A == B;
}

DSU_Node::DSU_Node(int id) : id(id) , parent(this), size(1) { }

DSU_Node * DSU_Node::getRoot() {
    if (parent != this) {
        parent = parent->getRoot();
    }
    return parent;
}

std::string DSU_Node::toString() {
    std::string result = "";
    result += "DSU_Node : ID = " + std::to_string(id);
    result += ", parent's ID = " + std::to_string(parent->id);
    result += ", size = " + std::to_string(size);
    result += ";\n";
    return result;
}

