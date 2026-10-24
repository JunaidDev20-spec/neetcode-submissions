class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> seen ;
        for(int i = 0 ;i < nums.size() ; i++){
            int compliment = target - nums[i] ;
            if(seen.find(compliment) != seen.end()){
                return{seen[compliment] , i} ;

            }

            seen[nums[i]] = i ;

            
        }

        return {-1 , -1} ;
    }
};
