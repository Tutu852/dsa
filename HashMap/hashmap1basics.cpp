#include<iostream>
#include <unordered_map>
using namespace std;



int main(){
    //creation

    unordered_map<string,int> mapping;

    //insertion
    pair<string,int>p = make_pair("love",25);
    
    pair<string,int>q("rajesh",24);

    pair<string,int>r;
    q.first = "gelli";
    q.second = 25;
    //insertion
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    //insertion using another way
    //ase karo
    mapping["vicky"]=26;

    cout<<"Size of map: " <<mapping.size()<<endl;
    //to access use at
    cout<<mapping.at("love") <<endl;
    //ase karo
    cout<<mapping["love"] <<endl;


    //searching
    //In map if ans will get in 1 and 0 if present you will get 1 or 0
    cout<<mapping.count("love") <<endl;

    if(mapping.find("gelli") != mapping.end()){
        cout<< " found" <<endl;
    }else{
        cout<<"Not found "<<endl;
    }

    cout<< "Size of map "<<mapping.size() <<endl;
    //this way if it present it will give the ans otherthen that it will create that in map
    cout<< mapping["kumar"] <<endl;
    
    cout<< "Size of Map "<<mapping.size()<<endl;
    return 0;
}