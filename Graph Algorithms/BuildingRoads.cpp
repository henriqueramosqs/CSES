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
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

class DSU{
public:
    vi parents;
    vi card;
    int n;

    DSU(int n):card(n+1,1),parents(n+1){
        rep(i,0,n+1){
            parents[i]=i;
        }
        this->n=n;
    }

    int root(int a){
        if(a==parents[a]){
            return a;
        }
        return parents[a] = root(parents[a]);
    }

    void unite(int a,int b){
        a = root(a);
        b= root(b);

        if(a==b){return;}

        if(card[a]<card[b]){swap(a,b);}

        parents[b]=a;
        card[a]+=card[b];
        card[b]=a;

    }

    void getAns(){
        set<int>s;  
        rep(i,1,n+1){
            s.insert(root(i));
        }

        cout<<s.size()-1<<"\n";

        for(set<int>::iterator it = s.begin(); next(it,1)!=s.end();it++){
            cout<<*it<<" "<<*next(it,1)<<"\n";
        }
    }
};

int main(){
    sws
    int n,m;
    cin>>n>>m;

    DSU dsu(n);

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        dsu.unite(a,b);
    }
    dsu.getAns();
}