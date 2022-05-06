#pragma once
#include "graph.h"
#include <utility>
#include <string>
#include <vector>

using namespace std;

class IDDFS {

    public:

        pair<bool, vector<string>> run(Graph graph, int startTeam, int endTeam, int maxStep);
        vector<string> returnPath(Graph graph, vector<int> previous, int startTeam, int endTeam);
        bool dfs(Graph graph, int startTeam, int endTeam, int maxSteps, vector<int> & previous);
        void printPath(Graph graph, int startTeam, int endTeam, int maxSteps);

};