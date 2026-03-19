#pragma once
#include <string>
#include <vector>

namespace wsg {

class Dict {
public:
  using value_type = std::string;
  using const_iterator = std::vector<std::string>::const_iterator;
  using difference_type = std::ptrdiff_t;
  using const_reference = const std::string &;

  Dict();
  Dict(int nwords);
  Dict(std::vector<std::string> d);
  int get_num_dict_words();
  void add_word(const std::string &word);

  const_iterator begin() const;
  const_iterator end() const;

private:
  std::vector<std::string> dict;
  int num_dict_words;
};

} // namespace wsg