#include "dijkstra.h"

std::vector<int> minDistance;
std::vector<int> previous;

// bool Comparison::operator() (const int & indexOne, const int & indexTwo) {
//     return minDistance[indexOne] > minDistance[indexTwo];
// }

struct {
    bool operator() (const int & indexOne, const int & indexTwo) {
        return minDistance[indexOne] > minDistance[indexTwo];
    }
} custom;

void Dijkstra::dijkstra(Graph graph, int startIndex) {

    if (!graph.teamExists(startIndex)) {
        std::cout << "\x1b[1m" << "Start index is invalid!" << "\x1b[0m" << std::endl;
        return;
    }

    minDistance.resize(0);
    previous.resize(0);
    
    for (unsigned i = 0; i < graph.getTeams().size(); i++) {
        minDistance.push_back(100000);
        previous.push_back(-1);
    }
    minDistance[startIndex] = 0;

    // std::priority_queue<int, std::vector<int>, Comparison> priorityQueue;
    // for (unsigned j = 0; j < graph.getTeams().size(); j++) {
    //     priorityQueue.push(j);
    // }

    std::vector<int> priorityQueue;
    for (unsigned j = 0; j < graph.getTeams().size(); j++) {
        priorityQueue.push_back(j);
    }
    std::sort(priorityQueue.begin(), priorityQueue.end(), custom);

    std::vector<bool> visitedVertices;
    visitedVertices.resize(graph.getTeams().size());

    while (priorityQueue.size() != 0) {

        int current = priorityQueue[priorityQueue.size() - 1];
        priorityQueue.pop_back();
        visitedVertices[current] = true;

        for (int connectedTeam : graph.getTeam(current).edges) {
            int edgeWeight = 1;
            if (edgeWeight + minDistance[current] < minDistance[connectedTeam]) {
                minDistance[connectedTeam] = edgeWeight + minDistance[current];
                previous[connectedTeam] = current;
            }
        }

        std::sort(priorityQueue.begin(), priorityQueue.end(), custom);

    }

    // while (!priorityQueue.empty()) {

    //     int current = priorityQueue.top();
    
    //     priorityQueue.pop();
    //     visitedVertices[current] = true;

    //     for (int connectedTeam : graph.getTeam(current).edges) {
    //         if (!visitedVertices[connectedTeam]) {
    //             int edgeWeight = 1;
    //             if (edgeWeight + minDistance[current] < minDistance[connectedTeam]) {
    //                 minDistance[connectedTeam] = edgeWeight + minDistance[current];
    //                 previous[connectedTeam] = current;
    //             }
    //         }
    //     }

    // }

}

void Dijkstra::dijkstra(Graph graph, std::string startTeam) {

    if (!graph.teamExists(startTeam)) {
        std::cout << "\x1b[1m" << "Start team does not exist! Check that you are using the correct team name." << "\x1b[0m" << std::endl;
        return;
    }

    int startIndex = graph.getIndex(startTeam);

    minDistance.resize(0);
    previous.resize(0);
    
    for (unsigned i = 0; i < graph.getTeams().size(); i++) {
        minDistance.push_back(100000);
        previous.push_back(-1);
    }
    minDistance[startIndex] = 0;

    // std::priority_queue<int, std::vector<int>, Comparison> priorityQueue;
    // for (unsigned j = 0; j < graph.getTeams().size(); j++) {
    //     priorityQueue.push(j);
    // }
    std::vector<int> priorityQueue;
    for (unsigned j = 0; j < graph.getTeams().size(); j++) {
        priorityQueue.push_back(j);
    }
    std::sort(priorityQueue.begin(), priorityQueue.end(), custom);

    std::vector<bool> visitedVertices;
    visitedVertices.resize(graph.getTeams().size());

    while (priorityQueue.size() != 0) {

        int current = priorityQueue[priorityQueue.size() - 1];
        priorityQueue.pop_back();
        visitedVertices[current] = true;

        for (int connectedTeam : graph.getTeam(current).edges) {
            int edgeWeight = 1;
            if (edgeWeight + minDistance[current] < minDistance[connectedTeam]) {
                minDistance[connectedTeam] = edgeWeight + minDistance[current];
                previous[connectedTeam] = current;
            }
        }

        std::sort(priorityQueue.begin(), priorityQueue.end(), custom);

    }

    // while (!priorityQueue.empty()) {

    //     int current = priorityQueue.top();
    //     priorityQueue.pop();
    //     visitedVertices[current] = true;

    //     for (int connectedTeam : graph.getTeam(current).edges) {
    //         int edgeWeight = 1;
    //         if (edgeWeight + minDistance[current] < minDistance[connectedTeam]) {
    //             minDistance[connectedTeam] = edgeWeight + minDistance[current];
    //             previous[connectedTeam] = current;
    //         }
    //     }

    // }

}

