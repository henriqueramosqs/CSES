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
    string s;cin>>s;
    int qtdOdd=0,qtdEven=0,sz=s.size();
    map<char,int>m;

    for(char c:s){
        m[c]++;
        int aux = m[c];
        if(aux%2==0){
            qtdOdd--;
            qtdEven++;
        }else{
            if(aux!=1)qtdEven--;
            qtdOdd++;
        }
    }

    if(sz%2==0){
        if(qtdOdd>=1){
            cout<<"NO SOLUTION";
            return 0;
        }

        string s;
        for(auto j:m){
            char c = j.ff;
            int qtd = j.ss;
            rep(i,0,qtd/2)s+=c;
        }

        cout<<s;
        
        for(int i =s.size()-1;i>=0;i--){
            cout<<s[i];
        }
        return 0;

    }else{
        if(qtdOdd>1){
            cout<<"NO SOLUTION";
            return 0;
        }

        string s;
        pair<char,int>stored = mp('1',0);

        for(auto j:m){
            char c = j.ff;
            int qtd = j.ss;
            if(qtd%2!=0){
                stored = mp(c,qtd);
                continue;
            }
            rep(i,0,qtd/2)s+=c;
        }

        if(stored.ff!='1'){
            rep(i,0,(stored.ss+1)/2){
                s+=stored.ff;
            }
            cout<<s;
            for(int i =s.size()-2;i>=0;i--){
                cout<<s[i];
            }
            return 0;
        }

        cout<<s;
        for(int i =s.size()-1;i>=0;i--){
            cout<<s[i];
        }
        return 0;
    }
}


2 hj
4 ontem 