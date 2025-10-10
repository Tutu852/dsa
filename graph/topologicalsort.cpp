#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    public:
    unordered_map<int ,list<int>>adjList;

    void addEdge(int u,int v,bool direction){
        //direction -> 0 -> undirected
        //direction -> 1 -> directed
        if(direction == 1){
            // u se v ka edge hai
            //u->v
            adjList[u].push_back(v);
        }else{
            //direction = 0;
            //u -> v
            adjList[u].push_back(v);
            //v -> u
            adjList[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i :adjList){
            cout<<i.first << "-> {";
            for(auto neighbour :i.second){
                cout<<neighbour <<", ";
            }
            cout<<"}"<<endl;
        }
    }

    //we are takig unordered_map beacause it is running in constant O(1) time
    void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& order) {
        visited[src] = true;

        for (auto neighbour : adjList[src]) {
            if (!visited[neighbour]) {
                topoSortDfs(neighbour, visited, order);
            }
        }
        order.push(src); // Add to the front to get the correct order
    }
    void topoSortBfs(int n){
        queue<int>q;
        unordered_map<int, int> indegree;
        // Calculate indegree of each node
        //initialize kardi indegree ko
        for (auto i : adjList){
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }
    //push all indegree wali node into queue 
        for(int node=0; node<n; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }
        //Bfs chata hai
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<" ";

            //agar me 0 ka indegree hata dia he to inke bacho ka bhi indegree kam karo
            //and agar indegree 0 ho gaya to unhe queue me daal do
            //this is the main part of topological sort
            //go to neighbour
            for(auto nbr : adjList[frontNode]){
                indegree[nbr]--;
                //-agar indegree 0 ho gaya to queue me daal do
                //this is the main part of topological sort
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        };
   
    };
         void shortPathBfs(int src,int dest){
            queue<int>q;
            map<int,bool>visited;
            map<int,int>parent;

            //initial state
            q.push(src);
            visited[src]=true;
            parent[src] =-1;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                for(auto nbr:adjList[frontNode]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        parent[nbr] = frontNode;
                        visited[nbr] = true;
                    }
                }
            }
            //paret array tayar hoga
            vector<int>ans;
            while(dest != -1){
                ans.push_back(dest);
                dest = parent[dest];
            }
            reverse(ans.begin(),ans.end());
            //print the shortest path
            for(auto i:ans){
                cout<<i <<" ";
            }
        };
};

int main(){
    Graph g;
    //for dfs graph
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,6,1);
    g.addEdge(6,7,1);
    g.addEdge(3,5,1);
    g.addEdge(5,6,1);

    //for bfs graph
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    // g.addEdge(2,4,1);
    // g.addEdge(4,5,1);
    // g.addEdge(5,6,1);
    // g.addEdge(5,7,1);
    

    g.printAdjList();
    // int n = 8;
    // vector<int>topoOrder;
    // g.topoSortBfs(n);

    // if(topoOrder.size() == n){
    //     cout<<"NO cycle: "<<endl;
    // }else{
    //     cout<<"Cycle Present: "<<endl;
    // }
    


    
    // int n=8;
    // map<int,bool>visited;
    // stack<int>st;
    // for(int node=0;node<n ; node++){
    //     if(!visited[node]){
    //         g.topoSortDfs(node, visited, st);
    //     }
    // }
    // cout<<"Topological Sort Order: ";
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
     //for shortest graph
    // g.addEdge(0,5,0);
    // g.addEdge(5,4,0);
    // g.addEdge(4,3,0);
    // g.addEdge(0,6,0);
    // g.addEdge(6,3,0);
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(2,3,0);
    
    // int src = 0;
    // int dest=3;
    // g.shortPathBfs(src,dest);
    return 0;
}