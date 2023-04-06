class Solution:
    def maxCoinsIniToj(nums:list[int],i:int,j:int):
        if i>j:
            return -1
        if i==j:
            ans=nums[i]
            if i-1>=0:
                ans*=nums[i-1]
            if i+1<=len(list):
                ans*=nums[i+1]
            return nums[i]
        
        
    def maxCoins(self, nums: list[int]) -> int:
        return self.maxCoinsIniToj(nums,0,len(nums)-1)
if __name__ == '__main__':
    test=Solution()
    print(test.maxCoins([3,1,5,8]))