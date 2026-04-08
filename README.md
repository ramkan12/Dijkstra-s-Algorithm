# Dijkstra's Algorithm - Graph Implementation

A C++ implementation of Dijkstra's shortest path algorithm using an undirected weighted graph data structure.

## Overview

This project implements a graph data structure with support for weighted edges and provides functionality to find the shortest path between any two vertices using Dijkstra's algorithm. The implementation uses a priority queue (min-heap) to efficiently select the next vertex to visit.

## Features

- **Add/Remove Vertices**: Dynamically add or remove vertices from the graph
- **Add/Remove Edges**: Create weighted edges between vertices
- **Shortest Path**: Find the shortest path between any two vertices using Dijkstra's algorithm
- **Print Graph**: Display the current graph structure
- **Memory Management**: Proper cleanup with destructors to prevent memory leaks

## File Structure

```
├── src/                    # Source code
│   ├── GraphBase.hpp       # Abstract base class defining graph interface
│   ├── Graph.hpp           # Graph class declaration with vertex/edge structures
│   └── Graph.cpp           # Graph implementation with Dijkstra's algorithm
├── examples/               # Example usage
│   └── main.cpp            # Demo program showing graph usage
├── docs/                   # Documentation and academic materials
│   ├── FinalProjectPresentation.pptx
│   └── FinalProjectReport.pdf
├── .gitignore              # Git ignore file
├── Makefile                # Build configuration
└── README.md               # This file
```

## Data Structures

### Vertex
- Stores a label (string identifier)
- Maintains a list of connected edges

### Edge
- Stores weight (unsigned long)
- Contains pointers to both connected vertices
- Represents undirected edges (accessible from both vertices)

## Implementation Details

The shortest path algorithm:
1. Uses a **priority queue** (min-heap) to select vertices with minimum distance
2. Maintains an **unordered map** to track the shortest distance to each vertex
3. Returns the total weight of the shortest path and populates a vector with the path

**Time Complexity**: O((V + E) log V) where V is vertices and E is edges

**Space Complexity**: O(V + E)

## Requirements

- C++11 or later
- Standard Template Library (STL)

## Quick Start

### Building the Project

Using the provided Makefile:
```bash
make
```

Or manually:
```bash
g++ -std=c++11 -Isrc -o graph src/Graph.cpp examples/main.cpp
```

### Running the Example

```bash
make run
```

Or:
```bash
./graph
```

### Cleaning Build Artifacts

```bash
make clean
```

## Usage Example

```cpp
#include "Graph.hpp"
#include <iostream>

int main() {
    Graph g;

    // Add vertices
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    // Add weighted edges
    g.addEdge("A", "B", 4);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "C", 1);
    g.addEdge("B", "D", 5);
    g.addEdge("C", "D", 8);

    // Find shortest path
    std::vector<std::string> path;
    unsigned long distance = g.shortestPath("A", "D", path);

    std::cout << "Shortest distance: " << distance << std::endl;
    std::cout << "Path: ";
    for (const auto& vertex : path) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## API Reference

### `void addVertex(std::string label)`
Adds a new vertex to the graph with the given label.

### `void removeVertex(std::string label)`
Removes a vertex and all its connected edges from the graph.

### `void addEdge(std::string label1, std::string label2, unsigned long weight)`
Creates an undirected weighted edge between two vertices.

### `void removeEdge(std::string label1, std::string label2)`
Removes the edge between two vertices.

### `unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)`
Finds the shortest path between start and end vertices. Returns the total weight and populates the path vector with vertex labels in order.

### `void print()`
Prints the graph structure showing all vertices and their edges.

### `void clear()`
Removes all vertices and edges from the graph.

## License

This project was created as a final project. Feel free to use and modify as needed.