std::vector<int> Dijkstra::shortestPath(Graph graph, int startTeam, int endTeam) {

    if (!graph.teamExists(startTeam) && !graph.teamExists(endTeam)) {
        std::cout << "\x1b[1m" << "Start and end indeces are invalid!" << "\x1b[0m" << std::endl;
        return std::vector<int>();
    } else if (!graph.teamExists(startTeam)) {
        std::cout << "\x1b[1m" << "Start index is invalid!" << "\x1b[0m" << std::endl;
        return std::vector<int>();
    } else if (!graph.teamExists(endTeam)) {
        std::cout << "\x1b[1m" << "End index is invalid!" << "\x1b[0m" << std::endl;
        return std::vector<int>();
    }

    dijkstra(graph, startTeam);
    
    std::vector<int> path;
    if (previous[endTeam] == -1) {
        return std::vector<int>();
    }

    int current = endTeam;
    while (current != startTeam) {
        path.push_back(current);
        current = previous[current];
    }
    path.push_back(startTeam);

    std::reverse(path.begin(), path.end());

    return path;

}

std::vector<int> Dijkstra::shortestPath(Graph graph, std::string startName, std::string endName) {

    if (!graph.teamExists(startName) && !graph.teamExists(endName)) {
        std::cout << "\x1b[1m" << "Start and end teams do not exist! Check that you are using the correct team names." << "\x1b[0m" << std::endl;
        return std::vector<int>();
    } else if (!graph.teamExists(startName)) {
        std::cout << "\x1b[1m" << "Start team does not exist! Check that you are using the correct team name." << "\x1b[0m" << std::endl;
        return std::vector<int>();
    } else if (!graph.teamExists(endName)) {
        std::cout << "\x1b[1m" << "End team does not exist! Check that you are using the correct team name." << "\x1b[0m" << std::endl;
        return std::vector<int>();
    }

    int startTeam = graph.getIndex(startName);
    int endTeam = graph.getIndex(endName);

    dijkstra(graph, startName);
    
    std::vector<int> path;
    if (previous[endTeam] == -1) {
        return std::vector<int>();
    }

    int current = endTeam;
    while (current != startTeam) {
        path.push_back(current);
        current = previous[current];
    }
    path.push_back(startTeam);

    std::reverse(path.begin(), path.end());

    return path;

}

int Dijkstra::shortestPathLength(Graph graph, int startTeam, int endTeam) {

    std::vector<int> path = shortestPath(graph, startTeam, endTeam);
    return path.size() - 1;

}

int Dijkstra::shortestPathLength(Graph graph, std::string startTeam, std::string endTeam) {

    std::vector<int> path = shortestPath(graph, startTeam, endTeam);
    return path.size() - 1;

}

void Dijkstra::printShortestPath(Graph graph, int startTeam, int endTeam) {

    std::vector<int> path = shortestPath(graph, startTeam, endTeam);
    std::string startName = graph.getTeamName(startTeam);
    std::string endName = graph.getTeamName(endTeam);

    if (path.size() == 0) {
        std::cout << "No path found between " << startTeam << " and " << endTeam << "!" << std::endl;
        return;
    }

    for (unsigned i = 0; i < path.size(); i++) {
        std::cout << graph.getTeamName(path[i]) << std::endl;
    }

}

void Dijkstra::printShortestPath(Graph graph, std::string startName, std::string endName) {

    std::vector<int> path = shortestPath(graph, startName, endName);

    if (path.size() == 0) {
        std::cout << "No path found between " << startName << " and " << endName << "!" << std::endl;
        return;
    }

    for (unsigned i = 0; i < path.size(); i++) {
        std::cout << graph.getTeamName(path[i]) << std::endl;
    }

}

void Dijkstra::shortestPathToFile(Graph graph, std::string startName, std::string endName) {

    std::vector<int> path = shortestPath(graph, startName, endName);

    std::ofstream ofs;
    ofs.open("path.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    std::ofstream myFile;
    myFile.open("path.txt");

    if (path.size() == 0) {
        myFile << startName << "\n";
        myFile << endName << "\n";
        myFile.close();
        return;
    }

    for (unsigned i = 0; i < path.size(); i++) {
        myFile << graph.getTeamName(path[i]) << "\n";
    }
    myFile.close();
}