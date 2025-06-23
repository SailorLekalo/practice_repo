"""
Реализовать функцию, которая заменяет пробелы в массиве символов на %20.
Делать это нужно "на месте", модифицируя исходный массив,
    в конце которого есть достаточно свободного места.


___
%20

r
hi_abc________, 6
 w

hi%20abc%20
"""

def replace_spaces(s: list[str], length: int) -> list[str]:
    # read from the last true string symbol
    read_p = length - 1
    space_count = 0
    for i in range(length):
        if s[i] == ' ':
            space_count += 1
    # we need two extra elements per space
    write_p = length - 1 + space_count * 2

    while read_p >= 0:
        if s[read_p] == ' ':
            # encode _ with %20 from the end
            s[write_p] = '0'
            s[write_p - 1] = '2'
            s[write_p - 2] = '%'
            write_p -= 3
        else:
            # write symbol as it is
            s[write_p] = s[read_p]
            write_p -= 1

        read_p -= 1

    return s


def main():
    s = list(input())
    length = int(input())
    print(replace_spaces(s, length))


if __name__ == '__main__':
    main()


# Runtime: O(N)
# Memory: O(1)
