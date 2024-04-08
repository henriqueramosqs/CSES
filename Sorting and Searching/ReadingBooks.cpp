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
#define int long long
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;


struct Book{
   int t,a,b;
    Book(int t,int a,int b){
        this->t =t;
        this->a =a;
        this->b =b;
    }

    void show(){
        printf("t: %lld, a: %lld, b:%lld\n",t,a,b);
    }

    bool uniq(){
        return a^b;
    }
};



bool Comp(Book a,Book b){
    if(a.t<b.t)return true;
    if(a.t>b.t) return false;
    return a.a==b.b;
}


int32_t main(){
    sws
    int n,k;cin>>n>>k;

    int sum=0;
    pq<int>alice,bob;

    int aBooks=0,bBooks=0;

    vector<Book>v;

    rep(i,0,n){
        int t,a,b;
        cin>>t>>a>>b;
        if(a==0 && b==0)continue;   
        v.pb(Book(t,a,b));
    }

    sort(v.begin(),v.end(),Comp);


    for(auto c:v){
       if(c.uniq()){
            if(c.a!=0){
                if(aBooks>=k)continue;
                alice.push(c.t);
                aBooks++;
                sum+=c.t;
            }else{
                if(bBooks>=k)continue;
                bob.push(c.t);
                bBooks++;
                sum+=c.t;
            }
       }else{

            // se alguém tiver precisando...
            if(aBooks<k || bBooks<k){
                sum+=c.t;

                if(bBooks>=k && !bob.empty()){
                    bBooks--;
                    sum-=bob.top();
                    bob.pop();
                }

                if(aBooks>=k && !alice.empty()){
                    aBooks--;
                    sum-=alice.top();
                    alice.pop();
                }

                aBooks++;bBooks++;
                continue;
            }

            int taken=0;

            if(!bob.empty())taken+=bob.top();
            if(!alice.empty())taken+=alice.top();

            if(c.t<taken){
                sum-=alice.top();
                sum-=bob.top();
                alice.pop();bob.pop();
                sum+=c.t;
            }
       }

    }


    if(aBooks<k || bBooks<k){
        cout<<-1;
    }else{
        cout<<sum;
    }
}
