/**
 * @file anagrams.cpp
 * @author <Enter Name>
 * @brief Code to find anagrams against a given dictionary
 * @date 2020-11-22
 */


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

/**
 * @brief Class to read file and store data against certain set of sorted keys to find anagrams
 */
class anagrams
{
private:
  std::string fname;
  std::map<std::string, std::vector<std::string>> table;
public:
  anagrams();
  anagrams(std::string);
  void interFace() const;
};

/**
 * @brief Construct a new anagrams::anagrams object with default constructor
 * 
 */
anagrams::anagrams() : fname(""), table() {}

/**
 * @brief Construct a new anagrams::anagrams object with file name provided
 * 
 * @param fn is the name of file provided by the user as an overload constructor
 */
anagrams::anagrams(std::string fn) : fname(fn), table()
{
  std::ifstream file;
  file.open(fn);
  if(file.bad())
  {
    std::cout << "File is bad\n";
    return;
  }
  else
  {
    std::string line;
    while(std::getline(file, line))
    {
      std::string temp = line;
      std::sort(temp.begin(), temp.end());
      if(table.count(temp) > 0)
        table.at(temp).push_back(line);
      else
      {
        table[temp].push_back(line);
      }
    }
  }
}

/**
 * @brief User interface to play with  the program
 * 
 */
void anagrams::interFace() const
{
  std::string input;
  while(true)
  {
    std::cout << "Enter a word (press enter to exit)> ";
    std::getline(std::cin, input);
    if(input.empty())
    {
      std::cout << "Good bye!\n";
      return;
    }
    std::sort(input.begin(), input.end());
    if(table.count(input) > 0)
    {
      std::cout << "Anagrams of " << input << ":";
      std::vector<std::string> anagramsVec = table.at(input);
      for(size_t itr = 0; itr<anagramsVec.size(); itr++)
      {
        std::cout << " " << anagramsVec[itr];
      }
      std::cout << std::endl;
    }
    else
    {
      std::cout << " No anagrams in the dictionary\n";
    }
  }
  return;
}

int main()
{
  anagrams test("alphabet.txt");
  test.interFace();
}