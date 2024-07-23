from decimal import Decimal, getcontext

def c(x):
    return (x * (x - 1)) // 2

def main():
    getcontext().prec = 50

    n = int(input())
    ans = Decimal('0.0')
    v = list(map(int, input().split()))
    
    for i in range(n):
        for j in range(i + 1, n):
            ctr = 0
            if v[i] <= v[j]:
                ctr = c(v[i])
            else:
                ctr = c(v[j])
                ctr += (v[i] - v[j]) * v[j]
            ans += Decimal(ctr) / Decimal(v[i] * v[j])
    
    print(f"{ans:.6f}")

if __name__ == "__main__":
    main()
