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
int n;

void generate(vi &v,vi &ans,int mn,int carry=1, int beg=0){
    if(carry>n)return;
    
    if(mn==0){
        ans.pb(carry);
        return ;
    }
    int ls = v.size();

    int q = n/carry;

    rep(i,beg,ls-mn+1){  
        if(v[i]>q)continue;
        generate(v,ans,mn-1,carry*v[i],i+1);
    }
}

int32_t main(){
    sws 
    int k;
    cin>>n>>k;
    vi v(k);rep(i,0,k)cin>>v[i];
    sort(v.begin(),v.end());
    int mul = 1;
    int finAns=0;

    rep(i,1,k+1){
        vi ans;
        generate(v,ans,i); 
        for(int c:ans){
            int qtd = n/c;
            finAns +=(mul*qtd);
        }
        mul*=-1;
    }

    cout<<finAns;
}
