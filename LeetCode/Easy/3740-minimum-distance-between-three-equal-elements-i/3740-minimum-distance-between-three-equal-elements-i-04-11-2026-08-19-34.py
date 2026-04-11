class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        min_dis=float("inf")
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                for k in range(j+1,len(nums)):
                    if(nums[i] == nums[j] and nums[j] == nums[k] and nums[k] == nums[i]):
                        min_dis= min(min_dis, (abs(i-j)+abs(j-k)+abs(k-i)))

        return min_dis if min_dis!= float("inf") else -1