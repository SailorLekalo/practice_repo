"""
Даны две строки, a и b, представляющие собой неотрицательные шестнадцатеричные числа.

Нужно вернуть строку, которая представляет их сумму, также в шестнадцатеричном формате


Вход: a = "fed", b = "13"
Выход: "1000"

a = 10, f = 15
fed = 13 + 14*16 + 16^3 = 4077
13 = 3 + 16 = 19
4096 =

   111      1
    fed    11d
     13     13
   1000    130

   11
    ff
    ff
   1fe

       01
    00000f
    123456
    123465
    15+6 21
    564321
"""

def hex_sum(s: str, t: str) -> str:
    hex_string = "0123456789abcdef"
    # to get number in O(1)
    hex_to_num = {}
    for i in range(16):
        hex_to_num[hex_string[i]] = i

    result = []

    # fill with needed 0's at the beginning
    if len(s) < len(t):
        s = (len(t) - len(s)) * '0' + s

    if len(s) > len(t):
        t = (len(s) - len(t)) * '0' + t

    remainder = 0
    for i in range(len(s)):
        # pointer to hex symbol in hex string
        p = hex_to_num[s[len(s) - i - 1]] + hex_to_num[t[len(t) - i - 1]] + remainder
        # remember to add 1 if crossed f-0 border
        remainder = p // 16
        result.append(hex_string[p % 16])

    if remainder == 1:
        result.append(hex_string[remainder])
    return ''.join(reversed(result))


def main():
    a, b = map(str, input().split())
    print(hex_sum(a, b))


if __name__ == '__main__':
    main()


# Runtime: O(max(|s|, |t|))
# Memory: O(max(|s|, |t|))
