#include "../catch/catch.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "../graph.h"
#include "../BFS.h"

///////////////////////////////////////
// TESTING SAMPLE BFS IMPLEMENTATION //
///////////////////////////////////////

TEST_CASE("BFS maintains the correct sample team on top (1)") {

    Graph graph("sample_games.csv", "teams.csv");
    int startTeam = 0;
    BFS bfs(graph, startTeam);

    bfs.add(2);
    bfs.add(1);
    bfs.add(5);

    REQUIRE( bfs.peek() == startTeam );

}

TEST_CASE("BFS maintains the correct sample team on top (2)") {

    Graph graph("sample_games.csv", "teams.csv");
    int startTeam = 10;
    BFS bfs(graph, startTeam);

    bfs.add(3);
    bfs.add(8);
    bfs.add(6);

    REQUIRE( bfs.peek() == startTeam );

}

TEST_CASE("BFS maintains the sample BFS ordering (1)") {

    Graph graph("sample_games.csv", "teams.csv");
    int startTeam = 0;
    BFS bfs(graph, startTeam);

    bfs.add(2);
    bfs.add(1);
    bfs.add(5);

    REQUIRE( bfs.pop() == 0 );
    REQUIRE( bfs.pop() == 2 );
    REQUIRE( bfs.pop() == 1 );
    REQUIRE( bfs.pop() == 5 );

}

TEST_CASE("BFS maintains the sample BFS ordering (2)") {

    Graph graph("sample_games.csv", "teams.csv");
    int startTeam = 10;
    BFS bfs(graph, startTeam);

    bfs.add(3);
    bfs.add(8);
    bfs.add(6);

    REQUIRE( bfs.pop() == 10 );
    REQUIRE( bfs.pop() == 3 );
    REQUIRE( bfs.pop() == 8 );
    REQUIRE( bfs.pop() == 6 );

}

TEST_CASE("BFS iterator starts at the sample start node (1)") {

    Graph graph("sample_games.csv", "teams.csv");
    int startTeam = 0;

    BFS bfs(graph, startTeam);
    REQUIRE( *(bfs.begin()) == startTeam );

}

TEST_CASE("BFS iterator starts at the sample start node (2)") {

    Graph graph("sample_games.csv", "teams.csv");
    int startTeam = 6;

    BFS bfs(graph, startTeam);
    REQUIRE( *(bfs.begin()) == startTeam );

}

TEST_CASE("BFS visits the correct sample team first (1)") {

    Graph graph("sample_games.csv", "teams.csv");
    int startTeam = 0;

    BFS bfs(graph, startTeam);
    Traversal::Iterator it = bfs.begin();
    ++it;
    int alsoCorrectIndex = graph.getTeam(startTeam).edges[0];
    int correctIndex = 1;

    REQUIRE( *it == correctIndex );
    REQUIRE( correctIndex == alsoCorrectIndex );

}

TEST_CASE("BFS visits the correct sample team first (2)") {

    Graph graph("sample_games.csv", "teams.csv");
    int startTeam = 5;

    BFS bfs(graph, startTeam);
    Traversal::Iterator it = bfs.begin();
    ++it;
    int alsoCorrectIndex = graph.getTeam(startTeam).edges[0];
    int correctIndex = 3;

    REQUIRE( *it == correctIndex );
    REQUIRE( correctIndex == alsoCorrectIndex );

}

TEST_CASE("BFS visits all sample teams in the correct order (1)") {

    // NOTE: team 1 corresponds to index 0

    Graph graph("sample_games.csv", "teams.csv");
    int startTeam = 0;

    BFS bfs(graph, startTeam);
    Traversal::Iterator it = bfs.begin();

    // start team (team 1)
    REQUIRE( *it == 0 ); ++it;

    // all teams that team 1 has beaten
    REQUIRE( *it == 1 ); ++it;
    REQUIRE( *it == 2 ); ++it;
    REQUIRE( *it == 3 ); ++it;
    REQUIRE( *it == 8 ); ++it;

    // all teams that team 2 has beaten
    REQUIRE( *it == 6 ); ++it;

    // all teams that team 3 has beaten
    // team 2 has already been visited
    REQUIRE( *it == 5 ); ++it;

    // all teams that team 4 has beaten
    REQUIRE( *it == 4 ); ++it;

    // all teams that team 5 has beaten
    REQUIRE( *it == 7 ); ++it;

    // all teams that team 6 has beaten
    // team 4 has already been visited
    // team 7 has already been visited

    // all teams that team 7 has beaten
    // none exist!

    // all teams that team 8 has beaten
    // team 9 has already been visited
    REQUIRE( *it == 9 ); ++it;
    REQUIRE( *it == 10 ); ++it;

    // all teams that team 9 has beaten
    // team 8 has already been visited

    // all teams that team 10 has beaten
    REQUIRE( *it == 11 ); ++it;

    // all teams that team 11 has beaten
    // team 12 has already been visited

    // all teams that team 12 has beaten
    // none exist!


}

