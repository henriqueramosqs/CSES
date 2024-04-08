#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
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
const int MAXN = 2*1e5+1;
const int LOGN = 19;
int deg[MAXN];
int up[MAXN][LOGN];
vi rev[MAXN];
int tin[MAXN];
int tout[MAXN];
int vis[MAXN];
int cycle[MAXN];
vi cycsz;
int cycidx=1;
int timer=0;
stack<int>s;
stack<int>auxStack;

inline bool isAncestor(int a,int b){
    return tin[a]<=tin[b] && tout[a]>=tout[b];
}


int get(int x,int pot,int depth=0){
    // if(pot<0 || depth>LOGN)return 0;
    // cout<<"x: "<<x<<", pot:"<<pot<<"\n";
    if(up[x][pot]!=0){
        // cout<<"retornou "<<up[x][pot]<<"\n";
        return up[x][pot];
    }
    return up[x][pot]=get(get(x,pot-1),pot-1,depth+1);
}
 
struct DSU{
    int n;
    vi parents;
    vi sz;
    DSU(){};
    DSU(int n):parents(n+1),sz(n+1,1){
        this->n  = n;
        rep(i,0,n+1)parents[i]=i;
    }
 
    int root(int x){
        if(x==parents[x])return x;
        return parents[x]=root(parents[x]);
    }
 
    void unite(int a,int b){
        a = root(a);
        b = root(b);
        if(a==b)return;
        sz[a]+=sz[b];
        parents[b]=a;
        sz[b]=a;
    }
};
 
 
DSU dsu;
 
void dfs(int v){
    vis[v]=1;
    s.push(v);  
    // dbg(v)
    tin[v]=timer++;
    int c = up[v][0];
    if(vis[c]==1){
        cycsz.pb(1);
        cycle[c]=cycle[v]=cycidx;
        // cout<<c<<" estah no ciclo "<<cycidx<<"\n";
        // cout<<v<<" estah no ciclo "<<cycidx<<"\n";
        while(s.top()!=c){
            cycle[s.top()]=cycidx;
            // cout<<s.top()<<" estah no ciclo "<<cycidx<<"\n";
            s.pop();
            cycsz.back()++;
        }
        // cout<<"reached\n";
        cycidx++;
    };
    
    if(!vis[c])dfs(c);
 
    // cout<<"reached\n";
    dsu.unite(c,v);
    // cout<<"\n";3
    rep(i,1,LOGN)up[v][i]=get(v,i);

    if(cycle[up[v][0]]!=0 && cycle[v]==0)auxStack.push(v);
 
 
    tout[v]=timer++;
    vis[v]=2;
}

inline int solveSameCyc(int a,int b){
    if(isAncestor(a,b))return abs(tin[b]-tin[a]);
    return cycsz[cycle[a]]-(abs(tin[a]-tin[b]));
}
inline int distToCyc(int a){
    int ans=0;
    int aux=a;
    for(int i = LOGN-1;i>=0;i--){
        if(cycle[up[aux][i]]==0){
            ans+=(1ll<<i);
            aux = up[aux][i];
        }

        }
    ans++;  
    return ans;
}

inline int above(int a,int x){
    for(int i = LOGN-1;i>=0;i--){
        if((1<<i)&x)a=up[a][i];
    }
    return a;
}
int32_t main(){
    sws;
    int n,q;
    cin>>n>>q;
    dsu = DSU(n);
 
    rep(i,1,n+1){
        cin>>up[i][0];
        deg[up[i][0]]++;
    }
    cycsz.pb(0);
 
    rep(i,1,n+1){
        if(deg[i]==0){
            dfs(i);
        }
    }
 
    rep(i,1,n+1){
        if(vis[i]==0)dfs(i); 
    }

 
    // cout<<"reached\n";
    // cout<<"\ndsu: ";
    // rep(i,1,n+1)cout<<dsu.root(i)<<" ";
    // cout<<"\ncyc: ";
    // rep(i,1,n+1)cout<<cycle[i]<<" ";
    // cout<<"\n";
 
    // cout<<"\ntinR: ";
    // rep(i,1,n+1)cout<<tinR[i]<<" ";
    // cout<<"\ntoutR: ";
    // rep(i,1,n+1)cout<<toutR[i]<<" ";
    // cout<<"\n";

    while(q--){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<"\n";
            continue;
        }
 
        if(dsu.root(a)!=dsu.root(b)){
            // cout<<"c1\n ";
            cout<<-1<<"\n";
            continue;
        }
 
        // a e b estão no ciclo
        if(cycle[a]==cycle[b] && cycle[a]+cycle[b]!=0){
            // cout<<"c2\n ";
            cout<<solveSameCyc(a,b)<<"\n";
            continue;
        }
 
        // a está no ciclo, b não tá 
        if(cycle[a]!=0 && cycle[b]==0){
            // cout<<"c3\n ";
            cout<<-1<<"\n";
            continue;
        }
 
        // a não tá no ciclo, b está
        if(cycle[a]==0 && cycle[b]!=0){
            // cout<<"c4\n ";
            int aux = a;
            int ans=0;
            for(int i = LOGN-1;i>=0;i--){
                if(cycle[up[aux][i]]==0){
                    ans+=(1ll<<i);
                    aux = up[aux][i];
                }
 
            }
            ans++;
            // dbg(ans)
            aux = up[aux][0];
            cout<< ans+solveSameCyc(aux,b)<<"\n";
            continue;
        }

        int ta = distToCyc(a);
        int tb = distToCyc(b);
        if(ta<tb || above(a,ta-tb)!=b){
            cout<<-1<<"\n";
            continue;
        }else{
            cout<<ta-tb<<"\n";
        }
 
    }
}