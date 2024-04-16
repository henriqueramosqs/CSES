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
const int M = 32;
const int MOD = 999999937;
const int MAXN = 2*1e5;
int pot[MAXN];
string s;

int getNum(char a){
    return  a-'a'+1;
}

int getMod(int x){
    x%=MOD;
    while(x<0)x+=MOD;
    return x;
}

void proc(){
    pot[0]=1;
    rep(i,1,MAXN){
        pot[i]=getMod(M*pot[i-1]);
    }
}

int add(int x,int y){
    x = getMod(x);
    y = getMod(y);
    int ans = x+y;
    return getMod(ans);
}

int sz(pii a){
    return a.ss-a.ff+1;
}

pii intersect(pii a,pii b){
    if(a.ff>b.ff)swap(a,b);
    if(a.ss<b.ff)return mp(0,-1);
    return mp(b.ff,min(a.ss,b.ss));
}

struct SegTree{
    int n;
    vi t;
    SegTree(){}
    SegTree(int n):n(n){
        t.resize(n<<2);
    }

    int get(int l,int r,int v,int tl,int tr){
        if(tl==l && tr==r)return t[v];
        if(tl>r || tr<l)return 0;
        int tm = (tl+tr)/2;
        int ls = get(l,min(tm,r),v<<1,tl,tm);
        int rs = get(max(tm+1,l),r,v<<1|1,tm+1,tr);
        return add(ls*pot[sz(intersect(mp(tm+1,tr),mp(l,r)))],rs);
    }       

    int get(int l,int r){
        return get(l,r,1,0,n-1);
    }
    void update(int pos,int val,int v,int tl,int tr){
        if(tl==tr){
            t[v]=val;
            return;
        }
        int tm = (tl+tr)/2;
        if(pos<=tm){
            update(pos,val,v<<1,tl,tm);
        }else{
            update(pos,val,v<<1|1,tm+1,tr);
        }
        t[v]=add(t[v<<1]*pot[sz(mp(tm+1,tr))],t[v<<1|1]);
    }

    void update(int pos,int val){
        update(pos,val,1,0,n-1);
    }

    void show(int v,int tl,int tr){
        cout<<v<<" ("<<tl<<", "<<tr<<") "<<t[v]<<"\n";
        int tm = (tl+tr)/2;
        if(tl==tr)return;
        show(v<<1,tl,tm);
        show(v<<1|1,tm+1,tr);
    }

    void show(){return show(1,0,n-1);}
};

SegTree front;
SegTree rear;

void change(int pos,char x){
    int n = s.size();

    front.update(pos,getNum(x));
    rear.update(n-1-pos,getNum(x));
}


bool check(int l,int r){
    int n = s.size();
    int m = (l+r)/2;
    if((r-l+1)%2==0){
        return front.get(l,m)==rear.get(n-1-(r),n-1-(m+1));
    }
    return front.get(l,m-1)==rear.get(n-1-(r),n-1-(m+1));
}

int32_t main(){
    sws
    proc();
    int n,q;
    cin>>n>>q;
    cin>>s;
    rear = front = SegTree(n);

    rep(i,0,n){
        front.update(i,getNum(s[i]));
        rear.update(n-1-i,getNum(s[i]));
    }

    while(q--){
        int op;cin>>op;
        if(op==2){
            int l,r;
            cin>>l>>r;
            l--;r--;
            check(l,r)?cout<<"YES\n":cout<<"NO\n";
        }else{
            int pos;
            char x;
            cin>>pos>>x;
            change(pos-1,x);
        }

    }
}
