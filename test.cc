#include "word_search.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace WSG;

TEST(WordSearchTest, EmptyBaseCase) {}

TEST(WordSearchTest, OneLetterGridAndDict) {
  WordSearchGrid wsg;
  std::vector<std::string> dict;
  dict.push_back("a");
  std::vector<std::vector<char>> word_grid;
  word_grid.push_back({'a'});
  wsg.set_dict(1, dict);
  wsg.set_2d_grid(1, 1, word_grid);
  std::vector<std::string> words_found = wsg.look_for_dict_words_in_grid();
  EXPECT_EQ(words_found, dict);
}