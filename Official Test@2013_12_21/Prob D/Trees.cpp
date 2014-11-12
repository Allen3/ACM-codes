/*
 *  ID:     Allen_3
 *  Prob:   Trees
 *  LANG:   C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int T , n;
int arr[100010];
int hash[300010];

void solve()
{
    memset(hash , 0 , sizeof(hash));
    for (int i = 0;i < (n >> 1);i ++)
    {
        arr[i] -= i;
        arr[n - i - 1] -= i;
    }   //for i _ n
    if (n & 1)
        arr[n >> 1] -= (n >> 1);

    for (int i = 0;i < n;i ++)
    {
        if (arr[i] > 0)
            hash[arr[i]] ++;
    }

    int ans = 0;
    for (int i = 0;i < n;i ++)
    {
        if (arr[i] > 0 && hash[arr[i]] > ans)
            ans = hash[arr[i]];
    }
    printf("%d\n" , n - ans);
}   //solve

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        scanf("%d" , &n);
        for (int i = 0;i < n;i ++)
            scanf("%d" , &arr[i]);
        solve();
    }   //for i _ T

    return 0;
}   //main
