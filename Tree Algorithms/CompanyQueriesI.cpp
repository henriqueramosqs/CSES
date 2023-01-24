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
const int MAXN = 2*1e5+1;
int fat[MAXN][18];

int n,q;

void process(int v=1,int p=1){
    if(v==1){
        rep(i,0,18)fat[1][i]=-1;
    }else{
        fat[v][0]=p;
        rep(i,1,18){
            int up =fat[v][i-1];
            if(up==-1){
                fat[v][i]=-1;
            }else{
                fat[v][i]=fat[up][i-1];
            }
        }
    }
}

int main(){
    sws
    cin>>n>>q;

    process(1,1);
    rep(i,2,n+1){
        int x;cin>>x;
        process(i,x);
    }       

    while(q--){
        int x,k;cin>>x>>k;
        int pos=0;
        int cur=x;
        while((1<<pos)<=k){
            if(cur==-1)break;
            if(((1<<pos)&k)!=0)cur=fat[cur][pos];
            pos++;
        }
        cout<<cur<<endl;
    }


}
