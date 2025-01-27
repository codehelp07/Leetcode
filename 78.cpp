class Solution {
public:
    void func(vector<int>nums,int i,int n,vector<vector<int>>&ans,vector<int>temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        func(nums,i+1,n,ans,temp);
        temp.push_back(nums[i]);
        func(nums,i+1,n,ans,temp);
        //temp.pop_back();
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>>ans;
         vector<int>temp;
         func(nums,0,n,ans,temp);
         return ans;
    }
};
