def building_input(t):                                                                    # 빌딩을 추가하는 함수이다
    global end_point
    for _ in range(t):                                                                    # 빌딩을 입력받고, 도시의 끝 점을 정해준다
        building = list(map(int,input().split()))
        if building[0] + building[2] > end_point : end_point = building[0] + building[2]
        building_list.append(building)
    building_list.sort()

def make_skyline(t):                                                                      # 스카이 라인을 정하는 함수이다
    for i in range(t):
        for j in range(building_list[i][2]):                                              # x좌표에 이미 빌딩이 들어와있으면, 그 높이를 비교하고 높은 빌딩의 높이를 저장한다.
            h = building_list[i][1]
            if skyline[building_list[i][0] + j] != 0:
                if h > skyline[building_list[i][0] + j]:
                    skyline[building_list[i][0] + j] = h
                else:
                    continue
            skyline[building_list[i][0] + j] = h

def print_skyline():                                                                      # 만든 스카이라인을 출력하는 함수이다.
    start = building_list[0][0]                                                           # 빌딩이 처음으로 시작되는 x좌표를 먼저 출력한다
    print(start,end = " ")
    height = 0
    cnt = 0
    for i in range(start,end_point+1):                                                    # 빌딩의 높이가 바뀔 때, 가로의 길이와 높이가 얼마나 바뀌었는지 출력해준다
        if height != skyline[i]:
            if cnt != 0:
                print(cnt, end = " ")
            print(skyline[i]-height, end = " ")
            height = skyline[i]
            cnt = 0
        cnt += 1

building_list = []
end_point = 0
t = int(input())

building_input(t)
skyline = [0]*(end_point+1)
make_skyline(t)
print_skyline()
"""
자료구조 수업의 4번째 과제이다. 도시에 빌딩이 추가 될 때 변하는 스카이 라인을 구하고, 출력하는 문제이다.
"""