///////////////////////////////////////
// TESTING ACTUAL BFS IMPLEMENTATION //
///////////////////////////////////////

TEST_CASE("BFS maintains the correct team on top") {

    Graph graph("games.csv", "teams.csv");
    int startTeam = graph.getIndex("Illinois");
    BFS bfs(graph, startTeam);

    bfs.add(0);
    bfs.add(99);
    bfs.add(44);

    REQUIRE( bfs.peek() == graph.getIndex("Illinois") );

}

TEST_CASE("BFS maintains the BFS ordering") {

    Graph graph("games.csv", "teams.csv");
    int startTeam = graph.getIndex("Illinois");
    BFS bfs(graph, startTeam);

    bfs.add(0);
    bfs.add(99);
    bfs.add(44);

    REQUIRE( bfs.pop() == graph.getIndex("Illinois") );
    REQUIRE( bfs.pop() == 0 );
    REQUIRE( bfs.pop() == 99 );
    REQUIRE( bfs.pop() == 44 );

}

TEST_CASE("BFS iterator starts at the start node") {

    Graph graph("games.csv", "teams.csv");
    int startTeam = graph.getIndex("Illinois");

    BFS bfs(graph, startTeam);
    REQUIRE( *(bfs.begin()) == startTeam );

}

TEST_CASE("BFS visits the correct team first") {

    Graph graph("games.csv", "teams.csv");
    int startTeam = graph.getIndex("Illinois");

    BFS bfs(graph, startTeam);
    Traversal::Iterator it = bfs.begin();
    ++it;
    int alsoCorrectIndex = graph.getTeam(startTeam).edges[0];
    int correctIndex = graph.getIndex("NC_A&T");

    REQUIRE( *it == correctIndex );
    REQUIRE( correctIndex == alsoCorrectIndex );

}

TEST_CASE("BFS visits all teams in the correct order") {

    Graph graph("games.csv", "teams.csv");
    int startTeam = graph.getIndex("Illinois");

    BFS bfs(graph, startTeam);
    Traversal::Iterator it = bfs.begin();

    // start team
    REQUIRE( *it == graph.getIndex("Illinois") ); ++it;

    // all teams that Illinois has beaten
    REQUIRE( *it == graph.getIndex("NC_A&T") ); ++it;
    REQUIRE( *it == graph.getIndex("Chicago_St") ); ++it;
    REQUIRE( *it == graph.getIndex("Ohio") ); ++it;
    REQUIRE( *it == graph.getIndex("Duke") ); ++it;
    REQUIRE( *it == graph.getIndex("Minnesota") ); ++it;
    REQUIRE( *it == graph.getIndex("Penn_St") ); ++it;
    REQUIRE( *it == graph.getIndex("Indiana") ); ++it;
    REQUIRE( *it == graph.getIndex("Purdue") ); ++it;
    REQUIRE( *it == graph.getIndex("Northwestern") ); ++it;
    REQUIRE( *it == graph.getIndex("Iowa") ); ++it;
    REQUIRE( *it == graph.getIndex("Wisconsin") ); ++it;
    REQUIRE( *it == graph.getIndex("Nebraska") ); ++it;
    REQUIRE( *it == graph.getIndex("Michigan") ); ++it;
    REQUIRE( *it == graph.getIndex("Ohio_St") ); ++it;
    REQUIRE( *it == graph.getIndex("Rutgers") ); ++it;
    REQUIRE( *it == graph.getIndex("Drexel") ); ++it;

    // all teams that NC_A&T beat
    // Chicago_St was already visited
    REQUIRE( *it == graph.getIndex("Charleston_So") ); ++it;
    REQUIRE( *it == graph.getIndex("S_Carolina_St") ); ++it;
    REQUIRE( *it == graph.getIndex("Florida_A&M") ); ++it;
    REQUIRE( *it == graph.getIndex("NC_Central") ); ++it;

    // all teams that Chicago_St beat

    // all teams that Ohio beat
    // Chicago_St was already visited
    // NC_A&T was already visited
    REQUIRE( *it == graph.getIndex("Cleveland_St") ); ++it;
    REQUIRE( *it == graph.getIndex("Ball_St") ); ++it;
    REQUIRE( *it == graph.getIndex("N_Illinois") ); ++it;
    REQUIRE( *it == graph.getIndex("Miami_OH") ); ++it;
    REQUIRE( *it == graph.getIndex("W_Michigan") ); ++it;
    REQUIRE( *it == graph.getIndex("Buffalo") ); ++it;
    REQUIRE( *it == graph.getIndex("C_Michigan") ); ++it;
    REQUIRE( *it == graph.getIndex("Akron") ); ++it;
    REQUIRE( *it == graph.getIndex("E_Michigan") ); ++it;
    REQUIRE( *it == graph.getIndex("Kent") ); ++it;
    REQUIRE( *it == graph.getIndex("Toledo") ); ++it;
    REQUIRE( *it == graph.getIndex("Virginia") ); ++it;

}



