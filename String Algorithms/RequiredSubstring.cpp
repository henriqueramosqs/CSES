#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
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
#define all(x) x.begin(),x.end();
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int INF = (1ll<<40);
const int MOD = 1e9+7;
const int MAXN = 2*1E5;
int pot[MAXN];
 
void proc(){
    pot[0]=1;
    rep(i,1,MAXN){
        (pot[i]=26*pot[i-1])%=MOD;
        if(pot[i]<0)pot[i]+=MOD;
    }
}
vi kmp(string &s){
    int n = s.size();
    vi pi(n,0);
    rep(i,1,n){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
    }
 
    return pi;
}
 
 
int32_t main(){
    sws
    proc();
    int n;cin>>n;
    string s;cin>>s;
 
    s += '#';
    int m = s.size();
    vi pi = kmp(s);
    vvi aut(m,vi(26));
    rep(i,0,m){
        rep(c,0,26){
            if (i > 0 && 'A' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('A' + c == s[i]);
        }
    }
 
    s.pop_back();
    m--;
    vvi dp(n,vi(m,0));
    
    // dbg(getNum(s.back()))
    for(int i =n-1;i>=0;i--){
        // fazer na mao pro 0
        rep(j,0,m){
            rep(tt,0,26){
                if(aut[j][tt] == m)continue;
                if(i<n-1){
                    (dp[i][j]+=dp[i+1][aut[j][tt]])%=MOD;
                }else{
                    dp[i][j]++;
                }
            }
        }
    }
    cout<<(pot[n]-dp[0][0]+MOD)%MOD;
}