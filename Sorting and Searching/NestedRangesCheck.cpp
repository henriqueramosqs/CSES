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

bool Comp(pair<pii,int> a1,pair<pii,int> b1){
    pii a = a1.ff;
    pii b = b1.ff;
    if(a.ff<b.ff)return true;
    if(a.ff>b.ff)return false;
    return a.ss>b.ss;
}

int main(){
    sws
    int n;cin>>n;
    vector<pair<pii,int> > v;

    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        v.pb(mp(mp(a,b),i));
    }

    sort(v.begin(),v.end(),Comp);
    sort(v.begin(),v.end(),Comp);

    int ans1[n],ans2[n];
    int maxim[n];
    int minim[n];

    minim[n-1]=v[n-1].ff.ss;
    rep(i,2,n+1){
        minim[n-i]=min(minim[n-i+1],v[n-i].ff.ss);
    }   

    maxim[0]=v[0].ff.ss;
    rep(i,1,n){
        maxim[i]=max(maxim[i-1],v[i].ff.ss);
    }


    rep(i,0,n){

        int idx = v[i].ss;
        if(i==(n-1))ans1[idx]=0;
        else{
            if(v[i].ff.ss>=minim[i+1]){
                ans1[idx]=1;
            }else{
                ans1[idx]=0;
            }
        }
    }


    rep(i,0,n){
        int idx = v[i].ss;
        if(i==0)ans2[idx]=0;
        else{
            if(v[i].ff.ss<=maxim[i-1]){
                ans2[idx]=1;
            }else{
                ans2[idx]=0;
            }
        }     
        
    }

    rep(i,0,n){
        cout<<ans1[i]<<" ";
    }

    cout<<endl;

    rep(i,0,n){
        cout<<ans2[i]<<" ";
    }
}
