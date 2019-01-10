/* 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现? */

int missingNumber(int* nums, int numsSize) {
    int sum=0;
    int sum1=0;
    for(int i=0;i<numsSize;i++){
        sum=sum+i+1;	//0~n个数的和
        sum1=sum1+nums[i];		//数组的和
    }
    return sum-sum1;
}//求差值，用0~n个数的和减去给定数组数字的和，差值就是要找的数字。


/* 
//位操作Bit Manipulation，将这个数组与0~n之间完整的数异或一下累加到res，相同的数字异或后都变为了0，最后剩下的结果就是缺失的数字。
int missingNumber(int* nums, int numsSize) {
        int res = 0;
        for (int i = 0; i < numsSize; i++ ) {
            res = res ^ (i + 1) ^ nums[i];
        }
        return res;
} */