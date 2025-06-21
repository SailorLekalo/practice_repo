"""
дан список символов, убрать лишние пробелы inplace, оставив по одному пробелу между словами

          r
a bc d  d .
       l

               r
 a  bc  d    d .
        l

a bc d d
8
"""

def remove_spaces(s: list[str]) -> list[str]:
    read_p = 0
    write_p = 0
    # not to include the last valid space
    length = 0

    while read_p < len(s):
        if s[read_p] != ' ':
            s[write_p] = s[read_p]
            write_p += 1
            length = write_p
        # write only the first space and not include it in length
        elif write_p != 0 and s[write_p-1] != ' ':
            s[write_p] = s[read_p]
            write_p += 1
        read_p += 1

    return s[:length]


def main():
    print(remove_spaces(list(input())))


if __name__ == '__main__':
    main()


# Runtime: O(N)
# Memory: O(1)
