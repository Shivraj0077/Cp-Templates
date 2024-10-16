#include<bits/stdc++.h>
using namespace std;

vector<int> adj;
vector<int> vis;

void dfs(int node){
    vis[node] = true;

    cout << node << " ";
    for(auto neig : node){
        if(!vis[neig]){
            dfs(neig);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1,false);

    for(int i = 0; i < m; i++ ){
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1 ; i<= n ;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

}
