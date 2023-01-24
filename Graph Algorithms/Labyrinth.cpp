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
const int MAXN = 1e3;
char grid[MAXN][MAXN];
char ans[MAXN][MAXN];
int distances[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n,m;

int main(){
    // sws
    cin>>n>>m;
    pii strt;
    pii fin;

    rep(i,0,n){
        rep(j,0,m){
            cin>>grid[i][j];

            distances[i][j]=INT32_MAX;
            visited[i][j]=false;
            
            if(grid[i][j]=='A'){
                strt=mp(i,j);
            }
            
            if(grid[i][j]=='B'){
                fin=mp(i,j);
            }       

        }
    }

    pq <pair< pair<int,char>,pii> >p;

    distances[strt.ff][strt.ss]=0;
    ans[strt.ff][strt.ss]='X';

    p.push(mp(mp(0,'X'),mp(strt.ff,strt.ss)));

    bool found = false;

    while(!p.empty()){

        pii cur = p.top().ss;
        char hT = p.top().ff.ss;
        int i = cur.ff,j=cur.ss;
        p.pop();      

        if(visited[i][j])continue;

        visited[i][j]=true;   
        ans[i][j]=hT;
        
        if(grid[i][j]=='B'){
            found = true;
            break;
        }   

        if(i>0 && grid[i-1][j]!='#' && !visited[i-1][j] && (distances[i][j]+1< distances[i-1][j] )){
            distances[i-1][j] = distances[i][j]+1;
            p.push(mp(mp(-distances[i-1][j],'U'),mp(i-1,j)));
        }

        if(j>0 && grid[i][j-1]!='#' && !visited[i][j-1] && (distances[i][j]+1< distances[i][j-1] )){
            distances[i][j-1] = distances[i][j]+1;
            p.push(mp(mp(-distances[i][j-1],'L'),mp(i,j-1)));
        }

        if(i<(n-1) && grid[i+1][j]!='#' && !visited[i+1][j] && (distances[i][j]+1< distances[i+1][j] )){
            distances[i+1][j] = distances[i][j]+1;
            p.push(mp(mp(-distances[i+1][j],'D'),mp(i+1,j)));
        }

        if(j<(m-1) && grid[i][j+1]!='#' && !visited[i][j+1] && (distances[i][j]+1< distances[i][j+1] )){
            distances[i][j+1] = distances[i][j]+1;
            p.push(mp(mp(-distances[i][j+1],'R'),mp(i,j+1)));
        }

    }

    if(!found){
        cout<<"NO";
        return 0;
    }

    cout<<"YES\n";

    stack<char>fil;

    pii cur = fin;

    while(ans[cur.ff][cur.ss]!='X'){
        char hT = ans[cur.ff][cur.ss];
        fil.push(hT);

        if(hT =='R'){
            cur = mp(cur.ff,cur.ss-1);
            continue;
        }

        if(hT =='L'){
            cur = mp(cur.ff,cur.ss+1);
            continue;
        }

        if(hT =='U'){
            cur = mp(cur.ff+1,cur.ss);
            continue;
        }

        if(hT =='D'){
            cur = mp(cur.ff-1,cur.ss);
            continue;
        }

    }

    cout<<fil.size()<<"\n";

    while(!fil.empty()){
        cout<<fil.top();
        fil.pop();
    }
   
}