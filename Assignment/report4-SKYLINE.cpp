#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int building_input(int t, vector<vector<int>> &building_list){
    int end_point = 0;
    for (int i = 0; i < t; i++) {
        int start, height, width;
        cin >> start >> height >> width;
        if (start + width > end_point)
            end_point = start + width;
        building_list[i][0] = start;
        building_list[i][1] = height;
        building_list[i][2] = width;
    }
    sort(building_list.begin(), building_list.begin()+t);
    return end_point;
}
void make_skyline(int t, vector<vector<int>>building_list, int skyline[]) {
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < building_list[i][2]; j++) {
            int h = building_list[i][1];
            if (skyline[building_list[i][0] + j] != 0) {
                if (h > skyline[building_list[i][0] + j])
                    skyline[building_list[i][0] + j] = h;
                else
                    continue;
            }
            skyline[building_list[i][0] + j] = h;
        }
    }
}
void print_skyline(vector<vector<int>>building_list, int skyline[],int end_point){
    int start = building_list[0][0];
    cout << start << " ";
    int height = 0;
    int cnt = 0;
    for (int i=start;i<=end_point;i++){
        if (height != skyline[i]){
            if (cnt != 0)
                cout << cnt << " ";
            cout << skyline[i] - height << " ";
            height = skyline[i];
            cnt = 0;
            }
        cnt += 1;
    }
}


int main(void){
    int t;
    cin >> t;
    vector<vector<int>> building_list(10000,vector<int>(3,0));
    int end_point = building_input(t, building_list);
    int* skyline = new int[end_point+1] {0};
    make_skyline(t, building_list, skyline);
    print_skyline(building_list, skyline, end_point);
    delete[] skyline;
    return 0;
}

/*
앞선 SKYLINE을 C++로 짠 코드이다
*/
