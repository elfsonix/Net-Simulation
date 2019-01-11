// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_NODECOLLECTION_HPP
#define SYMULACJA_SIECI_NODECOLLECTION_HPP

#include <list>
#include "Package.hpp"


template <typename Node> class NodeCollection {
private:
    std::list<Node> _nodes;
public:
    using iterator = typename std::list <Node>::iterator;
    using constIterator = typename std::list<Node>::const_iterator;
    std::list<Node> getNodes() {
        return _nodes;
    }
    constIterator cbegin() const { return _nodes.cbegin(); }
    constIterator cend() const { return _nodes.cend(); }
    iterator begin() { return _nodes.begin(); }
    constIterator begin() const { return _nodes.cbegin(); }
    iterator end() { return _nodes.end(); }
    constIterator end() const { return _nodes.cend(); }
    void add(const Node& node) {

    }

    iterator findById(ElementID nodeId) const {
        return 1;
    }
    constIterator cfindById(ElementID nodeId) const {
        return 1;
    }
    void removeById(ElementID nodeID) {

    }
};

#endif //SYMULACJA_SIECI_NODECOLLECTION_HPP
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)