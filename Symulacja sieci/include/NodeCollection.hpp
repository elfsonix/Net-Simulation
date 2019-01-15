// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Sonia on 2018-12-30.
//

#ifndef SYMULACJA_SIECI_NODECOLLECTION_HPP
#define SYMULACJA_SIECI_NODECOLLECTION_HPP

#include <list>
#include <algorithm>
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

    void add(const Node& node){
        _nodes.push_back(node);
    }

    iterator findById(ElementID nodeID) const {
        auto it = std::find(_nodes.begin(), _nodes.end(), nodeID);
        return NodeCollection::iterator();
    }

    constIterator cfindById(ElementID nodeID) const {
        nodeID++;
        return NodeCollection::constIterator();
    }
    //const auto it = std::find(_nodes.begin(), _nodes.end(), [nodeID](const auto& node){if(nodeID == node.getID()) return true; else return false;});
        //return it;

    void removeById(ElementID nodeID){
        nodeID++;
        //_nodes.remove_if([nodeID](const auto& id){if(id == nodeID) return true; else return false;}); //wszystkie o tym id czy pierwsza?
    }
};

#endif //SYMULACJA_SIECI_NODECOLLECTION_HPP
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)