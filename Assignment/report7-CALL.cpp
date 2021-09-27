#include <iostream>
#include <vector>

using namespace std;
void input(int N,vector<vector<string>> &statement) {                             // 입력을 받아 각 줄을 2차원 string 배열에 넣어주었다.
	string sequence;
	for (int i = 0; i < N; i++) {
		vector<string> temp;
		cin >> sequence;
		temp.push_back(sequence);
		while (sequence != "$") {                                                     // $가 나오기 전까지 입력을 받는다.
			cin >> sequence;
			if (sequence != "$")                                                        // 마지막 $는 배열에 저장하지 않는다
				temp.push_back(sequence);
		}
		statement.push_back(temp);

	}
}
void call(int current, vector<vector<string>>& statement, int N, vector<string>& answer,int count) {
	for (int i = 1; i < statement[current].size(); i++) {                          // 함수의 구현부이다.
		int check = 0;
		for (int j = 0; j < N; j++) {
			if (statement[current][i] == statement[j][0]) {                            // 만약 다른 줄을 호출하고 있으면, 그 줄을 current로 주어서 재귀호출 해준다.
				count++;
				if (count > 200) {                                                       // 문제가 무한루프쪽으로 빠지게 되면, DEADLOCK을 출력하고 프로그램을 종료한다.
					cout << "DEADLOCK";
					exit(0);
				}
				call(j, statement, N, answer, count);
			}
		}
		for (int j = 0; j < N; j++) {
			if (statement[current][i] == statement[j][0]) {                            // 다른 줄의 이름이 아닌 경우에는 줄의 이름-실행단어 형식으로 answer 배열에 저장해준다.
				check = 1;
			}
		}
		if (check != 1) {
			string make = statement[current][0] + "-" + statement[current][i];
			answer.push_back(make);
		}
	}
}
void print(int k1,int k2, vector<string> answer) {                                // 출력을 구현한 부분이다
	if (k1 > answer.size())                                                         // k1 k2가 배열의 길이보다 크면 NONE을 출력하고, 크지 않으면 k1과 k2번째 실행문을 출력해준다
		cout << "NONE" << endl;
	else
		cout << answer[k1 - 1] << endl;
	if (k2 > answer.size())
		cout << "NONE" << endl;
	else
		cout << answer[k2 - 1] << endl;
}
int main() {
	int N,k1,k2;
	bool deadlock;
	cin >> N >> k1 >> k2;
	vector<vector<string>> statement;
	vector<string> answer;
	input(N, statement);
	call(0, statement, N, answer,0);
	print(k1, k2, answer);
	return 0;
}
/* 
자료구조 수업의 7번째 과제이다. 함수 이름과 실행문을 입력받고, 만약 실행문이 다른 함수의 이름일 경우에는 그 함수를 재귀로 호출하는 문제이다.
*/
