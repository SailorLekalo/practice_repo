def main():
    players = {}
    n = int(input())
    for i in range(n):
        players[input()] = 0


    team_a = 0
    team_b = 0
    m = int(input())
    for i in range(m):
        a,b = input().split()
        a_surplus, b_surplus = map(int,a.split(":"))
        players[b] += a_surplus-team_a + b_surplus-team_b
        team_a,team_b = a_surplus,b_surplus
    
    output,counter = "",0
    for i in players:
        if players[i]>counter: output,counter = i,players[i]
        elif players[i] == counter and i>output: output = i
    print(output,counter)

if __name__ == '__main__':
    main()
