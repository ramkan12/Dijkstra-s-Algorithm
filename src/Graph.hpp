#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

struct vertex;

struct Edge {
    unsigned long weight;
    vertex *v1;
    vertex *v2;
};

struct vertex {
    std::string name;
    std::list<Edge*> edges;
};

struct EdgeNode {
    vertex *dest;
    vertex *source;
    unsigned long weight;
};

class Graph : GraphBase {
public:
    Graph();
    ~Graph();
    void addVertex(std::string label);
    void removeVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, 
                      std::string endLabel, std::vector<std::string> &path);
    void clear();
    void print();
private:
    std::unordered_map<std::string, vertex*> adjList;
    vertex *getVert(std::string label);
};

#endif