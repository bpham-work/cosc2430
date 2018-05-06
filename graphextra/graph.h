#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include "node.h"
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class DirectedGraph {
    int size;
    vector<Node*> nodes;
    public:
        DirectedGraph();
        DirectedGraph(int size);
        void addNode(int vertex);
        void addEdge(int from, int to, int cost);
        void dfs(int vertex);
        void bfs(int vertex);
        void resetNodes();
        string shortestPath(int from, int to);
        void print();
};

DirectedGraph::DirectedGraph() {}

DirectedGraph::DirectedGraph(int size) : size(size) {
    nodes = vector<Node*>(size);
}

void DirectedGraph::addNode(int vertex) {
    nodes[vertex-1] = new Node(vertex);
}

void DirectedGraph::addEdge(int from, int to, int cost = 0) {
    nodes[from-1]->addAdj(nodes[to-1], cost);
}

void DirectedGraph::dfs(int vertex) {
    resetNodes();
    stack<Node*> s;
    s.push(nodes[vertex-1]);
    while (!s.empty()) {
        Node* node = s.top();
        s.pop();
        if (node->visited) {
            continue;
        }
        node->visited = true;
        cout << node->val << " ";
        for (int k = 0; k < node->adj.size(); k++) {
            if (!node->adj[k]->visited) {
                s.push(node->adj[k]);
            }
        }
    } 
    cout << endl << endl;
}

void DirectedGraph::bfs(int vertex) {
    resetNodes();
    queue<Node*> q;
    q.push(nodes[vertex-1]);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->visited) {
            continue;
        }
        node->visited = true;
        cout << node->val << " ";
        for (int i = 0; i < node->adj.size(); i++) {
            if (!node->adj[i]->visited) {
                q.push(node->adj[i]);
            }
        }
    }
    cout << endl << endl;
}

void DirectedGraph::resetNodes() {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] != NULL)
            nodes[i]->reset();
    }
}

string DirectedGraph::shortestPath(int from, int to) {
    resetNodes();
    stack<Node*> s;
    unordered_map<int, int> costMap;
    unordered_map<int, int> toFrom;
    s.push(nodes[from-1]);
    nodes[from-1]->cost = 0;
    while (!s.empty()) {
        Node* n = s.top();
        s.pop();
        for (int i = 0; i < n->adj.size(); i++) {
            int edgeCost = n->getEdgeCost(n->adj[i]->val);
            int newCost = n->cost + edgeCost;
            bool updated = n->adj[i]->updateCost(newCost, n->val);
            if (updated) {
                s.push(n->adj[i]);
                costMap[n->adj[i]->val] = n->adj[i]->cost;
                toFrom[n->adj[i]->val] = n->adj[i]->from;
            }
        }
    }
    string result = to_string(to);
    int curr = to;
    while (curr != from) {
        result.insert(0, to_string(toFrom[curr]) + " ");
        curr = toFrom[curr];
    }
    cout << result << endl;
    return result;
}

void DirectedGraph::print() {
    cout << "----- PRINTING GRAPH ADJACENCY LIST -----" << endl;
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] != NULL) {
            cout << "Node " << nodes[i]->val << ":";
            for (int k = 0; k < nodes[i]->adj.size(); k++) {
                cout << " " << nodes[i]->adj[k]->val;
            }
            cout << endl;
        }
    }
    cout << endl << endl;
}

#endif
