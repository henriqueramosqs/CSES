// C++ program to demonstrate the
// ordered set in GNU C++
#include <iostream>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
const int MAXN = 2*1e5;
template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
ordered_set<pii> salaries;
// Driver program to test above functions
int main(){
    sws
    int n,q,a[200000];
    cin>>n>>q;
    
    
    rep(i,0,n){
        cin>>a[i];
        salaries.insert(mp(a[i],i));
    }
    
    
    while(q--){
        char op;cin>>op;
        
        if(op=='!'){
            int k,x;
            cin>>k>>x;
            k--;
            salaries.erase(salaries.find(mp(a[k],k)));
            a[k]=x;
            salaries.insert(mp(a[k],k));
        }else{
            int a,b;cin>>a>>b;b++;
            cout<<salaries.order_of_key(mp(b,0))-salaries.order_of_key(mp(a,0))<<endl;
        }
    }
    
    



}

