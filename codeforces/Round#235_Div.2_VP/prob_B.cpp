#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int x , k;
int vis[4100];

int main(){
    int cmd , num1 , num2;

    memset(vis , 0 , sizeof(vis));
    scanf("%d%d" , &x , &k);
    for (int i = 0;i < k;i ++){
        scanf("%d" , &cmd);
        if (cmd == 1){
            scanf("%d%d" , &num2 , &num1);
            vis[num2] = 2;
            vis[num1] = 1;
        }   //if
        else {
            scanf("%d" , &num2);
            vis[num2] = 2;
        }   //else        
    }   //for i _ k
    
    int ans_min = 0 , ans_max = 0;
    for (int i = 1;i < x;i ++){
        if (!vis[i])
            ans_max ++;
    }   //for i _ x

    for (int i = 1;i < x;){
        if (!vis[i] && vis[i + 1]){
            ans_min ++;
            i += 2;
            continue;
        }   //  DIV_2
        if (!vis[i] && !vis[i + 1]){
            ans_min ++;
            i += 2;
            continue;
        }   //  DIV_1 && DIV_2
        i ++;
    }   //for i _ x
    printf("%d %d\n" , ans_min , ans_max);

    return 0;
}   //main

