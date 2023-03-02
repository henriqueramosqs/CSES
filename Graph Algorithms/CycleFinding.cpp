#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2501;
const int INF = 1e14;

int32_t main(){
    sws
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int> >edjes;

    int path[n+1];
    
    rep(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        edjes.pb(mt(a,b,w));
    }

    int dist[n+1];
    rep(i,0,n+1)dist[i]=-INF;
    dist[1]=0;


    rep(i,0,n-1){
        for(auto e:edjes){
            int a,b,w;
            tie(a,b,w) =e;
            if(dist[a]+w<dist[b]){
                path[b]=a;
                dist[b]=dist[a]+w;
            }
        }
    }


    int sPoint =-1;

    for(auto e:edjes){
        int a,b,w;
        tie(a,b,w) =e;
        if(dist[a]+w<dist[b]){
            path[b]=a;
            sPoint = b;
        }
    }   

    if(sPoint ==-1){
        cout<<"NO\n";
        return 0;
    }

    set<int>s;
    stack<int>st;
    int v = sPoint;
    int closingPoint=-1;

    while(true){
        if(s.find(v)!=s.end()){
            closingPoint = v; 
            break;
        }
        s.insert(v);
        st.push(v);
        v = path[v];
    }

    cout<<"YES\n";
    cout<<closingPoint<<" ";

    while(st.top()!=closingPoint){
        cout<<st.top()<<" ";
        st.pop();
    }

    cout<<closingPoint;
}