#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int T , n , F;

int solve(int n , int F)
{
    int num = 1;
    while (n > 1)
    {
        F -= (num + 2 * num * (n - 1));
        n --; num ++;
    }   //while
    if (F < num)
        return -1;
    return F;
}   //solve

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        int tmp;
        scanf("%d%d" , &n , &F);
        tmp = solve(n , F);
        if (tmp != -1)
        {
            for (int j = 1;j < n;j ++)
                printf("%d " , j);
            printf("%d\n" , tmp);
        }
        else
            printf("-1\n");
    }   //for i _ T

    return 0;
}   //main
