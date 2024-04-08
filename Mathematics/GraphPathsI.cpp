#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD = 1e9+7;
vvi adj;
int n,m,k;

void printMat(vvi &a){
    cout<<endl;
    rep(i,0,n){
        rep(j,0,n){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int getPos(int x,int y,vvi &a,vvi &b){
    int ans=0;
    rep(i,0,n){
        (ans+=(a[x][i]*b[i][y]))%=MOD;
    }
    return ans; 
}
vvi mul(vvi &a,vvi &b){
    vvi ans(n,vi(n,0));
    rep(line,0,n){
        rep(col,0,n){
            ans[line][col]=getPos(line,col,a,b);
        }
    }

    return ans; 
}

vvi binexp(vvi a,int k){
    if(k==1){
        return  a;
    }

    vvi ans = binexp(a,k/2);
    ans = mul(ans,ans);
    if(k%2==1){
        ans=mul(a,ans);
    }
    return ans;
}
int32_t main(){
    sws
    cin>>n>>m>>k;
    adj.assign(n,vi(n,0));

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a][b]++;
    }

    cout<<binexp(adj,k)[0][n-1];
}