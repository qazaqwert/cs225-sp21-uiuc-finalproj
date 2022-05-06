#include "../catch/catch.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "../graph.h"
#include "../IDDFS.h"

/////////////////////////////////////////
// TESTING SAMPLE IDDFS IMPLEMENTATION //
/////////////////////////////////////////

TEST_CASE("IDDFS can go from team 1 to team 6 in a max of 3 steps") {

    // NOTE: team 1 corresponds to index 0, etc...

    Graph graph("sample_games.csv", "teams.csv");
    IDDFS iddfs;
    int startTeam = 0;
    int endTeam = 5;
    int maxSteps = 3;
    std::pair<bool, std::vector<std::string>> outputPair = iddfs.run(graph, startTeam, endTeam, maxSteps);
    REQUIRE( get<0>(outputPair) );
    REQUIRE( get<1>(outputPair)[0] == graph.getTeamName(startTeam) ); // starts at team 1
    REQUIRE( get<1>(outputPair)[1] == graph.getTeamName(2) ); // passes through team 3
    REQUIRE( get<1>(outputPair)[2] == graph.getTeamName(endTeam) ); // reaches team 6
    // iddfs.printPath(graph, startTeam, endTeam, maxSteps);

}

TEST_CASE("IDDFS can go from team 1 to team 6 in a max of 2 steps") {

    // NOTE: team 1 corresponds to index 0, etc...

    Graph graph("sample_games.csv", "teams.csv");
    IDDFS iddfs;
    int startTeam = 0;
    int endTeam = 5;
    int maxSteps = 2;
    std::pair<bool, std::vector<std::string>> outputPair = iddfs.run(graph, startTeam, endTeam, maxSteps);
    REQUIRE( get<0>(outputPair) );
    REQUIRE( get<1>(outputPair)[0] == graph.getTeamName(startTeam) ); // starts at team 1
    REQUIRE( get<1>(outputPair)[1] == graph.getTeamName(2) ); // passes through team 3
    REQUIRE( get<1>(outputPair)[2] == graph.getTeamName(endTeam) ); // reaches team 6

}

TEST_CASE("IDDFS cannot go from team 1 to team 6 in a max of 1 steps") {

    // NOTE: team 1 corresponds to index 0, etc...

    Graph graph("sample_games.csv", "teams.csv");
    IDDFS iddfs;
    int startTeam = 0;
    int endTeam = 5;
    int maxSteps = 1;
    std::pair<bool, std::vector<std::string>> outputPair = iddfs.run(graph, startTeam, endTeam, maxSteps);
    REQUIRE( !get<0>(outputPair) );
    REQUIRE( get<1>(outputPair).size() == 0 );

}

TEST_CASE("IDDFS can go from team 1 to team 1 in 0 steps") {

    // NOTE: team 1 corresponds to index 0, etc...

    Graph graph("sample_games.csv", "teams.csv");
    IDDFS iddfs;
    int startTeam = 0;
    int endTeam = 0;
    int maxSteps = 0;
    std::pair<bool, std::vector<std::string>> outputPair = iddfs.run(graph, startTeam, endTeam, maxSteps);
    REQUIRE( get<0>(outputPair) );
    REQUIRE( get<1>(outputPair)[0] == graph.getTeamName(startTeam) ); // starts and ends at team 1

}

TEST_CASE("IDDFS cannot go from team 9 to team 1 in any number of steps") {

    // NOTE: team 1 corresponds to index 0, etc...

    Graph graph("sample_games.csv", "teams.csv");
    IDDFS iddfs;
    int startTeam = 8;
    int endTeam = 0;
    int maxSteps = 100;
    std::pair<bool, std::vector<std::string>> outputPair = iddfs.run(graph, startTeam, endTeam, maxSteps);
    REQUIRE( !get<0>(outputPair) );
    REQUIRE( get<1>(outputPair).size() == 0 ); // starts at team 1

}