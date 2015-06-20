#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
public:
  bool check(const vector<vector<char> >& board, int i, int j, char c) {
    for (const char& n : board[i]) { if (n == c) { return false; } }
    for (const auto& r : board) { if (r[j] == c) { return false; } }
    for (int ii = 3 * (i / 3); ii < 3 * (i / 3) + 3; ++ii) {
      for (int jj = 3 * (j / 3); jj < 3 * (j / 3) + 3; ++jj) {
	if (board[ii][jj] == c) { return false; }
      }
    }
    return true;
  }

  bool solve(vector<vector<char> >& board)
  {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
	if (board[i][j] == '.') {
	  std::string numbers = "123456789";
	  for (const char& num : numbers) {
	    if (check(board, i, j, num)) {
	      board[i][j] = num;
	      if (solve(board)) { return true; }
	      board[i][j] = '.';
	    }
	  }
	  return false;
	}
      }
    }
    return true;
  }
};

#endif
