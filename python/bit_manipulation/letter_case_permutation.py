#!/usr/bin/env python
'''
Given a string S, we can transform every letter individually to be lowercase
or uppercase to create another string.  Return a list of all possible strings
we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
'''

class Solution(object):
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        res = ['']
        for ch in S:
            if ch.isalpha():
                res = [i + j for i in res for j in [ch.upper(), ch.lower()]]
            else:
                res = [i + ch for i in res]
        return res


if __name__ == "__main__":
    S = raw_input("Please input string: ")
    solution = Solution()
    res = solution.letterCasePermutation(S)
    print("The output combinations are: ")
    print(res)
