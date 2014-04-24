#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int T;

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        int n , m;
        scanf("%d%d" , &n , &m);
        if ((n % 2) || (m % 2))
            printf("UDK\n");
        else
            printf("RU\n");
    }   //for i _ T
    return 0;
}   //main
