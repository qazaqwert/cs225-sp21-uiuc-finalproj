#include <iterator>
#include <queue>
#include <map>

#include "graph.h"
#include "Traversal.h"

Traversal::Iterator::Iterator() {
    traversal = NULL;
    storedGraph = Graph();
}

Traversal::Iterator::Iterator(Traversal * inputTraversal) {
    if (inputTraversal != NULL) {
        traversal = inputTraversal;
        storedGraph = inputTraversal->getGraph();
        start = inputTraversal->getStart();
        current = inputTraversal->getStart();
    } else {
        traversal = NULL;
        storedGraph = Graph();
    }
}

void Traversal::Iterator::addNodes(int nodeIndex) {

    // if (storedGraph.getTeams()[nodeIndex] == ) {
    //     return;
    // }

    for (unsigned i = 0; i < storedGraph.getTeam(nodeIndex).edges.size(); i++) {
        int graphIndex = storedGraph.getTeam(nodeIndex).edges[i];
        if (!visitedMap[graphIndex]) {
            nodesToAdd.push(graphIndex);
        }
    }

}

Traversal::Iterator & Traversal::Iterator::operator++() {

    if (!traversal->empty()) {

        current = traversal->pop();
        visitedMap[current] = true;

        addNodes(current);
        while (!nodesToAdd.empty()) {
            traversal->add(nodesToAdd.front());
            nodesToAdd.pop();
        }

        bool exit = false;
        while(!(traversal->empty()) && !exit) {
            if (!visitedMap[traversal->peek()]) {
                exit = true;
            } else {
                traversal->pop();
            }
        }

        if (!traversal->empty()) {
            current = traversal->peek();
        } else {
            // current = int();
            traversal = NULL;
        }

    }

    return *this;

}

int Traversal::Iterator::operator*() {
    return current;
}

bool Traversal::Iterator::operator!=(const Traversal::Iterator & other) {

  bool thisEmpty = false;
  bool otherEmpty = false;

  if (traversal == NULL) {
    thisEmpty = true;
  }

  if (other.traversal == NULL) {
    otherEmpty = true;
  }

  if (!thisEmpty) {
    thisEmpty = traversal->empty();
  }

  if (!otherEmpty) {
    otherEmpty = other.traversal->empty();
  }

  if (thisEmpty && otherEmpty) {
    return false;
  } else if ((!thisEmpty) && (!otherEmpty)) {
    return (traversal != other.traversal);
  } else {
    return true;
  }
  
}