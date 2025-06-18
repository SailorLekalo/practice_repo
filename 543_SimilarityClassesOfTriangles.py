import sys

from math import gcd


# gcd(a, b) = gcd(b, a%b)
def own_gcd(a, b):
    while b:
        a, b = b, a%b
    return a


# O(1)
def own_sort(a, b, c):
    if a > b:
        a, b = b, a
    if b > c:
        b, c = c, b
    if a > b:
        a, b = b, a
    return a, b, c


def main():
    """
    Для чтения входных данных необходимо получить их
    из стандартного потока ввода (sys.stdin).
    Данные во входном потоке соответствуют описанному
    в условии формату. Обычно входные данные состоят
    из нескольких строк.
    Можно использовать несколько методов:
    * input() -- читает одну строку из потока без символа
    перевода строки;
    * sys.stdin.readline() -- читает одну строку из потока,
    сохраняя символ перевода строки в конце;
    * sys.stdin.readlines() -- вернет список (list) строк,
    сохраняя символ перевода строки в конце каждой из них.
    Чтобы прочитать из строки стандартного потока:
    * число -- int(input()) # в строке должно быть одно число
    * строку -- input()
    * массив чисел -- map(int, input().split())
    * последовательность слов -- input().split()
    Чтобы вывести результат в стандартный поток вывода (sys.stdout),
    можно использовать функцию print() или sys.stdout.write().
    Возможное решение задачи "Вычислите сумму чисел в строке":
    print(sum(map(int, input().split())))
    """

    lines = int(input())
    groups = set()
    for i in range(lines):
        line = []
        line.extend(map(int, input().split()))
        # gcd runtime: O(log min(a,b))
        gcd_val = gcd(gcd(line[0], line[1]), line[2])
        triangle = [x // gcd_val for x in line]
        # O(3 log3) ~> O(1)
        triangle.sort()
        # only adds unique
        groups.add(tuple(triangle))

    print(len(groups))


if __name__ == '__main__':
    main()


"""
6 6 10 -> 3 3 5
15 25 15 -> 3 5 3
35 21 21 -> 5 3 3
"""

# Runtime: O(N)
# Memory: O(N) because of set
