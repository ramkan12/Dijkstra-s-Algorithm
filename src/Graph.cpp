#include "Graph.hpp"
#include <queue>
#include <unordered_set>
#include <cstddef>
#include <iostream>

class isGreater {
public: 
    bool operator()(EdgeNode& n1, EdgeNode& n2) {
        return n1.weight>n2.weight;
    }
};

Graph::Graph() {
}

void Graph::addVertex(std::string label) {
    vertex *v = new vertex;
    v->name = label;
    adjList[label] = v;
}

void Graph::removeVertex(std::string label) {
    vertex *v = adjList[label];
    while (!v->edges.empty()) {
        Edge* e = v->edges.back();
        removeEdge(e->v1->name, e->v2->name);
    }
    adjList.erase(label);
    delete v;
}

void Graph::addEdge(std::string label1, std::string 
                label2, unsigned long weight) {
    Edge* e = new Edge;
    e->weight = weight;
    vertex *v1 = adjList[label1];
    vertex *v2 = adjList[label2];
    e->v1 = v1;
    e->v2 = v2;
    v1->edges.push_back(e);
    v2->edges.push_back(e);
}

void Graph::removeEdge(std::string label1, std::string label2) {
    vertex *v = adjList[label1];
    auto e = v->edges.begin();
    for (;
            (*e)->v1 != adjList[label2] && (*e)->v2 != adjList[label2];++e);
    v->edges.erase(e);
    
    v = adjList[label2];
    e = v->edges.begin();
    for (;
            (*e)->v1 != adjList[label1] && (*e)->v2 != adjList[label1];++e);
    Edge* tmp = *e;
    v->edges.erase(e);
    delete tmp;
}

unsigned long Graph::shortestPath(std::string startLabel, 
                 std::string endLabel, std::vector<std::string> &path) {
    std::string tmp = startLabel;
    startLabel = endLabel;
    endLabel = tmp;

    std::unordered_set<std::string> st;
    for (Edge* e : adjList[endLabel]->edges) {
        st.insert(e->v1->name);
        st.insert(e->v2->name);
    }
    st.erase(endLabel);

    std::unordered_map<std::string, EdgeNode> mp;
    std::priority_queue<EdgeNode,std::vector<EdgeNode>,isGreater> q;
    vertex *v = adjList[startLabel];
    q.push({v, v, 0});
    while (!st.empty()) {
        EdgeNode n = q.top();
        q.pop();
        if (n.dest->name == endLabel && st.count(n.source->name)) {
            st.erase(n.source->name);
        }
        if (mp.count(n.dest->name) && mp[n.dest->name].weight <= n.weight) {
            continue;
        }
        mp[n.dest->name] = n;
        if (n.dest->name == endLabel) {
            continue;
        }
        for (Edge* e : n.dest->edges) {
            vertex *dest;
            if (e->v1->name==n.dest->name) {
                dest = e->v2;
            }
            else {
                dest = e->v1;
            }
            q.push({dest, n.dest, e->weight+n.weight});
        }
    }
    std::string next = endLabel;
    while (next!=startLabel) {
        path.push_back(next);
        next = mp[next].source->name;
    }
    path.push_back(next);
    return mp[endLabel].weight;
}

void Graph::clear() {
    for (auto it=adjList.begin();it!=adjList.end();) {
        std::string tmp = it->first;
        ++it;
        adjList.erase(tmp);
    }
}

Graph::~Graph() {
    clear();
}

void Graph::print() {
    for (auto it=adjList.begin();it!=adjList.end();++it) {
        cout << it->first << ": ";
        for (Edge* e : it->second->edges) {
            cout << e->v1->name << "-" << e->v2->name << "," << e->weight << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

struct EdgeStruct { std::string a; std::string b; unsigned long w; };