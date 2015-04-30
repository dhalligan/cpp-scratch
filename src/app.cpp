#include <iostream>
#include <cstdlib>
#include <cctype>
#include <exception>
#include <stdexcept>
#include <memory>
#include <sstream>

#include "app.h"

App::App(int& argc, char** argv)
{
  std::cout << "Creating aapplication..." << std::endl;
  std::cout << "Finished." << std::endl;
}

App::~App()
{
}

int App::exec()
{
  std::cout << "Running application..." << std::endl;
  std::cout << std::endl;

  Parity parity;
  std::cout << "swap_bits(5) = " << parity.swap_bits(5,1,2) << std::endl;

  std::vector<int> vi1 = {1, 2, 3, 4};
   Polynomial<std::vector<int>::iterator,int,int> poly1 ( vi1.begin(), vi1.end() );
   std::cout << "poly_{1,2,3,4}(2) returns " << poly1(2) << std::endl;
   std::cout << std::endl;

   std::vector<int> vi2 = {2, 4};
   Polynomial<std::vector<int>::iterator,int,int> poly2 ( vi2.begin(), vi2.end() );
   std::cout << "poly_{2,4}(3) returns " << poly2(3) << std::endl;
   std::cout << std::endl;

   //  std::cout << "111 in base 2 is " << string_to_integer("111", 2) << std::endl;

  //  std::cout << "11 in base 10 is " << convert_base("11", 2, 10) << std::endl;

  std::cout << "reversed = " << parity.reverse_bits(6) << std::endl;

  std::cout << "ssDecodeColID(AC) = " << ssDecodeColID("AC") << std::endl;

  std::cout << "closest_int_same_bits(0b1100) = " << closest_int_same_bits(0b1001) << std::endl;

  std::cout << "power = " << pow(4.0,4) << std::endl;

  std::string test_string = "this is a test string";
  remove_replace(test_string, 's', 't', 'T');
  std::cout << test_string << std::endl;

  //  std::vector<int> tvec = {1, 6, 3, 4, 7, 4, 4, 7, 1, 3, 8};
  std::vector<int> tvec = {1, 2, 2, 3, 4, 4, 4, 4, 5, 5, 6};
  //my_partition(tvec.begin(), tvec.end(), less_than<int>(4) );
  //dutch_flag_partition(tvec.begin(), tvec.end(), less_than<int>(4), equal_to<int>(4) );
  //  my_remove_if(tvec.begin(), tvec.end(), equal_to<int>(4) );

  //  my_unique(tvec.begin(), tvec.end());
  //  my_for_each(tvec.begin(), tvec.end(), [](int x) {std::cout << x << std::endl;});

  std::vector<int> int_str = {9, 9, 9, 9, 9, 9};
  BigInt my_int(8);
  BigInt my_int2(8);
  s(s(s(my_int))).print();
  my_int2 = s(my_int);
  my_int2.print();
  std::cout << "random access: " << my_int2[7] << std::endl;
  //  my_int.s().s().s().print();
  //  my_int.s();
  //  val.print();

  //  increment_integer(my_int.begin(), my_int.end(), std::back_inserter<std::vector<int> >(my_int));
  //  my_for_each(my_int.begin(), my_int.end(), [](int x) {std::cout << x << std::endl;});

  decimal_digit d1(8);
  decimal_digit d2(2);
  decimal_digit d3 = (d1 + d2);
  std::cout << "decimal digit add: " << d3 << std::endl;

  std::cout << "Big Ints" << std::endl;
  std::vector<decimal_digit> v1 = {9, 2, 3};
  std::vector<decimal_digit> v2 = {2, 7};
  BigInt b1(v1);
  BigInt b2(v2);
  BigInt b3 = b1.a(b2);
  b1.print();
  b2.print();
  b3.print();
  std::cout << carry(2, 9, 0) << std::endl;

  std::cout << "testing missing int..." << std::endl;
  std::vector<int> vi = {5, 6, 99, 99, 2, 1, 99, 99};
  std::cout << "missing = " << smallest_missing_positive(vi) << std::endl;

  std::vector<int> prices = {6, 8, 2, 3, 8, 1, 40, 8, 9, 3, 2, 30};
  std::cout << "max gain = " << max_forward_diff_2(prices) << std::endl;

  std::vector<int> my_vec = {1, 2, 3, 4, 5, 6};
  //  my_reverse(my_vec.begin(), my_vec.end());
  my_rotate(my_vec.begin(), my_vec.begin()+2, my_vec.end());
  for (auto i : my_vec) std::cout << i << ' ';
  std::cout << std::endl;

  std::cout << "palindrome? " << palindromic("A man, a plan, a canal, Panama") << std::endl;

  //  std::cout << "1230 in base 10 is " << string_to_integer("-1230", 10) << std::endl;
  //  std::cout << "integer to string: " << integer_to_string(-123, 10) << std::endl;

  std::string sentence = "This    is  a sentence";
  std::cout << reverse_sentence(sentence) << std::endl;

  std::vector<std::string> res = tokenize_sentence(sentence);

  std::cout << "phone..." << std::endl;
  std::string pnum("23");
  std::string ans(pnum.size(), 0);
  phone_mnemonic_helper(pnum, 0, &ans);

  auto l1 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto l2 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto l3 = std::make_shared<ListNode<int> >(ListNode<int>());
  l3->data = 7; l3->next = nullptr;
  l2->data = 5; l2->next = l3;
  l1->data = 2; l1->next = l2;

  auto f1 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto f2 = std::make_shared<ListNode<int> >(ListNode<int>());
  f2->data = 11; f2->next = nullptr;
  f1->data = 3; f1->next = f2;

  // print_linked_list(f1);
  // print_linked_list(l1);

  // shared_ptr<ListNode<int> > merged = merge(f1,l1);
  // print_linked_list(merged);
  // shared_ptr<ListNode<int> > rev = reverse_list(merged);
  // print_linked_list(rev);

  // //  shared_ptr<ListNode<int> > rev2 = reverse_sublist(merged, 4, 3);
  // //  print_linked_list(rev2);


  auto g1 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto g2 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto g3 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto g4 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto g5 = std::make_shared<ListNode<int> >(ListNode<int>());
  g5->data = 15; g5->next = nullptr;
  g4->data = 15; g4->next = g5;
  g3->data = 15; g3->next = g4;
  g2->data = 13; g2->next = g3;
  g1->data = 3; g1->next = g2;


  // print_linked_list(g1);
  // unique_list(g1);
  // print_linked_list(g1);


  auto s1 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto s2 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto s3 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto s4 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto s5 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto s6 = std::make_shared<ListNode<int> >(ListNode<int>());
  s6->data = 3; s6->next = nullptr;
  s5->data = 13; s5->next = s6;
  s4->data = 15; s4->next = s5;
  s3->data = 15; s3->next = s4;
  s2->data = 13; s2->next = s3;
  s1->data = 3; s1->next = s2;

  //  std::cout << "The median of sorted LL is: " << find_median_sorted_list(s1) << std::endl;
  //  selection_sort_list(s1);
  //  std::cout << "Sorted LL: " << std::endl;
  //  print_linked_list(s1);
  std::cout << std::endl;

  std::stack<int> test_stack;
  test_stack.push(1);
  test_stack.push(4);
  test_stack.push(2);
  test_stack.push(7);

  //  sort(test_stack);
  //  std::string input = "1 5 6 7 3 8 2 5 7 3 4 5 3 6 3 4 6";
  //  cin cin;

  //  online_median(std::cin);

  // std::priority_queue<int, vector<int>, less<int> > mh;
  // mh.push(1);
  // mh.push(9);
  // mh.push(3);
  // mh.push(4);
  // mh.push(9);
  // mh.push(7);
  // mh.push(1);
  // mh.push(2);
  // mh.push(2);
  // mh.push(2);
  // mh.push(6);
  // k_largest(mh, 4);

  std::vector<int> search = {1, 1, 2, 3, 4, 5, 5, 5, 5, 6, 8, 9, 11, 14, 14, 15, 16, 17, 18, 20};
  //  std::cout << "index = " << binary_search(5, search) << std::endl;

  std::vector<int> fp_search = {-2,  0, 2,  3,  6,  7,  9};
  //  std::vector<int> fp_search = {-2, -1, 0,  0,  2,  2,  3};

  //  std::vector<int> fp_search = {-2,  0,  2,  2,  3,  6,  7,  9}; // what to do when repeats?
  //  std::vector<int> fp_search = {-2, -1,  0, -1, -1,  1,  1   2};

  //  std::cout << "fp index = " << binary_search_fixed_point(fp_search) << std::endl;

  //  vector<int> circular = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
  //  std::cout << "circular index = " << binary_search_circular(478, circular) << std::endl;

  std::cout << "sqrt = " << std::setprecision(20) << square_root_float(13) << std::endl;

  std::vector<string> dictionary = {"Hitler", "did", "nothing", "wrong", "deified", "edified", "test"};
  std::string query = "edified";
  find_palindrome_anagram(query, dictionary);

  std::vector<int> sorted_a = {1, 1, 2, 3, 4, 5, 8,  9, 10, 11, 14, 15, 17, 19, 20};
  std::vector<int> sorted_b = {1, 2, 3, 6, 6, 8, 9, 10, 12, 13, 14, 16, 17, 18, 20};

  //  vector<int> sd = union_intersection_difference(sorted_a, sorted_b);
  std::cout << "sorted_a: ";
  for (auto i : sorted_a) std::cout << i << " ";
  std::cout << std::endl;
  std::cout << "sorted_b: ";
  for (auto i : sorted_b) std::cout << i << " ";
  std::cout << std::endl;
  //  std::cout << "sd: ";
  //  for (auto i : sd) std::cout << i << " ";
  //  std::cout << std::endl;
  //  string example = "qwegwegwe";
  //  count_occurrences(example);

  //  std::vector<int> has_dups = {1, 4, 2, 76, 3, 4, 2, 76, 1, 1, 1, 5, 6, 4, 3, 2, 2, 1, 1 };
  //  eliminate_duplicates(has_dups);
  //  for (auto i : has_dups) std::cout << i << " ";
  //  std::cout << std::endl;

  //  move_tower_hanoi(10);

  std::cout << "(5, 4) = "  << n_choose_k(5, 5) << std::endl;
  std::cout << "(5, 4) = "  << n_choose_k2(5, 5) << std::endl;

  //  vector<int> score_ways = {2, 3, 7};
  //  std::cout << "score combinations: "  << count_combinations(42, score_ways) << std::endl;
  //  std::cout << "score combinations: "  << count_combinations2(42, score_ways) << std::endl;

  std::cout << "num paths: "  << num_paths(5, 3) << std::endl;
  std::cout << "num paths: "  << num_paths2(5, 3) << std::endl;

  std::cout << "Smallest k num of form a + b*sqrt(2): " << std::endl;
  vector<Num> smallest_k = generate_smallest(10);
  vector<Num> smallest_k2 = generate_smallest(10);
  vector<Num> smallest_k3 = generate_smallest(10);
  for (auto e : smallest_k) std::cout << e.value_ << " ";
  std::cout << std::endl;
  for (auto e : smallest_k2) std::cout << e.value_ << " ";
  std::cout << std::endl;
  for (auto e : smallest_k3) std::cout << e.value_ << " ";
  std::cout << std::endl;

  vector<int> e1 {9, 3, 11, 6, 55, 9, 7, 3, 29, 16, 4, 4, 20, 11, 6, 6, 8, 8, 4, 10, 11, 16, 10, 6, 10, 3, 5, 6, 4, 14, 5, 29, 15, 3};
  vector<int> e2 {18, 7, 7, 20, 4, 9, 3, 11, 38, 6, 3, 13, 12, 5, 10, 3, 3};
  vector<int> electoral = e1;
  copy(e2.begin(), e2.end(), back_inserter(electoral));

  std::cout << "tie possible: " << tie_election(electoral) << std::endl;
  std::cout << "tie possible: " << tie_election2(electoral) << std::endl;

  vector<Item<int> > clocks {{65,20}, {35,8}, {245,60}, {195,55}, {65,40}, {150,70}, {275,85}, {155,25}, {120,30}, {320,65}, {75,75}, {40,10}, {200,95}, {100,50}, {220,40}, {99,10}};

  std::cout << "Clock knapsack: " << knapsack(130, clocks) << std::endl;
  std::cout << "Clock knapsack: " << knapsack2(130, clocks) << std::endl;

  string entered = "bed bat hand beyond";
  vector<string> dict = {"bed", "bath", "and", "beyond", "Hitler", "did", "nothing", "wrong", "Hodor"};
  vector<string> words = word_breaking(entered, dict);
  for (auto w : words) { std::cout << w << " "; }
  std::cout << std::endl;

  vector<double> probs(435, 0.5);
  std::cout << "Probability of republican victory: " << house_majority(probs, 435) << std::endl;

  vector<pair<int,int> > events {{1, 5}, {6, 10}, {11, 13}, {14, 15}, {2, 7}, {8, 9}, {12, 15}, {4, 5}, {9, 17}};
  std::cout << "Max num events at one time: " << max_events(events) << std::endl;

  vector<int> to_sort {1, 6, 4, 7, 2, 4, 7, 1, 34, 2, 52, 5, 11, 22, 76, 3};
  copy (to_sort.begin(), to_sort.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  my_insertion_sort(to_sort.begin(), to_sort.end());
  copy (to_sort.begin(), to_sort.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  auto ss1 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto ss2 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto ss3 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto ss4 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto ss5 = std::make_shared<ListNode<int> >(ListNode<int>());
  auto ss6 = std::make_shared<ListNode<int> >(ListNode<int>());
  ss6->data = 3;  ss6->next = nullptr;
  ss5->data = 13; ss5->next = ss6;
  ss4->data = 15; ss4->next = ss5;
  ss3->data = 15; ss3->next = ss4;
  ss2->data = 13; ss2->next = ss3;
  ss1->data = 3;  ss1->next = ss2;

  // selection_sort_list(ss1);
  // std::cout << "Sorted LL: " << std::endl;
  // print_linked_list(ss1);
  // std::cout << std::endl;

  std::vector<int> heights {3, 7, 5, 78, 1, 2, 4, 5, 66, 4, 2, 44, 2, 33, 5, 3};
  copy (heights.begin(), heights.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  vector<int> views = sunset_view(heights);
  copy (views.begin(), views.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // std::cout << "reversing integer: " << reverse_integer(314) << std::endl;
  // std::cout << "reversing integer: " << reverse_integer(-314) << std::endl;
  // std::cout << "reversing integer: " << reverse_integer(2) << std::endl;
  // std::cout << "reversing integer: " << reverse_integer(12345) << std::endl;
  //  std::cout << "palindromic int: " << palindromic_integer(133321) << std::endl;

  double x = 4.0;
  std::cout << "Squaring: " << my_square(x) << std::endl;

  // string test_string_1 = "this is a test string, not unique";
  // string test_string_2 = "uniq str";
  // std::cout << "unique: " << string_chars_unique_4(test_string_1) << std::endl;
  // std::cout << "unique: " << string_chars_unique_4(test_string_2) << std::endl;

  // char tor[] = "this is a motherfucking string";
  // string tor_string(tor);
  // string tor_string2(tor);
  // reverse_string_4(tor_string);
  // std::cout << tor << std::endl;
  // std::cout << tor_string << std::endl;
  // std::cout << "Permutation? " << is_permutation_3(tor_string, tor_string2) << std::endl;

  // char torep[] = "Mr John Smith    ";
  // replace_spaces(&torep[0], 13);
  // std::cout << torep << std::endl;

  // string to_comp = "aaaaaaaabbbccdddeefffgg";
  // std::cout << "Compressed: " << compress_string(to_comp) << std::endl;
  // std::cout << "Compressed: " << compress_string_2(to_comp) << std::endl;

  // print_fraction_binary(0.72);
  // print_fraction_binary(0.5);
  // print_fraction_binary(0.75);
  // print_fraction_binary(0.875);

  // Stack<int> my_stack;
  // std::cout << "Stack empty? " << my_stack.empty() << std::endl;
  // my_stack.push(8);
  // my_stack.push(4);
  // my_stack.push(7);
  // my_stack.push(5);
  // my_stack.push(3);
  // my_stack.push(0);
  // my_stack.push(9);
  // my_stack.push(1);
  // my_stack.push(6);
  // my_stack.push(10);
  // my_stack.push(2);
  // std::cout << "Stack size? " << my_stack.size() << std::endl;
  // my_stack.print();
  // //  sort(my_stack);
  // Stack<int> my_stack2 = sort2(my_stack);
  // //  my_stack.print();
  // my_stack2.print();

  // vector<vector<unsigned int> > maze(10, vector<unsigned int>(10, 0));
  // maze[4][3] = 1;
  // maze[4][2] = 1;
  // maze[4][1] = 1;
  // maze[4][0] = 1;
  // maze[4][4] = 1;
  // maze[4][5] = 1;
  // maze[5][4] = 1;
  // maze[5][5] = 1;
  // maze[5][5] = 1;
  // maze[5][6] = 1;
  // maze[5][7] = 1;
  // maze[5][8] = 1;
  // maze[6][8] = 1;
  // maze[7][8] = 1;
  // maze[6][7] = 1;
  // maze[7][7] = 1;
  // maze[8][2] = 1;
  // maze[7][2] = 1;
  // maze[8][3] = 1;
  // maze[7][3] = 1;
  // print_vv(maze);
  // //  Coordinate<int> s{0, 0}, e{9, 0};
  // //  vector<Coordinate<int> > path = search_maze(maze, s, e);

  // //  for (auto c : path) {
  // //    std::cout << "(" << c.x << "," << c.y << ") -->";
  // //  }
  // //  std::cout << std::endl;

  // Coordinate<unsigned int> reg {5, 5};
  // flip_color_region_dfs(&maze, reg);
  // std::cout << "----------------------------" << std::endl;
  // print_vv(maze);

  // std::cout << "comb 5, 2" << std::endl;
  // vector<vector<int> > combs = combinations(5, 2);
  // for (auto v : combs) { std::cout << "{" << v[0] << " " << v[1] << "} "; }
  // std::cout << std::endl;

  // vector<int> water_vector {1, 2, 1, 3, 4, 4, 5, 6, 2, 1, 3, 1, 3, 2, 1, 2, 4, 1};
  // std::cout << "Water trapped two indices: " << water_p.first << " at indices " << water_p.second.first << ", " << water_p.second.second << std::endl;

  const int fib_n = 10000000;
  auto t0 = high_resolution_clock::now();
  std::cout << "fibonacci: " << fib_2(fib_n);
  auto t1 = high_resolution_clock::now();
  std::cout << "   time:  " << duration_cast<nanoseconds>(t1-t0).count() << " nsec" << std::endl;
  auto t2 = high_resolution_clock::now();
  std::cout << "fibonacci: " << fib_3(fib_n);
  auto t3 = high_resolution_clock::now();
  std::cout << "   time:  " << duration_cast<nanoseconds>(t3-t2).count() << " nsec" << std::endl;
  auto t4 = high_resolution_clock::now();
  std::cout << "fibonacci: " << fib_4(fib_n);
  auto t5 = high_resolution_clock::now();
  std::cout << "   time:  " << duration_cast<nanoseconds>(t5-t4).count() << " nsec" << std::endl;

  constexpr unsigned long long int fact_n = 20;
  auto t6 = high_resolution_clock::now();
  std::cout << "factorial: " << fact_1(fact_n);
  auto t7 = high_resolution_clock::now();
  std::cout << "   time:  " << duration_cast<nanoseconds>(t7-t6).count() << " nsec" << std::endl;
  auto t8 = high_resolution_clock::now();
  std::cout << "factorial: " << fact_2(fact_n);
  auto t9 = high_resolution_clock::now();
  std::cout << "   time:  " << duration_cast<nanoseconds>(t9-t8).count() << " nsec" << std::endl;
  auto t10 = high_resolution_clock::now();
  std::cout << "factorial: " << fact_3(fact_n);
  auto t11 = high_resolution_clock::now();
  std::cout << "   time:  " << duration_cast<nanoseconds>(t11-t10).count() << " nsec" << std::endl;
  auto t12 = high_resolution_clock::now();
  std::cout << "factorial: " << factorial<15>::value;
  auto t13 = high_resolution_clock::now();
  std::cout << "   time:  " << duration_cast<nanoseconds>(t13-t12).count() << " nsec" << std::endl;

  Heap<int> heap(16);
  vector<int> heap_elem_1 {1, 6, 5, 12, 55, 22, 51, 26, 12, 13, 8, 2, 9, 4, 16, 63};
  vector<int> heap_elem_2 {1, 6, 5, 12, 55, 22, 51, 26, 12, 13, 8, 2, 9, 4, 16, 63};
  for (int e : heap_elem_1) { heap.push(e); }
  std::cout << std::endl;
  for (int e : heap_elem_1) { std::cout << e << " "; }
  std::cout << std::endl;
  heap.print();
  std::cout << "Checking heap property... ";
  if (heap.check()) {
    std::cout << "   valid heap!" << std::endl;
  } else {
    std::cout << "   ERROR invalid heap!" << std::endl;
  }
  std::cout << "making another heap!" << std::endl;
  Heap<int> heap2(heap_elem_2);
  //  for (int i = 0; i < 16; ++i) { std::cout << heap2.top() << " "; heap.pop(); }
  //  std::cout << std::endl;
  heap2.print();
  if (heap2.check()) {
    std::cout << "   valid heap!" << std::endl;
  } else {
    std::cout << "   ERROR invalid heap!" << std::endl;
  }
  vector<int> largest_heap = heap2.k_largest(5);
  std::cout << "5 largest in heap: " << std::endl;
  for (int e : largest_heap) { std::cout << e << " "; }
  std::cout << std::endl;

  BST<int> bst;
  vector<int> bst_elem {1, 6, 5, 12, 55, 22, 51, 26, 12, 13, 8, 2, 9, 4, 16, 63};
  for (int e : bst_elem) { bst.insert(e); }
  for (int e : bst_elem) {
    if (bst.find(e)) {
      std::cout << "element " << e << " found in bst." << std::endl;;
    } else {
      std::cout << "didn't find " << e << std::endl;
    }
  }
  bst.erase(22);
  bst.erase(2);
  for (int e : bst_elem) {
    if (bst.find(e)) {
      std::cout << "element " << e << " found in bst." << std::endl;;
    } else {
      std::cout << "didn't find " << e << std::endl;
    }
  }

  std::cout << "checking for valid BST...";
  if (bst.check()) {
    std::cout << "valid bst!" << std::endl;
  } else {
    std::cout << "ERROR INVALID bst!" << std::endl;
  }
  vector<int> items = bst.inorder();
  std::cout << "Inorder traversal:  ";
  for (int e : items) { std::cout << e << " "; }
  std::cout << std::endl;
  vector<int> items2 = bst.preorder1();
  std::cout << "Preorder traversal 1:  ";
  for (int e : items2) { std::cout << e << " "; }
  std::cout << std::endl;
  vector<int> items3 = bst.preorder2();
  std::cout << "Preorder traversal 2:  ";
  for (int e : items3) { std::cout << e << " "; }
  std::cout << std::endl;

  vector<int> items5 = bst.postorder1();
  std::cout << "Postorder traversal 1:  ";
  for (int e : items5) { std::cout << e << " "; }
  std::cout << std::endl;

  vector<int> items6 = bst.postorder2();
  std::cout << "Postorder traversal 2:  ";
  for (int e : items6) { std::cout << e << " "; }
  std::cout << std::endl;

  vector<int> items7 = bst.postorder3();
  std::cout << "Postorder traversal 3:  ";
  for (int e : items7) { std::cout << e << " "; }
  std::cout << std::endl;

  vector<int> items8 = bst.topologicalorder();
  std::cout << "Topological order:  ";
  for (int e : items8) { std::cout << e << " "; }
  std::cout << std::endl;

  bst.print();

  vector<int> items9 = bst.k_largest(3);
  std::cout << "3 largest:  ";
  for (int e : items9) { std::cout << e << " "; }
  std::cout << std::endl;

  vector<int> items10 = bst.k_smallest(3);
  std::cout << "3 smallest:  ";
  for (int e : items10) { std::cout << e << " "; }
  std::cout << std::endl;

  std::cout << "BST height: " << bst.height() << std::endl;
  std::cout << "BST balanced? : " << bst.balanced() << std::endl;
  std::cout << "BST 1-balanced? : " << bst.k_balanced(1) << std::endl;
  std::cout << "BST 2-balanced? : " << bst.k_balanced(2) << std::endl;
  std::cout << "BST 3-balanced? : " << bst.k_balanced(3) << std::endl;
  std::cout << "BST 4-balanced? : " << bst.k_balanced(4) << std::endl;
  std::cout << "BST 5-balanced? : " << bst.k_balanced(5) << std::endl;
  std::cout << "BST 6-balanced? : " << bst.k_balanced(6) << std::endl;
  std::cout << "BST 7-balanced? : " << bst.k_balanced(7) << std::endl;
  std::cout << "BST 8-balanced? : " << bst.k_balanced(8) << std::endl;
  std::cout << "BST 9-balanced? : " << bst.k_balanced(9) << std::endl;
  std::cout << "BST 10-balanced? : " << bst.k_balanced(10) << std::endl;
  std::cout << "BST 11-balanced? : " << bst.k_balanced(11) << std::endl;
  std::cout << "BST 12-balanced? : " << bst.k_balanced(12) << std::endl;
  std::cout << "BST 13-balanced? : " << bst.k_balanced(13) << std::endl;
  std::cout << "BST 14-balanced? : " << bst.k_balanced(14) << std::endl;

  List<int> mylist;
  mylist.push_back(2);
  mylist.push_back(3);
  mylist.push_back(4);
  mylist.push_back(5);
  mylist.push_back(6);
  mylist.push_back(7);

  mylist.push_back(7);
  mylist.push_back(6);
  mylist.push_back(5);
  mylist.push_back(4);
  mylist.push_back(3);
  mylist.push_back(3);
  mylist.push_back(3);
  mylist.push_back(3);
  mylist.push_back(3);
  mylist.push_back(3);
  mylist.push_back(2);
  std::cout << "list size: " << mylist.size() << std::endl;
  mylist.print();
  mylist.unique();
  mylist.print();
  mylist.reverse();
  mylist.print();
  std::cout << "Palindromic? " << mylist.palindromic() << std::endl;


  auto ln0 = make_shared<ListNode<int> >();
  auto ln1 = make_shared<ListNode<int> >();
  auto ln2 = make_shared<ListNode<int> >();
  auto ln3 = make_shared<ListNode<int> >();
  auto ln4 = make_shared<ListNode<int> >();
  auto ln5 = make_shared<ListNode<int> >();
  auto ln6 = make_shared<ListNode<int> >();
  auto ln7 = make_shared<ListNode<int> >();
  auto ln8 = make_shared<ListNode<int> >();
  auto ln9 = make_shared<ListNode<int> >();
  auto ln10 = make_shared<ListNode<int> >();
  auto ln11 = make_shared<ListNode<int> >();
  auto ln12 = make_shared<ListNode<int> >();
  auto ln13 = make_shared<ListNode<int> >();
  auto ln14 = make_shared<ListNode<int> >();
  auto ln15 = make_shared<ListNode<int> >();
  auto ln16 = make_shared<ListNode<int> >();
  auto ln17 = make_shared<ListNode<int> >();
  auto ln18 = make_shared<ListNode<int> >();
  auto ln19 = make_shared<ListNode<int> >();
  auto ln20 = make_shared<ListNode<int> >();

  ln0->data = 0; ln0->next = ln1;
  ln1->data = 1; ln1->next = ln2;
  ln2->data = 2; ln2->next = ln3;
  ln3->data = 3; ln3->next = ln4;
  ln4->data = 4; ln4->next = ln5;
  ln5->data = 5; ln5->next = ln6;
  ln6->data = 6; ln6->next = ln7;
  ln7->data = 7; ln7->next = ln8;
  ln8->data = 8; ln8->next = ln9;
  ln9->data = 9; ln9->next = ln10;
  ln10->data = 10; ln10->next = ln11;
  ln11->data = 11; ln11->next = ln12;
  ln12->data = 12; ln12->next = ln13;
  ln13->data = 13; ln13->next = ln14;
  ln14->data = 14; ln14->next = ln15;
  ln15->data = 15; ln15->next = ln16;
  ln16->data = 16; ln16->next = ln17;
  ln17->data = 17; ln17->next = ln18;
  ln18->data = 18; ln18->next = ln19;
  ln19->data = 19; ln19->next = ln20;
  ln20->data = 20; ln20->next = ln5;

  shared_ptr<ListNode<int> > cstart = mylist.find_cycle(ln0);
  std::cout << "The cycle starts at node: " << cstart->data << std::endl;

  //  StringUtil sutil;
  //  string sut1 = "this is a test string to reverse";
  //  char* sut1c = "this is a test string to reverse";
  //  string sut2 = "anna";
  // string sut3 = "naan";
  // string sutr1 = sut1; sutil.reverse_1(sutr1);
  // string sutr2 = sut1; sutil.reverse_2(sutr2);
  // string sutr3 = sut1; sutil.reverse_3(sutr3);
  //  char* sutr4 = sut1c; sutil.reverse_4(sutr4);
  //  char* sutr5 = sut1c; sutil.reverse_5(sutr5);
  // std::cout << "reverse 1: " << sutr1 << std::endl;
  // std::cout << "reverse 2: " << sutr2 << std::endl;
  // std::cout << "reverse 3: " << sutr3 << std::endl;
  //  std::cout << "reverse 4: " << sutr4 << std::endl;
  //  std::cout << "reverse 5: " << sutr5 << std::endl;

  //  user();
  // std::cout << "is permutation 1: " << sutil.is_permutation_1(t1, t2) << std::endl;
  // std::cout << "is permutation 2: " << sutil.is_permutation_2(t1, t2) << std::endl;
  // std::cout << "is permutation 3: " << sutil.is_permutation_3(t1, t2) << std::endl;

  vector<int> svec1 {1, 3, 4, 5, 5, 5, 6, 7};
  vector<int> svec2 {1, 1, 1, 1, 1, 1, 1, 1, 2, 3};
  //  vector<int> svec2 {1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
  vector<int> sinter = intersection_sorted_arrays(svec1, svec2);
  for (int i : sinter) { std::cout << i << " "; }
  std::cout << std::endl;

  Rand_int rnd {0, 5};
  vector<int> rolls(6, 0);
  for (int i = 0; i < 200; ++i) {
    rolls[rnd()]++;
  }
  for (int i = 0; i < rolls.size(); ++i) {
    cout << "Rolled " << i + 1 << ": ";
    for (int j = 0; j < rolls[i]; ++j) {
      cout << "*";
    }
    cout << endl;
  }

  string uq = "brtwokal";
  cout << "unique chars? " << unique_chars(uq) << endl;

  string name = "Mr John Smith    ";
  const string rep = "%20";
  replace_spaces(name, rep);
  cout << "Formatted name: " << name << endl;

  string name2 = "Mr John Smith    ";
  string rep2 = "%20";
  my_replace_multiple(name2.begin(), std::next(name2.begin(), 13), name2.end(), ' ', rep2.begin(), rep2.end());
  cout << "Formatted name: " << name2 << endl;

  string name3 = "Mr John Smith    ";
  string rep3 = "%20";
  replace_character_string(name3, 13, ' ', rep3);
  cout << "Formatted name: " << name3 << endl;

  // string mystoi = "AB";
  // size_t mybase = 16;
  // cout << "converting string to integer: " << string_to_integer(mystoi, mybase) << endl;

  // List<int> testlist;
  // testlist.push_back(1);
  // testlist.push_back(2);
  // testlist.push_back(3);
  // testlist.push_back(4);
  // testlist.push_back(5);
  // testlist.push_back(5);
  // testlist.push_back(5);
  // testlist.push_back(5);
  // testlist.push_back(6);
  // testlist.print();
  // cout << "size of list: " << testlist.size() << ", " << testlist.size_recursive_1() << ", " << testlist.size_recursive_2() << ", " << testlist.size_iterative() << endl;
  // testlist.remove_duplicates();
  // testlist.print();
  // cout << "median: " << testlist.median() << endl;

  // CircularVector<int> mv(16);
  // Queue<int> myqueue(mv);
  // myqueue.push(1);
  // myqueue.push(2);
  // myqueue.push(3);
  // cout << "front of queue: " << myqueue.front() << endl;
  // //  QueueTwoStacks<int> mq;
  // //  Queue<int,List<int> > mq;
  // Queue<int,CircularVector<int> > mq;
  // mq.push(1);
  // mq.push(2);
  // mq.push(3);
  // cout << "front of queue: " << mq.front() << endl;
  // StackSet<int> stackset;
  // stackset.push(1);
  // stackset.push(2);
  // stackset.push(3);
  // cout << "top of stackset: " << stackset.top() << endl;
  // Stack<int> mystack;
  // mystack.push(1);
  // mystack.push(2);
  // mystack.push(3);
  // cout << "top of stack: " << mystack.top() << endl;
  // MaxStack_2<int> mxs;
  // mxs.push(1);
  // mxs.push(2);
  // mxs.push(3);
  // mxs.pop();
  // cout << "top of stack: " << mxs.top() << endl;
  // cout << "max of stack: " << mxs.max() << endl;

  // MaxQueue<int> mxq;
  // mxq.push(1);
  // mxq.push(3);
  // mxq.push(5);
  // mxq.push(2);
  // mxq.push(2);
  // cout << "max of queue: " << mxq.max() << endl;

  // Stack<int> mixedstack;
  // mixedstack.push(6);
  // mixedstack.push(5);
  // mixedstack.push(7);
  // mixedstack.push(4);
  // mixedstack.push(3);
  // mixedstack.push(0);
  // mixedstack.push(9);
  // mixedstack.push(1);
  // mixedstack.push(2);
  // auto sortedstack = stacksort_iterative(mixedstack);
  // while (!sortedstack.empty()) { cout << sortedstack.top() << " "; sortedstack.pop(); }
  // cout << endl;

  // LRUCache<string,vector<string>,32> cache;
  // cache.insert("testing", vector<string> {"one", "two", "three"});
  // vector<string> cache_val;
  // cout << cache.lookup("testing", &cache_val) << endl;
  // cout << cache_val.front() << endl;
  // cout << cache.lookup("testing1", &cache_val) << endl;

  // vector<int> to_remove {1, 5, 4, 6, 1, 2, 4, 1, 4, 6, 7, 2, 3, 2, 4, 5, 5, 5, 2, 3, 4, 2, 3, 4, 3, 2, 2, 2, 2, 2, 3, 5, 2, 3, 2, 1};
  // vector<int> to_remove2(to_remove);
  // auto it = my_remove(to_remove.begin(), to_remove.end(), 2);
  // auto it2 = std::remove(to_remove2.begin(), to_remove2.end(), 2);
  // for (auto i = to_remove.begin(); i != it; ++i) {
  //   cout << *i << " ";
  // }
  // cout << endl;
  // for (auto i = to_remove2.begin(); i != it2; ++i) {
  //   cout << *i << " ";
  // }
  // cout << endl;

  // int bst_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  // BST<int> my_bst(bst_data, 16);
  // my_bst.print();

  // vector<int> inorder = my_bst.inorder_successor();
  // cout << "inorder with successors" << endl;
  // for (auto e : inorder) {
  //   cout << e << " ";
  // }
  // cout << endl;

  // vector<int> step_ways {1, 2, 3};
  // cout << "ways 1: " << count_permutations_1(13) << endl;
  // cout << "ways 2: " << count_permutations_2(13, step_ways) << endl;
  // cout << "ways 3: " << count_permutations_3(13, step_ways) << endl;
  // cout << "ways 4: " << count_combinations(13, step_ways) << endl;

  // Vertex<char,int> gv1('F');
  // Vertex<char,int> gv2('B');
  // Vertex<char,int> gv3('A');
  // Vertex<char,int> gv4('D');
  // Vertex<char,int> gv5('C');
  // Vertex<char,int> gv6('E');
  // Vertex<char,int> gv7('G');
  // Vertex<char,int> gv8('I');
  // Vertex<char,int> gv9('H');
  // gv1.add_edge(&gv2, 1);
  // gv2.add_edge(&gv3, 1);
  // gv2.add_edge(&gv4, 1);
  // gv4.add_edge(&gv5, 1);
  // gv4.add_edge(&gv6, 1);

  // gv1.add_edge(&gv7, 1);
  // gv7.add_edge(&gv8, 1);
  // gv8.add_edge(&gv9, 1);

  // bool ir = is_reachable_bfs(&gv1, &gv9);
  // cout << "is reachable: " << ir << endl;

  // vector<vector<int> > cv = combinations(4, 2);
  // for (auto v : cv) {
  //   for (auto e : v) {
  //     cout << e << " ";
  //   }
  //   cout << endl;
  // }

  // string ptest = "cat";
  // vector<string> ps = permutations(ptest);
  // for (auto s : ps) {
  //   cout << s << endl;
  // }

  // vector<string> vps = valid_parenthesis(4);
  // for (auto p : vps) {
  //   cout << p << endl;
  // }

  // cout << "number of coin combinations: " << coin_combinations(10) << endl;

  // string pndigits = "231";
  // vector<string> pnl = phonenumber_letters(pndigits);
  // for (auto s : pnl) {
  //   cout << s << endl;
  // }

  // string myfile = "input/file1.txt";
  // string output = tail_2(myfile, 4);
  // cout << output;

  // const string estring = "aaaaabbccccddeefffgghhhhh";
  // cout << run_length_encode(estring) << endl;
  // cout << compress_string(estring) << endl;

  // const string rntest_1 = "LIX";
  // cout << "value of " << rntest_1 << " = " << roman_to_int_2(rntest_1) << endl;
  // const string rntest_2 = "XXXXXIIIIIIIII";
  // cout << "value of " << rntest_2 << " = " << roman_to_int_2(rntest_2) << endl;
  // const string rntest_3 = "LVIIII";
  // cout << "value of " << rntest_3 << " = " << roman_to_int_2(rntest_3) << endl;


  
}

// int string_to_integer(const std::string& s, const int base)
// {
//   bool is_negative = s[0] == '-';
//   int sn = is_negative ? -1 : 1;
//   return sn * Polynomial<std::string::const_iterator, const int, const decimal_digit>(is_negative ? s.begin() + 1 : s.begin(), s.end())(base);
// }

// std::string integer_to_string(int n, const int base)
// {
//   std::string result;
//   bool is_negative = (n < 0);
//   if (is_negative)
//     n = -n;

//   while (n) {
//     int r = n % base;
//     result.push_back( (r >= 10) ? 'A' + (r - 10) : '0' + r );
//     n /= base;
//   }
//   if (result.empty())
//     result.push_back('0');
//   else if (is_negative)
//     result.push_back('-');
//   my_reverse(result.begin(), result.end());
//   return result;
// }



int ssDecodeColID(const std::string& s) {
  return Polynomial<std::string::const_iterator, const int, const letter>(s.begin(), s.end())(26);
}

// std::string convert_base(const std::string& s, const int base1, const int base2)
// {
//   return integer_to_string( string_to_integer(s, base1), base2);
// }

Parity::Parity() {
  unsigned short i = 0;
  do { sixteenBitParityTable[i] = p2(i); i++; } while (i != 65535);
  sixteenBitParityTable[i] = p2(i);

  i = 0;
  do { sixteenBitReverseTable[i] = reverse_short_bits(i); i++; } while (i != 65535);
  sixteenBitReverseTable[i] = reverse_short_bits(i);

  fourBitParityTable = 0x6996;

}

unsigned short
Parity::p1(unsigned long long x) {
  unsigned short res = 0;
  while (x) {
    res ^= (x & 1);
    x >>= 1;
  }
  return res;
}

unsigned short
Parity::p2(unsigned long long x) {
  unsigned short res = 0;
  while (x) {
    res ^= 1;
    x &= (x - 1);
  }
  return res;
}

unsigned short
Parity::p3(unsigned long long x) {
  return
    sixteenBitParityTable[(x >> 48)          ] ^
    sixteenBitParityTable[(x >> 32)  & 0xffff] ^
    sixteenBitParityTable[(x >> 16)  & 0xffff] ^
    sixteenBitParityTable[(x      )  & 0xffff] ;
}

unsigned short
Parity::p4(unsigned long long x) {
  x ^= (x >> 32);
  x ^= (x >> 16);
  x ^= (x >> 8);
  x ^= (x >> 4);
  return (fourBitParityTable >> x) & 1;
}

unsigned short
Parity::reverse_short_bits(unsigned short x) {
  for (int i = 0; i != 8; ++i) {
    int j = 15 - i;
    x = swap_bits( x, i, j );
  }
  return x;
}

unsigned long long
Parity::reverse_bits(unsigned long long x) {
  return
    (unsigned long long) (sixteenBitReverseTable[(x >> 48)          ])        |
    (unsigned long long) (sixteenBitReverseTable[(x >> 32)  & 0xffff]) << 16  |
    (unsigned long long) (sixteenBitReverseTable[(x >> 16)  & 0xffff]) << 32  |
    (unsigned long long) (sixteenBitReverseTable[(x      )  & 0xffff]) << 48  ;
}

long long
Parity::swap_bits(long long x, int i, int j)
{
  if (((x >> i) & 1) != ((x >> j) & 1)) {
    x ^= ((1LL << i) | (1LL << j));
  }
  return x;
}

unsigned long long closest_int_same_bits(unsigned long long x)
{
  for (int i = 0; i != 63; ++i) {
    if (((x >> i) & 1) ^ ((x >> (i+1)) & 1)) {
      x ^= ((1L << i) | (1L << (i+1)));
      return x;
    }
  }
  throw std::invalid_argument("all bits are identical!");
}

unsigned long long next_int_same_bits(unsigned long long n)
{
  int c = n, t0 = 0, t1 = 0;
  while (((c & 1) == 0) && (c != 0)) { t0++; c >>= 1; }  // count trailing zeros
  while ((c & 1) == 1) { t1++; c >>= 1; }                // count ones

  if ((t0 + t1 == 63)) return 0;
  int p = t0 + t1;                                       // position of first non-trailing zero

  n ^= (1 << p);                                         // flip first non-trailing zero
  n &= ~((1 << p) - 1);                                  // clear bits after it
  n |= (1 << (t1 - 1)) - 1;                              // put the rest of the ones as far right as possible

  return n;
}

unsigned long long previous_int_same_bits(unsigned long long n)
{
  int c = n, t0 = 0, t1 = 0;
  if (c == 0) return -1;

  while ((c & 1) == 1) { t1++; c >>= 1; }                // count trailing ones
  while (((c & 1) == 0) && (c != 0)) { t0++; c >>= 1; }  // count zeros

  int p = t1 + t0;                                       // position of first non-trailing one

  n ^= (1 << p);                                         // flip first non-trailing one
  n &= ~((1 << p) - 1);                                  // clear bits after it
  n |= (((1 << (t1 + 1)) - 1) << (t0 - 1));              // put the rest of the ones as far left as possible

  return n;
}

void print_fraction_binary(double x)
{
  string result;
  int size = 0;
  double frac = 0.5;
  result.append("0.");
  while (x != 0 && size != 64) {
    if (x >= frac) {
      result.push_back('1');
      x -= frac;
    } else {
      result.push_back('0');
    }
    frac /= 2;
    size++;
  }
  std::cout << result << std::endl;
}

double pow(double x, int y)
{
  double res = 1.0;
  long long power = y;

  if (y < 0) {
    power = -power;
    x = 1.0 / x;
  }

  while (power) {
    if (power & 1) {
      res *= x;
    }
    x *= x;
    power >> 1;
  }
  return res;
}

void BigInt::increment()
{
  auto it = n_.begin();
  while ((it != n_.end()) && ((*it = *it + 1) == 0)) { it++; }
  if (it == n_.end()) { n_.push_back(1); }
}

const BigInt BigInt::s() const
{
  BigInt result(*this);
  result.increment();
  return result;
}

const BigInt s(const BigInt& b)
{
  return b.s();
}

void BigInt::add(const BigInt& b)
{
  auto i = n_.begin();
  auto j = b.begin();

  decimal_digit c = 0;
  decimal_digit d = 0;
  while (i != n_.end() && j != b.end()) {
    d = *i + *j + c;
    c = carry(*i, *j, c);
    *i = d;
    i++; j++;
  }
  if (i == n_.end()) {
    while (j != b.end()) {
      d = *j + c;
      c = carry(0, *j, c);
      n_.push_back(d);
      j++;
    }
    if (c != 0) n_.push_back(c);
  } else {
    *i = *i + c;
  }

}

const BigInt BigInt::a(const BigInt& b) const
{
  BigInt result(*this);
  result.add(b);
  return result;
}

const decimal_digit carry(const decimal_digit& d1, const decimal_digit& d2, const decimal_digit& c)
{
  return (d1 + d2 + c) / 10;
}

int smallest_missing_positive(std::vector<int>& v)
{
  using std::swap;
  int i = 0;
  while (i < v.size()) {
    if ((0 < v[i] && v[i] <= v.size()) && // v[i] is in the range [1, n]
	v[i] != i + 1 &&                  // v[i] is not locked in its final place
	v[i] != v[v[i]-1])                // not swapping equal elements
      swap(v[i], v[v[i]-1]);
    else {
      i++;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] != i+1)
      return i+1;
  }
  return v.size() + 1;

}

int max_forward_diff(const std::vector<int>& v)
{
  int min = std::numeric_limits<int>::max();
  int max_diff = 0;

  for (auto i : v) {
    max_diff = std::max( max_diff, i - min);
    min = std::min(min, i);
  }
  return max_diff;
}

int max_forward_diff_2(const std::vector<int>& v)
{
  int min = std::numeric_limits<int>::max(), max_diff = 0;

  std::vector<int> max_diffs;
  for (auto i = v.begin(); i != v.end(); i++) {
    max_diff = std::max( max_diff, *i - min);
    min = std::min(min, *i);
    max_diffs.push_back(max_diff);
  }

  int max = 0, min_diff = std::numeric_limits<int>::max();
  int max_sum = 0;

  auto i = v.rbegin();
  auto j = max_diffs.rbegin();
  for ( ; i != v.rend() && j != max_diffs.rend(); i++, j++){
    min_diff = std::min(min_diff, *i - max);
    max = std::max(max, *i);
    max_sum = std::max(max_sum, -min_diff + *j);
  }
  return max_sum;

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

void remove_replace(std::string& s, char remove, char replace, char with)
{
  my_replace(s.begin(), s.end(), replace, with);
  s.erase(my_remove(s.begin(), s.end(), remove), s.end());
}

std::string reverse_sentence(const std::string& s)
{
  std::string result(s);
  my_reverse(result.begin(), result.end());
  auto i = result.begin();
  auto j = result.begin();
  while (i != result.end() && j != result.end()) {
    j = my_find_if(i, result.end(), isspace);
    my_reverse(i, j);
    i = my_find_if_not(j, result.end(), isspace);
  }

  return result;
}

std::vector<std::string> tokenize_sentence(const std::string& s)
{
  std::string t;
  std::vector<std::string> result;
  auto i = s.begin();
  auto j = s.begin();
  while (i != s.end() && j != s.end()) {
    j = my_find_if(i, s.end(), isspace);
    result.push_back(std::string(i, j));
    i = my_find_if_not(j, s.end(), isspace);
  }
  return result;
}

std::string phone_digit_letters(const char c)
{
  switch (c) {
    case '1' :
      return "";
    case '2' :
      return "abc";
    case '3':
      return "def";
    case '4' :
      return "ghi";
    case '5' :
      return "jkl";
    case '6' :
      return "mno";
    case '7' :
      return "pqrs";
    case '8' :
      return "tuv";
    case '9' :
      return "wxyz";
    default :
      return "";
    }
}

void phone_mnemonic_helper(const std::string& number, int d, std::string* ans)
{
  if (d == number.size()) {
    std::cout << *ans << std::endl;
  } else {
    for (auto c : phone_digit_letters(number[d])) {
      (*ans)[d] = c;
      phone_mnemonic_helper(number, d+1, ans);
    }
  }
}

shared_ptr<ListNode<int> > reverse_sublist(const shared_ptr<ListNode<int> >& L, int s, int f)
{
  shared_ptr<ListNode<int> > s_ptr = L, prev_s_ptr = nullptr;
  size_t i = 1;
  while (i < s) {
    prev_s_ptr = s_ptr;
    s_ptr = s_ptr->next;
    i++;
  }

  if (prev_s_ptr)
    prev_s_ptr->next = nullptr;

  shared_ptr<ListNode<int> > curr = s_ptr;
  shared_ptr<ListNode<int> > prev = nullptr;
  shared_ptr<ListNode<int> > f_ptr, next_f_ptr;

  while (i < f) {
    f_ptr = curr->next;
    next_f_ptr = f_ptr->next;
    curr->next = prev;
    prev = curr;
    curr = f_ptr;
    i++;
  }
  f_ptr->next = prev;
  s_ptr->next = next_f_ptr;

  if (prev_s_ptr) {
    prev_s_ptr->next = f_ptr;
    return L;
  } else {
    return f_ptr;
  }

}

// buggy!

// shared_ptr<ListNode<int> > find_cycle(shared_ptr<ListNode<int> > L)
// {
//   shared_ptr<ListNode<int> > slow = L, fast = L;
//   while (slow && slow->next && fast && fast->next && fast->next->next) {
//     // Detect a cycle
//     if (slow == fast) {
//       // There is a cycle
//       // Compute cycle length
//       size_t length = 0;
//       do {fast = fast->next; length++;} while (slow != fast);
//       // Compute beginning of cycle
//       slow = L; fast = L;
//       do {fast = fast->next;} while (--length);
//       do {fast = fast->next; slow = slow->next;} while (slow != fast);
//       return fast;
//     }
//   }
//   // There is no cycle
//   return nullptr;
// }

void selection_sort_list(shared_ptr<ListNode<int> >& L)
{
  if (!(L->next)) return;

  for (auto i = L; i != nullptr; i = i->next) {
    auto min = i;
    for (auto j = i; j != nullptr; j = j->next) {
      min = (j->data < min->data) ? j : min;
    }
    std::swap(i->data, min->data); // switch pointers not data
  }
}

int eval(const std::string& s)
{
  std::stack<int> eval_stack;
  std::stringstream ss(s);

   std::string symbol;
   while (getline(ss, symbol, ',')) {
     if ((symbol == "+") || (symbol == "-") || (symbol == "*") || (symbol == "/")) {
       // Operator
       int y = eval_stack.top();
       eval_stack.pop();
       int x = eval_stack.top();
       eval_stack.pop();
       int result = 0;
       switch (symbol.front()) {
       case '+' :
       	 result = x + y;
       	 break;
       case '-' :
       	 result = x - y;
       	 break;
       case '*' :
       	 result = x * y;
       	 break;
       case '/' :
       	 result = x / y;
       	 break;
       default :
       	 result = 0;
       }
       eval_stack.emplace(result);
     } else {
       // Number
       eval_stack.emplace(std::stoi(symbol));
     }
   }
   return eval_stack.top();
}

bool pbb(const std::string& s)
{
  std::stack<char> stack;

  for (auto c : s) {
    if ((c == '(') || (c == '{') || (c == '[')) {
      stack.emplace(c);
    } else {
      if (stack.empty())
	return false;
      char top = stack.top();
      if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
	return false;
      else
	stack.pop();
    }
  }
  return stack.empty();
}

int match_length(const std::string& s)
{
  std::stack<int> stack;
  size_t max_len = 0, last_end = 0;

  for (size_t i = 0; i != s.size(); ++i) {
    if (s[i] == '(') {
      stack.emplace(i);
    } else {
      if (stack.empty()) {
     	// Matching failed. Move past this prefix.
	last_end = i + 1;
      } else {
	// Natched a paren. Compute distance to next unmatched paren.
	stack.pop();
	size_t start = stack.empty() ? last_end - 1 : stack.top();
	max_len = std::max(max_len, i - start);
      }
    }
  }
  return max_len;
}

void insert(int e, std::stack<int>& s) {
  if (s.empty() || s.top() <= e) {
    s.push(e);
  } else {
    int t = s.top();
    s.pop();
    insert(e, s);
    s.push(t);
  }
}

void sort(std::stack<int>& s)
{
  if (!s.empty()) {
    int e = s.top();
    s.pop();
    sort(s);
    insert(e, s);
  }
}

vector<int> sunset_view(vector<int> heights)
{
  std::stack<int> stack;
  for (int h : heights) {
    while (!stack.empty() && h > stack.top()) {
      stack.pop();
    }
    stack.emplace(h);
  }
  vector<int> result;
  while (!stack.empty()) {
    result.emplace_back(stack.top());
    stack.pop();
  }
  reverse(result.begin(), result.end());
  return result;
}

int height(const unique_ptr<BinaryTreeNode<int> >& T)
{
  if (!T) return -1;

  int lheight = height(T->left);
  if (lheight == -2) return -2;
  int rheight = height(T->right);
  if (rheight == -2) return -2;

  if (std::abs(lheight - rheight) > 1) return -2;

  return (std::max(lheight, rheight) + 1);
}

bool balanced(const unique_ptr<BinaryTreeNode<int> >& T)
{
  return (height(T) != -2);
}

std::pair<BinaryTreeNode<int>*,int> nodes(const unique_ptr<BinaryTreeNode<int> >& T, int k)
{
  if (!T) return {nullptr, 0};

  auto lnodes = nodes(T->left, k);
  if (lnodes.first) return lnodes;
  auto rnodes = nodes(T->right, k);
  if (rnodes.first) return rnodes;

  int num_nodes = lnodes.second + rnodes.second + 1;
  if (std::abs(lnodes.second - rnodes.second) > k) return {T.get(), num_nodes};

  return {nullptr, num_nodes};
}

BinaryTreeNode<int>* find_non_k_balanced_node(const unique_ptr<BinaryTreeNode<int> >& T, int k)
{
  return nodes(T, k).first;
}

int balanced_height(const unique_ptr<BinaryTreeNode<int> >& T)
{
  if (!T) return -1;

  auto lheight = balanced_height(T->left);
  if (lheight == -2) return -2;
  auto rheight = balanced_height(T->right);
  if (rheight == -2) return -2;

  if (std::abs(lheight - rheight) > 1) return -2;

  return std::max(lheight, rheight) + 1;
}

bool is_balanced(const unique_ptr<BinaryTreeNode<int> >& T)
{
  return balanced_height(T) != -2;
}

bool symmetric_match(const unique_ptr<BinaryTreeNode<int> >& L, const unique_ptr<BinaryTreeNode<int> >& R)
{
  if (!L && !R) return true;

  return
    (L && R) &&
    (L->data == R->data) &&
    symmetric_match(L->left, R->right) &&
    symmetric_match(L->right, R->left);
}

bool symmetric(const unique_ptr<BinaryTreeNode<int> >& T)
{
  return symmetric_match(T->left, T->right);
}

BinaryTreeNode<int>*
lca(const unique_ptr<BinaryTreeNode<int> >& T, const unique_ptr<BinaryTreeNode<int> >& A, const unique_ptr<BinaryTreeNode<int> >& B)
{
  if (!T) return nullptr;

  // This is A or B
  if (T == A || T == B) return T.get();

  auto *left = lca(T->left, A, B);
  auto *right = lca(T->right, A, B);

  // A, B in different subtrees; this is the lca
  if (left && right) return T.get();

  // A, B in same subtree; propagate lca result
  return left? left : right;
}

int
depth(const BinaryTreeNode2<int>* T)
{
  int d = 0;
  while (T) { T = T->parent; d++; };
  return d;
}

BinaryTreeNode2<int>*
lca2(const unique_ptr<BinaryTreeNode2<int> >& T, const unique_ptr<BinaryTreeNode2<int> >& A, const unique_ptr<BinaryTreeNode2<int> >& B)
{
  auto *i = A.get(), *j = B.get();
  int depth_i = depth(i);
  int depth_j = depth(j);
  if (depth_j > depth_i) std::swap(i, j);

  int depth_diff = std::abs(depth_i - depth_j);
  while (depth_diff--) { i = i->parent; };

  while (i != j) { i = i->parent; j = j->parent; };

  return i;
}

int inorder_traversal_1(const unique_ptr<BinaryTreeNode<int> >& T, int parent_num)
{
  if (!T) return 0;
  int node_num = parent_num << 1 + T->data;

  // This is a leaf, return the number at the node
  if (!T->left && !T->right) return node_num;

  // This is an interior node, add the left and right sums
  return inorder_traversal_1(T->left, node_num) + inorder_traversal_1(T->right, node_num);
}

int sum_root_to_leaf_paths(const unique_ptr<BinaryTreeNode<int> >& T)
{
  return inorder_traversal_1(T, 0);
}

bool inorder_traversal_2(const unique_ptr<BinaryTreeNode<int> >& T, int parent_num, int target)
{
  if (!T) return false;
  int node_num = parent_num + T->data;

  // This is a leaf, check the number at the node
  if (!T->left && !T->right) return node_num == target;

  // This is an interior node, check the left then right branches
  return inorder_traversal_2(T->left, node_num, target) || inorder_traversal_2(T->right, node_num, target);
}

int find_root_to_leaf_path(const unique_ptr<BinaryTreeNode<int> >& T, int target)
{
  return inorder_traversal_2(T, 0, target);
}

void inorder_traversal(const unique_ptr<BinaryTreeNode2<int> >& T)
{
  if (!T) return;

  BinaryTreeNode2<int> *prev = nullptr, *curr = T.get(), *next;

  while (curr) {
    if (!prev || curr == prev->left.get() || curr == prev->right.get()) {
      // Coming from parent node
      if (curr->left) {
   	next = curr->left.get();
      } else {
   	std::cout << curr->data << std::endl;
   	next = (curr->right ? curr->right.get() : curr->parent);
      }
    } else if (curr->left.get() == prev) {
      // Coming back from left child
      std::cout << curr->data << std::endl;
      next = (curr->right ? curr->right.get() : curr->parent);
    } else {
      // Coming back from right child
      next = curr->parent;
    }
    prev = curr;
    curr = next;
  }
}

// errors! ///

// vector<int> inorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T)
// {
//   stack<BinaryTreeNode<int>* > stack;
//   vector<int> result;
//   auto curr = T.get();
//   while (!stack.empty() && curr) {
//     if (curr) {
//       stack.emplace(curr);
//       curr = curr->left.get();
//     } else {
//       result.emplace_back(curr->data);
//       stack.pop();
//       curr = curr->right.get();
//     }
//   }
//   return result;
// }

vector<int> preorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T)
{
  stack<BinaryTreeNode<int>* > stack;
  vector<int> result;
  stack.emplace(T.get());
  while (!stack.empty()) {
    auto curr = stack.top();
    stack.pop();
    result.emplace_back(curr->data);
    if (curr->right) stack.emplace(curr->right.get());
    if (curr->left) stack.emplace(curr->left.get());
  }
  return result;
}

vector<int> reverse_preorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T)
{
  stack<BinaryTreeNode<int>* > stack;
  vector<int> result;
  stack.emplace(T.get());
  while (!stack.empty()) {
    auto curr = stack.top();
    stack.pop();
    result.emplace_back(curr->data);
    if (curr->left) stack.emplace(curr->left.get());
    if (curr->right) stack.emplace(curr->right.get());
  }
  return result;
}

vector<int> postorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T)
{
  vector<int> result = reverse_preorder_traversal(T);
  reverse(result.begin(), result.end());
  return result;
}

BinaryTreeNode3<int>* inorder_kth_node(const unique_ptr<BinaryTreeNode3<int> >& T, int k)
{
  auto *n = T.get();
  while (n) {
    int left_size = T->left->size;
    if (left_size < k - 1) {
      k -= (left_size + 1);
      n = n->right.get();
    } else if (left_size == k - 1) {
      return n;
    } else {
      n = n->left.get();
    }
  }
  throw std::length_error("no kth node in tree");
}

struct Compare {
  bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
    return lhs.first > rhs.first;
  }
};

