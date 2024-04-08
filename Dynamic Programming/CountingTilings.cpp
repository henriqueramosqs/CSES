#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long
#define ff first
#define ss second
#define pq priority_queue
typedef vector<long long > vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD = 1e9+7;
const int MAXN= 10;
const int MAXM =1e3;
int dp[MAXM][(1<<MAXN)];
int n,m;

int genLine(int x=0,int y=0,int making=0,int lineAbove=0){
    int ans=0;

    if(y==m){
        return 1;
    }

    if(x==n){
        return dp[y+1][making] = genLine(0,y+1,0,making);
    }

    if(x==0 && dp[y][lineAbove]!=-1)return dp[y][lineAbove];

    // casos com a linha de cima
    int abovePos=((1<<x)&lineAbove);

    if(abovePos){
        return (ans+=genLine(x+1,y,making,lineAbove))%=MOD;
    }
    
    // posso colocar uma horizontal
    if(x<(n-1) && !((1<<(x+1))&lineAbove) ){
        (ans+=genLine(x+2,y,making,lineAbove))%=MOD;
    }

    // posso colocar uma vertical
    if(y<(m-1)){ 
        (ans+=genLine(x+1,y,making+(1<<x),lineAbove))%=MOD;
    }

    return ans;;
}

int32_t main(){
    sws 
    cin>>n>>m;
    memset(dp,-1LL,sizeof(dp));
    cout<<genLine();
}   
