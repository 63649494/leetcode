/* 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶 */
//关于动态规划https://blog.csdn.net/u013309870/article/details/75193592

int climbStairs(int n) {
        if(n==1) return 1;
        int sum[n+1];
        sum[0]=0;sum[1]=1;sum[2]=2;
     for(int i=3;i<=n;i++){
         sum[i]=sum[i-2]+sum[i-1];
     }
        return sum[n];
    }
/* 	另一种比较省空间的方法：
int climbStairs(int n) {
    int a = 1, b = 1;
    while (n--) {
        b += a;
        a = b - a;
        }
        return a;
}
 */	
/*
int fun(int n,int sum){//递归方法,不过超过40就提示超出时间范围，因为递归计算了很多分支，效率很低，这里需要用动态规划 (Dynamic Programming) 来提高效率
    if(n>=2){
        return fun(n-2,sum)+fun(n-1,sum);
    }else{
        return sum+1;
    }
}

int climbStairs(int n) {
    return fun(n,0);
}
*/