vector<int> merge_arrays(const vector<vector<int> >& S)
{
  std::priority_queue<std::pair<int, int>, vector<std::pair<int, int> >, Compare> min_heap;
  vector<int> S_idx(S.size(), 0);

  for (int i = 0; i != S.size(); ++i) {
    if (S[i].size() > 0) {
      min_heap.emplace(S[i][0], i);
      S_idx[i] = 1;
    }
  }

  vector<int> result;
  while (!min_heap.empty()) {
    pair<int, int> p = min_heap.top();
    result.emplace_back(p.first);
    if (S_idx[p.second] < S[p.second].size()) {
      min_heap.emplace(S[p.second][(S_idx[p.second])++], p.second);
    }
    min_heap.pop();
  }
  return result;
}

vector<int> kid_sort(const vector<int>& v)
{
  vector<vector<int> > s;
  bool increasing = true;
  int start_idx = 0;

  for (int i = 0; i != v.size(); ++i) {
    if (increasing && v[i] <= v[i-1] ||
	!increasing && v[i] > v[i-1]) {
      if (increasing) {
	s.emplace_back(v.cbegin()+start_idx, v.cbegin()+i);
      } else {
	s.emplace_back(v.crbegin()+v.size()-i, v.crbegin()+v.size()-start_idx);
      }
      start_idx = i;
      increasing = !increasing;
    }
  }

  if (start_idx < v.size()) {
    if (increasing) {
      s.emplace_back(v.cbegin()+start_idx, v.cend());
    } else {
      s.emplace_back(v.crbegin(), v.crbegin()+v.size()-start_idx);
    }
  }
  return merge_arrays(s);
}

