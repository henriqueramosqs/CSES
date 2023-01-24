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

int main(){
    sws
    int n;
    queue<int>p;
    cin>>n;
    rep(i,1,n+1)p.push(i);
    bool takes=false;
     
    while(!p.empty()){
        int cur = p.front();
        p.pop();
        if(takes){
            cout<<cur<<" ";
        }else{
            p.push(cur);
        }
        takes =!takes;
    }
}
