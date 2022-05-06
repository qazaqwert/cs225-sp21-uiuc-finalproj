#include "IDDFS.h"

using namespace std;

pair<bool, vector<string>> IDDFS::run(Graph graph, int startTeam, int endTeam, int maxSteps) {

    vector<int> previous;
    for (unsigned i = 0; i < graph.getTeams().size(); i++) {
        previous.push_back(-1);
    }

    vector<string> path;
    pair<bool, vector<string>> returnPair;

    for (int i = 0; i <= maxSteps; i++)
        if (dfs(graph, startTeam, endTeam, i, previous)) {
            path = returnPath(graph, previous, startTeam, endTeam);
            returnPair = make_pair(true, path);
            return returnPair;
        }

    returnPair = make_pair(false, path);
    return returnPair;

}

vector<string> IDDFS::returnPath(Graph graph, vector<int> previous, int startTeam, int endTeam) {

    int current = endTeam;
    vector<string> pathToReturn;

    if (startTeam == endTeam) {
        pathToReturn.push_back(graph.getTeamName(startTeam));
        return pathToReturn;
    }

    if (previous[endTeam] == -1) {
        return vector<string>();
    }

    while (current != startTeam) {
        pathToReturn.push_back(graph.getTeamName(current));
        current = previous[current];
    }

    pathToReturn.push_back(graph.getTeamName(startTeam));
    reverse(pathToReturn.begin(), pathToReturn.end());

    return pathToReturn;

}

bool IDDFS::dfs(Graph graph, int startTeam, int endTeam, int maxSteps, vector<int> & previous) {

    if (startTeam == endTeam) {
        return true;
    } else if (maxSteps == 0) {
        return false;
    }

    for (int team : graph.getTeam(startTeam).edges) {

        if (dfs(graph, team, endTeam, maxSteps - 1, previous)) {
            previous[team] = startTeam;
            return true;
        }
    }

    return false;

}

void IDDFS::printPath(Graph graph, int startTeam, int endTeam, int maxSteps) {

    pair<bool, vector<string>> outputPair = run(graph, startTeam, endTeam, maxSteps);

    string team1 = graph.getTeamName(startTeam);
    string team2 = graph.getTeamName(endTeam);

    if (!get<0>(outputPair)) {
        cout << "Cannot go from " << team1 << " to " << team2 << " in " << maxSteps << "!" << endl;
        return;
    }

    for (unsigned i = 0; i < get<1>(outputPair).size(); i++) {
        cout << get<1>(outputPair)[i] << endl;
    }

}
