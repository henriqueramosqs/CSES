#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ll long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 1e5+3;
const ll INF = 1e15;
vpp adj[MAXN];

struct Path{
    ll distance;
    int v;
    bool discountApplied;

    Path(int v,ll distance,bool discountApplied){
        this->v = v;
        this->distance = distance;
        this->discountApplied = discountApplied;
    }

};

ostream &operator<<(ostream &os,Path const &m){
       string a = "S";
       if(!m.discountApplied)a="N";
       return os<<"Path to: "<<m.v<<", with distance: "<<m.distance<<", discount: "<<a<<endl;
}

bool operator < (const Path& u,const Path& o){
        if(u.distance<o.distance){
            return false;
        }
        if(u.distance==o.distance && (o.discountApplied && !u.discountApplied)){
            return false;
        }
        return true;
}

int main(){
    sws
    int n,m;
    cin>>n>>m;

    rep(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
    }
    ll distance[n+1][2];
    bool processed[n+1][2];

    rep(i,0,n+1){
        distance[i][0]=INF;
        distance[i][1]=INF;
        processed[i][0]=false;
        processed[i][1]=false;
    }

    distance[1][0]=0;

    pq<Path>p;
    p.push(Path(1,0,false));

    while(!p.empty()){
        Path cur = p.top();
        p.pop();

        if(processed[cur.v][cur.discountApplied]){
            continue;
        }

        if(cur.v==n){
            break;
        }

        processed[cur.v][cur.discountApplied]=true;

        for(auto c: adj[cur.v]){
            int b = c.ff, w = c.ss;

            if(cur.discountApplied){
                if(!processed[b][1] && cur.distance+w<distance[b][1]){
                    distance[b][1]=cur.distance+w;
                    p.push(Path(b,distance[b][1],true));
                }
            }else{
                if(!processed[b][0] && cur.distance+w<distance[b][0]){
                    distance[b][0]=cur.distance+w;
                    p.push(Path(b,distance[b][0],false));
                }
                if(!processed[b][1] && cur.distance+(w/2)<distance[b][1]){
                    distance[b][1]=cur.distance+(w/2);
                    p.push(Path(b,distance[b][1],true));
                }   
            }

        }
    }

    cout<<distance[n][1];
}