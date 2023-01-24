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

void print(bool a[],int chars){
    rep(i,16-chars,16){
        cout<<a[i];
    }
    cout<<endl;
}

int main(){
    sws
    int n;cin>>n;

    int nums = (1<<16);
    bool gc[nums][16];
    gc[1][15]=1;

    int pos = 14;
    int cpDist = 1;

    rep(i,2,nums){
        if( (i-cpDist) <0){
            pos--;
            cpDist=1;
        }

        gc[i][pos]=1;

        rep(aux,pos+1,16){
            gc[i][aux]=gc[i-cpDist][aux];
        }

        cpDist+=2;
    }

    rep(i,0,(1<<n)){
        print(gc[i],n);
    }
}
