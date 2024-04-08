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
set<pii>tams;  // (tamanho,l)
set<pii> ints; // l,r

inline int getTam(int l,int r){
    return r-l+1;
}

set<pii>::iterator getIt(int pos){
    auto it = ints.upper_bound(mp(pos,(1LL<<30)));
    if(it==ints.begin())return ints.end();
    it--;
    if(pos< it->ff || pos> it->ss)return ints.end();
    return it;
}


void rm(int pos){
    auto it = getIt(pos);
    if(it==ints.end())return;
    int l = it->ff, r = it->ss;
    ints.erase(it);
    tams.erase(tams.find(mp(getTam(l,r),l)));
}

void add(int l,int r){
    ints.insert(mp(l,r));
    tams.insert(mp(getTam(l,r),l));
}
void alt(int pos){
    auto it = getIt(pos);
    bool esq = (it->ff == pos);
    bool dir = (it->ss == pos); 

    //unico
    if(esq && dir){
        int tl =pos,tr = pos;
        auto itl = getIt(pos-1);
        auto itr = getIt(pos+1);
        if(itl!=ints.end())tl = itl->ff;
        if(itr!=ints.end())tr = itr->ss;
        rm(pos);rm(pos-1);rm(pos+1);
        add(tl,tr);
    }


    // no meio
    if(!esq && !dir){   
        int tl1=it->ff,tr1=pos-1;
        int tl=pos,tr=pos;
        int tl2 = pos+1,tr2=it->ss;
        rm(pos);
        add(tl1,tr1);
        add(tl,tr);
        add(tl2,tr2);
    }

    // na esquerda
    if(esq && !dir){
        int tl1=pos,tr1=pos,tl2=pos+1,tr2=it->ss;
        auto itl = getIt(pos-1);
        if(itl!=ints.end())tl1=itl->ff;
        rm(pos);rm(pos-1);
        add(tl1,tr1);
        add(tl2,tr2);
    }


    // na direita
    if(!esq && dir){
        int tl1=it->ff,tr1=pos-1,tl2=pos,tr2=pos;
        auto itr = getIt(pos+1);
        if(itr!=ints.end())tr2=itr->ss;
        rm(pos);rm(pos+1);
        add(tl1,tr1);
        add(tl2,tr2);
    }
}

void show(){
    cout<<"\n\nints:\n";
    for(auto c:ints)cout<<c.ff<<" "<<c.ss<<"\n";
    cout<<"\ntams:\n";
    for(auto c:tams)cout<<c.ss<<": "<<c.ff<<"\n";
    cout<<"\n";
}
int32_t main(){
    sws 
    string s;cin>>s;
    int n =s.size();
    int l =0;
    while(l<n){
        int r = l;
        while(r<n-1 && s[r+1]==s[l])r++;
        add(l,r);
        l=r+1;
    }

    int m;cin>>m;
    rep(i,0,m){
        int x;cin>>x;
        x--;
        alt(x);
        cout<<prev(tams.end())->ff<<" ";
    }
}