vector<int> kaway_sort(const vector<int>& v, int k)
{
  vector<int> result;
  std::priority_queue<int, vector<int>, std::greater<int> > min_heap;

  for (int i = 0 ; i != v.size(); ++i) {
    if (min_heap.size() == k) {
      min_heap.emplace(v[i]);
      result.emplace_back(min_heap.top());
      min_heap.pop();
    } else {
      min_heap.emplace(v[i]);
    }
  }

  while (!min_heap.empty()) {
    result.emplace_back(min_heap.top());
    min_heap.pop();
  }

  return result;
}

vector<Star> k_closest_stars(int k, std::istringstream *sin)
{
  std::priority_queue<Star, vector<Star> > max_heap;
  std::string line;

  while (getline(*sin, line)) {
    stringstream ss(line);
    string buf;
    getline(ss, buf, ',');
    int id = stoi(buf);
    array<double, 3> data;
    for (int i = 0; i != 3; ++i) {
      getline(ss, buf, ',');
      data[i] = stod(buf);
    }
    Star star{id, data[0], data[1], data[2]};

    if (max_heap.size() == k) {
      Star far_star = max_heap.top();
      if (star < far_star) {
	max_heap.pop();
	max_heap.emplace(star);
      }
    } else {
      max_heap.emplace(star);
    }
  }

  vector<Star> result;
  while (!max_heap.empty()) {
    result.emplace_back(max_heap.top());
    max_heap.pop();
  }

  return result;
}

