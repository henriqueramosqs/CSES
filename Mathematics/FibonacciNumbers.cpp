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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD = 1e9+7;

vector<vi> mul(vector<vi> a, vector<vi> b){
    vector<vi> ans(2,vi(2));
    
    ans[0][0] = (a[0][0]*b[0][0] +a[0][1]*b[1][0])%MOD;
    ans[0][1] = (a[0][0]*b[0][1] +a[0][1]*b[1][1])%MOD;
    ans[1][0] = (a[1][0]*b[0][0] +a[1][1]*b[1][0])%MOD;
    ans[1][1] = (a[1][0]*b[0][1] +a[1][1]*b[1][1])%MOD;

    return ans;
}

vector<vi> pow(vector<vi> a ,int n){
    if(n==1)return a;
    vector<vi> ans = pow(a,n/2);
    ans = mul(ans,ans);

    if(n%2==1)ans=mul(a,ans);
    return ans;
}

int solve(int n){
    if(n==0)return 0;
    if(n==1 || n==2)return 1;

    vector<vi> mat;
    vi l1,l2;
    l1.push_back(1);
    l1.push_back(1);
    l2.push_back(1);
    l2.push_back(0); 
    mat.pb(l1);mat.pb(l2);
    mat = pow(mat,n-2);
    return (mat[0][0]+mat[0][1])%MOD;

}


int32_t main(){
    sws
    int n;
    cin>>n;
    cout<<solve(n);
}
