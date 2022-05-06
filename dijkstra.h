#pragma once

#include "graph.h"
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

// struct Comparison {

//     bool operator() (const int & indexOne, const int & indexTwo);

// };

class Dijkstra {

    public:

        void dijkstra(Graph graph, int startTeam);
        std::vector<int> shortestPath(Graph graph, int startTeam, int endTeam);
        void printShortestPath(Graph graph, int startTeam, int endTeam);
        int shortestPathLength(Graph graph, int startTeam, int endTeam);

        void dijkstra(Graph graph, std::string startTeam);
        std::vector<int> shortestPath(Graph graph, std::string startTeam, std::string endTeam);
        void printShortestPath(Graph graph, std::string startTeam, std::string endTeam);
        int shortestPathLength(Graph graph, std::string startTeam, std::string endTeam);

        void shortestPathToFile(Graph graph, std::string startName, std::string endName);

    private:

        // std::vector<int> minDistance;
        // std::vector<int> previous;

};
