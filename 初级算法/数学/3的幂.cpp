/* 
给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？ */

/* 如果某个数n为3的幂 ，则k=log3N

代码思路：

首先求出int范围最大的3的幂   Max3

如果n为3的幂，则Max3必定能整除n */

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        const int maxint=0x7fffffff;
        int k=log(maxint)/log(3);
        int b3=pow(3,k);
        return (b3%n==0);
    }
};