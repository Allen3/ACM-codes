#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int T;
char str[100100];
int cnt_1[30] , cnt_2[30] , tmp[30];

bool check_with_cnt1(int arr[]){
    for (int i = 0;i < 'z' - 'a';i ++)
        if (cnt_1[i] != arr[i])
            return false;
    return true;
}   //check_with_cnt1

bool check_same(int h1 , int h2 , int len){
    for (int i = 0;i < len;i ++)
        if (str[h1 + i] != str[h2 + i])
            return false;
    return true;
}   //check_same

void solve(int index){
    memset(cnt_1 , 0 , sizeof(cnt_1));
    memset(cnt_2 , 0 , sizeof(cnt_2));
    int len = strlen(str);

    for (int i = 0;i < len / 2;i ++){
        cnt_1[str[i] - 'a'] ++;
        cnt_2[str[len - 1 - i] - 'a'] ++;

        if (check_with_cnt1(cnt_2)){
            bool flag_j = true;

            for (int j = i + 1;j < len;j += (i + 1)){
                memset(tmp , 0 , sizeof(tmp));
                bool flag_k = true;

                for (int k = j;k <= j + i;k ++){
                    tmp[str[k] - 'a'] ++;
                    if (tmp[str[k] - 'a'] > cnt_1[str[k] - 'a']){
                        flag_k = false;
                        break;
                    }   //  check if overload
                }   //for k

                if (flag_k){
                    if (check_with_cnt1(tmp)){
                        if (check_same(0 , j , i + 1)){
                            flag_j = false;
                            break;
                        }
                    }   //  check if the strings are same
                }   // flag_k
                else{
                    flag_j = false;
                    break;
                }   // !flag_k

            }   //for j
            if (flag_j){
                printf("Case #%d: " , index);
                for (int i = 0;i < 'z' - 'a';i ++)
                    for (int j = 0;j < cnt_1[i];j ++)
                        printf("%c" , i + 'a');
                printf("\n");
                return ;
            }   //  answer found!
        }   //  possible answer

    }   //for i
    printf("Case #%d: Impossible\n" , index);
}   //solve

int main(){
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++){
        scanf("%s" , str);
        solve(i + 1);
    }   //for i _ T

    return 0;
}   //main
