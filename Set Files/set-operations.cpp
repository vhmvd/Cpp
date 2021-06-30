/**
 * @file set-operations.cpp
 * @author NAME (EMAIL)
 * @brief 
 * @version 0.1
 * @date 2021-05-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <fstream>
using namespace std;

// Function prototypes
bool IsSet(string);
bool IsSubset(string, string);
bool Union(string, string, string);
bool Intersection(string, string, string);

/**
 * @brief Main function to make the function call and provide the filenames
 *        to function calls for set operations.
 * 
 * @return int 
 */
int main()
{
  int choice;
  string fname1, fname2, fname3;
  while (true)
  {
    cout << "\n1. Union\n2. Intersection\n0. EXIT\nINPUT: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter filename1 (Universal Set): ";
      cin >> fname1;
      cout << "Enter filename2: ";
      cin >> fname2;
      cout << "Enter filename3: ";
      cin >> fname3;
      Union(fname1, fname2, fname3);
      cout << "Union.out created successfully!\n";
      break;
    case 2:
      cout << "Enter filename1 (Universal Set): ";
      cin >> fname1;
      cout << "Enter filename2: ";
      cin >> fname2;
      cout << "Enter filename3: ";
      cin >> fname3;
      Intersection(fname1, fname2, fname3);
      cout << "Intersection.out created successfully!\n";
      break;
    case 0:
      return 0;
      break;
    default:
      cout << "Invalid choice!\n";
      break;
    }
  }
  return 0;
}

/**
 * @brief Checks if filename is a subset of S. Returns true if its a subset
 *        and returns false otherwise.
 * 
 * @param filename 
 * @return true
 * @return false 
 */
bool IsSet(string filename)
{
  int num;
  ifstream file(filename, ios::in);
  // Checks if file opened successfully
  if (!file.is_open())
  {
    return false;
  }
  // Checks if the num from file are in given range and
  // reads the file until EOF()
  while (file >> num)
  {
    if (num < 1 || num > 100)
    {
      file.close();
      return false;
    }
  }
  // Closes file after processing of data
  file.close();
  return true;
}

/**
 * @brief Checks if filename1 is subset of filename 2 and both are subset of
 *        universal set S. Returns true if they are and returns false otherwise.
 * 
 * @param filename1 
 * @param filename2 
 * @return true 
 * @return false 
 */
bool IsSubset(string filename1, string filename2)
{
  bool flag = false;
  int num1, num2;
  fstream file1(filename1), file2(filename2);
  if (IsSet(filename1) && IsSet(filename2))
  {
    // Checks if file opened successfully
    if (!file1.is_open() || !file2.is_open())
    {
      return false;
    }
    while (file1 >> num1)
    {
      while (file2 >> num2)
      {
        if (num1 == num2)
        {
          flag = true;
          break;
        }
      }
      if (flag)
      {
        // Resets file position to start
        file2.seekg(0);
        flag = false;
      }
      else
      {
        return false;
      }
    }
    // Closes file after processing of data
    file1.close();
    file2.close();
    return true;
  }
  else
  {
    return false;
  }
}

/**
 * @brief Checks if the filename1, filename2 and filename3 are subset of universal
 *        set and performs the union of filename2 and filename3. The uninon
 *        is stored in Union.out file and checks if filename2 and filename3 are
 *        subset of filename1. If all checks out, returns true else false.
 * 
 * @param filename1 
 * @param filename2 
 * @param filename3 
 * @return true 
 * @return false 
 */
bool Union(string filename1, string filename2, string filename3)
{
  int unionSet[100] = {0};
  int num;
  ofstream fileOut("Union.out");
  ifstream file1(filename2, ios::in), file2(filename3, ios::in);
  if (!IsSet(filename1) || !IsSet(filename2) || !IsSet(filename3))
  {
    return false;
  }
  if (!IsSubset(filename2, filename1) || !IsSubset(filename3, filename1))
  {
    return false;
  }
  // Checks if file opened successfully
  if (!file1.is_open() || !file2.is_open())
  {
    return false;
  }
  while (file1 >> num)
  {
    unionSet[num - 1] = num;
  }
  while (file2 >> num)
  {
    unionSet[num - 1] = num;
  }
  for (int i = 0; i < 100; i++)
  {
    if (unionSet[i] != 0)
    {
      fileOut << unionSet[i] << endl;
    }
  }
  // Closes file after processing of data
  file1.close();
  file2.close();
  fileOut.close();
  return true;
}

/**
 * @brief Checks if the filename1, filename2 and filename3 are subset of universal
 *        set and performs the intersection of filename2 and filename3. The intersection
 *        is stored in Intersection.out file and checks if filename2 and filename3 are
 *        subset of filename1. If all checks out, returns true else false.
 * 
 * @param filename1 
 * @param filename2 
 * @param filename3 
 * @return true 
 * @return false 
 */
bool Intersection(string filename1, string filename2, string filename3)
{
  int tempSet[100] = {0};
  int intersectionSet[100] = {0};
  int num;
  ofstream fileOut("Intersection.out");
  ifstream file1(filename2, ios::in), file2(filename3, ios::in);
  if (!IsSet(filename1) || !IsSet(filename2) || !IsSet(filename3))
  {
    return false;
  }
  if (!IsSubset(filename2, filename1) || !IsSubset(filename3, filename1))
  {
    return false;
  }
  // Checks if file opened successfully
  if (!file1.is_open() || !file2.is_open())
  {
    return false;
  }
  while (file1 >> num)
  {
    tempSet[num - 1] = num;
  }
  while (file2 >> num)
  {
    if (tempSet[num-1] > 0)
    {
      intersectionSet[num-1] = num;
    }
  }
  for (int i = 0; i < 100; i++)
  {
    if (intersectionSet[i] != 0)
    {
      fileOut << intersectionSet[i] << endl;
    }
  }
  // Closes file after processing of data
  file1.close();
  file2.close();
  fileOut.close();
  return true;
}