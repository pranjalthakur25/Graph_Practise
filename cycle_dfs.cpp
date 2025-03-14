#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    bool detect_Cycle(int node, int parent, int vis[], vector<int> adj[]){
        vis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(detect_Cycle(it, node, vis, adj)==true){return true;}
            }
            else if(it!=parent){return true;}
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<int> adj[]){
        int vis[V]={0};
        // for graph with connected components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect_Cycle(i, -1, vis, adj)==true){return true;}
            }
        }
        return false;

    }
};
int main(){
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    
    return 0;
}