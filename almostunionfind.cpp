//2018-07-19 kattisid almostunionfind

#include <iostream>
#include <vector>
#define MAXN 100020

using namespace std;

int root[MAXN];
vector<int> sets[MAXN];
long int sums[MAXN];

class AlmostUnionFind{
    public:
        AlmostUnionFind(int n){
            for(int i = 1; i <= n; i++){
                root[i] = i;
                sums[i] = i;
                sets[i].clear();
                sets[i].push_back(i);
            }
        }
        
        void move(int x, int y){
            if(root[x] == root[y]) return;
            vector<int>::iterator it = sets[root[x]].begin();
            while(*it != x) ++it;
            sums[root[x]] -= x;
            sums[root[y]] += x;
            sets[root[x]].erase(it);
            sets[root[y]].push_back(x);
            root[x] = root[y];
        }
        void unite(int x, int y){
            x = root[x];
            y = root[y];
            if(x == y) return;
        
            if(sets[x].size() >= sets[y].size()){
                for(int &i : sets[y]){
                    sets[x].push_back(i);
                    root[i] = x;
                }
                sets[y].clear();
                sums[x] += sums[y];
                sums[y] = 0;
            }
            else{
                for(int &i : sets[x]){
                    sets[y].push_back(i);
                    root[i] = y;
                }
                sets[x].clear();
                sums[y] += sums[x];
                sums[x] = 0;
            }
        }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, command, p, q;
    while(cin >> n >> m){
        AlmostUnionFind auf(n);
        while(m--){
            cin >> command;
            if(command == 1){
                cin >> p >> q;
                auf.unite(p, q);
            }
            else if(command == 2){
                cin >> p >> q;
                auf.move(p, q);
            }
            else if(command == 3){
                cin >> p;
                
                /* Using this method for finding the sum removes the requirement for a vector storing the sums, which would save space.
                long int sum = 0;
                for(int &i : sets[root[p]]){
                    sum += i;
                }
                */
                cout << sets[root[p]].size() <<  " " << sums[root[p]] << "\n";
            }
        }
    }
    return 0;
}
