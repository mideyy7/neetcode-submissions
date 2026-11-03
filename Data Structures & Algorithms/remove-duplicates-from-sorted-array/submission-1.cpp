class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        2 pointers 
            - insert position
            - scan through the array

            nums=[2,10,10,30,30,30]

            aftwer a swap incerement botj pointers

        */

        int i = 1;
        int j = 1;
        while (j < nums.size()) {
            while (j < nums.size() && nums[j] == nums[i - 1])j++;
            if (j < nums.size()) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        return i;  
    }
};