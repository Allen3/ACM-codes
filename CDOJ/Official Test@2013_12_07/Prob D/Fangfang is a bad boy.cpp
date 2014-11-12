#include<cstdio>
#include<cstring>
using namespace std;

#define     output      "test.txt"

int T , n , p;
int a[100010] , sum[100010];
int front[12] , rear[12];

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        memset(front , -1 , sizeof(front));
        memset(rear  , -1 , sizeof(rear));

        scanf("%d%d" , &n , &p);
        for (int i = 0;i < n;i ++)
        {
            scanf("%d" , &a[i]);
            if (i)
                sum[i] = (sum[i - 1] + a[i]) % p;
            else
                sum[i] = a[i] % p;
        }

        for (int i = 0;i < n;i ++)
            if (front[sum[i]] == -1)
                front[sum[i]] = i;

        for (int i = n - 1;i >= 0;i --)
            if (rear[sum[i]] == -1)
                rear[sum[i]] = i;

        front[0] = -1;
        int ans = 1;
        for (int i = 0;i < p;i ++)
        {
            if (rear[i] - front[i] > ans)
                ans = rear[i] - front[i];
        }

        printf("%d\n" , ans);
    }   //for i _ T

    return 0;
}   //main
