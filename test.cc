#include "word_search.h"
#include <gmock/gmock.h>
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

TEST(WordSearchTest, OneLetterGridAndDiffLetterDict) {
  WordSearchGrid wsg;
  std::vector<std::string> dict;
  dict.push_back("a");
  std::vector<std::vector<char>> word_grid;
  word_grid.push_back({'b'});
  wsg.set_dict(1, dict);
  wsg.set_2d_grid(1, 1, word_grid);
  std::vector<std::string> words_found = wsg.look_for_dict_words_in_grid();
  EXPECT_NE(words_found, dict);
}

TEST(WordSearchTest, OneLineSmall) {
  WordSearchGrid wsg;
  std::vector<std::string> dict;
  dict.push_back("a");
  dict.push_back("b");
  dict.push_back("ab");
  dict.push_back("ba");
  std::vector<std::vector<char>> word_grid;
  word_grid.push_back({'a', 'b'});
  wsg.set_dict(dict.size(), dict);
  wsg.set_2d_grid(1, 2, word_grid);
  std::vector<std::string> words_found = wsg.look_for_dict_words_in_grid();
  std::vector<std::string> solution;
  solution.push_back("a");
  solution.push_back("b");
  solution.push_back("ab");
  solution.push_back("ba");
  EXPECT_THAT(words_found, testing::UnorderedElementsAreArray(solution));
}

TEST(WordSearchTest, OneLine) {
  WordSearchGrid wsg;
  std::vector<std::string> dict;
  dict.push_back("a");
  dict.push_back("ab");
  dict.push_back("ba");
  dict.push_back("dcb");
  dict.push_back("db");
  dict.push_back("aa");
  dict.push_back("ac");
  dict.push_back("dca");
  std::vector<std::vector<char>> word_grid;
  word_grid.push_back({'a', 'b', 'c', 'd'});
  wsg.set_dict(dict.size(), dict);
  wsg.set_2d_grid(1, 4, word_grid);
  std::vector<std::string> words_found = wsg.look_for_dict_words_in_grid();
  std::vector<std::string> solution;
  solution.push_back("a");
  solution.push_back("ab");
  solution.push_back("ba");
  solution.push_back("dcb");
  EXPECT_THAT(words_found, testing::UnorderedElementsAreArray(solution));
}

TEST(WordSearchTest, OneLineRepeatLetters) {
  WordSearchGrid wsg;
  std::vector<std::string> dict;
  dict.push_back("a");
  dict.push_back("b");
  dict.push_back("ab");
  dict.push_back("ba");
  dict.push_back("aa");
  dict.push_back("bb");
  dict.push_back("aab");
  dict.push_back("bba");
  dict.push_back("baa");
  dict.push_back("aba");
  std::vector<std::vector<char>> word_grid;
  word_grid.push_back({'a', 'b', 'a', 'a'});
  wsg.set_dict(dict.size(), dict);
  wsg.set_2d_grid(1, 4, word_grid);
  std::vector<std::string> words_found = wsg.look_for_dict_words_in_grid();
  std::vector<std::string> solution;
  solution.push_back("a");
  solution.push_back("b");
  solution.push_back("ab");
  solution.push_back("ba");
  solution.push_back("aa");
  solution.push_back("aab");
  solution.push_back("baa");
  solution.push_back("aba");
  EXPECT_THAT(words_found, testing::UnorderedElementsAreArray(solution));
}

TEST(WordSearchTest, TwoLineSmall) {
  WordSearchGrid wsg;
  std::vector<std::string> dict;
  dict.push_back("a");
  dict.push_back("ab");
  dict.push_back("ba");
  dict.push_back("dcb");
  dict.push_back("db");
  dict.push_back("bc");
  dict.push_back("ac");
  dict.push_back("da");
  dict.push_back("dc");
  std::vector<std::vector<char>> word_grid;
  word_grid.push_back({'a', 'b'});
  word_grid.push_back({'c', 'd'});
  wsg.set_dict(dict.size(), dict);
  wsg.set_2d_grid(2, 2, word_grid);
  std::vector<std::string> words_found = wsg.look_for_dict_words_in_grid();
  std::vector<std::string> solution;
  solution.push_back("a");
  solution.push_back("ab");
  solution.push_back("ba");
  solution.push_back("db");
  solution.push_back("bc");
  solution.push_back("ac");
  solution.push_back("da");
  solution.push_back("dc");
  EXPECT_THAT(words_found, testing::UnorderedElementsAreArray(solution));
}

TEST(WordSearchTest, TwoLine) {
  WordSearchGrid wsg;
  std::vector<std::string> dict;
  dict.push_back("ab");
  dict.push_back("af");
  dict.push_back("ae");
  dict.push_back("ea");
  dict.push_back("fa");
  dict.push_back("ba");
  dict.push_back("cba");
  dict.push_back("gb");
  dict.push_back("efgh");
  dict.push_back("abg");
  dict.push_back("dg");
  dict.push_back("ff");
  std::vector<std::vector<char>> word_grid;
  word_grid.push_back({'a', 'b', 'c', 'd'});
  word_grid.push_back({'e', 'f', 'g', 'h'});
  wsg.set_dict(dict.size(), dict);
  wsg.set_2d_grid(2, 4, word_grid);
  std::vector<std::string> words_found = wsg.look_for_dict_words_in_grid();
  std::vector<std::string> solution;
  solution.push_back("ab");
  solution.push_back("af");
  solution.push_back("ae");
  solution.push_back("ea");
  solution.push_back("fa");
  solution.push_back("ba");
  solution.push_back("cba");
  solution.push_back("gb");
  solution.push_back("efgh");
  solution.push_back("dg");
  EXPECT_THAT(words_found, testing::UnorderedElementsAreArray(solution));
}

TEST(WordSearchTest, TwoLineComplexDiagonal) {
  WordSearchGrid wsg;
  std::vector<std::string> dict;
  dict.push_back("ab");
  dict.push_back("af");
  dict.push_back("ae");
  dict.push_back("ag");
  dict.push_back("ah");
  dict.push_back("ac");
  dict.push_back("ad");
  dict.push_back("ea");
  dict.push_back("fa");
  dict.push_back("ba");
  dict.push_back("cba");
  dict.push_back("gb");
  dict.push_back("df");
  dict.push_back("efgh");
  dict.push_back("abg");
  dict.push_back("dg");
  dict.push_back("ff");
  std::vector<std::vector<char>> word_grid;
  word_grid.push_back({'a', 'b', 'c', 'd'});
  word_grid.push_back({'e', 'f', 'g', 'h'});
  wsg.set_dict(dict.size(), dict);
  wsg.set_2d_grid(2, 4, word_grid);
  std::vector<std::string> words_found = wsg.look_for_dict_words_in_grid();
  wsg.print_words_found();
  std::vector<std::string> solution;
  solution.push_back("ab");
  solution.push_back("af");
  solution.push_back("ae");
  solution.push_back("ag");
  solution.push_back("ah");
  solution.push_back("ea");
  solution.push_back("fa");
  solution.push_back("ba");
  solution.push_back("cba");
  solution.push_back("gb");
  solution.push_back("df");
  solution.push_back("efgh");
  solution.push_back("dg");
  solution.push_back("ff");
  EXPECT_THAT(words_found, testing::UnorderedElementsAreArray(solution));
}