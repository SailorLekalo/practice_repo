def main():
    b,w = map(int,input().split())
    discr = (4+b)**2 - 16*(b+w)
    m = int((4+b+discr**0.5)/4)
    n = (b-2*m+4)/2
    print(int(max(n,m)),int(min(n,m)))


if __name__ == '__main__':
    main()
