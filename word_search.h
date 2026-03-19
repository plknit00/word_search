#pragma once

#include "dict.h"
#include "grid.h"
#include <string>
#include <vector>

namespace wsg {

class WordSearchGrid {
public:
  WordSearchGrid(wsg::Dict d, wsg::Grid wg);
  bool find_word_in_grid(const std::string &word);
  wsg::Dict &look_for_dict_words_in_grid();
  void print_words_found();

private:
  wsg::Dict dict;
  wsg::Grid word_grid;
  wsg::Dict words_found;
  bool check_letter(const char &letter, int r, int c);
  bool word_horiz_vert(const std::string &word, int r, int c);
  bool word_diag(const std::string &word, int r, int c);
  bool rational_diag(const std::string &word, int r, int c);
};
} // namespace wsg