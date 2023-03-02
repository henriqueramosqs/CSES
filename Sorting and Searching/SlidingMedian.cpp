
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
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int main(){
	sws
	int n,k;
	cin>>n>>k;
	oset<pii>s;
	int a[n];
	rep(i,0,n)cin>>a[i];
	int pos1=0,pos2=k;
	int pos = k/2;
	if(k%2==0)pos--;
	rep(i,0,k)s.insert(mp(a[i],i));
	while(pos2<=n){
	   cout<<(s.find_by_order(pos))->ff<<" ";
	   s.erase(mp(a[pos1],pos1));
	   s.insert(mp(a[pos2],pos2));
	   pos1++;pos2++;
	}
}
