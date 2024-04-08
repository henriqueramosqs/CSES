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
#define endl '\n'
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

struct  Group{
    bool a,t,c,g;
    Group(){
        a=false;
        t=false;
        c=false;
        g=false;
    }
    
    void add(char x){
        switch (x){
            case 'A':
                a=true;
                break;
            case 'T':
                t=true;
                break;
            case 'C':
                c=true;
                break;
            default:
                g=true;
        }
    }

    bool isFull(){
        return (a==true && t==true && c==true && g==true);
    }

    void clear(){
        a=false;
        t=false;
        c=false;
        g=false;
    }

    char getLacking(){
        if(!a)return 'A';
        if(!t)return 'T';
        if(!c)return 'C';
        return 'G';
    }


    friend ostream& operator<<(ostream& os, const Group& g) {
        os << "A: " << g.a << ", ";
        os << "T: " << g.t << ", ";
        os << "C: " << g.c << ", ";
        os << "G: " << g.g << "\n";
        return os;
    }

};

int32_t main(){
    sws
    string s;cin>>s;
    int gps=0;
    Group gp;

    string ans="";

    for(char c:s){
        gp.add(c);
        if(gp.isFull()){
            gps++;
            ans+=c;
            gp.clear();
        }
    }

    // dbg("gps",gps)
    // cout<<gp;

    cout<<ans<<gp.getLacking();
}

