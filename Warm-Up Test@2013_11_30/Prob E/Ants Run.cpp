/*
 *  ID:     Allen_3
 *  Prob:   Ants Run!
 *  LANG:   C++
*/
#include<cstdio>
using namespace std;

#define     pi      3.1415926
#define     INF     3f3f3f3f

int T , n , r;
int a[10002];

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        bool flag = false;
        scanf("%d%d" , &n , &r);
        for (int i = 0;i < n;i ++)
        {
            scanf("%d" , &a[i]);
            if (i && a[i] != a[i - 1])
                flag = true;
        }
        if (!flag)
        {
            printf("Inf\n"); continue;
        }
        a[n] = a[0];
        int sum = 0;
        for (int i = 0;i < n;i ++)
        {
            a[i] = a[i + 1] - a[i];
            if (a[i] > 0)
                sum += a[i];
        }
        printf("%.3f\n" , 2 * pi * (double)r / (double)sum);
    }   //for i _ T

    return 0;
}   //main
