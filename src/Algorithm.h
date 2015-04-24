namespace Algorithm {

template <class InputIt, class T>
InputIt my_find(InputIt first, InputIt last, const T& value)
{
  for ( ; first != last; ++first) {
    if (*first == value) {
      return first;
    }
  }
  return last;
}

template <class InputIt, class UnaryPredicate>
InputIt my_find_if(InputIt first, InputIt last, UnaryPredicate p)
{
  for ( ; first != last; ++first) {
    if (p(*first)) {
      return first;
    }
  }
  return last;
}

template <class InputIt, class UnaryPredicate>
InputIt my_find_if_not(InputIt first, InputIt last, UnaryPredicate p)
{
  for ( ; first != last; ++first) {
    if (!p(*first)) {
      return first;
    }
  }
  return last;
}

template <class InputIt, class UnaryFunction>
UnaryFunction my_for_each(InputIt first, InputIt last, UnaryFunction f)
{
  for ( ; first != last; ++first) {
    f(*first);
  }
  return std::move(f);
}

template <class ForwardIt, class T>
ForwardIt my_remove(ForwardIt first, ForwardIt last, const T& value)
{
  first = std::find(first, last, value);
  if (first == last) return last;

  ForwardIt result = first;
  while (++first != last) {
    if (!(*first == value)) {
      *result++ = std::move(*first);
    }
  }

  return result;
}

template <class ForwardIt, class UnaryPredicate>
ForwardIt my_remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
  first = std::find_if(first, last, p);
  if (first == last) return last;

  ForwardIt result = first;
  while (++first != last) {
    if (!p(*first)) {
      *result++ = std::move(*first);
    }
  }
  
  return result;
}

template <class ForwardIt, class T>
void my_replace(ForwardIt first, ForwardIt last, const T& old_value, const T& new_value)
{
  for ( ; first != last; ++first) {
    if (*first == old_value) {
      *first = new_value;
    }
  }
}

template <class ForwardIt, class UnaryPredicate, class T>
void my_replace(ForwardIt first, ForwardIt last, UnaryPredicate p, const T& new_value)
{
  for ( ; first != last; ++first) {
    if (p(*first)) {
      *first = new_value;
    }
  }
}

template <class BiDirIt>
void my_reverse(BiDirIt first, BiDirIt last)
{
  last--;
  while (first < last) {
    std::iter_swap(first++, last--);
  }
}

template <class InputIt, class OutputIt, class UnaryFunction>
OutputIt my_transform(InputIt first, InputIt last, OutputIt d_first, UnaryFunction f)
{
  while (first != last) {
    *d_first++ = f(*first++);
  }
  return d_first;
}

template <class ForwardIt, class OutputIt>
ForwardIt my_unique(ForwardIt first, ForwardIt last)
{
  if (first == last) return last;

  ForwardIt result = first;
  while (++first != last) {
    if (!(*first == *result)) {
      *(++result) = std::move(*first);
    }
  }
  return ++result;
}

template <class ForwardIt, class OutputIt, class BinaryPredicate>
ForwardIt my_unique(ForwardIt first, ForwardIt last, BinaryPredicate p)
{
  if (first == last) return last;

  ForwardIt result = first;
  while (++first != last) {
    if (!p(*first, *result)) {
      *(++result) = std::move(*first);
    }
  }
  return ++result;
}

template <class ForwardIt, class OutputIt>
ForwardIt my_unique_copy(ForwardIt first, ForwardIt last, OutputIt result)
{
  if (first == last) return result;

  *result = *first;
  while (++first != last) {
    if (!(*first == *result)) {
      *(++result) = *first;
    }
  }
  return ++result;
}

template <class ForwardIt, class OutputIt, class BinaryPredicate>
ForwardIt my_unique_copy(ForwardIt first, ForwardIt last, OutputIt result, BinaryPredicate p)
{
  if (first == last) return result;

  *result = *first;
  while (++first != last) {
    if (!(*first,  *result)) {
      *(++result) = *first;
    }
  }
  return ++result;
}

}
