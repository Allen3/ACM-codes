#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define     INF     0x3f3f3f3f

int T , n;
int a[10010] , b[10010] , c[10010] , d[10010] , b_c_d[10010];

inline int max(int x , int y)
{
    if (x > y)
        return x;
    return y;
}   //max

int solve_1()
{
    a[0] = -INF , b_c_d[0] = -INF;
    int ans;
    int max_a_i = 0 , max_b_c_d_i = 0;
    for (int i = 1;i <= n;i ++)
        b_c_d[i] = b[i] + c[i] + d[i];

    for (int i = 1;i <= n;i ++)
        if (a[i] > a[max_a_i])
            max_a_i = i;
    for (int i = 1;i <= n;i ++)
        if (i != max_a_i && b_c_d[i] > b_c_d[max_b_c_d_i])
            max_b_c_d_i = i;
    ans = a[max_a_i] + b_c_d[max_b_c_d_i];

    max_a_i = 0; max_b_c_d_i = 0;
    for (int i = 1;i <= n;i ++)
        if (b_c_d[i] > b_c_d[max_b_c_d_i])
            max_b_c_d_i = i;
    for (int i = 1;i <= n;i ++)
        if (i != max_b_c_d_i && a[i] > a[max_a_i])
            max_a_i = i;

    ans = max(ans , a[max_a_i] + b_c_d[max_b_c_d_i]);
    return ans;
}   //solve_1

int solve_2()
{
    a[0] = -INF , b[0] = -INF , c[0] = -INF;
    int ans;
    int max_a_i = 0 , max_b_i = 0 , max_c_i = 0;
    for (int i = 1;i <= n;i ++)
        if (a[i] > a[max_a_i])
            max_a_i = i;


}   //solve_2

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        scanf("%d" , &n);
        for (int i = 1;i <= n;i ++)
            scanf("%d" , &a[i]);
        for (int i = 1;i <= n;i ++)
            scanf("%d" , &b[i]);
        for (int i = 1;i <= n;i ++)
            scanf("%d" , &c[i]);
        for (int i = 1;i <= n;i ++)
            scanf("%d" , &d[i]);
        printf("%d %d\n" , solve_1() , solve_2());
    }   //for i _ T

    return 0;
}   //main
