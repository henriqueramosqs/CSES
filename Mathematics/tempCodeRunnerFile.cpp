
        int term = comb((x<<1) -1,x);
        dbg("p1:",comb((x<<1) -1,x))
        term*=comb( (n<<1) - (x<<1) +1,n-x );
        dbg("cima",(n<<1) - (x<<1) +1)
        dbg("baixo",n-x);
        dbg("p2:",comb( (n<<1) - (x<<1) +1,n-x ))
        term%=MOD;
        dbg("term",term)cout<<endl;
        ans-=term;
    }