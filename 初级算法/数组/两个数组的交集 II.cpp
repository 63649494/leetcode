#include<stdio.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /*
 给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 */
 
int Equalnums(int *nums,int a,int ns){//查询有几个相同的元素
    int n=0;
    printf("\n查询有几个相同的元素\n要匹配的值为%d,数组长度为%d",a,ns);
    int* nt=nums+ns;
    while(nums<nt){
        if(*nums==a){
            n++;
            printf("\nn为%d",n);
        }
        nums=nums+1;
    }
    printf("\nn为%d",n);
    return n;
}

void intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    //nums1中的每个元素和nums2的每个元素进行比较
        //如果相等，看return中有几个这个元素，有几个跳过几个相等的，然后再遇到的相同的加入return
    int* returnNum=returnSize;  //尾地址
    int n=0;    //记录结果数组的重复元素数
    int ns=0;   //记录结果数组的长度
    for(int i=0;i<nums1Size;i++){
        printf("开始匹配%d\n",*(nums1+i));
        n=Equalnums(returnSize,*(nums1+i),ns);
        printf("其在结果数组的个数为%d\n\n",n);
        for(int j=0;j<nums2Size;j++)
            if(*(nums2+j)==*(nums1+i)){
                printf("n为%d\n",n);
                if(n==0){
                    printf("ns 为%d\n",ns);
                    printf("%d 将插入结果数组\n",*(nums2+j));
                    *returnNum=*(nums2+j);
                    printf("%d 已插入结果数组\n",*returnNum);
                    ns++;
                    printf("ns 为%d\n",ns);
                    *returnNum++;
                    printf("尾指针自增结束\n\n");
                    break;
                }
                else{
                    n--;
                }
            }
    }
    printf("啦啦啦啦啦\n");
    while(returnSize<returnNum){
        printf("%d ",*returnSize);
        *returnSize++;
        }

}

int main(){
    int n1[5]={1,2,2,1};
    int *nums1=n1;
    int nums1Size=4;
    int n2[2]={2,2};
    int *nums2=n2;
    int nums2Size=2;
    int *returnSize;

    intersect(nums1, nums1Size, nums2, nums2Size, returnSize);

    printf("n1 is \n");
    while(nums1<(n1+4)){
        printf("%d ",*nums1);
        *nums1++;
        }
    printf("\nn2 is \n");
    while(nums2<(n2+2)){
        printf("%d ",*nums2);
        *nums2++;
        }
    return 0;
    }
