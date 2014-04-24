#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct _Name_List{
    char name[20];
};  //_Name_List

struct _Opt{
    int name_id , prob_id , status , pos;
};  //_Opt

int N , M , K;
_Opt opt[1000010];
int ACListCnt[15];
int ACList[15][160];
bool IsAC[15][160];
_Name_List      nameList[160];
char            probList[15];
int nameCnt , probCnt;

int getname(char str[]){
    int ans = -1;
    for (int i = 1;i <= nameCnt;i ++){
        if (strcmp(nameList[i].name , str) == 0){
            ans = i;
            return i;
        }   //  check whether same
    }   //for i _ nameCnt
    //add new name
    nameCnt ++;
    strcpy(nameList[nameCnt].name , str);
    return nameCnt;
}   //getname

int getprob(char ch){
    int ans = -1;
    for (int i = 1;i <= probCnt;i ++){
        if (probList[i] == ch){
            ans = i;
            return i;
        }   //  check whether same
    }   //for i _ probCnt
    probCnt ++;
    probList[probCnt] = ch;
    return probCnt;
}   //getprob

int getstatus(char str[]){
    if (strcmp(str , "AC") == 0)
        return 1;
    return 0;
}   //getstatus

void solve(){
    int ans = 0 , max_ans = 0;

    for (int i = 1;i < K;i ++){


    }   //for i _ K

    printf("%d\n" , max_ans);
}   //solve

int main(){
    memset(ACListCnt , 0 , sizeof(ACListCnt));
    char str_name[22] , str_status[3] , ch , ch_prob;
    int name_id , prob_id , status = 0;
    strcpy(nameList[1].name , "Captain_Chen");
    nameCnt = 1;    probCnt = 0;
//Initialize

    scanf("%d%d%d" , &N , &M , &K);
    for (int i = 0;i < K;i ++){

        scanf("%s" , str_name);
        name_id = getname(str_name);
        opt[i].name_id = name_id;

        if (i > 0){
            opt[i].prob_id = prob_id;
            opt[i].status  = status;
        }   //i > 0

        if (i == K - 1) break;
        scanf("%c%c%c" , &ch , &ch_prob , &ch);
        scanf("%s" , str_status);

        if (i > 0 && status == 1){
            ACListCnt[prob_id] ++;
            ACList[prob_id][ACListCnt[prob_id]] = name_id;
            IsAC[prob_id][name_id] = true;
            opt[i].pos = ACListCnt[prob_id];
        }   //  AC

        prob_id = getprob(ch_prob);
        status  = getstatus(str_status);
    }   //for i _ K - 1
    scanf("%s" , &str_name);
    solve();

    return 0;
}   //main
