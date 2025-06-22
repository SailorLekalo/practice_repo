class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1: return([[1]])
        if numRows == 2: return([[1],[1,1]])
        output = [[1],[1,1]]
        for i in range(3,numRows+1):
            mas = [1]+list(output[i-2][j]+output[i-2][j+1] for j in range(len(output[i-2])-1))+[1]
            output.append(mas)
        return output
        
