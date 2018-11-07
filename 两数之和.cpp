#include<stdio.h>
/*****************
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*****************/
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int a[2];
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
            if(nums[i]+nums[j]==target)
            {
                a[0]=nums[i];
                a[1]=nums[j];
                return a;
            }
    }
    return a;
}

int main(){
    int nums[4]={2,4,5,7};
    printf("%d,%d",*(twoSum(nums,4,9)),*(twoSum(nums,4,9)+1));
    }
