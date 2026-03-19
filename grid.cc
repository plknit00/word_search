#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "grid.h"

namespace wsg {

Grid::Grid() {
  // TODO set num rows and cols to be = number randomly from 6-9
  // TODO randomly generate word grid letters
}

Grid::Grid(int nrow, int ncol) {
  num_rows = nrow;
  num_cols = ncol;
  // TODO randomly generate word grid letters
}

Grid::Grid(std::vector<std::vector<char>> wg) {
  if (wg.size() == 0) {
    std::cout << "Word grid must have 1+ rows." << std::endl;
  } else if (wg[0].size() == 0) {
    std::cout << "Word grid must have 1+ columns." << std::endl;
  }
  word_grid = wg;
  num_rows = wg.size();
  num_cols = wg[0].size();
}

const std::vector<char> &Grid::operator[](int row) const {
  return word_grid[row];
}

int Grid::get_num_rows() { return num_rows; }

int Grid::get_num_cols() { return num_cols; }

} // namespace wsg