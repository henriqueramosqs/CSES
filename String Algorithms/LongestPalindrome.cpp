#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD1 = 1e9+7;
const int MOD2 =999999937;
const int M1 = 31;
const int M2 = 29;

int getNum(char a){
    return a-'a'+1;
}

struct  Hash{
    vi psum1;
    vi rev1;
    vi rev2;
    vi psum2;
    vi pot1;
    vi pot2;
    int n;

    Hash(string s):psum1(s.size(),0ll),psum2(s.size(),0ll),rev1(s.size(),0ll),rev2(s.size(),0ll),pot1(s.size()),pot2(s.size()){
        this->n = s.size();
        rep(i,0,n){
            pot1[i]=M1;
            pot2[i]=M2;
            if(i>0){
                (psum1[i]+=M1*psum1[i-1])%=MOD1;
                (psum2[i]+=M2*psum2[i-1])%=MOD2;
                (pot1[i]*=pot1[i-1])%=MOD1;
                (pot2[i]*=pot2[i-1])%=MOD2;
            }
            (psum1[i]+=getNum(s[i]))%=MOD1;
            (psum2[i]+=getNum(s[i]))%=MOD2;
            if(psum1[i]<0)psum1[i]+=MOD1;
            if(psum2[i]<0)psum2[i]+=MOD2;
            if(pot1[i]<0)pot1[i]+=MOD1;
            if(pot2[i]<0)pot2[i]+=MOD2;
        }

        rep(j,0,n){
            int i = n-1-j;
            if(j>0){
                (rev1[i]+=M1*rev1[i+1])%=MOD1;
                (rev2[i]+=M2*rev2[i+1])%=MOD2;
            }
            (rev1[i]+=getNum(s[i]))%=MOD1;
            (rev2[i]+=getNum(s[i]))%=MOD2;
            if(rev1[i]<0)rev1[i]+=MOD1;
            if(rev2[i]<0)rev2[i]+=MOD2;
        }
    }

    pii get(int l,int r){
        pii ans=mp(psum1[r],psum2[r]);
        if(l>0){
            int dif1=(psum1[l-1]*pot1[r-l])%MOD1;
            int dif2=(psum2[l-1]*pot2[r-l])%MOD2;
            if(dif1<0)dif1+=MOD1;if(dif2<0)dif2+=MOD2;
            (ans.ff-=(dif1))%=MOD1;
            (ans.ss-=(dif2))%=MOD2;
        }
        if(ans.ff<0)ans.ff+=MOD1;
        if(ans.ss<0)ans.ss+=MOD2;
        return ans;
    }

    pii getRev(int l,int r){
        pii ans=mp(rev1[l],rev2[l]);
        if(r<(n-1)){
            int dif1=(rev1[r+1]*pot1[r-l])%MOD1;
            int dif2=(rev2[r+1]*pot2[r-l])%MOD2;
            if(dif1<0)dif1+=MOD1;if(dif2<0)dif2+=MOD2;
            (ans.ff-=(dif1))%=MOD1;
            (ans.ss-=(dif2))%=MOD2;
        }
        if(ans.ff<0)ans.ff+=MOD1;
        if(ans.ss<0)ans.ss+=MOD2;
        return ans;
    }

    bool isPal(int l,int r){
        return get(l,r)==getRev(l,r);
    }


    bool isAnyPal(int x){
        rep(r,x-1,n){
            if(isPal(r-x+1,r))return true;
        }
        return false;
    }

    //sends size of pal as arument
    int findPal(int x){
        rep(r,x-1,n){
            if(isPal(r-x+1,r))return r-x+1;
        }
        return 0;
    }
    
};


int32_t main(){
    sws
    string s;cin>>s;
    Hash hash(s);
    int n = s.size();

    int k=0;
    for(int step = n/2;step>=1;step/=2){
        while(((k+step)<<1)<=n && hash.isAny((k+step)<<1))k+=step;
    }
    
    int k2=0;

    for(int step = n/2;step>=1;step/=2){
        while((((k2+step)<<1)|1)<=n && hash.isAny(((k2+step)<<1)|1))k2+=step;
    }

    
    if((k<<1) > (k2<<1|1)){
        int pos = hash.find(k<<1);
        cout<<s.substr(pos,k<<1)<<"\n";
    }else{
        int pos = hash.find(k2<<1|1);
        cout<<s.substr(pos,k2<<1|1)<<"\n";
    }
}   
