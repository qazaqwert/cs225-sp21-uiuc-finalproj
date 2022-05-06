#include <iostream>

#include "graph.h"
#include "Traversal.h"
#include "readFromFile.hpp"
#include "BFS.h"
#include "dijkstra.h"
#include "IDDFS.h"
#include <cstdlib>

int main() {
    
    // // Example for printing all results by team:  
    // Graph graph("games.csv", "teams.csv");
    // graph.printDefeatedTeams();

    // // Example for printing the shortest path from Illinois to Gonzaga: 
    // Graph graph("games.csv", "teams.csv");  
    // Dijkstra dijkstra;  
    // dijkstra.printShortestPath(graph, "Illinois", "Gonzaga");

    // // Example for visualizing the shortest path from Illinois to Gonzaga: 
    // Graph graph("games.csv", "teams.csv");
    // Dijkstra dijkstra;
    // dijkstra.shortestPathToFile(graph, "Illinois", "Gonzaga"); 
    // std::string command = "python visualization.py";
    // // if you have networkx installed for python, you can
    // // uncomment the line below to produce a visualization :)
    // std::system(command.c_str());

    // // Example for how to run a BFS traversal starting with Illinois:
    // Graph graph("games.csv", "teams.csv"); 
    // int startTeam = graph.getIndex("Illinois");  
    // BFS bfs(graph, startTeam);

    // // Example for how to run an IDDFS traversal starting from team 1 to team 6:  
    // Graph graph("sample_games.csv", "teams.csv");  
    // int startTeam = 0; // team 1
    // int endTeam = 5; // team 6
    // int maxSteps = 2;
    // iddfs(graph, startTeam, endTeam, maxSteps);
    // // this particular example ^ should return true

    return 0;

}
