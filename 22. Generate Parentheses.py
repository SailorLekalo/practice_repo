class Solution:
    output = set()

    def recursive(self, dp: str, op_left: int, cl_left: int, ava: int):
        if op_left <= 0 and cl_left <= 0:
            self.output.add(dp)
            return
        else:
            if ava > 0 and op_left>0 and cl_left>0:
                self.recursive(dp + "(", op_left - 1, cl_left, ava + 1)
                self.recursive(dp + ")", op_left, cl_left-1, ava - 1)
            elif ava>0:
                self.recursive(dp + ")", op_left, cl_left-1, ava - 1)
            elif op_left>0 and ava==0:
                self.recursive(dp + "(", op_left - 1, cl_left, ava + 1)

    def generateParenthesis(self, n: int) -> List[str]:
        dp = "("
        self.output = set()
        self.recursive(dp, n - 1, n, 1)
        return list(self.output)
