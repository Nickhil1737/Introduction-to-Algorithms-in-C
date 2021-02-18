#include<stdio.h>
#include<stdlib.h>

long long ans;
long long arr[200009];
long long S[200009];

int max(int x, int y)
{
    return x*(x>y) + y*(x<=y);
}
int min(int x, int y)
{
    return x*(x<y) + y*(x>=y);
}
void setSum(int N,int i, int v)
{
    int k = (1<<N)-1+i;
    S[k] = v;
    while (k > 0) {
        k = k/2;
        S[k] = S[k*2]+S[k*2+1];
    }
}

long long findSum (int v,int tl, int tr,int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return S[v];
    }
    int tm = (tl + tr) / 2;
    return findSum(v*2, tl, tm, l, min(r, tm))
           + findSum(v*2+1, tm+1, tr, max(l, tm+1), r);

}
void solve ()
{
    int n,m,k,q;  
    scanf("%d %d",&n,&q);
    for (int i = 0; i < n;++i) {
        scanf("%d",&arr[i]);
    }
    ans = 0;

    int num = n,N = 1;
    while (num > 1) {
        num = num/2;
        N++;
    }
    for (int i = (1<<N); i < (1<<(N+1))+1; ++i) {
        if (i-(1<<N) < n)
            S[i] = arr[i-(1<<N)];
        else
            S[i] = 0;
    }
    for (int i = (1<<N)-1; i > 0; --i) {
        S[i] = S[i<<1] + S[(i<<1)+1];
    }
    while (q--) {
        int a,b,c;  
        scanf("%d %d %d",&a,&b,&c);
        if (a == 1) {
            setSum(N,b+1,c);
        }
        else {
            ans = findSum(1,1,(1<<N),b+1,c);
            printf("%lld\n",ans);
        }
        
    }
}

int main ()
{
    solve();
    return 0;
}


/*
Sunday 14 February 2021 03:11:59 PM IST
     author:   __astrainL3gi0N
*/

