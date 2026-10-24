class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int ,int> mapp;

        for(int i = 0 ; i<nums.size() ; i++){
            if(mapp.find(nums[i]) != mapp.end()){
                return true ;
            }

            mapp[nums[i]] = 1 ;
    

            
        }
        return false ;
    }
};