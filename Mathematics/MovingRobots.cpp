#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
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
typedef pair<pii,int >pp;
ld dp[8][8][8][8][101];
ld tot[8][8];
vi dx{-1,0,0,1};
vi dy{0,-1,+1,0};

bool isIn(int x,int y){
    return (x>=0 && y>=0 && x<8 && y<8);
}

int32_t main(){
    sws 
    rep(i,0,8)rep(j,0,8)dp[i][j][i][j][0]=1.0;
    
    rep(x,0,8){
        rep(y,0,8){
            rep(d,0,4){
                int nx =x+dx[d];
                int ny = y+dy[d];
                if(isIn(nx,ny))tot[x][y]+=1.0;
            }
        }
    }
    
    rep(day,1,101){
        rep(x,0,8){
            rep(y,0,8){
                rep(d,0,4){
                    int nx =x+dx[d];
                    int ny = y+dy[d];
                    if(!isIn(nx,ny))continue;
                    rep(orgx,0,8){
                        rep(orgy,0,8){
                            dp[orgx][orgy][x][y][day]+=(dp[orgx][orgy][nx][ny][day-1]/tot[nx][ny]);
                        }
                    }
                }
            }
        }
    }
    
    int n;cin>>n;
    ld ans = 0.0;

    rep(x,0,8){
        rep(y,0,8){
            ld cont = 1.0;
            rep(orgx,0,8){
                rep(orgy,0,8){
                    cont*=(1.0-dp[orgx][orgy][x][y][n]);
                }
            }
            ans+=cont;
        }
    }

    cout<<fixed<<setprecision(6)<<ans;
    
}


// pq n usar o principio
