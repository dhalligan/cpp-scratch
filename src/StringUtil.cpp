#include "StringUtil.h"

namespace StringUtil {

  void reverse_1(string& s)
  {
    size_t i = 0, j = s.size() - 1;
    while (i < j) {
      std::swap(s[i++], s[j--]);
    }
  }

  void reverse_2(string& s)
  {
    auto b = s.begin(), e = s.end();
    e--;
    while (b < e) { iter_swap(b++, e--); }
  }

  void reverse_3(string & s)
  {
    auto b = s.begin(), e = s.end();
    e--;
    while (b < e) { std::swap(*b++, *e--); }
  }

  void reverse_4(char* s)
  {
    char* e = s;
    while (*e) { e++; } e--;
    while (s < e) { std::swap(*s++, *e--); }
  }

  void reverse_5(char* s)
  {
    size_t len = 0;
    for (size_t i = 0; s[i]; ++i) { len++; }
    for (int i = 0; i < len / 2; ++i) {
      std::swap(s[i], s[len - 1 - i]);
    }
  }

  bool is_permutation_1(string& s, string& t)
  {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }

  bool is_permutation_2(const string& s, const string& t)
  {
    unordered_map<char, size_t> count;
    for (char c : s) { count[c]++; }
    for (char c : t) {
      auto it = count.find(c);
      if (it != count.cend()) {
	if (--it->second == 0) {
	  count.erase(c);
	}
      } else {
	return false;
      }
    }
    return count.empty();
  }

  bool is_permutation_3(const string& s, const string& t)
  {
    if (s.size() != t.size()) { return false; }
    array<int,128> mp{};
    for (char c : s) { mp[c]++; }
    for (char c : t) { if(--mp[c] < 0) return false; }
    for (int i : mp) { if (i > 0) { return false; } }
    return true;
  }

  bool unique_chars(const string& s)
  {
    if (s.size() > 128) { return false; }

    bitset<128> count;
    for (char c : s) {
      if (count.test(c)) { return false; }
      count.set(c);
    }
    return true;
  }

  // replace_spaces replaces interior spaces in the string s with the string r in place.
  // s must have enough total spaces to accommodate the new characters from r.
  // Example: Input:  "Mr John Smith    ", "%20"
  //          Output: "Mr%20John%20Smith"
  void replace_spaces(string& s, const string& r)
  {
    int src = s.size() - 1, tar = s.size() - 1;
    while (isspace(s[src])) { src--; }
    while (src >= 0) {
      if (isspace(s[src])) {
	int i = r.size() - 1;
	while (i >= 0) {
	  s[tar--] = r[i--];
	}
	src--;
      } else {
	s[tar--] = s[src--];
      }
    }
  }

  void replace_character_string(string& s, size_t size, char c, string& r)
  {
    using namespace Algorithm;
    my_replace_multiple(s.begin(), std::next(s.begin(), size), s.end(), c, r.begin(), r.end());
  }

  string compress_string(const string& s)
  {
    auto first = s.begin(), last = s.end();
    string result;
    if (first == last) return result;

    size_t count = 1;
    result.push_back(*first);
    while (++first != last) {
      if (*first != result.back()) {
	result.append(integer_to_string(count, 10));
	result.push_back(*first);
	count = 1;
      } else {
	count++;
      }
    }
    result.append(integer_to_string(count, 10));
    return result.size() < s.size() ? result : s;
  }

  string run_length_encode(const string& s)
  {
    auto prev = s.begin(), ahead = prev, last = s.end();
    string result;
    size_t count = 1;
    if (ahead == last) { return result; }

    while (++ahead != last) {
      if (*prev != *ahead) {
	result.append(integer_to_string(count, 10));
	result.push_back(*prev);
	prev = ahead;
	count = 1;
      } else {
	count++;
      }
    }
    result.append(integer_to_string(count, 10));
    result.push_back(*prev);
    return result.size() < s.size() ? result : s;
  }

  string integer_to_string(int n, size_t base)
  {
    string result;
    bool is_negative = (n < 0);
    if (is_negative) { n = -n; }

    while (n) {
      int r = n % base;
      result.push_back( r >= 10 ? 'A' + r - 10 : '0' + r);
      n /= base;
    }

    if (result.empty()) { result.push_back('0'); }
    if (is_negative) { result.push_back('-'); }
    reverse(result.begin(), result.end());
    return result;
  }

