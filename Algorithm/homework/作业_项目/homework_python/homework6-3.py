class Solution:
    def allProfits(self, prices: list[int],days: int,dp: list[list[int]]):
        dp[0]=0
        minPrice=prices[0]
        for i in range(1,days):
            dp[i]=max(dp[i-1],prices[i]-minPrice)
            minPrice=min(minPrice,prices[i])
    def maxProfit(self, prices: list[int]) -> int:
        days=len(prices)
        if days<2:
            return 0
        dp=[0 for i in range(0,days)]
        self.allProfits(prices,days,dp)
        return dp[days-1]
    
if __name__ == '__main__':
    test=Solution()
    prices = [7,1,5,3,6,4]
    print(test.maxProfit(prices))