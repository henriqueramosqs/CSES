#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}
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
    cin>>n;
    if(n==3 ||  n==2){
        cout<<"NO SOLUTION";
        return 0;
    }


    if(n==4){
        cout<<"2 4 1 3";
        return 0;
    }
    int a[n];
    int pos=0;

    rep(i,1,n+1){
        a[pos]=i;
        pos+=2;
        if(pos>=n)pos=1;
    }


    output(a);
}