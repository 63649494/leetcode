/* 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？ */

class Solution {
public:  
    void setZeroes(vector<vector<int>>& matrix) {
        //先遍历一遍矩阵
        vector<int> mark;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                //cout<<"第"<<i<<"行"<<j<<"列的元素为"<<matrix[i][j]<<"  ";
                if(matrix[i][j]==0){
                    mark.push_back(i);
                    mark.push_back(j);
                }
            }
            //cout<<endl;
        }
        //根据mark中的记录置0
        for(int i=0;i<mark.size();i=i+2){
            int r=mark[i];
            int l=mark[i+1];
            Zero(matrix,r,l);
        }
    }

    void Zero(vector<vector<int>>& matrix,int r,int l){
        for(int j=0;j<matrix[0].size();j++)	//列置零
            matrix[r][j]=0;
        for(int i=0;i<matrix.size();i++)	//行置零
            matrix[i][l]=0;
        
    }
};