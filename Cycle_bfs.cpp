#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool detect_Cycle(int src, vector<int> adj[], int vis[]){
        vis[src]=1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
        

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it, node});
            }

            else if(parent!=it){
                return true;
            }
        }
        }
        return false;
    }
    

    public:
    bool isCycle(int V, vector<int> adj[]){
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect_Cycle(i, adj, vis))return true;
            }
        }
        return false;
    }
};
int main(){
    vector<int> adj[5]={{2,3},{1,5},{1,6,4},{2,7},{3,7}};
    Solution obj;
    bool ans=obj.isCycle(4, adj);
    if(ans)cout<<"Cycle is present";
    else cout<<"Cycle is not present";
    
    return 0;
}