#include<iostream>
// #include<map>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

//adjecent graph

// void solve(vector<pair<int,int>>edjList){
//     int n = edjList.size();

//     vector<vector<int>> adj(n,vector<int>(n,0));
//     for(auto i : edjList ){
//         int u = i.first; int v= i.second;
//         adj[u][v] =1;
//     }
// }


// template<typename T>
class Graph{
    public:
    //kis node ke baat karrahe ho and node ka imediate next koun hoga
    unordered_map<int ,list<int>>adjList;
    //u mean kahna se start ho rahahe aur v mean kahna tak jayega
    void addEdge(int u,int v,bool direction){
        // direction -> 0 -> undirected 
        // direction -> 1 -> directed 
        if(direction == 1){
            //u se v ek edge hai
            //u -> v
            adjList[u].push_back(v);
        }else{
            //direction = 0;
            //u -- v
            //u ->v
            adjList[u].push_back(v);
            // v->u
            adjList[v].push_back(u);
        }
        cout<<endl<<"practicing adjList"<<endl;
        prTAdjList();
        cout<<endl;
    }
    void prTAdjList(){
        for(auto i :adjList){
            cout<<i.first << "-> {";
            for(auto neighbour :i.second){
                cout<<neighbour <<", ";
            }
            cout<<"}"<<endl;
        }
    }
    bool checkCycleUndirectedBFS(int src){
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;

        //initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr:adjList[frontNode]){
                if(nbr == parent[frontNode]){
                    continue;
                }
                
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] =true;
                    parent[nbr]=frontNode;
                }
                //agar pehele se visited he 
                //jo node visit karrahahe he kya ye uska parent he agar thik he agar parent ke alawa koi aur he then cycle present he
                else if(visited[nbr] == true){
                    //cycle present
                    return true;
                }
            }
        }
        //cycle not present
        return false;
    }
};

// weight 

//this way also we can define the datatype T will the the datatype what type of it should mantioned on main() graph<int> g .this is a int type
//after this it is a reusable code just change the datatype name and that is convert to that datatype
// template<typename T>

// class Graph{
//     public:
//     unordered_map<T,list<pair<T,T> >>adjList;

//     void addEdge(T u,T v,T wt,bool direction){
//         //direction = 0 => undirected
//         //direction = 1 => directed graph
//         if(direction == 1){
//             adjList[u].push_back({v,wt});
//             //this is also write
//             // adjList[u].push_back(make_pair(v,wt));
//         }else{
//             //direction =0
//             //u ---- v
//             //u ->v
//             //v ->u
//             adjList[u].push_back({v,wt});
//             adjList[v].push_back({u,wt});
//         }
//         prTAdjList();
//         cout<<endl;
//     }
//     void prTAdjList(){
//         for(auto i: adjList){
//             cout<<i.first << ": {";
//             for(pair<T,T> p : i.second){
//                 cout<<"{"<<p.first <<", "<<p.second <<"}, ";
//             }
//             cout<<endl;
//         }
//     }
// };

//for char
// class Graph{
//     public:
//     unordered_map<T,list<pair<T,int> >>adjList;

//     void addEdge(T u,T v,T wt,bool direction){
//         //direction = 0 => undirected
//         //direction = 1 => directed graph
//         if(direction == 1){
//             adjList[u].push_back(make_pair(v,wt));
//         }else{
//             //direction =0
//             //u ---- v
//             //u ->v
//             //v ->u
//             adjList[u].push_back({v,wt});
//             adjList[v].push_back({u,wt});
//         }
//         prTAdjList();
//         cout<<endl;
//     }
//     void prTAdjList(){
//         for(auto i: adjList){
//             cout<<i.first << ": {";
//             for(pair<T,int> p : i.second){
//                 cout<<"{"<<p.first <<", "<<p.second <<"}, ";
//             }
//             cout<<endl;
//         }
//     }

    // dis connected wale case me fat jayega

// src is  nothing but the NODE
    // void bfsTraversal(T src,unordered_map<T,bool>&vis){
    //     //adjust already data nenber me hai
    //     queue<T>q;
    //     //initail code
    //     q.push(src);
    //     vis[src] = true;

    //     //jab tak empty nehni hota he tab tak chalo
    //     while(!q.empty()){
    //         T frontNode = q.front();
    //         cout<< frontNode << " ";
    //         q.pop();


    //         // go to neb
    //         for( auto nbr:adjList[frontNode]){
    //             T nbrData = nbr.first;

    //             if(!vis[nbrData]){
    //                 q.push(nbrData);
    //                 vis[nbrData] = true;
    //             }
    //         }
    //     }
    // }
    //dfs
    // void dfs(T src,unordered_map<T,bool>&vis){
    //     //visited to true mark karo
    //     vis[src] = true;
    //     //print karo
    //     cout<<src<<" ";
    //     //child pe rec call
    //     for(auto nbr:adjList[src]){
    //         T nbrData = nbr.first;
    //         //visited nehni he call karo
    //         if(!vis[nbrData]){
    //             dfs(nbrData,vis);
    //         }
    //     }       
    // }
 
// };
int main(){
    Graph g;
    // last me jo 1 add hua he becz wo directed edge he 
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    // g.addEdge(3,4,0);
    g.addEdge(2,5,0);

    int src =0;
    bool isCyclic = g.checkCycleUndirectedBFS(src);

    if(isCyclic){
        cout<<"Cycle Present"<<endl;
    }
    else{
        cout<<"Cycle Absent"<<endl;
    }

    //for weight

    // Graph<char> g;
    // g.addEdge('a','b',5,0);
    // g.addEdge('a','c',10,0);
    // g.addEdge('c','d',15,0);
    // g.addEdge('c','e',20,0);
    // g.addEdge('d','e',25,0);
    // g.addEdge('e','f',25,0);

    //this is MAIN 
    // //this is for disconnected component
    // unordered_map<char,bool>vis;
    // for(char node='a';node<='f';node++){
    //     if(!vis[node]){
    //         g.dfs(node,vis);
    //     }
    // }
    // g.addEdge('a','b',5,0);
    // g.addEdge('b','c',10,0);

    // g.addEdge('d','e',15,0);

    // g.addEdge('f','f',20,0);

    //dis connected wale case me ye soulution he
    // unordered_map<char,bool>vis;
    // for(char node ='a';node<='f';node++){
    //     if(!vis[node]){
    //         g.bfsTraversal(node,vis);
    //     }
    // }
   
    return 0;
}