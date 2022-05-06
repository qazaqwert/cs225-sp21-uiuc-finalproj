# Updates

### Week of April 5 - April 11
This week we spent the majority of our time deciding on the topic for our final project. While we initially wanted to analyze word lists
and specifically their use in crosswords, we felt this would not adequately use a graph implementation. As a result, we decided to pursue
a projcet focused on team wins within NCAA Division I men's basketball. More details about the goals of the project and how we hope to
implement everything can be found in our project_proposal.md file. As aforementioned, we created and wrote both our project_proposal.md file
along with our contract.md file. To finish off the week, we signed the contract.md file to formally agree to the terms we agreed upon.

### Week of April 12 - April 18
This week we implemented a basic graph class in the graph.h and graph.cpp files. Our graph class utilizes multiple vectors
to store the nodes and edges as we feel this is an efficient way to store our data (given that the teams are numbered from 1 to 347).
Additionally, we explored how to update the readFromFile.cpp file to fit the data we will be reading in from our source. While we did 
not write any additional code in the readFromFile.cpp that made it into the latest commit, we brainstormed ideas for the best way to
iterate through our comma separated lines in our csv files. We also created a Makefile using the template provided and altering it
slightly to fit our implementation (this is something that will continue to be updated throughout the project). We also set up the
catch, make, and tests files and their corresponding files in the Github.

### Week of April 19 - April 25
This week we altered the way we implemented our graph.h and graph.cpp files with the hopes of making future implementation simpler. 
Additionally, we added functionality to read in data from a csv file into the appropriate data structure for our graph implementation. 
We also finished creating the base traversal class and functions as well as implementing the BFS functionality. The next step is to 
test to see if the data is properly read into the graph and then to see if the BFS successfully performs a breadth-first search on our 
graph.

### Week of April 26 - May 2
This week we continued development of our makefile, in addition to creating some simple test cases for our graph creation and traversal
algorithms. In addition to this, we've began to explore and experiment with various C++ graph visualization libraries to produce a polished
and visually appealing cycle of teams, rather than just outputting to a text file or simply printing a string. The primary libraries we've
been working with are Tulip, iGraph, and OGDF, but currently we are leaning towards implementing iGraph in our final release due to its 
relative simplicity and flexibility. Our next steps forward will be to complete our graph traversal algorithms and produce a working visual
representation of our graphs.

### Week of May 3 - May 9
This week we finished the development of our makefile. In addition, we adjusted our way of implementing our graph class, which we tested through some unit tests seen in test_graph.cpp in the /tests folder. We also made changes to the traversal class to reflect the changes to our graph class. To go along with this, we tested the BFS traversal method using both basic and advanced tests seen in test_BFS.cpp in the /tests folder. We also finished the implementation of Dijkstra's algorithm and are working on the unit tests to ensure that this works properly. Still to come is (hopefully) the visualization of the results we get.

### Week of May 10 - May 12
This week we finished our final project. We completed the development of our graph visualization schema by outputting our graph data into a text file, and then calling a
python program within our cpp file to read said data and produce a graph. We opted to do this because there are significantly more simple graph visualization libraries
written in python than in C++. In addition to this, we wrote our IDDFS algorithm and also completed testing of Dijkstra's algorithm, BFS, and IDDFS on sample datasets to ensure that they were scalable. Finally, we recorded our final video for this project and completed the readme file.
