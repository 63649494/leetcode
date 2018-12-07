/***********
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*****************/
bool containsDuplicate(int* nums, int numsSize) {
    for(int i = 0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
            if(nums[i]==nums[j])
                return true;
        
    }
    return false;
}
//最简单的一个个遍历,时间复杂对为O(n2)
/*************
int main(void)
{
    int date[1001],book[1001]={0};//先将数组初始化为零
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&j);
        ++book[j];//将数据所在的单元自增
    }
 
    k=0;
    for(i=0;i<1001;++i)
    {
        if(book[i])//那些单元里面值不为0的说明有这个数据
            date[k++]=i;
    }

时间复杂度O(N)

可以看到,虽然时间复杂度不高,但是对于空间的消耗比较大上述的例子数据的范围是1~1000,所以该方法要知道数据的范围才可以保证不出错
--------------------- 
作者：码农一只 
来源：CSDN 
原文：https://blog.csdn.net/qq2071114140/article/details/80490400 
版权声明：本文为博主原创文章，转载请附上博文链接！
*************/