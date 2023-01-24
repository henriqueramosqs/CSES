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
#define pq xpriority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int main(){
    sws
    int n,m;
    cin>>n>>m;

    int a[n];
    int where_is[n+2];
    where_is[0]=n+1;
    where_is[n+1]=-1;
    
    rep(i,0,n){
        int x;cin>>x;
        a[i]=x;
        where_is[x]=i;
    }

    int ans=0;

    rep(i,0,n){
        int num = a[i];
        if(where_is[num-1]>where_is[num]){
            ans++;
        }
    }


    rep(i,0,m){
        int pos_1,pos_2;
        cin>>pos_1>>pos_2;
        pos_1--;
        pos_2--;
        int num_1=a[pos_1];
        int num_2 = a[pos_2];
        //Referencia antecessor

        bool first_was_aft_ant = where_is[num_1]>where_is[num_1-1];
        bool sec_was_aft_ant = where_is[num_2]>where_is[num_2-1];

        bool first_was_aft_suc = where_is[num_1]>where_is[num_1+1];
        bool sec_was_aft_suc = where_is[num_2]>where_is[num_2+1];

        a[pos_1]=num_2;
        a[pos_2]=num_1;
        where_is[num_2]=pos_1;
        where_is[num_1]=pos_2;

        bool first_sent_aft_ant = where_is[num_1]>where_is[num_1-1];
        bool sec_sent_aft_ant = where_is[num_2]>where_is[num_2-1];


        bool first_sent_aft_suc = where_is[num_1]>where_is[num_1+1];
        bool sec_sent_aft_suc = where_is[num_2]>where_is[num_2+1];

        if(first_was_aft_ant==false && first_sent_aft_ant==true )ans--;

        if(first_was_aft_ant==true && first_sent_aft_ant==false)ans++;
 
        if(sec_was_aft_ant==false && sec_sent_aft_ant==true)ans--;

        if(sec_was_aft_ant==true && sec_sent_aft_ant==false)ans++;

        if((num_2-num_1)!=1){
            if(first_was_aft_suc==false && first_sent_aft_suc==true )ans++;

            if(first_was_aft_suc==true && first_sent_aft_suc==false)ans--;

        }

        if((num_1-num_2)!=1){

            if(sec_was_aft_suc==false && sec_sent_aft_suc==true)ans++;

            if(sec_was_aft_suc==true && sec_sent_aft_suc==false)ans--;
            
        }
        cout<<ans<<endl;

    }
}


// se num_1 = num_2 +1, ver se 