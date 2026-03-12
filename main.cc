#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "word_search.h"

using namespace WSG;

int main(int argc, const char **argv) {

  if (argc != 2) {
    std::cout << "Expected input:" << std::endl;
    std::cout << "1. Dictionary of words separated by newline." << std::endl;
    std::cout << "2. 2D letter grid separated by space or newline."
              << std::endl;
    return -1;
  }

  //   FILE file1 = open(argv[0]);
  //   FILE file2 = open(argv[1]);

  // You are given a dictionary of words, and a 2d grid of letters and you're
  // finding all possible word search words. Normally word search only allows
  // following lines along one of 8 directions, but this word search allows you
  // to follow lines along any rational angle. For a line that is at some angle,
  // you only include the tiles that the line exactly intercepts. So for like a
  // line that goes at an angle of atan(3 / 5), if you atarted from (0,0) it
  // would include (5,3), (10,6), etc

  //   if (!WSG::init_dict_words(file1)) {
  //     std::cout << "Dictionary of words is invalid." << std::endl;
  //     return -1;
  //   }

  //   if (!WSG::init_2d_letter_grid(file2)) {
  //     std::cout << "2D letter grid invalid." << std::endl;
  //     return -1;
  //   }

  WordSearchGrid wsg;
  wsg.look_for_dict_words_in_grid();
  wsg.print_words_found();
}