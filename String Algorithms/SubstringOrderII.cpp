#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cerr<<#x<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
#define all(x) x.begin(),x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
typedef pair<pii,int >pp;
 
struct state {
    int len, link;
    int cnt, dp;
    map<char, int> next;
};
 
const int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;
 
void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].cnt=1;
 
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[clone].dp=st[clone].cnt=0;
 
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
 
void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}
 
 
bool isIn(int x,int l,int r){
    return  x>=l && x<=r;
}
 
int dfs(int k,string &finans,int v=0,int l=1){
    int r = l+st[v].dp-1;
 
    if(!isIn(k,l,r))return -1;
    
    if(v!=0 && isIn(k,l,l+st[v].cnt-1))return v;
    int dx=(v==0?0:st[v].cnt);
 
    for(auto c:st[v].next){
        int aux = dfs(k,finans,c.ss,l+dx);
        if(aux!=-1){
            finans+=c.ff;
            return aux;
        }
        dx+=st[c.ss].dp;
    }
 
}
int32_t main(){
    sws 
    sa_init();
    string s;cin>>s;
    int k;cin>>k;
    for(auto &c:s)sa_extend(c);
    pq<pii>p;
    rep(i,1,sz)p.push(mp(st[i].len,i));
    while(!p.empty()){
        int v = p.top().ss;p.pop();
        st[st[v].link].cnt+=st[v].cnt;
    }
 
    rep(i,0,sz)p.push(mp(st[i].len,i));
    
    while(!p.empty()){
        int v = p.top().ss;p.pop();
        st[v].dp=(v==0?0:st[v].cnt);
        for(auto c:st[v].next)st[v].dp+=st[c.ss].dp;
    }

    string finans="";
    int ans = dfs(k,finans);
    reverse(all(finans));
    cout<<finans<<"\n";
    
}