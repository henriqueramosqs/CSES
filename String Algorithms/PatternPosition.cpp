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
const int K = 26;

struct Vertex{
    int next[K];
    int go[K];
    int p;
    char pch;
    int suf_link;
    int dict_link;  
    bool output;
    int aux;

    Vertex(int p=0,char pch='$'):p(p),pch(pch){
        memset(next,-1,sizeof(next));
        memset(go,-1,sizeof(go));
        suf_link = -1;
        dict_link=-1;
        output=false;
        aux=(1ll<<30);
    }
};

void show(Vertex v){
    dbg(v.p)
    dbg(v.pch)
    dbg(v.suf_link)
    dbg(v.dict_link)
    dbg(v.output)
    dbg(v.aux)
    cout<<"\n";
}

vector<Vertex>t(1);

int add_string(string &s){
    int cur =0;
    for(auto c:s){
        if(t[cur].next[c-'a']<0){
            t[cur].next[c-'a']=t.size();
            t.pb(Vertex(cur,c));
        }
        cur =t[cur].next[c-'a'];
    }
    t[cur].output=true;
    return cur;
}

void build(){
    queue<int>q;
    q.push(0);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(v==0){
            t[v].suf_link=0;
            t[v].dict_link=0;
        }else{
            t[v].suf_link =t[t[t[v].p].suf_link].go[t[v].pch-'a'];
            if(t[v].p==0)t[v].suf_link =0;
            if(t[t[v].suf_link].output==true){
                t[v].dict_link = t[v].suf_link;
            }else{  
                t[v].dict_link = t[t[v].suf_link].dict_link;
            }
        }

        rep(i,0,K){ 
            if(t[v].next[i]>=0){
                q.push(t[v].next[i]);
                t[v].go[i]=t[v].next[i];
            }else{
                t[v].go[i]= (v==0?0:t[t[v].suf_link].go[i]);
            }
        }

    }
}

void run(string &s){
    int cur =0;
    rep(i,0,s.size()){
        cur = t[cur].go[s[i]-'a'];
        t[cur].aux=min(t[cur].aux,i);
        int cc = t[cur].dict_link;
        while(cc!=0){
            t[cc].aux=min(t[cc].aux,i);
            cc = t[cc].dict_link;
        }
    }
}

int32_t main(){
    sws
    string s;cin>>s;
    int m;cin>>m;
    vector<string>q(m);
    vector<int>fin(m);
    rep(i,0,m){
        cin>>q[i];
        fin[i]=add_string(q[i]);
    }

    build();
    run(s);


    rep(i,0,m){
        int nd = fin[i];
        t[nd].aux==(1ll<<30)?cout<<-1:cout<<t[nd].aux-q[i].size()+2;
        cout<<"\n";
    }
}
