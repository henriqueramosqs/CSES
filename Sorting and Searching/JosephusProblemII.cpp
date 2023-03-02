
#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> using oset =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ll long long 
#define ff first
#define ss second
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int main(){
    sws
	int n,k;
	cin>>n>>k;
	oset<int>kids;
	rep(i,0,n)kids.insert(i+1);
	int pos = 0;
    while(!kids.empty()){
      pos = (pos+k)%kids.size();
       auto it = kids.find_by_order(pos);
       cout<<*it<<" ";
       kids.erase(it);
    }
}
