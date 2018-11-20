#include<stdio.h>
#include<stdlib.h>
#define Stack_size 10000
typedef struct{
    char elem[Stack_size];
    int top;
} SeqStack;
void InitStack (SeqStack *S) {
    S->top = -1;
}
int IsEmpty (SeqStack *S) {
    if (S->top == -1)  return 1;
    else
        return 0;
}
int Push (SeqStack *S,char x) {
    if(S->top == Stack_size-1)  return 0;
    S->top++;
    S->elem[S->top] = x;
    return 0;
}
int GetTop (SeqStack *S,char *x) {
    if (S->top == -1)  return 0;
    else {
        *x=S->elem[S->top];
        return 1;
    }
}
int Pop (SeqStack *S,char *x) {
    if (S->top == -1)  return 0;
    else {
        *x=S->elem[S->top];
        S->top--;
        return 0;
    }
}
int Match (char a,char b){
    if (a+1==b||a+2==b)  return 1;//()¡¨∆¿¥ [] {}∏Ù¡À“ª∏ˆ ascii¬Î
    else
        return 0;
}
int BracketMatch (char *str){
    SeqStack S;int i;char ch;
    InitStack (&S);
    for (i=0; str[i]!='\0'; i++){
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                Push (&S,str[i]);
                break;
            case ')':
            case ']':
            case '}':
                if (IsEmpty (&S) ){
                    printf("Œ¥∆•≈‰\n");
                    return 0;
                }
                else {
                    GetTop (&S,&ch);
                    if (Match(ch,str[i]))
                        Pop (&S,&ch);
                    else{
                        printf("Œ¥∆•≈‰\n");
                        return 0;
                    }
                }
        }
    }
    if (IsEmpty (&S) )
        printf("∆•≈‰\n");
    else
        printf("Œ¥∆•≈‰\n");
    return 0;
}
int main(){
    int n;
    char a[10000];
    scanf("%d",&n);
    while (n--){
        scanf("%s",a);
        BracketMatch (a);
    }
    return 0;
}
