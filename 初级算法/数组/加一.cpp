/***************
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*****************/


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>

void print(int *h,int *t){
    int* head=h;
    int* tail=t;
    while(head<=tail){
        printf("%d ",*head);
        head++;
        }
}

int lastplusone(int *last){
    printf("lpo 加之前的last为%d\n",*last);
    *last=*last+1;
    printf("lpo 加之后的last为%d\n",*last);
    if(*last==10)
        return 1;
    else
        return 0;
}

int Carrying(int *digits,int *last){
        if(last==digits){
            printf("进位进到头了！\n");
            last--;
            return 1;   //进位到头
        }
        else{
            printf("进位还没有进到头！\n");
            last--;
            return 0;   //进位没到头

        }
    }

int recursion(int *last,int *digits){
    if(lastplusone(last)==0){//不需要进位
        printf("r last为%d\n",*last);
        return 1;//不需要重建
    }
    else{    //需要进位
        *last=0;
        printf("r 进位前此时last为%d\n",*last);
        if( Carrying(digits,last)==0 ){
            last--;
            printf("r 进位后此时last为%d\n",*last);
            return recursion(last,digits);
        }
        else {
        return 0;
        }
    }
}



int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* last=digits+digitsSize-1;
    int* last1=digits+digitsSize-1;
    printf("po 初始的last为%d\n",*last);
    //如果尾数加一为0，则last向前进一位然后尾数加一，循环，直到last=digits时如果加一还是0，则重设一个数组为1000.。。。
    if(recursion(last,digits)==1){
        print(digits,last1);
        return digits;}
    else{//重设数组
        printf("重设数组\n");
        //*returnSize=digitsSize+1;
        int re[digitsSize+1];
            re[0]=1;
        //printf("%d ",re[0]);
        for(int i=1;i<(digitsSize+1);i++){
            re[i]=0;
            //printf("%d ",re[i]);
        }
        for(int j=0;j<(digitsSize+1);j++){
            printf("%d ",re[j]);
            }
        return re;
    }
}

int main(){
    int a[]={9,9,9,9};
    int size=4;
    int *rs;
    int* b=plusOne(a, size ,rs);
    //print(b,(b+*rs));
    }
