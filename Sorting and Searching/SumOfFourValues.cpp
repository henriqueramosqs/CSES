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
typedef vector< bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5+1;

int32_t main(){
    sws 
    int n,k;
    cin>>n>>k;
    vpp v;
    rep(i,1,n+1){
        int x;cin>>x;
        v.pb(mp(x,i));
    }

    sort(v.begin(),v.end());

    // for(auto c:v){
    //     cout<<c.ff<<" "<<c.ss<<endl;
    // }
    // cout<<endl; 
    int p1=0,p2 =1;

    int sum=0;

    while(p1<=(n-4)){
        sum = v[p1].ff;

        while(p2<=(n-3)){
            sum+=v[p2].ff;

            int l = p2+1, r = n-1;

            while(l<r){
                sum+=v[l].ff;
                sum+=v[r].ff;

                if(sum==k){
                    cout<<v[p1].ss<<" "<<v[p2].ss<<" "<<v[l].ss<<" "<<v[r].ss;
                    return 0;
                }     
                
                if(sum<k){
                    sum-=v[l].ff;
                    sum-=v[r].ff;
                    l++;
                }

                if(sum>k){
                    sum-=v[l].ff;
                    sum-=v[r].ff;
                    r--;
                }
            }

            sum-=v[p2].ff;
            p2++;
        }
        p1++;
        p2=p1+1;
    }

    cout<<"IMPOSSIBLE";
}
