#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int N;
int arr[1000010];
int stack[1000010];
int top;

bool solve(){
    top = 0;
    int index = 0;
    for (int i = 0;i < N;i ++){
        int num;
        scanf("%d" , &num);
        if (top && stack[top] == num){
            top --;
            continue;
        }   //  pop out
        while (!top || stack[top] != num){
            if (index == N)
                break;
            stack[++ top] = arr[index ++];
        }   //  push in
        if (top && stack[top] == num){
            top --;
        }   //  pop out
    }   //for i _ N
    if (top)
        return false;
    return true;
}   //solve

int main(){
    scanf("%d" , &N);
    for (int i = 0;i < N;i ++)
        scanf("%d" , &arr[i]);
    if (solve())
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}   //main