void online_median(std::istream& in)
{
  // Min heap to store the higher elements
  std::priority_queue<int, vector<int>, greater<int> > H;
  // Max heap to store the lower elements
  std::priority_queue<int, vector<int>, less<int> > L;

  int x;
  while (in >> x) {

    // Push integer into higher or lower heap
    if (!L.empty() && x > L.top()) {
      H.push(x);
    } else {
      L.push(x);
    }

    // Balance heap sizes if necessary
    if (H.size() > L.size() + 1) {
      L.push(H.top());
      H.pop();
    } else if (L.size() > H.size() + 1) {
      H.push(L.top());
      L.pop();
    }

    if (L.size() == H.size()) {
      std::cout << "online median: " << 0.5 * (L.top() + H.top()) << std::endl;
    } else {
      std::cout << "online median: " << (H.size() > L.size() ? H.top() : L.top()) << std::endl;
    }
  }
}

int k_largest(std::priority_queue<int, vector<int>, less<int> >& mh, int k)
{
  int count = 0;
  while (!mh.empty() && count != k) {
    std::cout << "max: " << mh.top() << std::endl;
    mh.pop();
    count++;
  }
  return 0;
}

struct Compare2 {
  bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
    return lhs.second < rhs.second;
  }
};

vector<int> k_largest_in_binary_heap(const vector<int>& A, int k)
{
  std::priority_queue<pair<int,int>, vector<pair<int, int> >, Compare2> max_heap;

  max_heap.push({0, A[0]});
  vector<int> result;
  for (int i = 0; i != k; ++i) {
    int idx = max_heap.top().first;
    result.push_back(max_heap.top().second);
    max_heap.pop();

    int idx_l = 2*idx + 1;
    if (idx_l < A.size()) {
      max_heap.push({idx_l, A[idx_l]});
    }
    int idx_r = 2*idx + 2;
    if (idx_r < A.size()) {
      max_heap.push({idx_r, A[idx_r]});
    }
  }
  return result;
}

