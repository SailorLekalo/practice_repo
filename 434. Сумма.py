def recurse(dic,n,mx):
    if n == 0:
        print(dic[3:])
    for i in range(1,mx+1):
        if n-i>=0:
            recurse(dic+f" + {i}",n-i,i)
        
def main():
    n = int(input())
    recurse("",n,n)
    

if __name__ == '__main__':
    main()
