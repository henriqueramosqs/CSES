MAXN = 101

dp = [[0 for i in range(MAXN)] for j in range(MAXN)]
fact = [0 for j in range(MAXN)]

def process():
    for a in range(0,MAXN):
        dp[a][0]=1
        dp[a][1]=a
        for b in range(2,MAXN):
            dp[a][b]=a*dp[a][b-1]

    fact[0]=fact[1]=1
    for i in range(2,MAXN):
        fact[i]=i*fact[i-1]

process()
n,k = map(int,input().split())

ans=0

for val in range(1,k+1):
    aux=0
    for qtd in range(1,n+1):
        comb = fact[n]/(fact[qtd]*fact[n-qtd])
        if(qtd%2==0):
            aux-=comb*dp[val][n-qtd]
        else:
            aux+=comb*dp[val][n-qtd]
    aux*=val
    ans+=aux


ret = (ans)/(dp[k][n])
print(f"{ret:.6f}")
