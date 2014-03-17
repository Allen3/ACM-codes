#include<cstdio>
#include<cstring>
#include<cstdib>
#include<cmath>
using namespace std;

#ifdef unix
#define     _LL_FMT         "%lld"
#else
#define     _LL_FMT         "%I64d"
#endif

char str[20];
int m;
int num[10];

void preprocess(){
    for (int i = 0;i < strlen(str);i ++)
        num[str[i] - '0'] ++;
}   //preprocess

void solve(long long num , int cnt){
    

}   //solve

int main(){

    memset(num , 0 , sizeof(num));

    scanf("%s" , str);
    scanf("%d" , &m);

    preprocess();



    return 0;
}   //main
