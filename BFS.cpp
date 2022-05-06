#include <iterator>
#include <queue>

#include "Traversal.h"
#include "graph.h"
#include "BFS.h"

BFS::BFS(const Graph & inputGraph, int inputStart) {

    storedGraph = inputGraph;
    startNode = inputStart;
    q.push(startNode);

}

Graph BFS::getGraph() {
    return storedGraph;
}

int BFS::getStart() {
    return startNode;
}

Traversal::Iterator BFS::begin() {
    return Traversal::Iterator(this);
}

Traversal::Iterator BFS::end() {
    return Traversal::Iterator();
}

void BFS::add(int inputNode) {
    q.push(inputNode);
}

int BFS::pop() {

    int topNode = q.front();
    q.pop();
    return topNode;

}

int BFS::peek() const {
    return q.front();
}

bool BFS::empty() const {
    return q.empty();
}