  int string_to_integer(const string& s, size_t base)
  {
    int sgn = s.front() == '-' ? -1 : 1;
    int result = 0;

    for (char c : s) {
      result *= base;
      result += isdigit(c) ? c - '0' : 10 + c - 'A';
    }
    return sgn * result;

  }

  int atoi(const string& str)
  {
    auto first = str.begin(), last = str.end();
    if (first == last) { return 0; }
    while (isspace(*first) && first != last) { first++; }

    int sgn = 1;
    if (*first == '-' || *first == '+') {
      sgn = *first == '-' ? -1 : 1;
      first++;
    }

    unsigned long long int result = 0;
    for ( ; isdigit(*first) && first != last; ++first) {
      result = 10 * result + *first - '0';
      if (result >= numeric_limits<int>::max() && sgn == 1) { return numeric_limits<int>::max(); }
      if (result > numeric_limits<int>::max() && sgn == -1) { return numeric_limits<int>::min(); }
    }
    return sgn*result;
  }

  string longest_common_prefix(vector<string> &strs)
{
    if (strs.size() == 0) { return ""; }
    string prefix;
    bool done = false;
    for (size_t j = 0; !done && j < strs[0].size(); ++j) {
      char c = strs[0][j];
      for (string s : strs) {
	if (j ==  s.size() || s[j] != c) {
	  done = true;
	  break;
	}
      }
      if (!done) { prefix.push_back(c); }
    }
    return prefix;
  }

  void permutation_helper(string& s, int start, vector<string>* res)
  {
    if (start == s.size()) {
      res->emplace_back(s);
    }
    for (int i = start; i < s.size(); ++i) {
      std::swap(s[start], s[i]);
      permutation_helper(s, start + 1, res);
      std::swap(s[start], s[i]);
    }
  }

  vector<string> permutations(string& s)
  {
    vector<string> result;
    permutation_helper(s, 0, &result);
    return result;
  }

  vector<string> anagram_partition_1(const vector<string>& dictionary)
  {
    vector<string> result(dictionary);
    sort(result.begin(), result.end(), AnagramComparator());
    return result;
  }

  vector<string> anagram_partition_2(const vector<string>& dictionary)
  {
    vector<string> result;
    unordered_map<string, vector<string> > hash;
    for (const string& s : dictionary) {
      string sorted_s(s);
      sort(sorted_s.begin(), sorted_s.end());
      hash[sorted_s].emplace_back(s);
    }

    for (auto& p : hash) {
      for (auto& s : p.second) {
	result.emplace_back(s);
      }
    }
    return result;
  }

  void tail_1(string& filename, size_t k)
  {
    ifstream is(filename);
    string lines[k];
    size_t count = 0;

    while (getline(is, lines[count % k])) {
      count++;
    }

    size_t num_lines = std::min(k, count);
    size_t start = count > k ? count % k : 0;

    for (size_t i = 0; i < num_lines; i++) {
      cout << lines[(start + i) % k] << endl;
    }

  }

  string tail_2(string& filename, size_t k)
  {
    fstream file_ptr(filename.c_str());
    string result;

    file_ptr.seekg(0, ios::end);
    int file_size = file_ptr.tellg(), newline_count = 0;

    for (int i = 0; i < file_size; ++i) {
      file_ptr.seekg(-1 - i, ios::end);
      char c;
      cout << "read: " << c << endl;
      file_ptr.get(c);
      if (c == '\n') {
	if (++newline_count > k) {
	  break;
	}
      }
      result.push_back(c);
    }
    reverse(result.begin(), result.end());
    return result;

  }


  // int Roman::roman_to_int(const string& s)
  // {
  //   unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
  //   int sum = 0;
  //   for (int i = 0; i < s.size(); ++i) {
  //     sum += i == 0 || mp[s[i]] <= mp[s[i - 1]] ? mp[s[i]] : mp[s[i]] - 2 * mp[s[i - 1]];
  //   }
  //   return sum;
  // }

  int Roman::roman_to_int(string s)
  {
    unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    if (s.size() == 0) { return 0; }
    int sum = mp[s.back()];
    for (int i = s.size() - 2; i >= 0; --i) {
      sum += mp[s[i]] >= mp[s[i + 1]] ? mp[s[i]] : -mp[s[i]];
    }
    return sum;
  }

