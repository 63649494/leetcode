/* 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
] */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
        //第一个为[1],第二个为[1,1]
        if(numRows==0)
            return out;
        vector<int> Row1(1,1);
        out.push_back(Row1);
        if(numRows==1)
            return out;
        vector<int> Row2(2,1);
        out.push_back(Row2);
        if(numRows==2)
            return out;
        //第三个开始取前一个数组，相邻两个值加起来组成下一个数组的数，然后下一个数组头尾加1
        for(int i=3;i<=numRows;i++){
            vector<int> Row3(i,1);//第i行
            for(int j=1;j<i-1;j++){
        Row3[j]=out[i-2][j-1]+out[i-2][j];    
           }
        /*
            for(int n=0; n<Row3.size(); n++)    //获取向量中具体每个向量的大小
                 cout<<Row3[n]<<" " ;
             cout<<"\n" ;*/
            out.push_back(Row3);
        }
        return out;
    }
};