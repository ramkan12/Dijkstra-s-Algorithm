#include "Graph.hpp"
#include <iostream>
#include <vector>

int main() {
    Graph g;

    std::cout << "=== Dijkstra's Algorithm - Graph Demo ===" << std::endl;
    std::cout << std::endl;

    // Example 1: Simple graph
    std::cout << "Creating a simple graph with 5 vertices..." << std::endl;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");

    std::cout << "Adding weighted edges..." << std::endl;
    g.addEdge("A", "B", 4);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "C", 1);
    g.addEdge("B", "D", 5);
    g.addEdge("C", "D", 8);
    g.addEdge("C", "E", 10);
    g.addEdge("D", "E", 2);

    std::cout << std::endl;
    std::cout << "Graph structure:" << std::endl;
    g.print();

    // Find shortest path from A to E
    std::vector<std::string> path;
    unsigned long distance = g.shortestPath("A", "E", path);

    std::cout << "Shortest path from A to E:" << std::endl;
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Find shortest path from A to D
    path.clear();
    distance = g.shortestPath("A", "D", path);

    std::cout << "Shortest path from A to D:" << std::endl;
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Example 2: Different graph
    std::cout << "=== Creating a different graph ===" << std::endl;
    g.clear();

    g.addVertex("X");
    g.addVertex("Y");
    g.addVertex("Z");
    g.addVertex("W");

    g.addEdge("X", "Y", 3);
    g.addEdge("X", "Z", 6);
    g.addEdge("Y", "Z", 2);
    g.addEdge("Y", "W", 7);
    g.addEdge("Z", "W", 1);

    std::cout << "Graph structure:" << std::endl;
    g.print();

    path.clear();
    distance = g.shortestPath("X", "W", path);

    std::cout << "Shortest path from X to W:" << std::endl;
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    return 0;
}