  string Roman::int_to_roman(int n)
  {
    typedef pair<int, string> Entry;
    vector<Entry> mp {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    string result;
    while(n) {
      auto i = find_if(mp.begin(), mp.end(), [n](const Entry& e) { return n >= e.first; });
      result += i->second, n -= i->first;
    }
    return result;
  }

  bool Roman::valid_roman(string s)
  {
    regex p {R"(M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3}))"};
    return regex_match(s, p);
  }

  vector<string> group_anagrams(vector<string>& strs)
  {
    vector<string> result;
    unordered_map<string, vector<string> > mp;

    for (const string& s : strs) {
      string sorted_s(s);
      sort(sorted_s.begin(), sorted_s.end());
      mp[sorted_s].emplace_back(s);
    }

    for (auto& p : mp) {
      if (p.second.size() > 1) {
	for (auto& s : p.second) {
	  result.emplace_back(s);
	}
      }
    }
    return result;
  }

  bool isomorphic_strings(const string& s, const string& t)
  {
    if (s.size() != t.size()) { return false; }
    unordered_map<char,char> mp_f, mp_r;
    for (size_t i = 0; i < s.size(); ++i) {
      char c = s[i], d = t[i];
      if (mp_f.find(c) != mp_f.cend()) {
	if (mp_f[c] != d) { return false; }
      } else if (mp_r.find(d) != mp_r.cend()) {
	if (mp_r[d] != c) { return false; }
      } else {
	mp_f[c] = d, mp_r[d] = c;
      }
    }
    return true;
  }

  void reverse_words(string& s)
  {
    const string whitespace = " \t";
    auto i = s.find_first_not_of(whitespace), j = s.find_last_not_of(whitespace);
    if (i == string::npos) { s.replace(0, s.size(), ""); return; }
    s = s.substr(i, j - i + 1);

    i = s.find_first_of(whitespace);
    while (i != string::npos) {
      j = s.find_first_not_of(whitespace, i);
      s.replace(i, j - i, " ");
      i = s.find_first_of(whitespace, i + 1);
    }

    i = 0, j = 0;
    while (i != string::npos && j != string::npos) {
      j = s.find_first_of(whitespace, i);
      j == string::npos ? reverse(next(s.begin(), i), s.end()) : reverse(next(s.begin(), i), next(s.begin(), j));
      i = s.find_first_not_of(whitespace, j);
    }

  }

  string look_and_say(int n)
  {
    string result = "1";
    for (int i = 1; i < n; ++i) {
      string next;
      stringstream nextss;
      char u = result.front();
      int count = 0;
      for (const char& c : result) {
	if (count == 0) {
	  u = c, count = 1;
	} else if (u != c) {
	  nextss << count << u;
	  u = c, count = 1;
	} else {
	  count++;
	}
      }
      if (count != 0) { nextss << count << u; }
      result = nextss.str();
    }
    return result;
  }

  bool palindromic(std::string s)
  {
    auto first = s.begin();
    auto last = s.end() - 1;
    while ((first < last)) {
      while ((first < last) && !isalnum(*first)) first++;
      while ((first < last) && !isalnum(*last)) last--;
      if (tolower(*first++) != tolower(*last--)) return false;
    }
    return true;
  }

  void find_palindrome_anagram(string& word, const vector<string>& dictionary)
  {
    std::unordered_map<string, vector<string> > hash;
    for (const string& s : dictionary) {
      string sorted(s);
      std::sort(sorted.begin(), sorted.end());
      hash[sorted].emplace_back(s);
    }

    std::string sorted_word(word);
    std::sort(sorted_word.begin(), sorted_word.end());
    for (const string& s : hash[sorted_word]) {
      if (palindromic(s)) {
	std::cout << s << " " << std::endl;
      }
    }

  }

  int compare_versions(const string& version1, const string& version2)
  {
    auto i = version1.begin(), j = version2.begin();
    while (i != version1.end() && j != version2.end()) {
      auto i2 = find(i, version1.end(), '.'), j2 = find(j, version2.end(), '.');
      int num1 = stoi(string(i, i2)), num2 = stoi(string(j, j2));
      if (num1 > num2) { return 1; }
      if (num1 < num2) { return -1; }
      i = i2 == version1.end() ? version1.end() : next(i2);
      j = j2 == version2.end() ? version2.end() : next(j2);
    }
    if (i != version1.end() && stoi(string(i, version1.end())) != 0) { return 1; }
    if (j != version2.end() && stoi(string(j, version2.end())) != 0) { return -1; }
    return 0;
  }

}
