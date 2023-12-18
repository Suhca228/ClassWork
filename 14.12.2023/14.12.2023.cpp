#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_words(const string& text) {
  auto is_separator = [](char c) {
    return c == ' ' || c == '\n' || c == '\t';
  };

  vector<string> words;
  int i = 0;
  for (char c : text) {
    if (!is_separator(c)) {
      string word;
      while (!is_separator(c)) {
        word += c;
        c = text[++i];
      }
      words.push_back(word);
    }
  }

  return words;
}

int count_words(const vector<string>& words) {
  int count = 0;
  for (const string& word : words) {
    if (!word.empty()) {
      count++;
    }
  }

  return count;
}

string find_longest_word(const vector<string>& words) {
  string longest_word = "";
  for (const string& word : words) {
    if (word.length() > longest_word.length()) {
      longest_word = word;
    }
  }

  return longest_word;
}

int main() {
  string text;
  cout << "Введіть текст: ";
  getline(cin, text);

  vector<string> words = split_words(text);

  int word_count = count_words(words);

  string longest_word = find_longest_word(words);

  cout << "Кількість слів: " << word_count << endl;
  cout << "Найдовше слово: " << longest_word << endl;

}
