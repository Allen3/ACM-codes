/*
 *  ID:     Allen_3
 *  Prob:   The Game of Little P
 *  LANG:   C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define     MOD     1000000007LL

#ifdef unix
#define     LL_FMT      "%lld"
#else
#define     LL_FMT      "%I64d"
#endif // unix

int T;
long long n , m;

void solve()
{
    long long ans = 0 , tmp;
    long long a = m * (m + 1) ;
    long long b = 2 * m + 1;
    bool flag1 = false , flag2 = false;

    if (!flag1 && (a % 2 == 0))
    {
        flag1 = true;
        a = a / 2;
    }
    if (!flag2 && (a % 3 == 0))
    {
        flag2 = true;
        a = a / 3;
    }
    if (!flag1 && (b % 2 == 0))
    {
        flag1 = true;
        b = b / 2;
    }
    if (!flag2 && (b % 3 == 0))
    {
        flag2 = true;
        b = b / 3;
    }

    tmp = ((a % MOD) * (b % MOD)) % MOD;

    long long ll = n / (m + 1) , mm;
    ans = (tmp * ll) % MOD;

    mm = n - ll * (m + 1);
    a = mm * (mm + 1); b = 2 * mm + 1;
    flag1 = false ; flag2 = false;

    if (!flag1 && (a % 2 == 0))
    {
        flag1 = true;
        a = a / 2;
    }
    if (!flag2 && (a % 3 == 0))
    {
        flag2 = true;
        a = a / 3;
    }
    if (!flag1 && (b % 2 == 0))
    {
        flag1 = true;
        b = b / 2;
    }
    if (!flag2 && (b % 3 == 0))
    {
        flag2 = true;
        b = b / 3;
    }

    tmp = ((a % MOD) * (b % MOD)) % MOD;

    ans = (ans + tmp) % MOD;
    printf(LL_FMT"\n" , ans);
}   //solve

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        scanf(LL_FMT LL_FMT , &n , &m);
        solve();
    }   //for i _ T

    return 0;
}   //main
