#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define     input       "input.txt"
#define     output      "output.txt"


int n , m;
int arr[100010];

int solve(int l , int r){
    int ans = -0x3f3f3f3f;
    for (int i = l;i <= r;i ++){
        int cnt = 0;
        for (int j = i;j <= r;j ++){
            cnt += arr[j];
            ans = max(ans , cnt);
        }   //for j
    }   //for i 
    return ans;
}   //soive

int main(){
    freopen(input , "r" , stdin);
    freopen(output , "w" , stdout);

    scanf("%d%d" , &n , &m);
    for (int i = 1;i <= n;i ++)
        scanf("%d" , &arr[i]);

    for (int i = 0;i < m;i ++){
        int cmd;
        scanf("%d" , &cmd);
        if (cmd == 0){
            int l , r;
            scanf("%d%d" , &l , &r);
            printf("%d\n" , solve(l , r));
        }   //  query
        else{
            int x , w;
            scanf("%d%d" , &x , &w);
            arr[x] = w;
        }   //  update
    }   //for i _ m

    return 0;
}   //main
