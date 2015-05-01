#include <string>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <limits>
#include <vector>
#include <iostream>
#include <fstream>

#include "Algorithm.h"

using std::string;
using std::unordered_map;
using std::array;
using std::sort;
using std::bitset;
using std::numeric_limits;
using std::vector;
using std::istream;
using std::getline;
using std::cout;
using std::endl;
using std::ifstream;
using std::fstream;
using std::ios;

namespace StringUtil {

  struct LexicographicComparator {
    bool operator() (const string& lhs, const string& rhs) {
      size_t i = 0;
      while (i < lhs.size() && i < rhs.size()) {
	if (lhs[i] < rhs[i]) { return true; }
	if (lhs[i] > rhs[i]) { return false; }
      }
      return lhs.size() < rhs.size();
    }
  };

  struct AnagramComparator {
    bool operator() (const string& lhs, const string& rhs) {
      string sorted_lhs(lhs);
      string sorted_rhs(rhs);
      std::sort(sorted_lhs.begin(), sorted_lhs.end());
      std::sort(sorted_rhs.begin(), sorted_rhs.end());
      return sorted_lhs < sorted_rhs;
    }
  };

  void reverse_1(string& s);
  void reverse_2(string& s);
  void reverse_3(string& s);
  void reverse_4(char* s);
  void reverse_5(char* s);
  bool is_permutation_1(string& s, string& t);
  bool is_permutation_2(const string& s, const string& t);
  bool is_permutation_3(const string& s, const string& t);
  bool unique_chars(const string& s);
  void replace_spaces(string& s, const string& r);
  void replace_character_string(string& s, size_t size, char c, string& r);
  string compress_string(const string& s);
  string integer_to_string(int n, size_t base);
  int string_to_integer(const string& s, size_t base);
  int atoi(const string& str);
  string longest_common_prefix(vector<string> &strs);
  void permutation_helper(string& s, int start, vector<string>* res);
  vector<string> permutations(string& s);
  void anagram_partition_1(vector<string>& dictionary);
  vector<string> anagram_partition_1(const vector<string>& dictionary);
  vector<string> anagram_partition_2(const vector<string>& dictionary);
  void tail_1(string& filename, size_t k);
  string tail_2(string& filename, size_t k);
  string run_length_encode(const string& s);
  int roman_to_int_1(const string& s);
  int roman_to_int_2(const string& s);

}
