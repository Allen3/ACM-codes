#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define     INF     0x3f3f3f3f

int T , n , p;
char str[1010];
int que[1010];

void solve()
{
    for (int i = 0;i <= n;i ++)
            que[i] = INF;
    int head = 0 , tail = 0 , ans = 0 , cnt = 0;
    for (int i = 0;i < n;i ++)
    {
        //printf("%d %d %d %d %d\n" , i , head , tail , ans , cnt);
        if (str[i] == '2')
            if (head < tail)
            {
                head ++;
                cnt += 2;
            }
        if (que[head] + p == i)
        {
            head ++;
        }
        if (str[i] == '1')
        {
            que[tail ++] = i;
        }
        if (cnt + tail - head > ans)
                ans = tail - head + cnt;

    }
    printf("%d\n" , ans);
}   //solve

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        scanf("%d%d" , &n , &p);
        scanf("%s" , str);
        solve();
    }   //

    return 0;
}   //main
