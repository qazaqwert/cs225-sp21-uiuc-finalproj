# CS 225 Project Proposal (jjoshi8-markb5-jtentis2)

1. **Leading Question:** Given two teams in NCAA Division I men’s basketball, we would like to find the shortest path linking team A to team B based on the teams that team A has beaten and the teams that those teams have beaten and so on until we reach a team that has beaten team B. Additionally, if team A equals team B, then the output would attempt to return a full circle linking teams they have beat all the way back around to a team that has beaten them. For instance, if Illinois beats Purdue, Purdue beats Michigan, and Michigan beats Illinois, this would achieve the full circle result with a minimum total path weight of 3. We want to prove that a full circle (a "circle of suck") is possible.

2. **Dataset Acquisition and Processing:** ~~Due to the lack of an easily accessible data set to the best of our knowledge, the data will be manually obtained by looking at each team’s 2020-2021 season schedule and recording a list of teams they have lost to. For example, if Illinois had only beaten Purdue and Michigan, they would be inputted into a .txt file as “Illinois, Purdue, Michigan”, where the teams after Illinois are the teams they beat. The data will be obtained from ESPN’s website.~~

	The data can be obtained from https://www.masseyratings.com/scores.php?s=320158&sub=11590&all=1&mode=2&format=0 (to be cited) and will be copied into a .txt file for reading in purposes. The teams can be represented by the numbers 1 through 347 to decode the data that will be inputted into the file (the data is arranged using numbers to represent teams).

    For our graph structure, the nodes will consist of the teams in NCAA Division 1 men’s basketball and an edge will exist between two teams if they played each other at any point in the 2020-2021 season. In addition, the graph will be directed so as to know which team beat which team. Each will have a weight of 1 to allow for the calculation of the fewest number of teams needed to span a path.

3. **Graph Algorithms:** For the graph traversal, we will implement a breadth-first search (BFS) using an  iterator. The iterator constructor’s input will be the starting team. Every time that operator++ is called, the current team should become a new team until no nodes are left unvisited.

    For our first graph algorithm, we will use Dijikstra’s algorithm. The input will consist of team A and team B, so that we attempt to traverse from team A to team B while minimizing the path length (i.e. minimizing the number of teams needed for team A to “beat” team B). This path of the minimum number of teams should be the output.

    For our second graph algorithm, we will implement the iterative deepening depth-first search where the input is team A and team B again, and we traverse through the graph to find team B. The goal of this search will probably be to determine whether team A “beat” team B by the transitive property within a set number of steps.
    
    We will also be implementing a graph visualization that shows all of the outcomes of the 2020-2021 season as well as the shortest path from team A to team B highlighted in red.

4. **Timeline:**
	
	- [x] April 8 - complete team contract and project proposal

	- [x] April 9 - submit team contract and project proposal

	- [x] April 13 - set up initial repository and Makefile

	- [x] April 15 - finish gathering all data into .csv file

	- [x] April 16 - finish reading in data into array format and test

	- [x] April 18 - convert array format into graph format and test

	- [x] April 21 - write BFS iterator
	
	- [x] April 21 - test BFS iterator

	- [x] April 27 - write Dijikstra’s

	- [x] April 27 - test Dijikstra’s
	
	- [x] May 4 - write IDDFS
	
	- [x] May 4 - test IDDFS

	- [x] May 6 - visualize the results

	- [x] May 8 - finish report
    
	- [x] May 9/10 - record, edit, and submit presentation
