#include<stdio.h>
/*****************
����һ�����������һ��Ŀ��ֵ���ҳ������к�ΪĿ��ֵ����������

����Լ���ÿ������ֻ��Ӧһ�ִ𰸣���ͬ����Ԫ�ز��ܱ��ظ����á�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
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
