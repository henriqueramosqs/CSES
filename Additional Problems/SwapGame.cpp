#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
int pot[11];

void proc(){
    pot[0]=1;
    rep(i,1,11)pot[i]=10*pot[i-1];
}

int getIdx(vvi &v){
    int ans =0;
    rep(pos,0,9){
        int num = v[pos/3][pos%3];
        ans+=num*pot[8-pos];          
    }
    return ans;
}

vvi unpack(int idx){
    vvi ans(3,vi(3));
    stack<int> aux;

    rep(i,0,9){
        aux.push(idx%10);
        idx/=10;
    }
    rep(pos,0,9){   
        ans[pos/3][pos%3]=aux.top();
        aux.pop();
    }
    return ans;
}

int32_t main(){
    sws
    proc();

    vvi cur(3,vi(3));
    rep(i,0,3)rep(j,0,3)cin>>cur[i][j];
    queue<int>q;
    
    unordered_map<int,int >dd;
    int idx = getIdx(cur);

    q.push(idx);
    dd[idx]=0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v==123456789ll){
            cout<<dd[v];
            return 0;
        }
        vvi mat = unpack(v);
        rep(i,0,3){
            rep(j,0,3){
                // pra cima
                if(i>0){
                    swap(mat[i][j],mat[i-1][j]);
                    int idx = getIdx(mat);
                    if(dd.find(idx)==dd.end()){
                        dd[idx]=dd[v]+1;
                        q.push(idx);
                    }
                    swap(mat[i][j],mat[i-1][j]);
                }

                // pra baixo
                if(i<2){
                    swap(mat[i][j],mat[i+1][j]);
                    int idx = getIdx(mat);
                    if(dd.find(idx)==dd.end()){
                        dd[idx]=dd[v]+1;
                        q.push(idx);
                    }
                    swap(mat[i][j],mat[i+1][j]);
                }

                // pra esquerda
                if(j>0){
                    swap(mat[i][j],mat[i][j-1]);
                    int idx = getIdx(mat);
                    if(dd.find(idx)==dd.end()){
                        dd[idx]=dd[v]+1;
                        q.push(idx);
                    }
                    swap(mat[i][j],mat[i][j-1]);
                }

                // pra direita
                if(j<2){
                    swap(mat[i][j],mat[i][j+1]);
                    int idx = getIdx(mat);
                    if(dd.find(idx)==dd.end()){
                        dd[idx]=dd[v]+1;
                        q.push(idx);
                    }
                    swap(mat[i][j],mat[i][j+1]);
                }
                
            }
        }
    }
}
