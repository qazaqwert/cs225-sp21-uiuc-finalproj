#pragma once

#include <iterator>
#include <queue>
#include <map>

#include "graph.h"

class Traversal {

    public:

        class Iterator : std::iterator<std::forward_iterator_tag, Graph::GraphNode> {

            public:

                Iterator();
                Iterator(Traversal * inputTraversal);

                Iterator & operator++();
                int operator*();
                bool operator!=(const Iterator &other);

            private:

                Traversal * traversal;
                Graph storedGraph;
                int current;
                int start;
                std::map<int, bool> visitedMap;

                std::queue<int> nodesToAdd;
                void addNodes(int nodeIndex);

        };

        virtual Iterator begin() = 0;
        virtual Iterator end() = 0;
        virtual void add(int t) = 0;
        virtual int pop() = 0;
        virtual int peek() const = 0;
        virtual bool empty() const = 0;
        virtual Graph getGraph() = 0;
        virtual int getStart() = 0;

    private:

};