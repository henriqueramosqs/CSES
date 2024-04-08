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
const int MAXN = 1e6;
const int MOD = 1e9+7;
int t[MAXN][26];
bool finish[MAXN];
int idx =1;

int getCode(char a){
    return a-'a';
}

void add(string s){
    int n = s.size();
    int pos =0;
    int cur =0;

    rep(i,0,n){
        int cd = getCode(s[i]);
        if(t[cur][cd]){
            cur = t[cur][cd];
        }else{
            cur = t[cur][cd]=idx++;
        }
    }
    finish[cur]=true;
}


void solve(vi &dp,string &s,int pos){
    int n = s.size();
    int cur =0;
    rep(i,pos,n){
        int cd = getCode(s[i]);
        if(t[cur][cd]){
            cur = t[cur][cd];
        }else{
            return;
        }
        if(finish[cur])(dp[pos]+=dp[i+1])%=MOD;
    }
}

int main(){
    sws
    string s;cin>>s;
    int n;cin>>n;
    rep(i,0,n){
        string x;cin>>x;
        add(x);
    }
    int m = s.size();
    vi dp(m+1,0);
    dp[m]=1;
    for(int i = (m-1);i>=0;i--){
        solve(dp,s,i);
    }
    
    cout<<dp[0];
}
