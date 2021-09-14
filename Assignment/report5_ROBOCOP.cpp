#include <iostream>
#include <vector>
using namespace std;

void point_input(int t,int x_list[],int y_list[]){  // 처음에 점들을 입력받는 함수이다.
    int x, y;
    for(int i = 0; i < t;i++){
        cin >> x >> y;
        x_list[i] = x;
        y_list[i] = y;
    }
}

void make_answer(int t, int x_list[], int y_list[], vector <vector <int>>& answer, vector <int> xy) { // 정답배열 즉, 로봇이 길을 1바퀴 돌 때의 위치를 초마다 저장한 배열을 만드는 함수이다.
    for (int i = 1; i < t+1; i++) {                                     // 세로방향으로 움직일 때.(x좌표가 바뀔 때)
        if (x_list[i] != x_list[i - 1]) {
            if (x_list[i] > x_list[i - 1]) {
                for (int j = x_list[i - 1]; j < x_list[i]; j++) {
                    xy[0] = j;
                    xy[1] = y_list[i - 1];
                    answer.push_back(xy);
                }
            }
            else {
                for (int j = x_list[i - 1]; j > x_list[i]; j--) {
                    xy[0] = j;
                    xy[1] = y_list[i - 1];
                    answer.push_back(xy);
                }
            }
        }
        else if (y_list[i] != y_list[i - 1]) {                          // 가로 방향으로 움직일 때(y좌표가 바뀔 때)
            if (y_list[i] > y_list[i - 1]) {
                for (int j = y_list[i - 1]; j < y_list[i]; j++) {
                    xy[0] = x_list[i-1];
                    xy[1] = j;
                    answer.push_back(xy);
                }
            }
            else {
                for (int j = y_list[i - 1]; j > y_list[i]; j--) {
                    xy[0] = x_list[i - 1];
                    xy[1] = j;
                    answer.push_back(xy);
                }
            }
        }
    }
}
void print_answer(int time_list[],vector <vector <int>> answer){          // 정답을 출력하는 함수이다.
    for(int i = 0; i<5; i++){
        cout << answer[time_list[i] % answer.size()][0] << " " << answer[time_list[i] % answer.size()][1] << endl;
        }
}

int main(void) {
    int t;
    int time;
    cin >> t;
    
    int* x_list = new int[t+1];
    int* y_list = new int[t+1];
    vector <vector <int>> answer;
    vector <int> xy(2, 0);
    int time_list[5];
    point_input(t, x_list, y_list);
    x_list[t] = x_list[0];
    y_list[t] = y_list[0];
    for (int i = 0; i < 5; i++) {
        cin >> time;
        time_list[i] = time;
    }
    make_answer(t, x_list, y_list, answer,xy);
    print_answer(time_list, answer);
    delete[] x_list;
    delete[] y_list;
    return 0;
}
/*
자료구조 과목의 5번째 과제이다. 길의 꼭짓점이 되는 점들을 입력받으면, 그 점들을 이은 길로 로봇이 순찰을 한다. 한칸을 움직이는데는 1초가 걸린다
후에 초를 입력받으면 그 때의 위치를 출력하는 문제이다.
*/
