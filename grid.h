#pragma once
#include <string>
#include <vector>

namespace wsg {

class Grid {
public:
  Grid();
  Grid(int nrow, int ncol);
  Grid(std::vector<std::vector<char>> wg);
  const std::vector<char> &operator[](int row) const;
  int get_num_rows();
  int get_num_cols();

private:
  std::vector<std::vector<char>> word_grid;
  int num_rows;
  int num_cols;
};
} // namespace wsg