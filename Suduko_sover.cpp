#include<bits/stdc++.h>

using namespace std;

bool IsValid(int box[][9], int row, int col, int no) {
  for (int i = 0; i < 9; i++) {
    if (box[i][col] == no)
      return false;

    if (box[row][i] == no)
      return false;

    if (box[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == no)
      return false;

  }
  return true;
}

bool Solve(int box[][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (box[i][j] == 0) {
        for (int no = 1; no <= 9; no++) {
          if (IsValid(box, i, j, no)) {
            box[i][j] = no;

            if (Solve(box))
              return true;
            else box[i][j] = 0;
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main() {

  int box[9][9];

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> box[i][j];
    }
  }

  Solve(box);

  cout << "Be Happy your suduko is solve" << endl;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << box[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
