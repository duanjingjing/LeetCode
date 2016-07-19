#!/bin/env python

class Solution:
    # @param matrix, a list of lists of integers
    # @param target, an integer
    # @return a boolean
    def searchMatrix(self, matrix, target):
        l, h = 0, len(matrix) * len(matrix[0])-1
        while (l <= h):
            m = l + ((h-l) >> 2)
            v = matrix[m/len(matrix[0])][m % len(matrix[0])]
            if v < target:
                l = m+1
            elif v > target:
                h = m-1
            else:
                return True
        return False

