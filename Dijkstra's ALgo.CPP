const int INF = INT_MAX; // Infinite distance to represent unreachable nodes

// Function to initialize the distance array from the source vertex
vector<int> initializeDistanceArray(int n, int src) {
    vector<int> dist(n, INF); // Set all distances to infinity
    dist[src] = 0; // Set distance to the source itself as 0
    return dist;
}

// Function to print the current state of the distance array
void print(const vector<int>& dist) {
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == INF)
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << " : " << dist[i] << "\n";
    }
    cout << "\n";
}

// Function to implement Dijkstra's Algorithm
vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adjList, int src) {
    // Step 1: Initialize distances from src to all other vertices as INFINITE
    vector<int> dist = initializeDistanceArray(n, src);
    
    // Step 2: Use a priority queue (min-heap) to keep track of the shortest path
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // Push the source vertex with distance 0

    // Step 3: Relax vertices
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If the current distance is greater than the recorded distance, skip it
        if (d > dist[u]) continue;

        // Iterate over the neighbors of the current vertex
        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relax the edge (u, v)
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Push the new distance into the priority queue
            }
        }
    }

    // Return the final distances
    return dist;
}

int main() {
    // Number of vertices (n) and adjacency list
    int n = 5;
    vector<vector<pair<int, int>>> adjList(n);

    // Adding edges to the adjacency list
    adjList[0].push_back({1, 10});
    adjList[0].push_back({4, 5});
    adjList[1].push_back({2, 1});
    adjList[1].push_back({4, 2});
    adjList[2].push_back({3, 4});
    adjList[3].push_back({2, 6});
    adjList[4].push_back({1, 3});
    adjList[4].push_back({2, 9});
    adjList[4].push_back({3, 2});

    int src = 0; // Source vertex
    vector<int> distances = dijkstra(n, adjList, src);

    // Printing the results
    cout << "Vertex Distance from Source:\n";
    for (int i = 0; i < distances.size(); ++i) {
        if (distances[i] == INF)
            cout << "Vertex " << i << " : INF\n";
        else
            cout << "Vertex " << i << " : " << distances[i] << "\n";
    }

    return 0;
}
