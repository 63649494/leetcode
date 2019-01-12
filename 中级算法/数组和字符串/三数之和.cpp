/* 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
] */

class Solution {
public:
    void sort(vector<int>& arr){
        int len = arr.size();
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - 1 - i; j++) {
                if (arr[j] > arr[j+1]) {        // 相邻元素两两对比
                    int temp = arr[j+1];        // 元素交换
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> re;
        sort(nums);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){//三层循环
                        if(re.size()!=0){
                            int mark=0;
                            for(int o=0;o<re.size();o++){
                                    if(re[o][0]==nums[i]&&re[o][1]==nums[j]&&re[o][2]==nums[k]){
                                    mark=1;
                                    break;
                                }
                            }
                            if(mark==1)
                                continue;
                        }
                        cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                        vector<int> sum;
                        sum.push_back(nums[i]);
                        sum.push_back(nums[j]);
                        sum.push_back(nums[k]);
                        re.push_back(sum);
                    }
                }
            }
        }
        return re;
    }
};