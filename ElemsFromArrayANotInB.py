"""
Даны два отсортированных массива a и b. Вернуть элементы из a, которых нет в b
"""

def in_a_not_in_b(a, b):
    p1 = 0
    p2 = 0
    result = []

    while p1 < len(a) and p2 < len(b):
        # if elem is in both, move on
        if b[p2] == a[p1]:
            p1 += 1
            p2 += 1
        elif b[p2] < a[p1]:
            p2 += 1
        # elem is certainly missed in b
        else:
            result.append(a[p1])
            p1 += 1

    # we may yet have elems to consider
    while p1 < len(a):
        result.append(a[p1])
        p1 += 1

    return result


"""
arr1 = [1, 2, 5, 8], arr2 = [2, 4, 8, 9]
[1, 5]
"""

# Runtime: O(N+M)
# Memory: O(1)
