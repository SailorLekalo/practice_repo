def main():
    text = input()
    d = {}
    for i in range(len(text)-1):
        if text[i]!= " " and text[i+1]!=" ":
            a = text[i]+text[i+1]
            if a not in d: d[a] = 1
            else: d[a] +=1
    output,count = "",0
    for i in d:
        if d[i]>count:
            output = i
            count = d[i]
        elif d[i] == count and i>output:
            output = i
    print(output)



if __name__ == '__main__':
    main()
