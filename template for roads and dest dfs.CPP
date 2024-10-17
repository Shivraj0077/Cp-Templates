int dfs(vector<vector<int>> &adj,int src,vector<bool> &vis){
    vis[src] = true;
    int ans = 1;
    for(auto it : adj[src]){
        if(!vis[it]){
           ans+= dfs(adj,it,vis);
        }
    }
    return ans;
}


long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    vector<vector<int>> adj(n + 1);
    for(size_t i = 0;i < cities.size(); i++){
        adj[cities[i][0]].push_back(cities[i][1]);
        adj[cities[i][1]].push_back(cities[i][0]);
    }
    vector<int> cmp;
    vector<bool> vis(n + 1,false);
    for(int i = 1;i <= n;i++){
        if(adj[i].size()>0 && !vis[i]){
            cmp.push_back(dfs(adj,i,vis));
        }else if(adj[i].size() == 0 ) cmp.push_back(1);
    }
    long long int fin = 0;
    for(int i = 0;i < cmp.size();i++){
        fin += min((cmp[i] - 1) * c_road + c_lib,c_lib * cmp[i]);
    }
    return fin;
}
