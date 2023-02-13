#include<bits/stdc++.h>
using namespace std;

class graph{
    int V;
    list<int> *adj;

    public:
        graph(int V){
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

        vector<int> BFS(){
            vector<int> result;
            bool *visited = new bool[this->V];
            for(int i = 0; i < this->V; i++){
                visited[i] = false;
            }

            list<int> Q;
            int source = 0;
            visited[source] = true;
            Q.push_back(source);

            while(!Q.empty()){
                source = Q.front();
                Q.pop_front();
                result.push_back(source);

                for(auto itr = adj[source].begin(); itr != adj[source].end(); itr++){
                    if(!visited[*itr]){
                        visited[*itr] = true;
                        Q.push_back(*itr);
                    }
                }
            }
            return result;
        }
    };

int main(){
    return 0;
}