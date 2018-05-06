#include "graph.h"
#include "splitter.h"
#include <iostream>
#include <vector>
using namespace std;

DirectedGraph createGraph() {
    int size;
    cout << "Enter number of nodes in graph: ";
    cin >> size;
    DirectedGraph graph(size);
    for (int i = 1; i <= size; i++) {
        graph.addNode(i);
    }
    string input;
    while (input != "-1") {
        cout << "Create edges - enter connecting node numbers and weight; i.e. 1,2,4 - Enter -1 to finish" << endl;
        cout << "Create edge: ";
        cin >> input;
        if (input == "-1") break;
        vector<string> fields = util::split(input, ',');
        graph.addEdge(stoi(fields[0]), stoi(fields[1]), stoi(fields[2]));
    }
    return graph;
}

void dfs(DirectedGraph& graph) {
    int input;
    cout << "Enter start vertex: ";
    cin >> input;
    graph.dfs(input);
}

void bfs(DirectedGraph& graph) {
    int input;
    cout << "Enter start vertex: ";
    cin >> input;
    graph.bfs(input);
}

void dijkstra(DirectedGraph& graph) {
    int start;
    int end;
    cout << "Enter start vertex: ";
    cin >> start;
    cout << "Enter end vertex: ";
    cin >> end;
    graph.shortestPath(start, end);
}

int main() {
    DirectedGraph graph;
    int input = -1;
    while (input != 0) {
        cout << "----- MENU -----" << endl;
        cout << "1: Create graph" << endl;
        cout << "2: Print graph" << endl;
        cout << "3: Depth first search" << endl;
        cout << "4: Breadth first search" << endl;
        cout << "5: Dijkstra shortest path" << endl;
        cout << "0: Exit" << endl;
        cout << "Input: ";
        cin >> input;
        switch (input) {
            case 0:
                return 0;
            case 1:
                graph = createGraph();
                break;
            case 2:
                graph.print();
                break;
            case 3:
                dfs(graph);
                break;
            case 4:
                bfs(graph);
                break;
            case 5:
                dijkstra(graph);
                break;
        }
    }

    return 0;
}
