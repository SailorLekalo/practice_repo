class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # check rows
        for i in range(len(board)):
            dict = set()
            for j in range(len(board[i])):
                if board[i][j] == ".":
                    continue
                if board[i][j] in dict:
                    return False
                dict.add(board[i][j])
        # check columns
        for i in range(len(board)):
            dict = set()
            for j in range(len(board[j])):
                if board[j][i] == ".":
                    continue
                if board[j][i] in dict:
                    return False
                dict.add(board[j][i])
        # check squares
        for row in range(3):
            for col in range(3):
                dict = set()
                for i in range(3):
                    for j in range(3):
                        if board[row * 3 + i][col * 3 + j] == ".":
                            continue
                        if board[row * 3 + i][col * 3 + j] in dict:
                            return False
                        dict.add(board[row * 3 + i][col * 3 + j])
        # if still there the board is valid
        return True
