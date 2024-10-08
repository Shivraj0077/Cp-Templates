const int INF=INT_MAX;
const int NINF= INT_MIN;

// Function to initialize the distance array from the source vertex
vector<int> distance(int n, int src){
  vector<int> dist(n,INF);
  dist[src]=0;
  return dist;
}

// Function to print the current state of the distance array
void print(const vector<int>& dist){
  for(int i=0;i<dist.size();i++){
    if(dist[i]==INF)
      cout<<"Vertex"<<" "<<i<<": INF\n"; 
    else
      cout<<"Vertex"<<" "<<i<<" : "<<dist[i]<<"\n";
    }
  cout<<"\n";
}

// Function to implement the modified Bellman-Ford Algorithm
vector<int> bellman_ford(int n,vector<vector<int>>& edges,int src){
// Step 1: Initialize distances from src to all other vertices as INFINITE
vector<int> dist=distance(n,src);

// Step 2: Relax all edges |V| - 1 times and keep track of distances before final iteration
vector<int> distBeforeNegCycle=dist;
  for(int i=0;i<n-1;i++){
    for(const auto& edge:edges) {
      int u=edges[0],v=edges[1],w=edges[2];
      if(dist[u]!=INF && dist[u]+w<dist[v]){
      dist[v]=dist[u]+w;
      }
    }
  }
//Cycle detection code
  bool cycle=false;
    for(const auto& edge:edges) {
      int u=edges[0],v=edges[1],w=edges[2];
      if(dist[u]!=INF && dist[u]+w<dist[v]){
      cycle=true;
      break;
      }
    }
//If cycle detected print current ditances
  if(cycle){  
  print(dist);
  return{};
  }
//No cycle detected print distances
return dist;
}

int main(){
// Number of vertices (n) and edges
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    
int src = 0; // Source vertex
    vector<int> distances = bellmanFord(n, edges, src);

    if (distances.empty()) {
        cout << "Stopped due to the negative weight cycle.\n";
    } else {
        cout << "Vertex Distance from Source:\n";
        for (int i = 0; i < distances.size(); ++i) {
            if (distances[i] == INF)
                cout << "Vertex " << i << " : INF\n";
            else
                cout << "Vertex " << i << " : " << distances[i] << "\n";
        }
    }
  return 0;
}

