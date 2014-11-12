#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
    int cnt , level;
    bool isEnd;
    node *son[2];
};  //node

node *root;
int N;
int ans = 0;

void init(){
    root = new node;
    root->cnt = 0;
    root->level = 0;
    root->isEnd = false;
    root->son[0] = NULL;
    root->son[1] = NULL;
}   //init

void solve(char str[]){
    node *nowNode = root , *p;
    for (int i = 0;i < strlen(str);i ++){
        if (str[i] - '0' == 0){
            if (!nowNode->son[0]){
                p = new node;
                p->cnt = 0;
                p->level = nowNode->level + 1;
                p->son[0] = NULL;   p->son[1] = NULL;
                nowNode->son[0] = p;
                nowNode = p;
            }   //  create new node
            else
                nowNode = nowNode->son[0];
            nowNode->cnt ++;
        }   //  0
        else{
            if (!nowNode->son[1]){
                p = new node;
                p->cnt = 0;
                p->level = nowNode->level + 1;
                p->son[0] = NULL;   p->son[1] = NULL;
                nowNode->son[1] = p;
                nowNode = p;
            }   //  create new node
            else
                nowNode = nowNode->son[1];
            nowNode->cnt ++;
        }   //  1
    }   //for i _ strlen
    nowNode->isEnd = true;
}   //solve

void visit(node *p){
    ans = max(ans , p->cnt * p->level);
    if (p->son[0])  visit(p->son[0]);
    if (p->son[1])  visit(p->son[1]);
}   //visit

int main(){

    init();
    scanf("%d" , &N);
    char str[210];
    for (int i = 0;i < N;i ++){
        scanf("%s" , str);
        solve(str);
    }   //for i _ N
    visit(root);
    printf("%d\n" , ans);

    return 0;
}   //main
