#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int T , n , k;

inline int min(int x , int y)
{
    if (x < y)
        return x;
    return y;
}   //min

int main()
{
    int T , n , k;
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        scanf("%d%d" , &n , &k);
        int ans = 0;
        for (int i = 1;i <= n;i ++)
        {
            if (i % (k + 1))
                ans += min(k , n - i);
        }
        printf("%d\n" , ans);

    }
    return 0;
}   //main
