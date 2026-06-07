class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmp;
        int complement;

        for (int i =0; i < nums.size(); i++){
            complement = target - nums[i];

            if (hashmp.count(complement)){
                return {hashmp[complement], i};
            }
            hashmp[nums[i]]= i;
        }
        return {};
    }
};