class Solution:
    def minWeightTriangulation(self, length:int, values:list[int], dp:list[list[int]],cutPoint:list[list[int]]):
        for i in range(1,length):
            dp[i][i]=0
        for r in range(2,length+1):
            for i in range(1,length-r+1):
                j=i+r-1
                dp[i][j]=dp[i+1][j]+values[i-1]*values[i]*values[j]
                for k in range(i+1,j):
                    temp=dp[i][k]+dp[k+1][j]+values[i-1]*values[k]*values[j]
                    if temp<dp[i][j]:
                        dp[i][j]=temp
                        cutPoint[i][j]=k
        return dp[1][length-1]
    def minScoreTriangulation(self, values: list[int]) -> int:
        dp=[[-1 for j in range(0,len(values))] for i in range(0,len(values))]
        cutPoint=[[-1 for j in range(0,len(values))] for i in range(0,len(values))]
        return self.minWeightTriangulation(len(values),values,dp,cutPoint)
if __name__ == '__main__':
    test=Solution()
    print(test.minScoreTriangulation([1,3,1,4,1,5]))