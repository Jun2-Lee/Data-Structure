Tile = list(map(int,input().split()))
ans = [0]*(max(Tile)+1)                 # 정답을 저장하기 위한 배열이다
for i in Tile:                          
    for j in range(i):
        ans[j] += 1                     # 세로로 셌을 때 j번째 칸에 타일이 있으면 +1을 해 주었다
print(' '.join(map(str,ans)))

"""
자료구조 수업의 두 번째 과제이다. Tile을 가로로 셌을 때의 갯수를 입력해주면, 세로로 셌을 때의 갯수를 출력해주는 것이다.
"""
