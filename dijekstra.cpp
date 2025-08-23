/*
 * Monte Carlo Graph Simulation
 * Calculates average shortest path using Dijkstra's algorithm on randomly generated graphs
 *
 * Style conventions followed:
 * - One statement per line
 * - Descriptive variable names
 * - Proper indentation
 * - Consistent bracket style
 * - Clear comments and documentation
 */

#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cmath>

using namespace std;

// Custom type for graph representation using adjacency lists
typedef vector<vector<pair<int, double>>> Graph;

/**
 * Generates a random weighted undirected graph
 * @param numNodes Number of vertices in the graph
 * @param edgeProbability Probability of an edge between any two vertices
 * @param minWeight Minimum edge weight
 * @param maxWeight Maximum edge weight
 * @param randomEngine Random number engine for generation
 * @return Generated graph
 */
Graph generateRandomGraph(int numNodes, double edgeProbability, 
                         double minWeight, double maxWeight,
                         mt19937& randomEngine) {
    uniform_real_distribution<double> probDist(0.0, 1.0);
    uniform_real_distribution<double> weightDist(minWeight, maxWeight);
    
    Graph graph(numNodes);
    
    for (int i = 0; i < numNodes; ++i) {
        for (int j = i + 1; j < numNodes; ++j) {
            if (probDist(randomEngine) < edgeProbability) {
                double weight = weightDist(randomEngine);
                graph[i].emplace_back(j, weight);
                graph[j].emplace_back(i, weight);
            }
        }
    }
    
    return graph;
}

/**
 * Dijkstra's algorithm for shortest paths from a source node
 * @param graph Input graph
 * @param source Source node index
 * @return Vector of shortest distances from source to all other nodes
 */
vector<double> dijkstra(const Graph& graph, int source) {
    const double INF = numeric_limits<double>::infinity();
    int numNodes = graph.size();
    vector<double> distances(numNodes, INF);
    distances[source] = 0.0;
    
    // Priority queue (min-heap) of nodes to visit
    priority_queue<pair<double, int>, vector<pair<double, int>>, 
                  greater<pair<double, int>>> pq;
    pq.emplace(0.0, source);
    
    while (!pq.empty()) {
        double currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        
        // Skip if we already found a better path
        if (currentDist > distances[currentNode]) {
            continue;
        }
        
        // Visit all neighbors
        for (const auto& neighbor : graph[currentNode]) {
            int neighborNode = neighbor.first;
            double edgeWeight = neighbor.second;
            double newDist = currentDist + edgeWeight;
            
            if (newDist < distances[neighborNode]) {
                distances[neighborNode] = newDist;
                pq.emplace(newDist, neighborNode);
            }
        }
    }
    
    return distances;
}

/**
 * Calculates the average shortest path length for a given graph
 * @param graph Input graph
 * @return Average shortest path length, or NaN if graph is disconnected
 */
double calculateAverageShortestPath(const Graph& graph) {
    int numNodes = graph.size();
    double totalPathLength = 0.0;
    int pathCount = 0;
    
    for (int source = 0; source < numNodes; ++source) {
        vector<double> distances = dijkstra(graph, source);
        
        for (int dest = source + 1; dest < numNodes; ++dest) {
            if (distances[dest] < numeric_limits<double>::infinity()) {
                totalPathLength += distances[dest];
                pathCount += 1;
            }
        }
    }
    
    return (pathCount > 0) ? (totalPathLength / pathCount) : numeric_limits<double>::quiet_NaN();
}

/**
 * Runs the Monte Carlo simulation of multiple random graphs
 * @param numNodes Number of nodes in each random graph
 * @param edgeProbability Probability of an edge between any two nodes
 * @param minWeight Minimum edge weight
 * @param maxWeight Maximum edge weight
 * @param numSimulations Number of simulations to run
 * @param randomSeed Seed for random number generator (0 for time-based seed)
 */
void runMonteCarloSimulation(int numNodes, double edgeProbability,
                            double minWeight, double maxWeight,
                            int numSimulations, unsigned int randomSeed = 0) {
    // Initialize random number generator
    randomSeed = (randomSeed == 0) ? random_device{}() : randomSeed;
    mt19937 randomEngine(randomSeed);
    
    cout << "Running Monte Carlo simulation with parameters:" << endl;
    cout << "Nodes: " << numNodes << ", Edge probability: " << edgeProbability
         << ", Weight range: [" << minWeight << ", " << maxWeight << "]" << endl;
    cout << "Random seed: " << randomSeed << endl << endl;
    
    vector<double> simulationResults;
    
    for (int sim = 0; sim < numSimulations; ++sim) {
        Graph graph = generateRandomGraph(numNodes, edgeProbability,
                                         minWeight, maxWeight, randomEngine);
        
        double avgPathLength = calculateAverageShortestPath(graph);
        simulationResults.push_back(avgPathLength);
        
        cout << "Simulation " << sim + 1 << ": ";
        if (isnan(avgPathLength)) {
            cout << "Graph is disconnected (no paths between some nodes)";
        } else {
            cout << "Average shortest path = " << fixed << setprecision(3) << avgPathLength;
        }
        cout << endl;
    }
    
    // Calculate and display statistics
    double total = 0.0;
    int validCount = 0;
    for (double result : simulationResults) {
        if (!isnan(result)) {
            total += result;
            validCount += 1;
        }
    }
    
    cout << endl << "=== Simulation Statistics ===" << endl;
    cout << "Completed simulations: " << numSimulations << endl;
    cout << "Valid (connected) graphs: " << validCount << endl;
    
    if (validCount > 0) {
        cout << "Average path length across all valid simulations: "
             << fixed << setprecision(3) << (total / validCount) << endl;
    } else {
        cout << "No valid graphs were generated (all were disconnected)" << endl;
    }
}

int main() {
    // Simulation parameters
    const int NUM_NODES = 10;
    const double EDGE_PROBABILITY = 0.3;
    const double MIN_WEIGHT = 1.0;
    const double MAX_WEIGHT = 10.0;
    const int NUM_SIMULATIONS = 100;
    const unsigned int RANDOM_SEED = 42; // Use 0 for time-based random seed
    
    runMonteCarloSimulation(NUM_NODES, EDGE_PROBABILITY,
                           MIN_WEIGHT, MAX_WEIGHT,
                           NUM_SIMULATIONS, RANDOM_SEED);
    
    return 0;
}

