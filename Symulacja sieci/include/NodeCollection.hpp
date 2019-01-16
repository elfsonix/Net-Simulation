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

    iterator findById(ElementID nodeID){
        NodeCollection::iterator it = std::find_if(_nodes.begin(), _nodes.end(), [nodeID](Node& node){return node.getID()==nodeID;});
        return it;
    }

    constIterator cfindById(ElementID nodeID) const {
        NodeCollection::constIterator it = std::find_if(_nodes.begin(), _nodes.end(), [nodeID](Node& node){return node.getID()==nodeID;});
        return it;
    }


    void removeById(ElementID nodeID){
        NodeCollection::iterator it = findById(nodeID);
        if(it!=_nodes.end()){
            _nodes.erase(it);
        }
    }
};

#endif //SYMULACJA_SIECI_NODECOLLECTION_HPP
// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)