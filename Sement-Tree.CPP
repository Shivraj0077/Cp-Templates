#include<bits/stdc++.h>
using namespace std;

#define nl '\n'

// Function to build the segment tree for minimum query
void build(const vector<int>& v, vector<int>& t, int node, int st, int ed){
    if(st == ed){
        t[node] = v[st];
    } else {
        int mid = (st + ed) / 2;
        build(v, t, 2 * node, st, mid);
        build(v, t, 2 * node + 1, mid + 1, ed);
        t[node] = min(t[2 * node], t[2 * node + 1]);
    }
}

// Propagate lazy updates to the children nodes
void propagate(vector<int>& t, vector<int>& lazy, int node, int st, int ed){
    if(lazy[node] != 0){ // If there is a pending update
        t[node] += lazy[node]; // Apply the update
        
        if(st != ed){ // If not a leaf node, propagate to children
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0; // Clear the lazy value for the current node
    }
}

// Range update function with lazy propagation
void rangeUpdate(vector<int>& t, vector<int>& lazy, int node, int st, int ed, int lef, int rig, int incr){
    propagate(t, lazy, node, st, ed); // Ensure all pending updates are applied
    
    if(rig < st || lef > ed) return; // No overlap
    
    if(lef <= st && ed <= rig){ // Total overlap
        lazy[node] += incr;
        propagate(t, lazy, node, st, ed);
        return;
    }
    
    int mid = (st + ed) / 2;
    rangeUpdate(t, lazy, 2 * node, st, mid, lef, rig, incr);
    rangeUpdate(t, lazy, 2 * node + 1, mid + 1, ed, lef, rig, incr);
    t[node] = min(t[2 * node], t[2 * node + 1]);
}

// Query function with lazy propagation
int query(vector<int>& t, vector<int>& lazy, int node, int st, int ed, int lef, int rig){
    propagate(t, lazy, node, st, ed); // Ensure all pending updates are applied

    if(rig < st || lef > ed) return INT_MAX; // No overlap
    
    if(lef <= st && ed <= rig) return t[node]; // Total overlap
    
    int mid = (st + ed) / 2;
    int leftMin = query(t, lazy, 2 * node, st, mid, lef, rig);
    int rightMin = query(t, lazy, 2 * node + 1, mid + 1, ed, lef, rig);
    return min(leftMin, rightMin);
}

// Function to print the segment tree with lazy values (for debugging)
void print(const vector<int>& t, const vector<int>& lazy){
    cout << "Segment Tree:\n";
    for(size_t i = 1; i < t.size(); i++){
        cout << "Node " << i << " : Value = " << t[i] << ", Lazy = " << lazy[i] << nl;
    }
}

int main(){
    vector<int> v = {1, 3, 2, -5, 6, 4}; // Initial array
    int n = v.size();
    vector<int> t(4 * n, 0);  // Segment tree array
    vector<int> lazy(4 * n, 0); // Lazy array for lazy propagation
    
    build(v, t, 1, 0, n - 1); // Build the segment tree with root at node 1
    
    // Sample range update and query with lazy propagation
    int lef = 1, rig = 4, incr = 10;
    rangeUpdate(t, lazy, 1, 0, n - 1, lef, rig, incr); // Range update on [1, 4] by +10
    cout << "Minimum in range [0, n-1]: " << query(t, lazy, 1, 0, n - 1, 0, n - 1) << nl;

    // Print the segment tree and lazy values
    print(t, lazy);

    return 0;
}
