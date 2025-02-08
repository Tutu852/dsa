#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char value;
    TrieNode* children[26];
    bool isEndOfWord;


    TrieNode(char val){
        this->value = val;
        //suruwat me sare ke sare child ko null mark kardia 
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        this->isEndOfWord= false;
    }
};
//insertion
void insertWord(TrieNode* root,string word){
    //base case
    //word katham hogaya to ture mark kardo udhar
    if(word.length() == 0){
        root->isEndOfWord = true;
        return;
    }
    //present absent case
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        //present
        //child present he to travel karo
        child = root->children[index];
    }else{
        //absent
        //root node ke andar ch wala charater nehni he so create karo and travel karo
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion 
    //love me l ko chod ke ove ko substring hoga and next me o ko chod ke ve substring hoga so we need word.substr(1);
    insertWord(child,word.substr(1));
}

bool searchWord(TrieNode* root ,string word){
    //base case

    if(word.length() == 0){
        
        return root->isEndOfWord;
    }
    //koun sa character ka baat ho raha he
    char ch =word[0];
    // index se map karo
    int index =ch -'a';
    //child present he to travel karo
    TrieNode* child;


    if(root->children[index] != NULL){
        //present
        //child present he to travel karo
        child = root->children[index];
    }else{
        //absent
        //root node ke andar ch wala charater nehni he so return false
        return false;
    }

    //baaki recursion
    bool recursionKaAns = searchWord(child,word.substr(1));
    return recursionKaAns;
};

void deleteWord(TrieNode* root,string word){
    if(word.length() == 0){
        root->isEndOfWord = false;
        return;
    }

    //1 case mera
    //baaki recursion tera
    char ch =word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        //present
        child = root->children[index];
    }else{
        return;
    }
    //baaki sab recursion sambalega
    deleteWord(child,word.substr(1));
}

void storeString(TrieNode* root,vector<string>& ans,string &input,string& prefix){
    //base case
    if(root->isEndOfWord == true){
        //ans case
        ans.push_back(prefix + input);    
    }

    for(char ch ='a';ch <='z';ch++){
        int index = ch - 'a';
        TrieNode* next = root->children[index];
        if(next != NULL){
            //child exist
            input.push_back(ch);
            //baaki sab  recursion
            storeString(next ,ans , input , prefix);
            //backtracking
            input.pop_back();
        }
    }
}
void findPrefixString(TrieNode* root,string input,vector<string>&ans,string &prefix){
    //base case
    if(input.length() == 0){
        TrieNode* lastChar = root;
        storeString(root,ans,input,prefix);
        return;
    }
    char ch = input[0];
    int index = ch - 'a';
    TrieNode* child ;
    if(root->children[index] != NULL){
        // child present 
        child = root->children[index];
    }
    else{
        return;
    }
    //recursion call
    findPrefixString(child,input.substr(1),ans,prefix);
}

vector<vector<string> >getSuggestions(TrieNode* root , string input){
    vector<vector<string> >output;
    //i create a copy of root because i dont want to bother the main root
    TrieNode* prev = root;
    string inputHelper = "";

    for(int i=0;i<input.length();i++){
        //har character ko last character mana
        char lastChar = input[i];
        //har character ko index mark kia
        int index = lastChar - 'a';
        TrieNode* curr = prev->children[index];
        //childern exist nehni karta to
        if(curr == NULL){
            break;
        }else{
            //if childern exist karta he
            vector<string>nicheKaAns;
            inputHelper.push_back(lastChar);
            string dummy="";
            storeString(curr,nicheKaAns,inputHelper,dummy);
            output.push_back(nicheKaAns);
            //important
            prev = curr;
        }
    }
    return output;
}

int main(){
    TrieNode* root = new TrieNode('-');


    insertWord(root,"cater");
    insertWord(root,"care");
    insertWord(root,"com");
    insertWord(root,"lover");
    insertWord(root,"loved");
    insertWord(root,"load");
    insertWord(root,"lov");
    insertWord(root,"bat");
    insertWord(root,"cat");
    insertWord(root,"car");

    vector<vector<string>> ans = getSuggestions(root,"lov");

    //print ans;
    for(int i=0;i<ans.size();i++){
        cout<<i <<"->";
        for (auto str:ans[i]){
            cout<<str<<",";
        }cout<<endl;
    }
    //question is i need all c word 

    // string input ="c";
    // string prefix = input;
    // vector<string>ans;

    // findPrefixString(root,input,ans,prefix);

    // for(auto i:ans){
    //     cout<<i <<" ";
    // }
    // cout<<endl;

    // cout<<"Insertion Done " <<endl;
    // if(searchWord(root,"lov")){
    //     cout<< " found"<<endl;
    // }else{
    //     cout<<"Not found"<<endl;
    // }

    // deleteWord(root,"lov");
    //  if(searchWord(root,"lov")){
    //     cout<< " found"<<endl;
    // }else{
    //     cout<<"Not found"<<endl;
    // }

    
}