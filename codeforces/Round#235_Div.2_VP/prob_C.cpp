#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int n , m;

int main(){
    scanf("%d%d" , &n , &m);
    if ((m > ((n + 1) << 1)) || (n > (m + 1)))
        printf("-1\n");
    else if (m >= (n << 1)){
        for (int i = 0;i < n;i ++)
            printf("110");
        for (int i = 0;i < m - (n << 1);i ++)
            printf("1");
        printf("\n");
    }   // 110...
    else if (m >= n){
        for (int i = 0;i < m - n;i ++)
            printf("110");
        for (int i = 0;i < (n << 1) - m;i ++)
            printf("10");
        printf("\n");
    }   // 110...10...
    else if (n == m + 1){
        printf("0");
        for (int i = 0;i < m;i ++)
            printf("10");
        printf("\n");
    }   // 0 10...

    return 0;
}   //main
