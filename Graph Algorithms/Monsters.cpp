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

    int n,m;
    cin>>n>>m;

    char grid[n][m];
    int monsterDists[n][m];  
    bool monsterVisited[n][m];

    rep(i,0,n*m)monsterDists[i/m][i%m]=__INT32_MAX__;
    memset(monsterVisited,false,n*m);

    int humanDists[n][m];
    char humanPath[n][m];
    bool humanVisited[n][m];

    rep(i,0,n*m)humanDists[i/m][i%m]=__INT32_MAX__;
    memset(humanVisited,false,n*m);

    pii humanPos;
    pq<pair<int,pii > >q;

    rep(i,0,n){
        rep(j,0,m){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                humanPos=mp(i,j);
                humanDists[i][j]=0;
            }
            if(grid[i][j]=='M'){
                q.push(mp(0,mp(i,j)));
                monsterDists[i][j]=0;
            }
        }
    }

    humanPath[humanPos.ff][humanPos.ss]='X';

    while(!q.empty()){
        int dist = -q.top().ff;
        pii pos = q.top().ss;
        int x = pos.ff, y=pos.ss;
        q.pop();
        if(monsterVisited[x][y])continue;
        monsterVisited[x][y]=true;

        if(x>0 && monsterDists[x-1][y]>dist+1 && grid[x-1][y]!='#'){
            q.push(mp(-(dist+1),mp(x-1,y)));
            monsterDists[x-1][y]=dist+1;
        }
        
        if(y>0 && monsterDists[x][y-1]>dist+1 && grid[x][y-1]!='#'){
            q.push(mp(-(dist+1),mp(x,y-1)));
            monsterDists[x][y-1]=dist+1;
        }
        
        if(x<(n-1) && monsterDists[x+1][y]>dist+1 && grid[x+1][y]!='#'){
            q.push(mp(-(dist+1),mp(x+1,y)));
            monsterDists[x+1][y]=dist+1;
        }

        if(y<(m-1) && monsterDists[x][y+1]>dist+1 && grid[x][y+1]!='#'){
            q.push(mp(-(dist+1),mp(x,y+1)));
            monsterDists[x][y+1]=dist+1;
        }


    }

    q.push(mp(0,humanPos));

    if(humanPos==mp(0,0) || humanPos==mp(0,m-1) 
        || humanPos==mp(n-1,0) || humanPos==mp(n-1,m-1)){
            cout<<"YES\n0";
            return 0;
        }


    pii poss;
    while(!q.empty()){
        int dist = -q.top().ff;
        pii pos = q.top().ss;
        int lin = pos.ff, col=pos.ss;
        q.pop();
        if(humanVisited[lin][col])continue;
        humanVisited[lin][col]=true;

        if(lin>0 && humanDists[lin-1][col]>dist+1 && grid[lin-1][col]!='#' && dist+1<monsterDists[lin-1][col]){
            q.push(mp(-(dist+1),mp(lin-1,col)));
            humanDists[lin-1][col]=dist+1;
            humanPath[lin-1][col]='U';
            if(lin-1==0){
                poss = mp(lin-1,col);
                goto finish; 
            }
        }
        
        if(col>0 && humanDists[lin][col-1]>dist+1 && grid[lin][col-1]!='#' && dist+1<monsterDists[lin][col-1]){
            q.push(mp(-(dist+1),mp(lin,col-1)));
            humanDists[lin][col-1]=dist+1;
            humanPath[lin][col-1]='L';

            if(col-1==0){
                poss = mp(lin,col-1);
                goto finish; 
            }

        }
        
        if(lin<(n-1) && humanDists[lin+1][col]>dist+1 && grid[lin+1][col]!='#' && dist+1<monsterDists[lin+1][col]){
            q.push(mp(-(dist+1),mp(lin+1,col)));
            humanDists[lin+1][col]=dist+1;
            humanPath[lin+1][col]='D';
        
            if(lin+1==(n-1)){
                poss = mp(lin+1,col);
                goto finish; 
            }

        }

        if(col<(m-1) && humanDists[lin][col+1]>dist+1 && grid[lin][col+1]!='#' && dist+1<monsterDists[lin][col+1] ){
            q.push(mp(-(dist+1),mp(lin,col+1)));
            humanDists[lin][col+1]=dist+1;
            humanPath[lin][col+1]='R';

            if(col+1==(m-1)){
                poss = mp(lin,col+1);
                goto finish; 
            }
        }

    }


    cout<<"NO";
    return 0;

finish:
    stack<char>s;   
    s.push(humanPath[poss.ff][poss.ss]);


    while(true){
        int lin = poss.ff;
        int col = poss.ss;

        if(s.top()=='X')break;

        if(s.top()=='L'){
            poss.ss++;
            s.push(humanPath[lin][col+1]);
            continue;
        }

        if(s.top()=='R'){
            poss.ss--;
            s.push(humanPath[lin][col-1]);
            continue;
        }

        if(s.top()=='U'){
            poss.ff++;
            s.push(humanPath[lin+1][col]);
            continue;
        }

        if(s.top()=='D'){
            poss.ff--;
            s.push(humanPath[lin-1][col]);
            continue;
        }
    
    }
    s.pop();

    cout<<"YES\n"<<s.size()<<"\n";
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}
