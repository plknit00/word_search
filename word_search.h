#include <string>
#include <vector>

namespace WSG {

class WordSearchGrid {
public:
  void set_dict(int num_words, std::vector<std::string> d);
  void set_2d_grid(int nr, int nc, std::vector<std::vector<char>> wg);
  bool create_2d_letter_grid(FILE *file);
  bool init_2d_letter_grid(FILE *file);
  bool check_letter(const std::string &word, int r, int c, int i);
  bool word_hoirz_vert(const std::string &word, int r, int c);
  bool word_diag(const std::string &word, int r, int c);
  bool funky_cases(const std::string &word, int r, int c);
  bool find_word_in_grid(const std::string &word);
  std::vector<std::string> look_for_dict_words_in_grid();
  void print_words_found();

private:
  std::vector<std::string> dict;
  std::vector<std::vector<char>> word_grid;
  int num_rows;
  int num_cols;
  int num_dict_words;
  std::vector<std::string> words_found;
};
} // namespace WSG