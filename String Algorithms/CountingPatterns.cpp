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
const int MAXN = 6*1e5;
vi vis(MAXN,0);
int fin[MAXN];
// convenção:       
// -1 = não calculado
// -2 = não tem

struct Vertex{
    int next[26];
    int go[26];
    int p;
    char pch;
    int dict_link;
    int suf_link;
    int output;

    Vertex(int p=-1,char ch='$'): p(p),pch(ch){
        memset(next,-1,sizeof(next));
        memset(go,-1,sizeof(go));
        dict_link=-1;
        suf_link=-1; 
        output=-1;
    }
};
void show(Vertex &v){
    dbg(v.p)
    dbg(v.pch)
    dbg(v.dict_link)
    dbg(v.suf_link)
    dbg(v.output)
}


vector<Vertex>t(1);
void add_string(string &s,int idx){
    int v = 0;

    for(auto &c:s){
        if(t[v].next[c-'a']==-1){
            t[v].next[c-'a']=t.size();
            t.pb(Vertex(v,c));
        }
        v= t[v].next[c-'a'];
    }
    t[v].output=idx;
    fin[idx]=v;
}

int go(int v,char ch);

int get_link(int v){
    if(t[v].suf_link==-1){
        if(v==0 || t[v].p==0){
            t[v].suf_link =0;
        }else{
            t[v].suf_link = go(get_link(t[v].p),t[v].pch);
        }
    }
    return t[v].suf_link;
}

int go(int v,char ch){   
    int c  = ch-'a';
    if(t[v].go[c]==-1){
        if(t[v].next[c]!=-1){
            t[v].go[c]=t[v].next[c];
        }else{
            t[v].go[c]= ( v==0?0:go(get_link(v),ch) );
        }
    }
    return t[v].go[c];
}

int get_dictlink(int v){
    int suf = t[v].suf_link;
    if(t[v].dict_link>=0)return t[v].dict_link;
    if(suf==0)return t[v].dict_link =0;

    if(t[suf].output>=0){
        return t[v].dict_link = suf;
    }
    if(t[suf].dict_link==-1)get_dictlink(suf);
    t[v].dict_link = t[suf].dict_link;
    return t[v].dict_link;
}

void build_links(){
    t[0].suf_link=0;
    rep(i,1,t.size())get_link(i);

    t[0].dict_link=0;
    rep(i,1,t.size())get_dictlink(i);
}

void dfs(string &s,int cur=0,int idx=0){
    vis[cur]++;
    if(idx!=s.size()){
        int nx = go(cur,s[idx]);
        dfs(s,nx,idx+1);
    }

    // percorre os dict_lin ks
    int cc = t[cur].dict_link;
    while(cc!=0){
        vis[cc]++;
        cc = t[cc].dict_link;
    }
}

int32_t main(){
    sws
    string s;
    cin>>s;
    int m;cin>>m;
    rep(i,0,m){
        string x;cin>>x;
        add_string(x,i);
    }
    build_links();

    dfs(s);
    rep(i,0,m){
        cout<<vis[fin[i]]<<"\n";
    }   

}
