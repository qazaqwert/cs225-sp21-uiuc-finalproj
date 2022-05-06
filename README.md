# 2020-2021 NCAA Division I Men's Basketball Season

**Goal:** The goal of this project was to represent the 347 teams that competed in the 2020-2021 NCAA Division I men's basketball season in a graph format and perform traversals/algorithms on this data.

## "Behind the Scenes" (Code/Data)

**Where to find graph & traversal code:** The code found to perform a breadth-first search (BFS) can be found in `BFS.(cpp/h)` and the code found to run Dijkstra's can be found in `dijkstra.(cpp/h)`. Additionally, the code used to run the IDDFS algorithm can be found in `IDDFS.(cpp/h)`. The graph structure and the methods used to read in data into the graph structure can be found in `graph.(cpp/h)` and `readFromFile.(cpp/hpp)`, respectively.

**Where to find data:** There is a sample set of games played between teams 1 - 12 that can be found in `sample_games.csv`. The actual data was taken from the site following site with the teams stored in `teams.csv` and the game outcomes stored in `games.csv` (https://www.masseyratings.com/scores.php?s=320158&sub=11590&all=1&mode=2&format=0).

**Where to find visualization code:** The main code for producing the visualizations can be found in `visualization.py` with necessary functions, `edgesToFile()` and `shortestPathToFile()`, found in `graph.(cpp/h)` and `dijkstra.(cpp/h)`, respectively.

**Where to find results:** The results of the project can be found in `results.md` with a sample shortest path visualization seen in `path.png`.

## Running the Code

**How to run the code:** An example for running the code can be seen in main.cpp. (Note: if you want to display the graph visualization, `networkx` must be installed which can be done by using the following command `$ pip install networkx`.) Below you can find other example code to analyze the data. When the code is placed in the `main.cpp` file, the `make` and `./finalproj` commands can be used to run the code.

**Example for printing all results by team:**   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Graph graph("games.csv", "teams.csv");`    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`graph.printDefeatedTeams();`    

**Example for printing Dijkstra's shortest path from Illinois to Gonzaga:**   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Graph graph("games.csv", "teams.csv");`   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Dijkstra dijkstra;`    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`dijkstra.printShortestPath(graph, "Illinois", "Gonzaga");`

**Example for visualizing Dijkstra's shortest path from Illinois to Gonzaga:**   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Graph graph("games.csv", "teams.csv");`   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Dijkstra dijkstra;`    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`dijkstra.shortestPathToFile(graph, "Illinois", "Gonzaga");`   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`std::string command = "python visualization.py";`   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`std::system(command.c_str());`  

**Example for how to run a BFS traversal starting with Illinois:**     
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Graph graph("games.csv", "teams.csv");`     
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int startTeam = graph.getIndex("Illinois");`    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`BFS bfs(graph, startTeam);`    

**Example for how to run an IDDFS traversal from team 1 to team 6:**     
NOTE: IDDFS returns a pair containing a bool (can it reach the end team in x number of steps?) and a vector of strings (the shortest path if it can reach the end team in x number of steps).      
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Graph graph("sample_games.csv", "teams.csv");`     
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int startTeam = 0; // corresponds to team 1`    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int endTeam = 5; // corresponds to team 6`    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int maxSteps = 2;`    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`IDDFS iddfs`    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`iddfs.run(graph, startTeam, endTeam, maxSteps);`    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`iddfs.printPath(graph, startTeam, endTeam, maxSteps);`    

**NOTE:** For all of Dijkstra's shortest path functions, the teams can be inputted as their name or as their corresponding index (both can be seen in teams.csv).

## Testing

**Run the tests:** In order to run the tests, use the `make test` and `./test` commands. This runs all 3 test suites which test the graph, BFS, and Dijkstra's implementations. All 3 test suites run tests on sample data (seen in `sample_games.csv`) as well as the actual data (seen in `games.csv`) and can be found in the `/tests` folder.

**Graph tests:** The graph tests ensure that the data has been properly inputted into a graph format and that each team has directed edges that point to the correct teams (teams they have beaten in the 2020-2021 season).

**BFS tests:** The BFS tests ensure that a proper breadth-first check is performed by checking that the correct team is on top, the ordering is maintained, the iterator starts at the correct team, and the BFS visits all of the teams in the correct order (checked fully on the sample data).

**Dijkstra tests:** The Dijkstra tests ensure that the shortest path algorithm is properly implemented by checking that true outcomes are reflected by a shortest path length of 1, that Chicago_St (which did not win any games) has no path to beating any team, and that the shortest path is chosen by choosing the team that comes first (based on sorted order) or by choosing the path that contains the least number of teams.

**IDDFS tests:** The IDDFS tests ensure that within a certain number of teams visited, a start team can or cannot reach an end team. This was tested using the data seen in `sample_games.csv` and checks to make sure that a team can reach itself in any number of steps and a team that is not connected at all to another specified team cannot reach that team in any number of steps. It also checks that correct shortest path is outputted.
