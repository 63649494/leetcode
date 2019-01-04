/* 统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。 */

/*埃拉托斯特尼筛法Sieve of Eratosthenes，这个算法的过程如下，我们从2开始遍历到根号n，先找到第一个质数2，然后将其所有的倍数全部标记出来，然后到下一个质数3，标记其所有倍数，一次类推，直到根号n，此时数组中未被标记的数字就是质数。我们需要一个n-1长度的bool型数组来记录每个数字是否被标记，长度为n-1的原因是题目说是小于n的质数个数，并不包括n。 然后我们来实现埃拉托斯特尼筛法*/
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> prime(n, true);
        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                ++res;
                for (int j = 2; i * j < n; ++j) {
                    prime[i * j] = false;
                }
            }
        }
        return res;
    }
};


/*
//超时算法，复杂度O(n*n),上述方法为空间换时间
class Solution {
public:
    int countPrimes(int n) {
        int count=1;
        if(n<=2)
            return 0;
        for(int i=3;i<n;i++){
            int mark=0;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    mark=1;
                    break;
                }
            }
            if(mark==0){//判断是否为质数
                count++;    
            }
        }
        return count;
    }
};
*/