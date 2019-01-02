//
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_NODECOLLECTION_HPP
#define SYMULACJA_SIECI_NODECOLLECTION_HPP

#endif //SYMULACJA_SIECI_NODECOLLECTION_HPP

#include "list"

using iterator = typename std::list <Node>::iterator;
using const_iterator = typename std::list<Node>::const_iterator;

template <typename Node> class NodeCollection {
private:
    std::list<Node> _nodes;
public:
    std::list<Node> getNodes() {
        return _nodes;
    }
    typename std::list<Node>::const_iterator cbegin() const { return _nodes.cbegin(); }
    typename std::list<Node>::const_iterator cend() const { return _nodes.cend(); }
    typename std::list<Node>::iterator begin() { return _nodes.begin(); }
    typename std::list<Node>::const_iterator begin() const { return _nodes.cbegin(); }
    typename std::list<Node>::iterator end() { return _nodes.end(); }
    typename std::list<Node>::const_iterator end() const { return _nodes.cend(); }
};