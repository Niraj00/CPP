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

        bool isCyclic(int source, int parent, bool *visited){
            visited[source] = true;

            for(auto itr = adj[source].begin(); itr != adj[source].end(); itr++){
                    if(!visited[*itr]){
                        if(isCyclic(*itr, source, visited)){
                            return true;
                        }
                    }
                    else{
                        //Parent or cycle
                        if(*itr != parent){
                            return true;
                        }
                    }
                }
            return false;
        }

        bool isCycle(){
            bool * visited = new bool[this->V];

            for(int i = 0; i < this->V; i++){
                visited[i] = false;
            }
            for(int i = 0; i < this->V; i++){
                if(!visited[i]){
                    if(isCyclic(i, -1, visited)){
                        return true;
                    }
                }
            }
            return false;
        }
};

int main(){
    return 0;
}