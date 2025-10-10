#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include <limits.h>
#include <set>
using namespace std;

//directed graph
class Graph{
    public:
    //distance bhi store karna hai to pair use karna padega
    unordered_map<int,list<pair<int,int>>>adjList;
    void addEdge(int u,int v,int wt,bool direction){
        //direction  -> 0-> undirected
        //direction  -> 1-> directed
       if(direction == 1){
        //u se v ka edge hai
        //u -> v
        adjList[u].push_back({v,wt});
       }else{
        //direction =0;
        //u -> v
        adjList[u].push_back({v,wt});
        //v->u
        adjList[v].push_back({u,wt});
       }
    }
    void printAdjList(){
        for(auto i :adjList){
            cout<<i.first << "-> {";
            for(auto neighbour :i.second){
                cout<<"{"<<neighbour.first <<", "<<neighbour.second<<"}, ";
            }
            cout<<"}"<<endl;
        }
    }


    void topologicalSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& order) {
        visited[src] = true;

        for (auto nbrPair : adjList[src]) {
            int nbrNode = nbrPair.first;
            if (!visited[nbrNode]) {
                topologicalSortDfs(nbrNode, visited, order);
            }
        }
        //jab bhi src ka sare child visit ho jayenge tab src ko stack me dal do
        //this is the main part of topological sort
        //we are adding to the top of the stack
        order.push(src); 
    }
    //this is also called single source shortest path
    void shortestPathDfs(stack<int>&order,int n){
        vector<int>dist(n,INT_MAX);
        //initially ,maintain src
        int src = order.top();
        order.pop();
        //src he to dist 0 hoga
        dist[src] = 0;

        //update nbr distance for the src Node
        for(auto nbrPair :adjList[src]){
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            //if the distance is greater then  the current distance + edge weight
            if(dist[nbrNode] > dist[src] + nbrDist){
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }
        //now pop the stack and update the distance for all nodes
        //agar vbaki node me bhi ame logic lagaoo 
        while(!order.empty()){
            int frontNode = order.top();
            order.pop();

            //go to all nbr of frontNode
            for(auto nbrPair : adjList[frontNode]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                //if the distance is greater than the current distance + edge weight
                if(dist[nbrNode] > dist[frontNode] + nbrDist){
                    dist[nbrNode] = dist[frontNode] + nbrDist;
                }
            }
        }
        //print the distance
        cout << "Shortest distances from source node " << src << ":\n";
        for(auto i :dist){
            cout << i << " ";
        }
    }
    
    // Dijkstra algorithm
    void DijkstraShortesDistance(int src,int n,int dest){
        vector<int>dist(n+1,INT_MAX);
        //using set to maintain the minimum distance
        set<pair<int,int>>st;

        // Initial state
        st.insert({0,src});
        //src node ko 0 mark kardo
        dist[src] = 0;

        //distance update
        while(!st.empty()){
            // reference milgaya starting point ka
            //ye  4 line 1st element ko nikalta hai 
            auto topElement = st.begin();  
            // *topElement dereferences the iterator → gives the actual value stored in the set.
            // Since the set is storing pairs like (distance, node), the type is pair<int,int>.
            // So this line extracts that pair into a variable called topPair.
            pair<int,int> topPair = *topElement;
            int nodeDist = topPair.first;
            int node = topPair.second;
            
            //remove the top element
            st.erase(st.begin());

            // update distance of nbr 
            for(pair<int,int> nbrPair : adjList[node]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                //if the distance is greater than the current distance + edge weight
                //this is also called relaxation step boltehne
                if(dist[nbrNode] > nodeDist + nbrDist){
                    //found a new shorter distance
                    //now update:
                    //->set ki entry
                    // jo nbtnode and distance purani entry thi usko erase kar do
                    auto prevEntry = st.find({dist[nbrNode], nbrNode});
                    if(prevEntry != st.end()){
                        st.erase(prevEntry);
                    }
                    //->distance array
                    dist[nbrNode] = nodeDist + nbrDist;
                    //->insert the new entry in the set
                    st.insert({dist[nbrNode], nbrNode});

                }
            }
            
        }
        
        cout << "Node: " << src << ", Distance: " << dist[dest] << endl;
    }
};
int main(){
    Graph g;
    //for directed graph
    // g.addEdge(0,1,5,1);
    // g.addEdge(0,2,3,1);
    // g.addEdge(2,1,2,1);
    // g.addEdge(1,3,3,1);
    // g.addEdge(2,3,5,1);
    // g.addEdge(2,4,6,1);
    // g.addEdge(4,3,1,1);
    // g.printAdjList();

    
    
    // int src = 0;
    // stack<int> topoOrder;
    // unordered_map<int, bool> visited;
    // g.topologicalSortDfs(src, visited, topoOrder);
    // cout << "Topological Sort Order: ";
    // while (!topoOrder.empty()) {
        //     cout << topoOrder.top() << " ";
        //     topoOrder.pop();
        // }
        // cout << endl;   
        // int n = 5;
        // g.shortestPathDfs(topoOrder, n);
        
        g.addEdge(1,6,14,0);
        g.addEdge(1,3,9,0);
        g.addEdge(1,2,7,0);
        g.addEdge(2,3,10,0);
        g.addEdge(2,4,15,0);
        g.addEdge(3,4,11,0);
        g.addEdge(6,3,2,0);
        g.addEdge(6,5,9,0);
        g.addEdge(5,4,6,0);
    //for shortest path]
    g.DijkstraShortesDistance(6,6,4);
    return 0;
}