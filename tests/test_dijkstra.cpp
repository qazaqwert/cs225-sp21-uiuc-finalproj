#include "../catch/catch.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "../graph.h"
#include "../dijkstra.h"

//////////////////////////////////////////////
// TESTING SAMPLE DIJKSTRA'S IMPLEMENTATION //
//////////////////////////////////////////////

TEST_CASE("Team 1 directly beat team 2") {

    // NOTE: team 1 corresponds to index 0, etc...

    Graph graph("sample_games.csv", "teams.csv");
    int teamOne = 0;
    int teamTwo = 1;
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( shortestPath[0] == teamOne );
    REQUIRE( shortestPath[1] == teamTwo );
    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == 1 );

}

TEST_CASE("Team 1 indirectly beat team 7") {

    // NOTE: team 1 corresponds to index 0, etc...

    Graph graph("sample_games.csv", "teams.csv");
    int teamOne = 0;
    int teamTwo = 6;
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( shortestPath[0] == teamOne );
    REQUIRE( shortestPath[1] == 1 );
    REQUIRE( shortestPath[2] == teamTwo );
    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == 2 );

}

TEST_CASE("Team 1 indirectly beat team 8") {

    // NOTE: team 1 corresponds to index 0, etc...
    // shorter path is: team 1 -> team 9 -> team 8
    // longer path is: team 1 -> team 4 -> team 5 -> team 8

    Graph graph("sample_games.csv", "teams.csv");
    int teamOne = 0;
    int teamTwo = 7;
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( shortestPath[0] == teamOne );
    REQUIRE( shortestPath[1] == 8 );
    REQUIRE( shortestPath[2] == teamTwo );
    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == 2 );

}

TEST_CASE("Team 6 indirectly beat team 9") {

    // NOTE: team 1 corresponds to index 0, etc...
    // shortest path is: team 6 -> team 4 -> team 5 -> team 8 -> team 9

    Graph graph("sample_games.csv", "teams.csv");
    int teamOne = 5;
    int teamTwo = 8;
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( shortestPath[0] == teamOne );
    REQUIRE( shortestPath[1] == 3 );
    REQUIRE( shortestPath[2] == 4 );
    REQUIRE( shortestPath[3] == 7 );
    REQUIRE( shortestPath[4] == teamTwo );
    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == 4 );

}

TEST_CASE("Team 8 indirectly beat team 12") {

    // NOTE: team 1 corresponds to index 0, etc...
    // correct path is: team 8 -> team 10 -> team 12
    // incorrect path is: team 8 -> team 11 -> team 12

    Graph graph("sample_games.csv", "teams.csv");
    int teamOne = 7;
    int teamTwo = 11;
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( shortestPath[0] == teamOne );
    REQUIRE( shortestPath[1] == 9 );
    REQUIRE( shortestPath[2] == teamTwo );
    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == 2 );

}

TEST_CASE("Team 8 did not (indirectly or directly) beat team 1") {

    // NOTE: team 1 corresponds to index 0, etc...

    Graph graph("sample_games.csv", "teams.csv");
    int teamOne = 8;
    int teamTwo = 0;
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == -1 );

}

//////////////////////////////////////////////
// TESTING ACTUAL DIJKSTRA'S IMPLEMENTATION //
//////////////////////////////////////////////

TEST_CASE("Illinois directly beat Michigan") {

    Graph graph("games.csv", "teams.csv");
    int teamOne = graph.getIndex("Illinois");
    int teamTwo = graph.getIndex("Michigan");
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( shortestPath[0] == teamOne );
    REQUIRE( shortestPath[1] == teamTwo );
    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == 1 );

}

TEST_CASE("Chicago_St beat no one") {

    Graph graph("games.csv", "teams.csv");
    int teamOne = graph.getIndex("Chicago_St");
    int teamTwo = graph.getIndex("Illinois");
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == -1 );

}

TEST_CASE("Indiana indirectly beat Illinois") {

    Graph graph("games.csv", "teams.csv");
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, "Indiana", "Illinois");

    REQUIRE( shortestPath[0] == graph.getIndex("Indiana") );
    REQUIRE( shortestPath[1] == graph.getIndex("Maryland") );
    REQUIRE( shortestPath[2] == graph.getIndex("Illinois") );
    REQUIRE( dijkstra.shortestPathLength(graph, "Indiana", "Illinois") == 2 );

}

TEST_CASE("Illinois beat Indiana") {

    Graph graph("games.csv", "teams.csv");
    int teamOne = graph.getIndex("Illinois");
    int teamTwo = graph.getIndex("Indiana");
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( shortestPath[0] == graph.getIndex("Illinois") );
    REQUIRE( shortestPath[1] == graph.getIndex("Indiana") );
    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == 1 );

}

TEST_CASE("Georgia_Tech indirectly beat E_Illinois") {

    Graph graph("games.csv", "teams.csv");
    std::string teamOne = "Georgia_Tech";
    std::string teamTwo = "E_Illinois";
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( shortestPath[0] == graph.getIndex("Georgia_Tech") );
    REQUIRE( shortestPath[1] == graph.getIndex("Clemson") );
    REQUIRE( shortestPath[2] == graph.getIndex("Morehead_St") );
    REQUIRE( shortestPath[3] == graph.getIndex("E_Illinois") );
    REQUIRE( dijkstra.shortestPathLength(graph, teamOne, teamTwo) == 3 );

}

TEST_CASE("Illinois indirectly beat Gonzaga") {

    Graph graph("games.csv", "teams.csv");
    std::string teamOne = "Illinois";
    std::string teamTwo = "Gonzaga";
    Dijkstra dijkstra;
    std::vector<int> shortestPath = dijkstra.shortestPath(graph, teamOne, teamTwo);

    REQUIRE( shortestPath[0] == graph.getIndex("Illinois") );
    REQUIRE( shortestPath[shortestPath.size() - 1] == graph.getIndex("Gonzaga") );

}

//////////////////////////////////////////////////
// LONG TEST CASES OF DIJKSTRA'S IMPLEMENTATION //
//////////////////////////////////////////////////

// NOTE: THESE WERE COMMENTED OUT BECAUSE THEY TAKE A FEW SECONDS TO RUN (TESTING EVERY TEAM)

// TEST_CASE("Almost all or all teams (besides Chicago_St) should have a path to beating Illinois") {

//     // THIS TEST CASE IS BASED OFF OF KNOWING THAT THERE IS A FULL CIRCLE OF SUCK BETWEEN 342 TEAMS

//     Graph graph("games.csv", "teams.csv");
//     Dijkstra dijkstra;
//     int Illinois = graph.getIndex("Illinois");
//     int count = 0;

//     for (unsigned teamTwo = 0; teamTwo < graph.getTeams().size(); teamTwo++) {
//         if (dijkstra.shortestPathLength(graph, teamTwo, Illinois) >= 1) {
//             count++;
//         }
//     }

//     REQUIRE( count >= 342 );

// }

// TEST_CASE("Illinois should have a path to beating almost all or all teams") {

//     // THIS TEST CASE IS BASED OFF OF KNOWING THAT THERE IS A FULL CIRCLE OF SUCK BETWEEN 342 TEAMS

//     Graph graph("games.csv", "teams.csv");
//     Dijkstra dijkstra;
//     int Illinois = graph.getIndex("Illinois");
//     int count = 0;
    
//     for (unsigned teamTwo = 0; teamTwo < graph.getTeams().size(); teamTwo++) {
//         if (dijkstra.shortestPathLength(graph, Illinois, teamTwo) >= 1) {
//             count++;
//         }
//     }

//     REQUIRE( count >= 342 );

// }