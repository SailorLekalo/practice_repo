"""

есть список транзакций из банковской системы
Каждая транзакция представлена словарём с двумя полями:
timestamp — время транзакции в формате Unix time
    (целое число, количество секунд с 1 января 1970 года)
amount — сумма транзакции
    (целое или дробное число)
Список транзакций не отсортирован по времени.

Напиши функцию aggregate_by_quarter(transactions),
которая принимает этот список транзакций и возвращает словарь, где:
ключи — это строки, представляющие квартал в формате "YYYY-Q#"
    (например, "2023-Q1", "2023-Q2")
значения — это общая сумма всех транзакций за этот квартал

Input:

transactions = [
    {"timestamp": 1672531200, "amount": 100},  # 2023-01-01 -> Q1
    {"timestamp": 1680307200, "amount": 150},  # 2023-04-01 -> Q2
    {"timestamp": 1675209600, "amount": 200},  # 2023-02-01 -> Q1
    {"timestamp": 1704067200, "amount": 50},   # 2024-01-01 -> Q1
    {"timestamp": 1682899200, "amount": 250},  # 2023-05-01 -> Q2
]

Output:

{
    "2023-Q1": 300,
    "2023-Q2": 400,
    "2024-Q1": 50
}

"""

import datetime
from typing import Dict, List

def aggregate_by_quarter(transactions: List[Dict[str, int]]) -> Dict[str, int]:
    result: Dict[str, int] = {}
    for transaction in transactions:
        date = datetime.datetime.fromtimestamp(transaction["timestamp"])
        quarter = (date.month - 1) // 3 + 1
        key = str(date.year) + "-Q" + str(quarter)
        result[key] = result.get(key, 0) + transaction["amount"]
    return result


if __name__ == "__main__":
    transactions = [
        {"timestamp": 1672531200, "amount": 100},
        {"timestamp": 1680307200, "amount": 150},
        {"timestamp": 1675209600, "amount": 200},
        {"timestamp": 1704067200, "amount": 50},
        {"timestamp": 1682899200, "amount": 250},
    ]
    print(aggregate_by_quarter(transactions))

# Runtime: O(n)
# Memory: O(unique quarters num)
