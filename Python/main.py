import sys
from typing import List
import collections
import math


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        res = []
        sol = []
        self.dfs(s, wordDict, res, sol, 0)
        return len(res) != 0

    def dfs(self, s, wordDict, res, sol, start):
        if start == len(s):
            res.append(sol[:])
        else:
            for i in range(start, len(s)):
                tmp = s[start:i + 1]
                if tmp in wordDict:
                    sol.append(tmp)
                    self.dfs(s, wordDict, res, sol, i + 1)
                    sol.pop()


solution = Solution()
# print(solution.threeSumClosest([1,1,1,0], -100))

vals = [1,2,3]
print("vals=|{}|".format(' '.join(map(str, vals))))
data = '1 2 3'
print("splits=|{}|".format([e for e in ''.split(' ')]))
vals = collections.deque(int(val) for val in data.split())
print(f'vals={vals}')
vals = collections.deque([int(val) for val in data.split()])
print(f'vals={vals}')


nums = [1,5,1,1,6,4]
nums = sorted(nums)
print(f'nums={nums}')

lst = ['H', 'e', 'l', 'l', 'o', ' ', 'z', 'o', 'r', 'l', 'd']
print(str(lst))

k = math.log(sys.maxsize)//math.log(3)
maxPower = pow(3, int(k))
print(k)
print(maxPower)
print(maxPower%27)

a = '11'
a = list(reversed(a))
print(a)

s = "a good   example"
print(s.split())

i = 10.1
print([str(i)])

dp = collections.Counter()
dp[0] = 1
print(dp)
print(dp[0][0])