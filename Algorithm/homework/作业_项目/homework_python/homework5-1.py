class Solution:
    def fib(self, n: int) -> int:
        m=[0,1]
        if n<=1:
            return m[n]
        for i in range(2,n+1):
            m.append(m[i-1]+m[i-2])
        return m[n]

if __name__ == '__main__':
    #Solution test
    test=Solution
    print(test.fib(test,5))