#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<" ";
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

struct Vertex {
    int arrIdx;
    Vertex *l, *r;
    int sum;

    Vertex(int idx,int val) : l(nullptr), r(nullptr), arrIdx(idx),sum(val) {}
    Vertex(int idx, Vertex *l, Vertex *r) : l(l), r(r), sum(0),arrIdx(idx)  {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int idx,int a[], int tl, int tr) {
    if (tl == tr)
        return new Vertex(idx,a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(idx,build(idx,a, tl, tm), build(idx,a, tm+1, tr));
}

int get(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get(v->l, tl, tm, l, min(r, tm))
         + get(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(int idx,Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(idx,new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(idx,update(idx,v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(idx,v->l, update(idx,v->r, tm+1, tr, pos, new_val));
}

int32_t main(){
    sws
    int n,q;
    cin>>n>>q;
    int a[n];
    rep(i,0,n)cin>>a[i];
    vector<Vertex*>v;
    v.pb(build(0,a,0,n-1));

    while (q--){
        int op;cin>>op;
        if(op==1){
            int k,a,x;
            cin>>k>>a>>x;
            k--;a--;
            v[k]=update(k,v[k],0,n-1,a,x);
            continue;
        }

        if(op==2){
            int k,a,b;
            cin>>k>>a>>b;
            k--;a--;b--; 
            cout<<get(v[k],0,n-1,a,b)<<"\n";
            continue;
        }
        int k;cin>>k;
        k--;
        int idx = v.size();
        v.pb(new Vertex(idx,v[k]->l,v[k]->r));
    }
    
}
