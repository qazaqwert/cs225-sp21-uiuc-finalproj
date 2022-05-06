#include "graph.h"

// custom constructor for Graph class
Graph::Graph(const std::string & gameData, const std::string & teamsData) {
    //do the team resizing after doing filename shenanigans
    //std::cout << "hi 1" << std::endl;

    teamNames = getTeamList(teamsData);

    teamIndeces = getIndecesOfTeams(teamNames);

    //std::cout << "hi 2" << std::endl;

    teams.resize(teamNames.size());

    //std::cout << "hi 3" << std::endl;

    //it would appear we segfault here
    csvToTeams(teams, gameData);
    //std::cout << "hi 4" << std::endl;

    edgesToFile();
}

Graph::Graph() {
    // DO NOTHING FOR NOW
}

std::vector<Graph::GraphNode> Graph::getTeams() {
    return teams;
}

Graph::GraphNode Graph::getTeam(int index) {
    return teams[index];
}

std::vector<std::string> Graph::getTeamNames() {
    return teamNames;
}

std::string Graph::getTeamName(int index) {
    return teamNames[index];
}

std::vector<std::string> Graph::getTeamList(const std::string & filename) {
    std::vector<std::string> data = file_to_vector(filename);
    std::vector<std::string> names;

    for (std::string line : data) {
        //std::cout << line << std::endl;
        std::vector<std::string> lineData = splitTeams(line, ',');
        //std::cout << lineData[1] << std::endl;

        names.push_back(lineData[1]);

        // sets team name to exist

    }

    return names;
}

// std::map<std::string, int> Graph::getExistingTeams(std::vector<std::string> teamNamesList) {

//     std::map<std::string, int> returnMap;

//     for (std::string n : teamNamesList) {
//         returnMap[n] = 1;
//     }
//     return returnMap;

// }

std::map<std::string, int> Graph::getIndecesOfTeams(std::vector<std::string> teamList) {

    std::map<std::string, int> mapOfIndeces;

    for (unsigned i = 0; i < teamList.size(); i++) {
        mapOfIndeces[teamList[i]] = i;
    }

    return mapOfIndeces;

}

int Graph::getIndex(std::string teamName) {

    return teamIndeces[teamName];

}

void Graph::csvToTeams(std::vector<GraphNode> & t, const std::string & filename) {
    std::vector<std::string> data = file_to_vector(filename);
    //std::cout << data.size() << std::endl;
    //t.resize(data.size());

    // int i = 0;
    for (std::string line : data) {
        //std::cout << i << std::endl;
        //i++;
        std::vector<int> lineData = split(line, ',');
        // std::cout << lineData[0] << std::endl;
        // std::cout << lineData[1] << std::endl;
        // std::cout << lineData[2] << std::endl;
        // std::cout << lineData[3] << std::endl;
        // std::cout << "~~~~~~~~~" << std::endl;


        int team1 = lineData[2] - 1;
        int score1 = lineData[4];
        int team2 = lineData[5] - 1;
        int score2 = lineData[7];

        int winner = (score1 > score2) ? team1 : team2;
        int loser = (score1 > score2) ? team2 : team1;

        //std::cout << "hi 1" << std::endl;

        //if winning node has no outgoing edges, then it hasnt been created yet
        if (t[winner].edges.empty()) {
            GraphNode winningTeam;
            
            winningTeam.addEdge(loser);
            t[winner] = winningTeam;
        } 

        //else, check for dupes in edges. If we dont find a dupe, add edge

        else {
            bool found = false;
            for (int edge : t[winner].edges) {
                if (edge == loser) {
                    found = true;
                    break;
                }
            }

            //if we didnt find a dupe, add edge
            if (!found) {
                t[winner].addEdge(loser);
            }
        }

        // else {
        //     //node for winner does exist, so check if an edge exists.
        //     //i dont think we'll encounter a case here where size isn't
        //     //greater than 0, assuming this is implemented the way i intended.
        //     //rather than having a graph node with no edges, id rather the slot
        //     //just be null.
        //     //std::cout << "hi 2" << std::endl;
        //     if (t[winner].edges.size() != 0) {
        //         //std::cout << "hi 3" << std::endl;
        //         bool foundEdge = false;
        //         for (GraphEdge * ptr : t[winner]->edges) {
        //             //we found an edge to the losing team, so we stop
        //             //std::cout << ptr->endTeam << std::endl;

        //             if (ptr->endTeam == loser) {
        //                 std::cout << "hi 7" << std::endl;
        //                 foundEdge = true;
        //                 break;
        //             }
        //         }
        //         //if we didnt find edge, create and add one
        //         if (!foundEdge) {
        //             //std::cout << "hi 5" << std::endl;
        //             GraphEdge newEdge(loser);
        //             t[winner]->addEdge(&newEdge);
        //         }
        //     }
        // }
    }
}

/*
// custom constructor for GraphEdge subclass
Graph::GraphEdge::GraphEdge(int endTeam_) {
    endTeam = endTeam_;
}

// adds edge to graph node in GraphNode subclass
void Graph::GraphNode::addEdge(GraphEdge * edge_) {
    edges.push_back(edge_);
}
*/

void Graph::GraphNode::addEdge(int edge_) {
    edges.push_back(edge_);
}

void Graph::printDefeatedTeams() {

    int i = 0;
    for (Graph::GraphNode team : teams) {
        std::string out;
        unsigned j = 0;
        for (int edge : team.edges) {
            if (j == team.edges.size() - 1) {
                out += teamNames[edge];
            } else {
                out += teamNames[edge] + ", ";
            }
            j++;
        }
        std::cout << "\x1b[1m" << getTeamName(i) << " beat:" << "\x1b[0m" << std::endl;
        std::cout << out << std::endl;
        std::cout << "--------" << std::endl;
        i++;
    }

}

bool Graph::teamExists(std::string teamName) {
    
    if (getIndex(teamName) == 0 && teamName != teamNames[0]) {
        return false;
    }
    return true;

}

bool Graph::teamExists(int teamIndex) {

    int size = teams.size();
    if (teamIndex < 0 || teamIndex >= size) {
        return false;
    }
    return true;

}

void Graph::edgesToFile() {
    std::ofstream ofs;
    ofs.open("edges.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    std::ofstream myFile;
    myFile.open("edges.txt");
    for (int i = 0; i < int(teams.size()); i++) {
        for (int j = 0; j < int(teams[i].edges.size()); j++) {
            std::string line = teamNames[i] + ", " + teamNames[teams[i].edges[j]] + "\n";
            myFile << line;
        }
    }

    myFile.close();
}
