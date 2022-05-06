#include "../catch/catch.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "../graph.h"

////////////////////////////////////////////////
// TESTING SAMPLE CSV TO GRAPH IMPLEMENTATION //
////////////////////////////////////////////////

TEST_CASE("Team 1 GraphNode inputted correctly") {

    // NOTE: team 1 corresponds to index 0

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 0;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {1, 2, 3, 8};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 1 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 2 GraphNode inputted correctly") {

    // NOTE: team 2 corresponds to index 1

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 1;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {6};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 2 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 3 GraphNode inputted correctly") {

    // NOTE: team 3 corresponds to index 2

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 2;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {1, 5};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 3 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 4 GraphNode inputted correctly") {

    // NOTE: team 4 corresponds to index 3

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 3;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {4};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 4 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 5 GraphNode inputted correctly") {

    // NOTE: team 5 corresponds to index 4

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 4;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {7};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 5 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 6 GraphNode inputted correctly") {

    // NOTE: team 6 corresponds to index 5

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 5;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {3, 6};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 6 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 7 GraphNode inputted correctly") {

    // NOTE: team 7 corresponds to index 6

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 6;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 7 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 8 GraphNode inputted correctly") {

    // NOTE: team 8 corresponds to index 7

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 7;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {8, 9, 10};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 8 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 9 GraphNode inputted correctly") {

    // NOTE: team 9 corresponds to index 8

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 8;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {7};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 9 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 10 GraphNode inputted correctly") {

    // NOTE: team 10 corresponds to index 9

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 9;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {11};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 10 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 11 GraphNode inputted correctly") {

    // NOTE: team 11 corresponds to index 10

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 10;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {11};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 11 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Team 12 GraphNode inputted correctly") {

    // NOTE: team 12 corresponds to index 11

    Graph graph("sample_games.csv", "teams.csv");
    int teamIndex = 11;
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<int, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        if (!actualDefeatedTeams[teamIndex]) {
            actualDefeatedTeams[teamIndex] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<int> expectedDefeatedTeams {};
    
    for (int expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that 12 beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

////////////////////////////////////////////////
// TESTING ACTUAL CSV TO GRAPH IMPLEMENTATION //
////////////////////////////////////////////////

TEST_CASE("Illinois GraphNode inputted correctly") {

    Graph graph("games.csv", "teams.csv");
    int teamIndex = graph.getIndex("Illinois");
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<std::string, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        std::string teamName = graph.getTeamName(teamIndex);
        if (!actualDefeatedTeams[teamName]) {
            actualDefeatedTeams[teamName] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<std::string> expectedDefeatedTeams {"NC_A&T", "Chicago_St", "Ohio", "Duke", "Minnesota",
                                                    "Penn_St", "Indiana", "Purdue", "Northwestern", "Iowa",
                                                    "Wisconsin", "Nebraska", "Michigan", "Ohio_St",
                                                    "Rutgers", "Drexel"};
    
    for (std::string expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that Illinois beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Duke GraphNode inputted correctly") {

    Graph graph("games.csv", "teams.csv");
    int teamIndex = graph.getIndex("Duke");
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<std::string, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        std::string teamName = graph.getTeamName(teamIndex);
        if (!actualDefeatedTeams[teamName]) {
            actualDefeatedTeams[teamName] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<std::string> expectedDefeatedTeams {"Coppin_St", "Bellarmine", "Notre_Dame", "Boston_College",
                                                    "Wake_Forest", "Georgia_Tech", "Clemson", "NC_State",
                                                    "Virginia", "Syracuse", "Louisville"};
    
    for (std::string expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Team that Duke beat was not included");
        }
    }

    REQUIRE( numberOfTeamsBeaten == expectedDefeatedTeams.size() );

}

TEST_CASE("Chicago_St GraphNode inputted correctly") {

    Graph graph("games.csv", "teams.csv");
    int teamIndex = graph.getIndex("Chicago_St");
    Graph::GraphNode team = graph.getTeam(teamIndex);

    std::map<std::string, bool> actualDefeatedTeams;

    unsigned numberOfTeamsBeaten = 0;
    for (int teamIndex : team.edges) {
        std::string teamName = graph.getTeamName(teamIndex);
        if (!actualDefeatedTeams[teamName]) {
            actualDefeatedTeams[teamName] = true;
            numberOfTeamsBeaten++;
        }
    }

    std::vector<std::string> expectedDefeatedTeams;
    
    for (std::string expectedTeam : expectedDefeatedTeams) {
        if (!actualDefeatedTeams[expectedTeam]) {
            FAIL("Should not get here because Chicago_St did not win any games!");
        }
    }

    REQUIRE( numberOfTeamsBeaten == 0 );

}