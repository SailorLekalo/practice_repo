class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0: return([1])
        if rowIndex == 1: return([1,1])
        output = [[1],[1,1]]
        for i in range(3,rowIndex+2):
            mas = [1]+list(output[i-2][j]+output[i-2][j+1] for j in range(len(output[i-2])-1))+[1]
            output.append(mas)
        return (output[-1])
