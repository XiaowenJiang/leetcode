#!/usr/bin/env python
"""
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

"""
class Solution(object):

    # Solution: slow ver
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        rst = []
        for h in range(12):
            for m in range(60):
                count_h = list(("{:b}".format(h))).count("1")
                count_m = list(("{:b}".format(m))).count("1")
                if count_h + count_m == num:
                    rst.append("%d:%02d" % (h, m))
        return rst


if __name__ == "__main__":
    num = raw_input("Please input number of 1: ")
    solution = Solution()
    print("The possible times are:")
    print(solution.readBinaryWatch(int(num)))

