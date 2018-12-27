/* 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。 */

int maxProfit(int* prices, int pricesSize) {
        int result = 0;
        int minbuy = prices[0]; 
        for(int i = 1;i<pricesSize;i++){
            // 最小的购买，最大的卖
            result = result>prices[i] - minbuy?result:prices[i] - minbuy;
            minbuy = minbuy<prices[i]?minbuy:prices[i];
        }
        return result;
    }


/* 
//非动态规划法 时间复杂度O(n)
int maxProfit(int* prices, int pricesSize) {
    int min=0;//记录绝对值最大的
    for(int i=0;i<pricesSize;i++){
        for(int j=i+1;j<pricesSize;j++){
            if(prices[i]-prices[j]<min)
                min=prices[i]-prices[j];
        }
    }
    return -1*min;
} */