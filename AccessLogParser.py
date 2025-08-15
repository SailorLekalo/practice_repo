"""

Тебе дан список строк logs, где каждая строка — это запись из лог-файла.
У записей есть разный формат, но тебя интересуют только те,
    которые касаются модификации кластеров.

Строки, связанные с модификацией, всегда содержат подстроку "Modify cluster_id=".
Результат модификации указан в той же строке в виде
    "status=SUCCESS" или "status=FAIL".

Напиши функцию get_successfully_modified_clusters(logs), которая принимает список logs
    и возвращает список уникальных идентификаторов кластеров,
    для которых была зафиксирована хотя бы одна успешная модификация (status=SUCCESS).
Порядок идентификаторов в итоговом списке не важен.

Input:

logs = [
    "2025-08-10 10:00:01 INFO Modify cluster_id=cl-123 status=SUCCESS",
    "2025-08-10 10:00:02 INFO Read cluster_id=cl-456",
    "2025-08-10 10:00:03 ERROR Modify cluster_id=cl-789 status=FAIL",
    "2025-08-10 10:00:04 INFO Modify cluster_id=cl-123 status=SUCCESS", # Успешный дубликат
    "2025-08-10 10:00:05 INFO Malformed log line",
    "2025-08-10 10:00:06 INFO Modify cluster_id=cl-abc status=SUCCESS"
]
Output:

['cl-123', 'cl-abc'] # или ['cl-abc', 'cl-123']

"""

from typing import Set, List

def get_clusters(logs: List[str]) -> List[str]:
    # maintain uniqueness of clusters
    clusters: Set[str] = set()
    MODIFY = "Modify cluster_id="
    SUCCESS = "status=SUCCESS"

    for log in logs:
        if MODIFY in log and SUCCESS in log:
            try:
                # cluster name goes after "Modify cluster_id=" and before " "
                after_id = log.split(MODIFY)[1]
                clusters.add(after_id.split()[0])
                # error may happen for incorrect input ending with "Modify cluster_id="
            except IndexError:
                continue
    return list(clusters)


if __name__ == "__main__":
    logs = [
        "2025-08-10 10:00:01 INFO Modify cluster_id=cl-123 status=SUCCESS",
        "2025-08-10 10:00:02 INFO Read cluster_id=cl-456",
        "2025-08-10 10:00:03 ERROR Modify cluster_id=cl-789 status=FAIL",
        "2025-08-10 10:00:04 INFO Modify cluster_id=cl-123 status=SUCCESS",
        "2025-08-10 10:00:05 INFO Malformed log line",
        "2025-08-10 10:00:06 INFO Modify cluster_id=cl-abc status=SUCCESS"
    ]
    print(get_clusters(logs))

# Runtime: O(nm) if m is avg length
# Memory: O(k) for #k unique clusters
