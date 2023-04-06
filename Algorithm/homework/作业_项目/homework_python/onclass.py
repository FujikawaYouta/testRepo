class Fibonacci:
    def fibonacci(self,k:int)->int:
        if k==0:
            return 1
        elif k==1:
            return 1
        return self.fibonacci(k-1)+self.fibonacci(k-2)
    def fibonacciTopToBottom(self,k:int):
        return 0
    def fibonacciBottomToTop(self,k:int):
        return 0
class MatrixChain:
    def matrixChain(self,matrixRows:list,n:int,m:list[list[int]],s:list[list[int]]):
        for i in range(0,n):
            m[i][i]=0
        for r in (1,n):
            for i in range(0,n-r):
                j=i+r
                m[i][j]=m[i][i]+m[i+1][j]+matrixRows[i]*matrixRows[i+1]*matrixRows[j]
                for k in range(i+1,j):
                    temp=m[i][k]+m[k+1][j]+matrixRows[i]*matrixRows[k+1]*matrixRows[j]
                    if temp<m[i][j]:
                        m[i][j]=temp
                        s[i][j]=k
if __name__ == '__main__':
    testFibonacci=Fibonacci()
    arr=[1,2,6,3]
    print(testFibonacci.fibonacci(12))
    print(testFibonacci.fibonacciBottomToTop(12))
    print(testFibonacci.fibonacciTopToBottom(12))

    testMatrixChain=MatrixChain()
    arrM=[[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1]]
    arrMatrixRows=[30,35,15,5,10,20,25]
    n=6
    arrS=[[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1]]
    testMatrixChain.matrixChain(arrMatrixRows,n,arrM,arrS)
