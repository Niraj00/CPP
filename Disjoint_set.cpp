#include<bits/stdc++.h>
using namespace std;

class Disjoint_Set{
    int *parent;
    int N;
    public:
        Disjoint_Set(int N){
            this->N = N;
            this->parent = new int[this->N];
            for(int i = 0; i < this->N; i++){
                this->parent[i] = i;
            }
        }

        void Union(int a, int b){
            int parentA = this->parent[a];
            
            for(int i = 0; i < this->N; i++){
                if(this->parent[i] == parentA){
                    this->parent[i] = this->parent[b];
                }
            }
        }

        bool find(int a, int b){
            return (this->parent[a] == this->parent[b]);
        }
};

int main(){
    return 0;
}