#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
        Graph(int V){
            this->V = V;
            this->adj = new list<int>[this->V];
        }

        void addedge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void dfs(int source, bool *visited, vector<int> &result){
            visited[source] = true;
            result.push_back(source);
            for(auto itr = adj[source].begin(); itr != adj[source].end(); itr++){
                if(!visited[*itr]){
                    dfs(*itr, visited, result);
                }
            }
        }

        vector<int> dfs(){
            vector<int> result;
            bool *visited = new bool[this->V];
            for(int i = 0; i < this->V; i++){
                visited[i] = false;
            }

            int count = 0;

            for(int i = 0; i < this->V; i++){
                if(!visited[i]){
                    count++;
                    dfs(i, visited, result);
                }
            }
            cout << count << endl;
        }

        bool isCyclic(int source, bool *visited, bool *recursive){
            visited[source] = true;
            recursive[source] = true;

            
            for(auto itr = adj[source].begin(); itr != adj[source].end(); itr++){
                    if(!visited[*itr] && isCyclic(*itr, visited, recursive)){
                        return true;                        
                    }
                    else if(recursive[*itr] == true){
                        return true;
                    }
            }

            recursive[source] = false;
            return false;
        }

        bool isCycle(){
            bool *visited = new bool[this->V];
            bool *recursive = new bool[this->V];

            for(int i = 0; i < this->V; i++){
                recursive[i] = visited[i] = false;
            }

            for(int i = 0; i < this->V; i++){
                if((isCyclic(i, visited, recursive))){
                    return true;
                }
            }
            return false;
        } 
    };

int main(){
    return 0;
}