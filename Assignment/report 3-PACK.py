box = [list(map(int,input().split())) for _ in range(3)]

def Big_box(box):                                   # 큰 박스 1개를 만드는 함수
    max_w = 0
    max_h = 0
    h = 0
    for i in range(3):                              # 박스를 2개, 1개로 나누어서 붙이는 경우
        if max_h < box[i][1]:                       # 다른 박스와 세로로 붙이지 않을 박스로 세로 길이가 가장 긴 박스를 설정
            max_h = box[i][1]                       
            temp_w,temp_h = box[i][0],box[i][1]     # 그 박스의 가로와 세로를 임시로 저장해준다
            temp = i

    box[temp][0] = 0
    box[temp][1] = 0
    for j in range(3):                              # 가장 긴 박스보다 나머지 2개 박스의 세로 길이가 더 긴 경우, 큰 박스의 세로 길이를 재설정 해준다.
        h += box[j][1]
    if max_h < h:
        max_h = h
    max_w = max(box)[0]                             # 세로로 붙인 박스의 가로 길이중에 큰 것과, 세로로 붙이지 않을 박스의 가로 길이를 더해서 큰 박스의 가로 길이를 정해준다.
    max_w += temp_w
    price_1 = max_w*max_w + max_h*max_h
    box[temp][0],box[temp][1] = temp_w,temp_h

    max_w = max(box)[0]                             # 박스를 3개 모두 한 방향으로 붙이는 경우(세로)
    max_h = box[0][1] + box[1][1] + box[2][1]       # 세로 길이는 3개의 박스를 세로로 붙인 총 길이이고, 가로 길이는 3개의 박스중에 가장 가로로 긴 것이다.
    price_2 = max_w*max_w + max_h*max_h

    max_h = box[0][1]                               # 박스를 3개 모두 한 방향으로 붙이는 경우(가로)
    for i in range(1,3):
        if max_h < box[i][1]:
            max_h = box[i][1]
    max_w = box[0][0] + box[1][0] + box[2][0]       
    price_3 = max_w*max_w + max_h*max_h

    least_price = min(price_1,price_2,price_3)      # 만든 3개의 큰 박스 중에 비용이 가장 작은 것을 선택한다(가로^2+세로^2의 값이 작은 것)
    return least_price

least_price = Big_box(box)                          # 처음 입력한 박스를 돌리지 않고 만들 수 있는 가장 적은 비용의 큰 박스

for i in range(3):                                  # 박스를 하나만 회전시킨 경우(2개를 회전시키는 것과 1개만 회전시키는 것은 동일하다.)
    box[i].reverse()
    price = Big_box(box)
    if least_price > price:
        least_price = price
    box[i].reverse()

print(least_price)

"""
자료구조 수업의 3번째 과제이다. 작은 3개의 박스를 입력받고, 
그 3개의 박스를 넣을 수 있는 큰 박스중에 가로^2+세로^2의 값이 가장 작은 것을 찾는 문제이다.
"""
