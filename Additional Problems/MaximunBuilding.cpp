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

int32_t main(){
    sws
    int n,m;
    cin>>n>>m;
    char grid[n][m];
    rep(i,0,n)rep(j,0,m)cin>>grid[i][j];

    int up[n][m];
    
    rep(col,0,m){
        int ls = n;
        for(int lin=n-1;lin>=0;lin--){
            if(grid[lin][col]=='*')ls=lin;
            up[lin][col]=(ls-lin);
        }
    }
    int aux[n][m];

    rep(lin,0,n){
        stack<int>s;
        s.push(m);
        for(int col = m-1;col>=0;col--){
            while(s.top()!=m && up[lin][s.top()]>=up[lin][col])s.pop();
            aux[lin][col]=s.top();
            s.push(col);
        } 

    }
    int ans=0;

    rep(i,0,n){
        rep(j,0,m){
            int lim = aux[i][j];
            int tam = up[i][j];
            while(true){
                ans=max(ans,tam*(lim-j));
                if(lim==m)break;
                tam = up[i][lim];
                lim = aux[i][lim];
            }
        }
    }


    cout<<ans;
}
