#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include "readFromFile.hpp"
#include <map>
#include <cstdio>
#include <stdio.h>

class Graph {

    public:

        /*
        struct GraphEdge {

            // endTeam which represents the the team that the graph edge points to
            int endTeam;

            // weight of edge is 1 by default
            int weight = 1;

            // custom constructor for the graph edge
            GraphEdge(int endTeam_);

        };
        */

        struct GraphNode {

            // node which consists of vector containing edges connected out of node
            std::vector<int> edges;

            // adds edge to graph node
            //void addEdge(GraphEdge * edge_);
            void addEdge(int edge_);

            //default constructor that will initialize edges to an empty vector
            //GraphNode();

        };

        // drop numteams from the constructor, replace it with filename
        Graph(const std::string & gameData, const std::string & teamsData);

        Graph();

        void csvToTeams(std::vector<GraphNode> & t, const std::string & filename);

        std::vector<std::string> getTeamList(const std::string & filename);

        // returns Graph vector with all teams
        std::vector<GraphNode> getTeams();

        // returns the GraphNode at a given index
        GraphNode getTeam(int index);

        // returns all of the team names stored as a vector
        std::vector<std::string> getTeamNames();

        // returns the team name that corresponds to the specified index
        std::string getTeamName(int index);

        // returns a map with team name as the key and the graph node index as the value
        std::map<std::string, int> getIndecesOfTeams(std::vector<std::string> teamList);

        // returns the index of the team's GraphNode
        int getIndex(std::string teamName);

        // prints the teams beaten by each team
        void printDefeatedTeams();

        bool teamExists(std::string teamName);

        bool teamExists(int teamIndex);

        std::map<std::string, int> getExistingTeams(std::vector<std::string> names);

        void edgesToFile();

    private:

        // vector storing GraphNode objects representing teams
        std::vector<GraphNode> teams;

        std::vector<std::string> teamNames;

        std::map<std::string, int> teamIndeces;

};
