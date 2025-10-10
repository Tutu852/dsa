#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>

using namespace std;

class Graph{
    public:
    
unordered_map<char,list<pair<char,int>>>adjList;

void addEdge(char u ,char v, int wt, bool direction) {
    //direction -> 0 undirected
    //direction -> 1 directed

    if(direction == 0){
        adjList[u].push_back({v,wt});
        adjList[v].push_back({u,wt});
    }else{
        adjList[u].push_back({v,wt});
    }
}

void printAdjList(){
    for(auto i:adjList){
        cout<<i.first << "->";
        for(auto j:i.second){
            cout<<"{" <<j.first<<", "<<j.second<<"}, ";
        }cout<<endl;
    }
}

void ballmenFord(int n , char src){
    //initial state
    vector<int>dist(n,INT_MAX);
    dist[src - 'A'] = 0;
    //N-1 times ->RElAXATION
    for(int i=0;i<n;i++){
        //traverse on entire edge list
        for(auto a:adjList){
            for(auto b:a.second){
                char u = a.first;
                char v = b.first;
                int wt =b.second;
                if(dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A']){
                    dist[v - 'A'] = dist[u - 'A'] + wt;
                }
            }
        }
    }
    //yaha tak shortest distance ready he
    //check for -ve cycle
    //1 time relaxation
    bool anyupdate = false;
    for (auto a:adjList){
        for(auto b:a.second){
            char u = a.first;
            char v = b.first;
            int wt = b.second;
            if(dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A']){
                anyupdate = true;
                break;
                dist[v -'A'] = dist[u - 'A'] + wt;
            }
        }
    }
    if(anyupdate == true){
        cout<<"Negative cycle present "<<endl;
    }else
    {
        cout<<"Negative cycle not present " <<endl;
        cout<<"Printing distance array: " ;
        for(auto i:dist){
            cout<<i << ", ";
        }cout<<endl;
    }
}
};

int main(){
    Graph g;
    g.addEdge('A','B',-1,1);
    g.addEdge('B','E',2,1);
    g.addEdge('E','D',-3,1);
    g.addEdge('D','C',5,1);
    g.addEdge('A','C',4,1);
    g.addEdge('B','C',3,1);
    g.addEdge('B','D',2,1);
    g.addEdge('D','B',1,1);
    // g.printAdjList();
    g.ballmenFord(5,'A');
    return 0;
}