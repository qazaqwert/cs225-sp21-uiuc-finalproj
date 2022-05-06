#pragma once

#include <iterator>
#include <queue>

#include "Traversal.h"
#include "graph.h"

class BFS : public Traversal {

    public:

        BFS(const Graph & inputGraph, int inputStart);
        Traversal::Iterator begin();
        Traversal::Iterator end();

        void add(int inputNode);
        int pop();
        int peek() const;
        bool empty() const;

        Graph getGraph();
        int getStart();

    private:

        std::queue<int> q;
        Graph storedGraph;
        int startNode;

};