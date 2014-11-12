/*
 *  ID:     Allen_3
 *  Prob:   Fruit Ninja
 *  LANG:   C++
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define     input       "test.txt"
#define     output      "result.txt"

#ifdef unix
#define     LL_FMT      "%lld"
#else
#define     LL_FMT      "%I64d"
#endif

int a[2002];
int T , cnt = 0;
long long ans , n , m;

inline long long max(long long x , long long y)
{
    if (x > y)
        return x;
    return y;
}   //max

long long solve(int x)
{
    long long num = 5555LL;
    for (int i = 1;i <= 100;i ++)
    {
        num = num * 10LL + 5LL;
        if (!((num - x) % m))
            return (num + m + n);
    }   //for i
}   //solve

int main()
{
    //freopen(input  , "r" , stdin);
    //freopen(output , "w" , stdout);

    for (int i = 1;i <= 10000;i ++)
        if (!(i % 5))
            a[cnt ++] = i;

    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        printf("Case #%d: " , i + 1);
        scanf(LL_FMT LL_FMT , &m , &n);
        //printf(LL_FMT" "LL_FMT" ", m , n);
        if (!(m % 10LL))
        {
            printf("INF\n");
        }
        else if (!(m % 5LL) && (m % 10LL))
        {
            if (!(n % 5LL))
            {
                printf("INF\n");
            }
            else
            {
                if (m == 35 || m == 25)
                {
                    printf("INF\n"); continue;
                }
                ans = 0;
                for (int i = 0;i < cnt;i ++)
                    ans = max(ans , solve(a[i]));
                printf(LL_FMT"\n" , ans);
            }
        }
        else
        {
            ans = 9999LL + n;
            if (!(ans % 5LL))
                ans += m;
            if (10000LL + m > ans)
                ans = 10000LL + m;
            printf(LL_FMT"\n" , ans);
        }

    }   //for i _ T

    return 0;
}   //main
