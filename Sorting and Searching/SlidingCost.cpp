
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
#define int long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
	sws
	int n,k;
	cin>>n>>k;
	int a[n];rep(i,0,n)cin>>a[i];
	oset<pii>o;
	set<pii>ls,rs;
	int lsum=0,rsum=0;
	
	rep(i,0,k){
	    o.insert(mp(a[i],i));
	}
	
	int median = o.find_by_order(k/2)->ff;
	
	rep(i,0,k){
	    if(a[i]<=median){
	       lsum+=a[i];
	       ls.insert(mp(a[i],i));
	    }else{
	       rsum+=a[i];
	       rs.insert(mp(a[i],i));
	    }
	}   
	cout<<rsum-(rs.size())*median +(ls.size())*median-lsum<<" ";
	int toCut=0;
	
	rep(i,k,n){
	    o.erase(o.find(mp(a[toCut],toCut)));
	    
	    if(a[toCut]<=median){
	       ls.erase(mp(a[toCut],toCut));
	       lsum-=a[toCut];
	    }else{
	       rs.erase(mp(a[toCut],toCut));
	       rsum-=a[toCut];
	    }
	    
	    o.insert( mp(a[i],i) );
	    median = o.find_by_order(k/2)->ff;
	    
	    if(a[i]<=median){
	       ls.insert(mp(a[i],i));
	       lsum+=a[i];
	    }else{
	       rs.insert(mp(a[i],i));
	       rsum+=a[i];
	    }
	    
	    while(!rs.empty() && (rs.begin()->ff)<=median){
	        ls.insert(*rs.begin());
	        lsum+=(rs.begin()->ff);
	        rsum-=(rs.begin()->ff);
	        rs.erase(rs.begin());
	    }
	    
	    while((--ls.end())->ff>median){
	        auto it = --ls.end();
	        rs.insert(*it);
	       	rsum+=(rs.begin()->ff);
	        lsum-=(rs.begin()->ff);
	        ls.erase(it);
	    }
	    cout<<rsum-(rs.size())*median +(ls.size())*median-lsum<<" ";
	    toCut++;
	}
}
