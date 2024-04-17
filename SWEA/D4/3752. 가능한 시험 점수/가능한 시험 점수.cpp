#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    vector<int> scores;
    for (int j = 0; j < n; j++) {
      int score;
      cin >> score;

      scores.push_back(score);
    }

    vector<int> answer;
    answer.push_back(0);
    int check[10'001] = {};
    check[0] = 1;

    for (int j = 0; j < scores.size(); j++) {
      int current_score = scores[j];
      int answer_size = answer.size();

      for (int k = 0; k < answer_size; k++) {
        if (check[answer[k] + current_score] == 0) {
          check[answer[k] + current_score] = 1;
          answer.push_back(answer[k] + current_score);
        }
      }
    }

    cout << "#" << i << " " << answer.size() << endl;
  }
}