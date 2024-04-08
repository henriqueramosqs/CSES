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
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
int pots[20];
int dp[19][10];
 
void process(){
    pots[0]=1;
    rep(i,1,20)pots[i]=10*pots[i-1];
} 


bool canVary(int lim,int pos,int pref){
    int aux = pots[pos+1];aux--;
    return pref+aux<=lim;
}



// Dando ruim no 109
int calc(int lim,int pos = 18,int last=-1,int pref=0){

    // pref>lim
    if(pref>lim)return 0;

    // printf("pos:%d, last:%d, pref:%d\n",pos,last,pref);
    if(pos<0)return 1;


    bool goDbg = (pos==0 && last==0 && pref==100);

    if(last!=-1 && dp[pos][last]!=-1 && canVary(lim,pos,pref)){
        // printf("1)pos:%d, last:%d, pref:%d returning %d \n",pos,last,pref,dp[pos][last]);
        return dp[pos][last];
    }

 

    // só salvo se eu puder variar a voltade
    int ans = 0;
    rep(i,0,10){
        if(pref!=0 && last==i)continue;
        int aux = pref+i*pots[pos];
        if(aux>lim)break;
        ans+=calc(lim,pos-1,i,aux);
    }

    if(canVary(lim,pos,pref) && pref!=0)dp[pos][last]=ans;

    //  printf("2)pos:%d, last:%d, pref:%d returning %d \n",pos,last,pref,ans);
    return ans;
}


bool testa(int x){
    int last=-1;    
    while(x>0){
        int aux = x%10;
        x/=10;
        if(aux==last)return false;
        last=aux;
    }

    return true;
}

int brutecalc(int x){
    int ans=0;
    rep(i,0,x+1){
        if(testa(i))ans++;
    }
    return ans;
}


int32_t main(){
    sws
    process();
    int men,mai;
    cin>>men>>mai;

    memset(dp,-1,sizeof(dp));
    int aux_mai = calc(mai);
    memset(dp,-1,sizeof(dp));
    int aux_men = calc(men-1);

    // dbg("aux_mai",aux_mai)
    // dbg("aux_men",aux_men)

    cout<<aux_mai-aux_men;

    // cout<<calc(109)<<"\n";
    // cout<<brutecalc(109);
    // int counter=0;

    // while(true){
    //     memset(dp,-1,sizeof(dp));
    //     int a_1 = brutecalc(counter);;
    //     int a_2 = calc(counter);
    //     if(brutecalc(counter)!=calc(counter)){
    //         dbg("counter do ruim",counter)
    //          dbg("ans_ruim",a_1)
    //          dbg("ans_ruim",a_2)
    //         break;
    //     }

    //     dbg("counter_bom",counter)
    //     dbg("ans_bom",a_1)
    //     counter++;
    // }
}
 
