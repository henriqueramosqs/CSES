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
int a[3];
int ans[16];

void solve(int qtd,int org,int dest,int mid){
    if(qtd==1){
        a[org]--;
        a[dest]++;
        cout<<org+1<<" "<<dest+1<<endl;
        return;
    }

    solve(qtd-1,org,mid,dest);
    solve(1,org,dest,mid);
    solve(qtd-1,mid,dest,org);
}
int main(){
    sws
    int x;cin>>x;
    a[0]=x;
    a[1]=1;
    a[2]=1;

    ans[0]=1;
    rep(i,1,16){
        ans[i] = 2*(ans[i-1])+1;
    }
    cout<<ans[x-1];
    cout<<endl;

    solve(x,0,2,1);
    
}
