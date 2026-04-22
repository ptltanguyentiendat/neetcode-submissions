class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int i = 0; i < nums.size(); i++){
            auto id = lower_bound(v.begin(), v.end(), nums[i]);
            if(id != v.end()) *id = nums[i];
            else v.push_back(nums[i]);
        }
        return v.size();
    }
};
