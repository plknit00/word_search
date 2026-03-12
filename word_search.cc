#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "word_search.h"

namespace WSG {

bool WordSearchGrid::create_2d_letter_grid(FILE *file) {
  // to do
  return true;
}

bool WordSearchGrid::init_2d_letter_grid(FILE *file) {
  // to do
  return true;
}

bool WordSearchGrid::check_letter(const std::string &word, int r, int c,
                                  int i) {
  // indecies out of bounds
  if ((r < 0) || (r >= num_rows) || (c < 0) || (c >= num_cols)) {
    return false;
  }
  // not a letter match
  else if (word_grid[r][c] != word[i]) {
    return false;
  }
  // letter match found!
  return true;
}

bool WordSearchGrid::word_hoirz_vert(const std::string &word, int r, int c) {
  int word_len = word.length();
  for (int i = 1; i < word_len; i++) {
    int true_count = 0;
    if (check_letter(word, r - i, c, i) || check_letter(word, r + i, c, i) ||
        check_letter(word, r, c - i, i) || check_letter(word, r, c + i, i)) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

bool WordSearchGrid::word_diag(const std::string &word, int r, int c) {
  int word_len = word.length();
  for (int i = 1; i < word_len; i++) {
    int true_count = 0;
    if (check_letter(word, r - i, c - i, i) ||
        check_letter(word, r + i, c - i, i) ||
        check_letter(word, r + i, c - i, i) ||
        check_letter(word, r + i, c + i, i)) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

bool WordSearchGrid::funky_cases(const std::string &word, int r, int c) {
  // to do
  return false;
}

bool WordSearchGrid::find_word_in_grid(const std::string &word) {
  for (int r = 0; r < num_rows; r++) {
    for (int c = 0; c < num_cols; c++) {
      if (word_grid[r][c] == word[0]) {
        if (word_hoirz_vert(word, r, c)) {
          return true;
        } else if (word_diag(word, r, c)) {
          return true;
        } else if (funky_cases(word, r, c)) {
          return true;
        }
      }
    }
  }
  return false;
}

void WordSearchGrid::look_for_dict_words_in_grid() {
  for (int i = 0; i < num_dict_words; i++) {
    if (find_word_in_grid(dict[i])) {
      words_found.push_back(dict[i]);
    }
  }
}

void WordSearchGrid::print_words_found() {
  int words_found_len = words_found.size();
  std::cout << "Number of words from dictionary found in 2D grid: "
            << words_found_len << std::endl;
  for (int i = 0; i < words_found_len; i++) {
    std::cout << words_found[i] << std::endl;
  }
}

} // namespace WSG