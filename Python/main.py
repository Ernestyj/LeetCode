import sys
from typing import List


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