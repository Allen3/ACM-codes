#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int n , x;

int main(){
    int num , sum = 0;

    scanf("%d%d" , &n , &x);
    for (int i = 0;i < n;i ++){
        scanf("%d" , &num);
        sum += num;
    }   //for i _ n
    sum = abs(sum);
    int ans = sum / x;
    if (sum % x)
        ans ++;
    printf("%d\n" , ans);

    return 0;
}   //main
