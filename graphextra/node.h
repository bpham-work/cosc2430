#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <climits>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int val;
        int cost = INT_MAX;
        bool visited = false;
        vector<Node*> adj;
        unordered_map<int, int> edges;
        int from;
        Node(int val);
        Node();
        void addAdj(Node* adjNode, int cost);
        void reset();
        bool updateCost(int cost, int from);
        int getEdgeCost(int to);
};

Node::Node() {}
Node::Node(int val) : val(val) {}
void Node::addAdj(Node* adjNode, int cost = 0) {
    adj.push_back(adjNode);
    edges[adjNode->val] = cost;
}
void Node::reset() {
    visited = false;
    cost = INT_MAX;
}
bool Node::updateCost(int newCost, int from) {
    if (newCost < cost) {
        cost = newCost;
        this->from = from;
        return true;
    }
    return false;
}
int Node::getEdgeCost(int to) {
    return edges[to];
}

#endif
