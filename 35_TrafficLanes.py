import sys


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
    m, n = map(int, input().split())

    # store amounts for calculated states
    memo = {}

    def dp(lane, max_covered, last_max):
        if lane == n:
            return 1 if max_covered == m - 1 else 0

        state = (lane, max_covered, last_max)
        if state in memo:
            return memo[state]

        result = 0

        # dive into all possible intervals of roads for current lane to take
        for start in range(last_max, m):
            for end in range(start, m):
                new_max_covered = max(max_covered, end)
                if start <= max_covered + 1:
                    # check all possible intervals for the next lane
                    result += dp(lane + 1, new_max_covered, end)

        memo[state] = result
        return result

    print(dp(0, -1, 0))


if __name__ == '__main__':
    main()


# Runtime: O(N^2)
# Memory: O(N^4)

"""
  дорог/направлений:
- 2 3  4  5 6
1 1 1  1  1 1
2 3 5  7  9 11
3 5 11 23

"""
