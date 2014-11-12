#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct node{
    char Name[22];
};  //node

struct point{
    int id , name , pos , state;
};  //point

int N , M , K;
point ops[1000010];
int Name_cnt , Prob_cnt;
node List[200];
char Prob_List[15];
int Prob[27][150];
int max_ans = 0 , ans = 0;

int main(){
    memset(Prob , 0 , sizeof(Prob));
    strcpy(List[1].Name , "Captain_Chen");
    Name_cnt = 2;   Prob_cnt = 1;

    scanf("%d%d%d" , &N , &M , &K);
    char str_name[20] , str_state[4] , ch_Prob_id , ch;
    int  name_id , prob_id , now_name_id;
    for (int i = 0;i < K - 1;i ++){
        scanf("%s" , str_name);
        name_id = -1;   prob_id = -1;
        for (int j = 1;j < Name_cnt;j ++){
            if (strcmp(str_name , List[j].Name) == 0){
                name_id = j;
                break;
            }
        }   //for j _ Name_cnt
        if (name_id == -1){
            name_id = Name_cnt;
            strcpy(List[Name_cnt].Name , str_name);
            Name_cnt ++;
        }
        scanf("%c%c%c" , &ch , &ch_Prob_id , &ch);
        scanf("%s" , str_state);

        for (int j = 1;j < Prob_cnt;j ++){
            if (Prob_List[j] == ch_Prob_id){
                prob_id = j;
                break;
            }
        }   //for j _ Prob_cnt
        if (prob_id == -1){
            prob_id = Prob_cnt;
            Prob_List[Prob_cnt] = ch_Prob_id;
            Prob_cnt ++;
        }

        ops[i].id    = prob_id;
        ops[i].name  = name_id;
        if (strcmp(str_state , "AC") == 0)
            ops[i].state = 1;
        else
            ops[i].state = 0;

        if (ops[i].state == 1){
            Prob[ops[i].id][0] ++;
            Prob[ops[i].id][Prob[ops[i].id][0]] = name_id;
            ops[i].pos = Prob[ops[i].id][0];
        }
    }   //for i _ K

    scanf("%s" , str_name);
    for (int j = 1;j < Name_cnt;j ++){
        if (strcmp(str_name , List[j].Name) == 0){
            now_name_id = j;
            break;
        }
    }

    for (int i = 1;i <= M;i ++)
        if (Prob[i][1] == 1 || Prob[i][0] == 0)
            max_ans ++;

    //solve
    for (int i = K - 2;i >= 0;i --){
        ans = 0;
        if (ops[i].state == 1){
            /*
            printf("TEST info===\n");
            printf("i=%d ops[i].id=%d ops[i].name=%d ops[i].state=%d ops[i].pos=%d\n" ,
                    i , ops[i].id , ops[i].name , ops[i].state , ops[i].pos);
            printf("now_name_id=%d\n" , now_name_id);
            */

            Prob[ops[i].id][ops[i].pos] = now_name_id;
        }   //if AC
        now_name_id = ops[i].name;
        for (int j = 1;j <= M;j ++)
            if ((Prob[j][0] == 0) || (Prob[j][1] == 1))
                ans ++;
        if (ans > max_ans)
            max_ans = ans;
    }   //for i _ 0

    printf("%d\n" , max_ans);

    return 0;
}   //main
