#include<cstdio>
#include<cstring>
using namespace std;

#define output      "test.txt"

int main()
{
    freopen(output , "w" , stdout);
    printf("2500\n");
    for (int i = 1;i <= 50;i ++)
        for (int j = 1;j <= 50;j ++)
            printf("%d %d\n" , i , j);

    return 0;
}   //main
