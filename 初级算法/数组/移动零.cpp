/**********
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
/***********
void swap(int* nums,int* numstile){
    if(nums!=numstile){
        int t=*nums;
        *nums=*(nums+1);
        *(nums+1)=t;
        nums++;
    }
}

void moveZeroes(int* nums, int numsSize) {
    //判断是不是零 不是往后判断，是则开始一个个交换顺序
    int* numstile=nums+numsSize;
    while(nums<numstile){
        if(*nums==0)
            swap(nums,numstile);
        else nums++;
    }
}
***************/
void moveZeroes(int* nums, int numsSize) {
        int zeroNum=0;//用来计算0的个数
        for(int i=0;i<numsSize;i++){
            if(nums[i]==0){//如果nums[i]=0,zeroNum个数加一
                zeroNum++;
            }else if(zeroNum!=0){//如果nums[i]不等于0,将nums[i]跟前zeroNum个交换，并且将nums[i]赋值为0
                nums[i-zeroNum]=nums[i];
                nums[i]=0;
            }
        }
}
