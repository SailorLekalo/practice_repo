def main():
    n = int(input())
    costs = list(map(int,input().split()))

    x = int(input())
    combo = list(map(int,input().split()))

    k = int(input())
    goods = list(map(int,input().split()))
    goods_dict_etalon = {}
    for i in goods:
        goods_dict_etalon[i] = goods.count(i)
    top_border = max(goods.count(combo[i]) for i in range(4))
    
    output_cost = 99999999999999999999

    for tr in range(top_border+1):
        goods_dict = goods_dict_etalon.copy()
        total_cost = x*tr
        for i in range(tr):
            for j in combo:
                if j not in goods_dict: pass
                elif goods_dict[j] <= 0: goods_dict.pop(j)
                else: goods_dict[j] -= 1
        for i in goods_dict:
            total_cost += costs[i-1]*goods_dict[i]
        if total_cost<output_cost:
            output_cost = total_cost
    print(output_cost)
if __name__ == '__main__':
    main()
