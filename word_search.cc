#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "word_search.h"

namespace wsg {

WordSearchGrid::WordSearchGrid(wsg::Dict d, wsg::Grid wg) {
  dict = d;
  word_grid = wg;
}

bool WordSearchGrid::check_letter(const char &letter, int r, int c) {
  // indecies out of bounds
  if ((r < 0) || (r >= word_grid.get_num_rows()) || (c < 0) ||
      (c >= word_grid.get_num_cols())) {
    return false;
  }
  // not a letter match
  if (word_grid[r][c] != letter) {
    return false;
  }
  // letter match found!
  return true;
}

bool WordSearchGrid::word_horiz_vert(const std::string &word, int r, int c) {
  int word_len = word.length();
  bool up_path_valid = true;
  bool down_path_valid = true;
  bool left_path_valid = true;
  bool right_path_valid = true;
  for (int i = 1; i < word_len; i++) {
    if (!check_letter(word[i], r - i, c)) {
      up_path_valid = false;
    }
    if (!check_letter(word[i], r + i, c)) {
      down_path_valid = false;
    }
    if (!check_letter(word[i], r, c - i)) {
      left_path_valid = false;
    }
    if (!check_letter(word[i], r, c + i)) {
      right_path_valid = false;
    }
  }
  // word found value
  return (up_path_valid || down_path_valid || left_path_valid ||
          right_path_valid);
}

bool WordSearchGrid::word_diag(const std::string &word, int r, int c) {
  int word_len = word.length();
  bool q1 = true;
  bool q2 = true;
  bool q3 = true;
  bool q4 = true;
  for (int i = 1; i < word_len; i++) {
    if (!check_letter(word[i], r - i, c + i)) {
      q1 = false;
    }
    if (!check_letter(word[i], r - i, c - i)) {
      q2 = false;
    }
    if (!check_letter(word[i], r + i, c - i)) {
      q3 = false;
    }
    if (!check_letter(word[i], r + i, c + i)) {
      q4 = false;
    }
  }
  // word found value
  return (q1 || q2 || q3 || q4);
}

bool WordSearchGrid::rational_diag(const std::string &word, int r, int c) {
  // to do
  return false;
}

bool WordSearchGrid::find_word_in_grid(const std::string &word) {
  for (int r = 0; r < word_grid.get_num_rows(); r++) {
    for (int c = 0; c < word_grid.get_num_cols(); c++) {
      // check match on first letter of word
      if (word_grid[r][c] == word[0]) {
        int word_len = word.size();
        if (word_len == 1) {
          return true;
        }
        if ((word_len > 1) && word_horiz_vert(word, r, c)) {
          return true;
        } else if ((word_len > 1) && word_diag(word, r, c)) {
          return true;
        } else if ((word_len > 1) && rational_diag(word, r, c)) {
          return true;
        }
      }
    }
  }
  return false;
}

wsg::Dict &WordSearchGrid::look_for_dict_words_in_grid() {
  for (auto word : dict) {
    if (find_word_in_grid(word)) {
      words_found.add_word(word);
    }
  }
  print_words_found();
  return words_found;
}

void WordSearchGrid::print_words_found() {
  int words_found_len = words_found.get_num_dict_words();
  std::cout << "Number of words from dictionary found in 2D grid: "
            << words_found_len << std::endl;
  for (auto word_found : words_found) {
    std::cout << word_found << std::endl;
  }
}

} // namespace wsg