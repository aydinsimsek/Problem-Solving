#include <vector>

class Solution
{
    public:
        int search(std::vector<int>& nums, int target)
        {
            int left = 0;
            int right = nums.size()-1;
            while(left <= right)
            {
                int mid = left + (right-left) / 2;
                if(target == nums[mid])
                {
                    return mid;
                }
                else
                {
                    if(nums[mid] >= nums[left]) 
                    {
                        if(nums[left] <= target && target < nums[mid])
                        {
                            right = mid-1;
                        }
                        else
                        {
                            left = mid+1;
                        }
                    }
                    else
                    {
                        if(nums[mid] < target && target <= nums[right])
                        {
                            left = mid+1;
                        }
                        else
                        {
                            right = mid-1;
                        }
                    }
                }
            }
            return -1; 
        }
};