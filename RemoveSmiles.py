"""
Реализовать функцию remove_smiles(text),
которая удаляет из строки смайлики вида :-) или :-( (включая многократные скобки)
"""

def remove_smiles(s: str) -> str:
    result = []
    read_p = 0

    while read_p < len(s):
        # find minimal smile
        if s[read_p] == ':' and read_p + 2 < len(s) and s[read_p + 1] == '-' and \
                s[read_p + 2] in ['(', ')']:
            read_p += 3
            # skip until the same bracket ends
            while read_p < len(s) and s[read_p] == s[read_p - 1]:
               read_p += 1
        else:
            # read all symbols that are not part of smile
            result.append(s[read_p])
            read_p += 1

    return "".join(result)


def main():
    s = input()
    print(remove_smiles(s))


if __name__ == '__main__':
    main()


# Runtime: O(N)
# Memory: O(N)
