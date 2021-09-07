def Big_box(box):
    price = 200000
    for i in range(6):
        for j in range(6):
            for k in range(6):
                if(i%3 == j%3 or j%3 == k%3 or k%3 == i%3):     # 중복된 박스일 때 실행하지 않는다
                    continue

                row   = max(box[i][0] + box[j][0],   box[k][0]) # 2개, 1개로 나누었을 때 
                col   = max(box[i][1] , box[j][1]) + box[k][1]
                price = min(price, row*row + col*col)       

                row   = box[i][0] + box[j][0] + box[k][0]       # 3개를 연달아 붙였을 때
                col   = max(box[i][1], box[j][1], box[k][1])
                price = min(price, row*row + col*col)
    return price

box = [[0]*2 for _ in range(6)]
for i in range(3):
    width, height = map(int,input().split())
    box[i][0]  ,box[i][1]   = width , height                    # 박스를 회전시키는 경우 추가
    box[i+3][0],box[i+3][1] = height, width

print(Big_box(box))
