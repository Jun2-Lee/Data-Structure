while True:                               # 입력이 끝날 때 까지 계속 가위바위보를 한다
    try:
        a, b = input().strip().split()
        if a == b:                        # 같은 것을 냈으면, 'D'를 출력
           print('D')
        if a == 'R':                      # 그 후엔 이긴 사람이 낸 것을 출력해준다
            if b == 'S':
                print('R')
            if b == 'P':
                print('P')
        if a == 'S':
            if b == 'R':
                print('R')
            if b == 'P':
                print('S')
        if a == 'P':
            if b == 'R':
                print('P')
            if b == 'S':
                print('S')
    except EOFError:                      # 입력이 들어오지 않은 경우의 
        break
