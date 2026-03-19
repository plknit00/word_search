#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "dict.h"

namespace wsg {

Dict::Dict() {
  // TODO set num words between 6-10
  // TODO randomly generate dict words
}

Dict::Dict(int nwords) {
  num_dict_words = nwords;
  // TODO randomly generate dict words
}

Dict::Dict(std::vector<std::string> d) {
  if (d.size() == 0) {
    std::cout << "Dictionaries must have 1+ rows." << std::endl;
  }
  dict = d;
  num_dict_words = d.size();
}

int Dict::get_num_dict_words() { return num_dict_words; }

void Dict::add_word(const std::string &word) { dict.push_back(word); }

Dict::const_iterator Dict::begin() const { return dict.begin(); }
Dict::const_iterator Dict::end() const { return dict.end(); }

} // namespace wsg