// int binary_search(int k, const vector<int>& A)
// {
//   int L = 0, U = A.size()-1;
//   int R = -1;
//   while (L <= U) {
//     int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
//     if (A[M] < k) {
//       L = M + 1;
//     } else if (A[M] == k) {
//       R = M; U = M - 1;
//     } else {
//       U = M - 1;
//     }
//   }
//   return R;
// }

int binary_search_greater(int k, const vector<int>& A)
{
  int L = 0, U = A.size()-1;
  int R = -1;
  while (L <= U) {
    int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
    if (A[M] <= k) {
      L = M + 1;
    } else {
      R = M; U = M - 1;
    }
  }
  return R;
}

int binary_search_fixed_point(const vector<int>& A)
{
  int L = 0, U = A.size() - 1;
  int R = -1;
  while (L <= U) {
    int M = ((L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2);
    if (A[M] - M < 0 )
      L = M + 1;
    else if (A[M] - M == 0) {
      R = M; U = M - 1;
    } else
      U = M - 1;
  }
  return R;
}

// Min value of circular array *assuming no repeats*
// int binary_search_min_circular(const vector<int>& A)
// {
//   int L = 0, U = A.size()-1;
//   while (L < U) {
//     int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
//     if (A[M] > A[U]) {
//       L = M + 1;
//     } else {
//       U = M;
//     }
//   }
//   return L;
// }

// int binary_search_circular(int k, const vector<int>& A)
// {
//   int L = 0, R = A.size() - 1;
//   int M = binary_search_min_circular(A);
//   if (k > A[R])
//     return binary_search(k, vector<int>(A.cbegin(), A.cbegin() + M));
//   else
//     return M + binary_search(k, vector<int>(A.cbegin() + M, A.cend()));
// }

int square_root_int(int x)
{
  if (x <= 1)
    return x;

  int L = 0, U = x;
  while (L + 1 < U) {
    int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
    int square = M * M;
    if (square < x)
      L = M;
    else if (square == x)
      return M;
    else
      U = M - 1;
  }
  if (U * U < x)
    return U;
  else
    return L;
}

int compare(double x, double y)
{
  double diff = (x - y) / y;
  return (diff < -std::numeric_limits<double>::epsilon() ? - 1 : diff > std::numeric_limits<double>::epsilon());
}

double square_root_float(double x)
{
  double L = 0.0, U = 0.0;
  if (x == 1.0) {
    return x;
  } else if (x > 1.0) {
    L = 1.0; U = x;
  } else {
    L = x; U = 1.0;
  }

  while (compare(L, U) == -1) {
    double M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
    std::cout << "current estimate... " << std::setprecision(30) << M << std::endl;
    double square = M * M;
    if (compare(square, x) == 0) {
      return M;
    } else if (compare (square, x) == 1) {
      U = M;
    } else {
      L = M;
    }
  }
  return L;
}


void find_anagrams(const vector<string>& dictionary)
{
  std::unordered_map<string, vector<string> > hash;
  for (const string& s : dictionary) {
    string sorted(s);
    std::sort(sorted.begin(), sorted.end());
    hash[sorted].emplace_back(s);
  }

  for (const pair<string, vector<string> >& p : hash) {
    if (p.second.size() >= 2) {
      for (auto s : p.second) {
  	std::cout << s << " " << std::endl;
      }
      std::cout << std::endl;
    }
  }
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

bool anonymous_letter(const string& L, const string& M)
{
  std::unordered_map<char,int> hash;
  for_each (L.begin(), L.end(), [&hash] (const char& c) {hash[c]++; });

  for (const char& c : M) {
    auto it = hash.find(c);
    if (it != hash.cend()) {
      if (--it->second == 0) {
	hash.erase(it);
	if (hash.empty() == true) {
	  return true;
	}
      }
    }

  }

  return hash.empty();
}

vector<int> intersection_sorted_arrays(vector<int> A, vector<int> B)
{
  int i = 0, j = 0;
  vector<int> result;
  while (i != A.size() && j != B.size()) {
    if (A[i] == B[j] && (i == 0 || A[i] != A[i-1])) {
      result.emplace_back(A[i]);
      i++; j++;
    } else if (A[i] < B[j]) {
      i++;
    } else {
      j++;
    }
  }
  return result;
}

vector<int> intersection_sorted_arrays2(vector<int> A, vector<int> B)
{
  vector<int> result;
  for (int i = 0; i != A.size(); ++i)
    if ((i == 0 || A[i] != A[i-1]) && binary_search(B.cbegin(), B.cend(), A[i]))  {
      result.emplace_back(A[i]);
    }
  return result;
}

vector<int> intersection_unsorted_arrays(vector<int> A, vector<int> B)
{
  std::unordered_map<int,int> hash;
  for_each (A.cbegin(), A.cend(), [&hash] (const int& i) { hash[i]++; });

  vector<int> result;
  for (const int& i : B) {
    auto it = hash.find(i);
    if (it != hash.cend()) {
      result.emplace_back(i);
      hash.erase(it);
    }
  }

  return result;
}

std::tuple<vector<int>,vector<int>,vector<int> > union_intersection_difference(vector<int>& A, vector<int>& B)
{
  std::unordered_map<int,int> u_hash, i_hash;
  for_each (A.cbegin(), A.cend(), [&u_hash] (const int& i) { u_hash[i]++; });
  for_each (B.cbegin(), B.cend(), [&u_hash, &i_hash] (const int& i) { if (u_hash.find(i) != u_hash.cend()) i_hash[i]++; } );
  for_each (B.cbegin(), B.cend(), [&u_hash] (const int& i) { u_hash[i]++; });

  std::unordered_map<int,int> d_hash(u_hash);
  for_each (i_hash.cbegin(), i_hash.cend(), [&i_hash, &d_hash] (std::pair<int,int> p)
	    { auto it = d_hash.find(p.first);
	      if (it != d_hash.cend())
		d_hash.erase(it); }
	    );

  vector<int> u_result, i_result, d_result;
  for_each (u_hash.cbegin(), u_hash.cend(), [&u_result] (std::pair<int,int> p) {u_result.push_back(p.first);} );
  for_each (i_hash.cbegin(), i_hash.cend(), [&i_result] (std::pair<int,int> p) {i_result.push_back(p.first);} );
  for_each (d_hash.cbegin(), d_hash.cend(), [&d_result] (std::pair<int,int> p) {d_result.push_back(p.first);} );

  return std::tuple<vector<int>,vector<int>,vector<int> >(u_result, i_result, d_result);
}

void merge_two_sorted_arrays(int A[], int m, int B[], int n)
{
  int a = m - 1, b = n - 1, tar = m + n - 1;
  while (a >= 0 && b >= 0)
    A[tar--] = A[a] > B[b] ? A[a--] : B[b--];
  while (b >= 0)
    A[tar--] = B[b--];
}

void count_occurrences(string& s)
{
  sort( s.begin(), s.end() );
  int count = 1;
  for (int i = 1; i != s.size(); ++i) {
    if (s[i] == s[i-1]) {
      count++;
    } else {
      std::cout << s[i-1] << ": " << count << std::endl;
      count = 1;
    }
  }
  std::cout << s.back() << ": " << count << std::endl;
}

void eliminate_duplicates(vector<int>& v)
{
  sort( v.begin(), v.end() );
  v.erase( unique(v.begin(), v.end()), v.end() );
}

int max_events(const vector<pair<int,int> >& events)
{
  vector<Event_Point> points;
  for (auto e : events) { points.emplace_back(Event_Point{e.first, true}); points.emplace_back(Event_Point{e.second, false}); }

  sort(points.begin(), points.end());

  int same = 0, max_same = 0;
  for (auto e : points) {
    if (e.is_start) {
      max_same = std::max(max_same, ++same);
    } else {
      --same;
    }
  }
  return max_same;
}

vector<Interval> insert_interval(const vector<Interval>& A, Interval I)
{
  vector<Interval> result;
  int i = 0;
  while (i != A.size() && I.left > A[i].right) {
    result.emplace_back(A[i++]);
  }

  while (i != A.size() && I.right >= A[i].left) {
    I = {std::min(A[i].left, I.left), std::max(A[i].right, I.right)};
    i++;
  }
  result.emplace_back(I);

  result.insert(result.end(), A.begin() + i, A.end());
  return result;
}

vector<Interval2> union_intervals(vector<Interval2> A)
{
  if (A.empty()) return {};

  sort(A.begin(), A.end());
  vector<Interval2> result;
  Interval2 curr = A[0];
  int i = 0;
  while (i != A.size()) {
    if (curr.right.val > A[i].left.val || (curr.right.val == A[i].left.val && (curr.right.closed || A[i].left.closed))) {
      if (curr.right.val < A[i].right.val || (curr.right.val == A[i].right.val && A[i].right.closed)) {
	curr.right = A[i].right;
      } else {
	result.emplace_back(curr);
	curr = A[i];
      }
    }
    i++;
  }
  result.emplace_back(curr);
  return result;
}

bool is_BST_helper(const std::unique_ptr<BSTNode<int> >& T, int lower, int upper)
{
  if (!T) return true;

  if (lower > T->data || T->data > upper)
    return false;
  else
    return is_BST_helper(T->left, lower, T->data) && is_BST_helper(T->right, T->data, upper);
}

bool is_BST(const std::unique_ptr<BSTNode<int> >& T)
{
  return is_BST_helper(T, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

BSTNode<int>* find_equal_k(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  if (!T) return nullptr;

  if (T->data == k) {
    return T.get();
  } else {
    return find_equal_k(T->data > k ? T->left : T->right, k);
  }
}

BSTNode<int>* find_equal_k2(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  BSTNode<int>* curr = T.get();
  while (curr) {
    if (curr->data == k) {
      return curr;
    } else {
      curr = (curr->data > k ? curr->left.get() : curr->right.get());
    }
  }
  return curr;
}

BSTNode<int>* find_first_equal_k(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  if (!T) return nullptr;

  if (T->data == k) {
    auto* N = find_first_equal_k(T->left, k);
    return N ? N : T.get();
  } else {
    return find_first_equal_k(T->data > k ? T->left : T->right, k);
  }
}

BSTNode<int>* find_first_equal_k2(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  BSTNode<int> *first = nullptr, *curr = T.get();
  while (curr) {
    if (curr->data == k) {
      first = curr;
      curr = curr->left.get();
    } else {
      curr = (curr->data > k ? curr->left.get() : curr->right.get());
    }
  }
  return first;
}

BSTNode<int>* find_first_greater_k(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  BSTNode<int> *first = nullptr, *curr = T.get();
  bool found_k;
  while (curr) {
    if (curr->data == k) {
      found_k = true;
      curr = curr->right.get();
    } else if (curr->data > k) {
      first = curr;
      curr = curr->left.get();
    } else {
      curr = curr->right.get();
    }
  }
  return found_k ? first : nullptr;
}

void find_k_largest_in_BST_helper(const std::unique_ptr<BSTNode<int> >& T, int k, vector<int>* k_elements)
{
  if (k_elements->size() < k) {
    find_k_largest_in_BST_helper(T->right, k, k_elements);
    if (k_elements->size() < k) {
      k_elements->emplace_back(T->data);
      find_k_largest_in_BST_helper(T->left, k, k_elements);
    }
  }
}

vector<int> find_k_largest_in_BST(const std::unique_ptr<BSTNode<int> >& T, int k, vector<int>* k_elements)
{
  vector<int> k_largest(k);
  find_k_largest_in_BST_helper(T, k, &k_largest);
  return k_largest;
}

void find_k_smallest_in_BST_helper(const std::unique_ptr<BSTNode<int> >& T, int k, vector<int>* k_elements)
{
  if (k_elements->size() < k) {
    find_k_smallest_in_BST_helper(T->left, k, k_elements);
    if (k_elements->size() < k) {
      k_elements->emplace_back(T->data);
      find_k_smallest_in_BST_helper(T->right, k, k_elements);
    }
  }
}

vector<int> find_k_smallest_in_BST(const std::unique_ptr<BSTNode<int> >& T, int k, vector<int>* k_elements)
{
  vector<int> k_smallest(k);
  find_k_smallest_in_BST_helper(T, k, &k_smallest);
  return k_smallest;
}

BSTNode<int>* find_LCA(const std::unique_ptr<BSTNode<int> >& T,
		       const std::unique_ptr<BSTNode<int> >& S,
		       const std::unique_ptr<BSTNode<int> >& B)
{
  auto* curr = T.get();
  int s = S->data, b = B->data;
  while (curr) {
    if (curr->data > b)
      curr = curr->left.get();
    else if (curr->data < s)
      curr = curr->right.get();
    else
      return curr;
  }
}

void hanoi_transfer(int n, array<std::stack<int>, 3>& pegs, int from, int to, int use)
{
  if (n != 0) {
    hanoi_transfer(n-1, pegs, from, use, to);
    pegs[to].push(pegs[from].top());
    pegs[from].pop();
    std::cout << "Move from peg " << from << " to peg " << to << std::endl;
    hanoi_transfer(n-1, pegs, use, to, from);
  }
}

void move_tower_hanoi(int n)
{
  array<std::stack<int>, 3> pegs;
  for (int i = n; i != 0; --i) { pegs[0].push(i); }
  hanoi_transfer(n, pegs, 0, 1, 2);
}

void permutation_helper(vector<int>* A, size_t i, vector<vector<int> >* result)
{
  if (i == A->size()) {
    result->emplace_back(*A);
    return;
  } else {
    for (size_t j = i; j != A->size(); ++j) {
      swap(A[i], A[j]);
      permutation_helper(A, i+1, result);
      swap(A[i], A[j]);
    }
  }
}

vector<vector<int> > print_permutations(vector<int>& A)
{
  vector<vector<int> > result;
  permutation_helper(&A, 0, &result);
  return result;
}

vector<vector<int> > print_permutations2(vector<int>& A)
{
  vector<vector<int> > result;
  sort(A.begin(), A.end());
  do { result.emplace_back(A); } while (next_permutation(A.begin(), A.end()));
  return result;
}

void generate_powerset_helper(vector<int>& S, int m, vector<int>* subset)
{
  if (!subset->empty()) {
    copy(subset->cbegin(), subset->cend()-1, std::ostream_iterator<int>(std::cout, ","));
    std::cout << subset->back();
  }
  std::cout << std::endl;

  for (int i = m; i != S.size(); ++i) {
    subset->emplace_back(S[i]);
    generate_powerset_helper(S, m + 1, subset);
    subset->pop_back();
  }
}

void generate_powerset(vector<int>& S)
{
  vector<int> subset;
  generate_powerset_helper(S, 0, &subset);
}

vector<std::unique_ptr<BinaryTreeNode<int> > > generate_all_binary_trees_helper(int start, int end)
{
  vector<std::unique_ptr<BinaryTreeNode<int> > > result;
  if (start > end) {
    result.emplace_back(nullptr);
    return result;
  }

  for (int i = start; i <= end; ++i) {
    auto left_result = generate_all_binary_trees_helper(start, i - 1);
    auto right_result = generate_all_binary_trees_helper(i + 1, end);
    for (auto& left : left_result) {
      for (auto& right : right_result) {
	result.emplace_back(new BinaryTreeNode<int>{i, std::move(left), std::move(right)});
      }
    }
  }
  return result;
}

pair<int,int> find_maximum_subarray_sub(const vector<int>& A)
{
  pair<int,int> range(0, 0);
  int min_idx = -1, sum = 0, min_sum = 0, max_sum = 0;

  for (int i = 0; i != A.size(); ++i) {
    sum += A[i];
    if (sum < min_sum) {
      min_sum = sum; min_idx = i;
    }
    if (sum - min_sum > max_sum) {
      max_sum = sum - min_sum; range = {min_idx, i + 1};
    }
  }
  return range;
}

// DP algorithm avoids overflow
//
// 1
// 1  1
// 1  2  1
// 1  3  3  1
// 1  4  6  4  1
// 1  5  10 10 5  1
// 1  6  15 20 15 6  1
//
int n_choose_k(int n, int k)
{
  // Store two rows of Pascal's triangle. Overwrite the oldest at each step using the last.
  array<vector<int>, 2> table = {vector<int>(k + 1), vector<int>(k + 1)};
  table[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int curr_row = i & 1, last_row = (i - 1) & 1;
    table[curr_row][0] = 1;
    for (int j = 1; j <= k; ++j) {
      table[curr_row][j] = table[last_row][j] + table[last_row][j - 1];
    }
  }
  return table[n & 1][k];
}

int n_choose_k2(int n, int k)
{
  vector<Item<int> > num;
  for (int i = 0; i != n; ++i) { num.emplace_back(Item<int>{1, 1}); }

  return general_knapsack<int,Add_Op<int>,Mult_Op<int> > (num, true, k, k);
}

// int count_combinations(int s, vector<int>& score_ways)
// {
//   vector<int> combinations(s + 1, 0);
//   combinations[0] = 1;
//   for (int score : score_ways) {
//     for (int k = score; k <= s; ++k) {
//       combinations[k] += combinations[k - score];
//     }
//   }
//   return combinations[s];
// }

int count_combinations2(int s, vector<int>& score_ways)
{
  vector<Item<int> > scores;
  for (int s : score_ways) { scores.emplace_back(Item<int>{1, s}); }

  return general_knapsack<int,Add_Op<int>,Mult_Op<int> > (scores, false, s, s);
}

int count_combinations3(int s, vector<int>& score_ways)
{
  vector<vector<int> > w (score_ways.size(), vector<int>(s + 1, 0));
  w[0][0] = 1;
  for (int i = 0; i < score_ways.size(); ++i) {
    for (int k = 0; k <= s; ++k) {
      w[i][k] = (k >= score_ways[i] ? w[i][k - score_ways[i]] : 0) + (i >= 1 ? w[i - 1][k] : 0);
    }
  }
  return w[score_ways.size() - 1][s];
}

int maximize_fishing(vector<vector<int> >& A)
{
  for (int i = 0; i != A.size(); ++i) {
    for (int j = 0; j != A[i].size(); ++j) {
      A[i][j] += std::max(i < 1 ? 0 : A[i - 1][j], j < 1 ? 0 : A[i][j - 1]);
    }
  }
}

int num_paths(int m, int n)
{
  if (n < m) std::swap(n, m);
  vector<vector<int> > table(2, vector<int>(m, 1));

  for (int i = 1; i != n; ++i) {
    for (int j = 1; j != m; ++j) {
      table[i&1][j] = table[i&1][j-1] + table[(i-1)&1][j];
    }
  }

  return table[(n-1)&1][m-1];
}

int num_paths2(int m, int n)
{
  return n_choose_k2(n + m - 2, std::min(m - 1, n - 1));
}

int num_paths_with_obstacles(int m, int n, const vector<deque<bool> >& B)
{
  if (B[0][0]) return 0;

  vector<vector<int> > table(n, vector<int>(m, 0));
  table[0][0] = 1;

  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != m; ++j) {
      table[i][j] = B[i][j] ? 0 : (i<1 ? 0 : table[i-1][j]) + (j<1 ? 0 : table[i][j-1]);
    }
  }

  return table.back().back();
}

int knapsack(int w, const vector<Item<int> >& items)
{
  vector<int> V(w + 1, 0);
  for (int i = 0; i != items.size(); ++i) {
    for (int k = w; k >= items[i].weight; --k) {
      V[k] = std::max(V[k], V[k - items[i].weight] + items[i].value);
    }
  }
  return V[w];
}

int knapsack2(int w, const vector<Item<int> >& items)
{
  return general_knapsack<int,Max_Op<int>,Add_Op<int> > (items, true, w, w);
}

vector<Num> generate_smallest(int k)
{
  vector<Num> result;
  set<Num> T;
  T.insert({0, 0});

  while (result.size() != k) {
    auto it = T.cbegin();
    result.emplace_back(*it);
    T.insert({it->a_+1, it->b_});
    T.insert({it->a_, it->b_+1});
    T.erase(it);
  }

  return result;
}

vector<Num> generate_smallest2(int k)
{
  vector<Num> result;
  std::priority_queue<Num> T;
  T.emplace(Num(0, 0));

  while (result.size() != k) {
    Num t = T.top();
    T.pop();
    result.emplace_back(t);
    T.emplace(Num(t.a_+1, t.b_));
    T.emplace(Num(t.a_, t.b_+1));
    T.pop();
  }

  return result;
}

vector<Num> generate_smallest3(int k)
{
  int i = 0, j = 0;
  vector<Num> result;
  result.emplace_back(Num(0, 0));
  for (int n = 0; n < k; ++n) {
    Num x(result[i].a_ + 1, result[i].b_);
    Num y(result[j].a_, result[j].b_ + sqrt(2));
    if (x < y) {
      i++;
      result.emplace_back(x);
    } else if (y < x) {
      j++;
      result.emplace_back(y);
    } else {
      i++, j++;
      result.emplace_back(x);
    }
  }
}

long long tie_election(const vector<int>& V)
{
  long long total_votes = accumulate(V.begin(), V.end(), 0);

  if (total_votes & 1) {
    return 0;
  }

  vector<vector<long long> > T(V.size() + 1, vector<long long>(total_votes + 1, 0));
  T[0][0] = 1;
  for (int i = 0; i < V.size(); ++i) {
    for (int j = 0; j <= total_votes; ++j) {
      T[i+1][j] = T[i][j] + (j >= V[i] ? T[i][j - V[i]] : 0);
    }
  }
  return T[V.size()][total_votes >> 1];
}

long long tie_election2(const vector<int>& V)
{
  typedef long long T;

  T total_votes = accumulate(V.begin(), V.end(), 0);
  if (total_votes & 1) return 0;

  vector<Item<T> > states;
  for (int votes : V) {states.emplace_back(Item<T>{1, votes});}

  return general_knapsack<T,Add_Op<T>,Mult_Op<T> > (states, true, total_votes, total_votes >> 1);
}

vector<string> word_breaking(const string& str, const vector<string>& dictionary)
{
  string s(str);
  s.erase(remove_if(s.begin(), s.end(), isspace), s.end());
  unordered_set<string> dict;
  for (const string& s : dictionary) { dict.insert(s); }

  vector<int> table(s.size(), 0);

  for (int i = 0; i != s.size(); ++i) {
    if (dict.find(s.substr(0, i + 1)) != dict.cend()) {
      table[i] = i + 1;
    }

    for (int j = 0; j != i && table[i] == 0; ++j) {
      if (table[j] != 0 && dict.find(s.substr(j + 1, i - j)) != dict.cend()) {
	table[i] = i - j;
      }
    }
  }

  vector<string> result;
  if (table.back()) {
    int idx = s.size()-1;
    while (idx >= 0) {
      result.emplace_back(s.substr(idx - table[idx] + 1, table[idx]));
      idx -= table[idx];
    }
    reverse(result.begin(), result.end());
  }

  return result;
}

double house_majority_helper(const vector<double>& prob, int r, int n, vector<vector<double> >& P)
{
  if (r > n) {
    return 0.0;
  } else if (r == 0 && n == 0) {
    return 1.0;
  } else if (r < 0) {
    return 0.0;
  }
  if (P[r][n] == -1.0) {
    P[r][n] =
      house_majority_helper(prob, r - 1, n - 1, P) * prob[n - 1] +
      house_majority_helper(prob, r, n - 1, P) * (1 - prob[n - 1]);
  }
  return P[r][n];
}

double house_majority(const vector<double>& prob, int n)
{

  vector<vector<double> > P(n + 1, vector<double>(n + 1, -1.0));

  double prob_sum = 0.0;
  for (int r = ceil(0.5 * n); r <= n; ++r) {
    prob_sum += house_majority_helper(prob, r, n, P);
  }
  return prob_sum;
}



bool is_feasible(const Coordinate<int>& coord, const vector<vector<int> >& maze)
{
  return
    (coord.x >= 0 && coord.y >= 0) &&
    (coord.x < maze.size() && coord.y < maze[coord.x].size()) &&
    (maze[coord.x][coord.y] == 0);
}

bool search_maze_helper (const Coordinate<int>& curr, const Coordinate<int>& e, vector<vector<int> >* maze, vector<Coordinate<int> >* path)
{
  if (curr == e) return true;

  // Array needs double init braces because need to init inner actual T[N] array object. Is this only true for array<array<T>> ?
  const array<array<int, 2>, 4> shift {{{{1, 0}}, {{0, 1}}, {{-1, 0}}, {{0, -1}}}};

  for (auto& s : shift) {
    const Coordinate<int> next {curr.x + s[0], curr.y + s[1]};
    if (is_feasible(next, *maze)) {
      (*maze)[next.x][next.y] = 1;
      path->emplace_back(next);
      if (search_maze_helper(next, e, maze, path)) {
	return true;
      }
      path->pop_back();
    }
  }
  return false;
}

vector<Coordinate<int> > search_maze(vector<vector<int> >& maze, const Coordinate<int>& s, const Coordinate<int>& e)
{
  vector<Coordinate<int> > path;
  maze[s.x][s.y] = 1;
  path.emplace_back(s);

  if (!search_maze_helper(s, e, &maze, &path)) {
    path.pop_back();
  }
  return path;
}

void flip_color_region(vector<vector<unsigned int> >* colors, const Coordinate<unsigned int>& co)
{
  queue<Coordinate<unsigned int> > coords;
  auto color = (*colors)[co.x][co.y];
  auto new_color = !color;
  coords.emplace(co);
  while (!coords.empty()) {
    auto curr = coords.front();
    coords.pop();
    (*colors)[curr.x][curr.y] = new_color;
    const array<array<int, 2>, 4> shift {{{{0, 1}}, {{1, 0}}, {{0, -1}}, {{-1, 0}}}};
    for (auto s : shift) {
      const Coordinate<unsigned int> next {curr.x + s[0], curr.y + s[1]};
      if ((next.x >= 0 && next.x <= colors->size()) &&
	  (next.y >= 0 && next.y <= (*colors)[next.x].size()) &&
	  ((*colors)[next.x][next.y] == color)) {
	coords.emplace(next);
      }
    }
  }
}

void print_vv(const vector<vector<unsigned int> >& v)
{
  for (int i = 0; i != v.size(); ++i) {
    for (int j = 0; j!= v[i].size(); ++j) {
      std::cout << v[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void flip_color_region_dfs(vector<vector<unsigned int> >* colors, const Coordinate<unsigned int>& co)
{
  auto color = (*colors)[co.x][co.y];
  auto new_color = !color;
  (*colors)[co.x][co.y] = new_color;

  const array<array<int, 2>, 4> shift {{{{1, 0}}, {{0, 1}}, {{-1, 0}}, {{0, -1}}}};

  for (auto& s: shift) {
    const Coordinate<unsigned int> next {co.x + s[0], co.y + s[1]};
    if ((next.x >= 0 && next.x <= colors->size()) &&
	(next.y >= 0 && next.y <= (*colors)[next.x].size()) &&
	(*colors)[next.x][next.y] == color)
      flip_color_region_dfs(colors, next);
  }
}

void mark_region_if_surrounded(int i, int j, vector<vector<char> >* board, vector<deque<bool> >* visited) {
  array<array<int, 2>, 4> dir {{{{0, 1}}, {{-1, 0}}, {{0, -1}}, {{1, 0}}}};

  vector<pair<int,int> > q;
  (*visited)[i][j] = true;
  q.emplace_back(i, j);
  bool is_surrounded = true;
  size_t idx = 0;
  // Build up a queue of coordinates in breadth-first manner. If we ever hit the edge, the original coordinate was not surrounded
  // Never pop anything from the queue. Save the aggregate BFS queue to turn the nodes black later if needed
  while (idx < q.size()) {
    const auto curr = q[idx++];
    if (curr.first == 0 || curr.first == board->size()-1 || curr.second == 0 || curr.second == board->size()-1) {
      is_surrounded = false;
    } else {
      for (auto& d : dir) {
  	const pair<int,int> next {curr.first + d[0], curr.second + d[1]};
  	if (((*board)[next.first][next.second] == 'W') && !(*visited)[next.first][next.second]) {
  	  (*visited)[next.first][next.second] == true;
  	  q.emplace_back(next.first, next.second);
  	}
      }
    }
  }

  if (is_surrounded) {
    for (auto& p : q) {
      (*board)[p.first][p.second] = 'B';
    }
  }

}

void fill_surrounded_regions(vector<vector<char> >* board)
{
  vector<deque<bool> > visited (board->size(), deque<bool>(board->front().size(), false));

  for (int i = 1; i != board->size() - 1; ++i) {
    for (int j = 1; j != board->front().size() - 1; ++j) {
      if ((*board)[i][j] == 'W' && !visited[i][j]) {
	mark_region_if_surrounded(i, j, board, &visited);
      }
    }
  }
}

GraphVertex<int>* copy_graph(GraphVertex<int>* G)
{
  if (!G) return nullptr;

  unordered_map<GraphVertex<int>*,GraphVertex<int>*> vertex_map;
  queue<GraphVertex<int>*> q;
  vertex_map.emplace(G, new GraphVertex<int>{G->label});
  q.emplace(G);
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    for (auto e : v->edges) {
      if (vertex_map.find(e) == vertex_map.cend()) {
	vertex_map.emplace(e, new GraphVertex<int>{e->label});
	q.emplace(e);
      }
      vertex_map[v]->edges.emplace_back(vertex_map[e]);
    }
  }
  return vertex_map[G];
}

shared_ptr<SGraphVertex<int> > copy_graph(const shared_ptr<SGraphVertex<int> >& G)
{
  if (!G) return nullptr;

  unordered_map<shared_ptr<SGraphVertex<int> >,shared_ptr<SGraphVertex<int> > > vertex_map;
  queue<shared_ptr<SGraphVertex<int> > > q;
  vertex_map.emplace(G, std::make_shared<SGraphVertex<int> >(SGraphVertex<int>{G->label}));
  q.emplace(G);
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    for (auto e : v->edges) {
      if (vertex_map.find(e) == vertex_map.cend()) {
  	vertex_map.emplace(e, std::make_shared<SGraphVertex<int> >(SGraphVertex<int>{e->label}));
  	q.emplace(e);
      }
      vertex_map[v]->edges.emplace_back(vertex_map[e]);
    }
  }
  return vertex_map[G];
}

bool assignment_BFS(GraphVertex2<int>* s)
{
  queue<GraphVertex2<int>* > q;
  q.emplace(s);
  for (auto& t : q.front()->edges) {
    if (t->d == -1) {
      t->d = q.front()->d + 1;
      q.emplace(t);
    } else if (t->d == q.front()->d) {
      return false;
    }
    q.pop();
  }
  return true;
}

bool is_any_placement_feasible(vector<GraphVertex2<int> >* G)
{
  for (GraphVertex2<int>& v : *G) {
    if (v.d == -1) {
      if (!assignment_BFS(&v)) {
	return false;
      }
    }
  }
  return true;
}

int merge_count(vector<int>& A, int start, int mid, int end)
{
  int i = start, j = mid, result = 0;
  vector<int> sorted_A;
  while (i != mid && j != end) {
    if (A[i] < A[j]) {
      sorted_A.emplace_back(A[i++]);
    } else {
      result += (mid - i);
      sorted_A.emplace_back(A[j++]);
    }
  }
  copy(A.begin() + i, A.begin() + mid, back_inserter(sorted_A));
  copy(A.begin() + j, A.begin() + end, back_inserter(sorted_A));
  copy(sorted_A.begin(), sorted_A.end(), A.begin() + start);
  return result;
}

int inverted_pairs(vector<int>& A, int start, int end)
{
  if (end - start <= 1) { return 0; }
  int mid = start + (end - start) / 2;
  return inverted_pairs(A, start, mid) + inverted_pairs(A, mid, end) + merge_count(A, start, mid, end);
}

pair<double,double> compute_height_diameter(const unique_ptr<TreeVertex<int> >& T)
{
  if (!T) return {0.0, 0.0};
  array<double, 2> h {{0.0, 0.0}};
  double diameter = 0.0;

  for (auto& e : T->edges) {
    auto h_d = compute_height_diameter(e.first);
    if (h_d.first + e.second > h[0]) {
      h[1] = h[0];
      h[0] = h_d.first + e.second;
    } else if (h_d.first + e.second > h[1]) {
      h[1] = h_d.first + e.second;
    }
    diameter = max(diameter, h_d.second);
  }
  return {h[0], max(diameter, h[0] + h[1])};
}

double diameter(const unique_ptr<TreeVertex<int> >& T)
{
  return T? compute_height_diameter(T).second : 0.0;
}

void combination_helper(int n, int k, int start, vector<vector<int> >* res, vector<int>* ans)
{
  if (ans->size() == k) {
    res->emplace_back(*ans);
    return;
  }

  if (k - ans->size() <= (n - 1) - start) {
    combination_helper(n, k, start + 1, res, ans);
  }
  ans->emplace_back(start + 1);
  combination_helper(n, k, start + 1, res, ans);
  ans->pop_back();
}

vector<vector<int> > combinations(int n, int k)
{
  vector<vector<int> > result;
  vector<int> ans;
  combination_helper(n, k, 0, &result, &ans);
  return result;
}

bool dfs_2_exist(ColoredVertex* curr, const ColoredVertex* pre)
{
  if (curr->color == ColoredVertex::gray) {
    return true;
  }

  curr->color = ColoredVertex::gray;

  for (auto e : curr->edges) {
    if (e != pre && e->color != ColoredVertex::black) {
      if (dfs_2_exist(e, curr)) {
	return true;
      }
    }
  }
  curr->color = ColoredVertex::black;
  return false;
}

bool is_2_exist(vector<ColoredVertex>* G)
{
  if (!G->empty()) {
    return dfs_2_exist(&G->front(), nullptr);
  }
  return false;
}

bool dfs_2_all(DLVertex* curr, DLVertex* pre, int time)
{
  curr->d = time++;
  curr->l = std::numeric_limits<int>::max();

  for (auto next : curr->edges) {
    if (next != pre) {
      if (next->d != 0) {
	// back edge
	curr->l = min(curr->l, next->d);
      } else {
	// forward edge
	if (!dfs_2_all(next, curr, time)) {
	  return false;
	}
	curr->l = min(curr->l, next->l);
      }
    }
  }
  return (pre == nullptr || curr->l < curr->d);
}

bool is_2_all(vector<DLVertex>* G)
{
  if (!G->empty()) {
    return dfs_2_all(&G->front(), nullptr, 0);
  }
  return false;
}

// Not solved
int water_tapped_2(const vector<int>& A)
{
  int h_max = distance(A.begin(), max_element(A.begin(), A.end()));

  int sum = 0, rmax = 0;
  for (int i = 0; i < h_max; ++i) {
    rmax = max(rmax, A[i]);
    sum += rmax - A[i];
  }

  // How to get the other half???
  return 0;
}

// Not working yet
bool two_sum_abs(const vector<int>& A, int k)
{
  int i = 0, j = A.size() - 1;
  if (A[i] + A[j] == k) {
    return true;
  } else if (A[i] + A[j] < k) {
    if ((A[i] < 0) && (A[j] < 0)) {
      i++;
    } else if (A[i] > 0 && A[j] > 0) {
      i++;
    } else if (A[i] < 0) {
      i++;
    } else {

    }
    return false;
  }
}

int fib_1(int n)
{
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return fib_1(n - 1) + fib_1(n - 2);
  }
}

int fib_2(int n)
{
  vector<int> fibs;
  try {
    fibs.reserve(n+1);
  } catch (std::bad_alloc) {
    std::cout << "fib_2: out of memory! exiting." << std::endl;
    return 0;
  }
  fibs[0] = 1; fibs[1] = 1;
  for (int i = 2; i <= n; i++) {
    fibs[i] = (fibs[i-1] + fibs[i-2]);
  }
  return fibs[n];
}

int fib_3(int n)
{
  array<int,2> x {{1, 1}};
  for (int i = 2; i <= n; ++i) {
    int temp = x[1];
    x[1] += x[0];
    x[0] = temp;
  }
  return x[1];
}

pair<int,int> fib_4_helper(int n)
{
  if (n == 0) {
    return {0, 1};
  } else {
    pair<int,int> x = fib_4_helper(n / 2);
    pair<int,int> y = {x.first * (2 * x.second - x.first), x.first * x.first + x.second * x.second};
    if (n & 1) {
      return {y.second, y.first + y.second};
    } else {
      return y;
    }
  }
}

int fib_4(int n)
{
  return fib_4_helper(n).second;
}

unsigned int fact_1(unsigned int n)
{
  return n == 0 ? 1 : n * fact_1(n - 1);
}

unsigned int fact_2_helper(unsigned int n, unsigned int acc)
{
  if (n == 0) {
    return acc;
  } else {
    return fact_2_helper(n - 1, n * acc);
  }
}

unsigned int fact_2(unsigned int n)
{
  return fact_2_helper(n, 1);
}

unsigned int fact_3(unsigned int n)
{
  unsigned int acc = 1;
  for (unsigned int i = 1; i <= n; ++i) {
    acc *= i;
  }
  return acc;
}
