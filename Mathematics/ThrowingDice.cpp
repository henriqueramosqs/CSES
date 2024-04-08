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
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD = 1e9+7;

struct Mat{

    int lines;
    int cols;
    vvi v;


    Mat(){
        lines=cols=0;
        v = vvi(0);
    }
    Mat(vvi& v ){
        this->v=v;
        lines=v.size();
        cols = v[0].size();
    }


    Mat operator*(const Mat &m){
        int l1=lines,l2 = m.lines;
        int c1 = cols,c2=m.cols;
        vvi ans(l1,vi(c2,0));

        rep(l,0,l1){
            rep(c,0,c2){
                rep(i,0,c1){
                    (ans[l][c]+=(v[l][i]*m.v[i][c]))%=MOD;
                }
            }
        }

        return Mat(ans);
    }

    Mat operator^(int b){
        if(b==1)return Mat(v);
        Mat ans = *this^(b/2);
        ans = ans*ans;
        if(b%2==1) ans = (ans*v);
        return ans;
    }
};


vvi base(6,vi(6,0));
vvi aux(6,vi(1));

Mat basemat;
Mat auxmat;

void process(){
    rep(i,0,6)base[0][i]=1;
    rep(i,1,6)base[i][i-1]=1;

    aux[5][0]=1;

    rep(i,1,6){
        aux[5-i][0]=(aux[5-i+1][0]<<1);
    }

    basemat=Mat(base);
    auxmat=Mat(aux);
}

int32_t main(){
    sws
    int n;
    cin>>n;
    process();



    if(n<=6){
        cout<<aux[6-n][0];
        return 0 ;
    }


    Mat res = basemat^(n-6);
    res = res*auxmat;
    cout<<res.v[0][0];
}
