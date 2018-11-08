#include<stdio.h>

/**********
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
***********/

int reverse(int x){
    int m=0;
    int INT_MAX=~(unsigned int)0 / 2;     //int的最大值，分析：当无符号0以二进制储存在内存中的时候，每一位都为0，取反后全为1，因为int有正数负数，所以除以2
    int INT_MIN=(-1)*INT_MAX-1;
    printf("%d\n",INT_MAX);
    for(;x!=0;){    //判断是不是小数
        int p=x%10;
        if( m > INT_MAX/10 || ( m == INT_MAX / 10 && p > 7))return 0;     //判断是否溢出
        if( m < INT_MIN/10 || ( m == INT_MIN / 10 && p < -8)) return 0;
        m=10*m+x%10;
        x=x/10;}
    return m;
    }

int main(){
    int a=1569;
    printf("%d",reverse(a));
    return 0;
    }
