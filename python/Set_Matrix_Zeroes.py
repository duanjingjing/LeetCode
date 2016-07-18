#!/bin/env python

class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void 
        """

        m=len(matrix)
        n=len(matrix[0])

        row = [False for i in range(m)]
        column = [False for j in range(n)]

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row[i]=True
                    column[j]=True
        
        for i in range(m):
            for j in range(n):
                if row[i] or column[j]:
                    matrix[i][j] = 0
