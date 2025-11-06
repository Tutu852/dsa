#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
#include<stack>

using namespace std;

class Graph{
    public:
    //this is for getStronglyconnectedcomponent
    unordered_map<int,list<int >>adjList;
    void addEdge(int u ,int v, bool direction) {
        //direction -> 0 undirected
        //direction -> 1 directed

        if(direction == 0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }else{
            adjList[u].push_back(v);
        }
    }



    void dfs1(int node ,stack<int>&ordering, unordered_map<int,bool>&vis){
        vis[node] = true;
        for(auto nbr: adjList[node]){
            if(!vis[nbr]){
                dfs1(nbr,ordering,vis);
            }
        }
        //wapas aate hua stak me push
        ordering.push(node);
    }
    void dfs2(int src,unordered_map<int,bool>&vis2,unordered_map<int,list<int>>&adjNew){
        vis2[src]=true;
        cout<< src<<", ";
        for(auto nbr:adjNew[src]){
            if(!vis2[nbr]){
                dfs2(nbr,vis2,adjNew);
            }
        }
    }
    int getStronglyConnectedComponents(int n) {
        //step1 get the ordering
        stack<int>ordering;
        unordered_map<int,bool>vis;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs1(i,ordering,vis);
            }
        }
        //step-2 reverse edge
        unordered_map<int,list<int>>adjNew;
        for(auto a:adjList){
            for(auto b: a.second){
                int u = a.first;
                int v=b;
                //v->u ki entry create karni hein to
                adjNew[v].push_back(u);
            }
        }
        //step-3 reverse using ordring and count component
        int count =0;
        unordered_map<int,bool>vis2;

        while(!ordering.empty()){
            int node = ordering.top();
            ordering.pop();
            if(!vis2[node]){
                cout<< "SCC #" <<count+1 << ": ";
                dfs2(node,vis2,adjNew);
                count++;
                cout<<endl;
            }
        }
        return count;
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);

    int n = 8;
    int ans = g.getStronglyConnectedComponents(n);

    cout << "\nSCC count: " << ans << endl;


    return 0;
}