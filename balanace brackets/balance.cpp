#include <iostream>
#include <list>
#include <stack>

using namespace std;
/*
   * This program reads from standard input, checking for balancing of
   * () [], and {} pairs.
   *
   * If an error is detected, then the program prints an error message to 
   * standard output. The messages are one of the following:
   *  "Unmatched { in line N"
   *  "Unmatched } in line N"
   *  "Mismatched { and } in line N"
   * where the character { could be replaced by any of {, (, or [
   * and the charcter } could be replaced by any of }, ], or ) and
   * N is the line number in which the error was detected.
   */

/*
 * Use this routine to signal errors when you have encountered a )]}
 * that does not match the most recent ([{
 * 
 * @param left character that we were trying to match (one
 *     of '(', '[', or '{')
 * @param right character that saw instead (one
 *     of ')', ']', or '}')
 * @param lineNumber  line of input in which the right character
 *     was encountered.
 * 
 */
void mismatchError(char left, char right, int lineNumber)
{
      cout << "*Mismatched " << left << " and " << right
           << " in line " << lineNumber << endl;
}

/*
 * Use this routine to signal errors when you have encountered a {[(
 * and there are no )]} (even non-matching ones) left in the input, or 
 * if you have encountered a )]} with no preceding ({[ (even non-matching 
 * ones) in the input.
 *
 * @param c Character that was not properly matched.
 * @param lineNumber  line of input in which that character was encountered.
 */
void unmatchedError(char c, int lineNumber)
{
      cout << "*Unmatched " << c
           << " in line " << lineNumber << endl;
}

typedef std::stack<char> StackType;
typedef std::stack<int> StackTypeLines;

bool LRmatch(char left, char right)
{
      if ((left == '(' && right == ')') || (left == '{' && right == '}') || (left == '[' && right == ']'))
      {
            return true;
      }
      else
      {
            return false;
      }
}

int main()
{

      StackType stk;
      StackTypeLines lines;
      char c;
      int lineNumber = 0;

      while (!cin.eof())
      {
            c = cin.get();
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                  stk.push(c);
                  lines.push(lineNumber);
                  break;

            case ')':
            case ']':
            case '}':
                  if (stk.size() > 0)
                  {
                        if (LRmatch(stk.top(), c))
                        {
                              stk.pop();
                              lines.pop();
                        }
                        else
                        {
                              mismatchError(stk.top(), c, lines.top());
                              stk.pop();
                              lines.pop();
                        }
                  }
                  else
                  {
                        unmatchedError(c, lineNumber);
                  }
                  break;

            case '\n':
                  if (stk.size() > 0)
                  {
                        while (!stk.empty())
                        {
                              unmatchedError(stk.top(), lines.top());
                              stk.pop();
                              lines.pop();
                        }
                  }
                  ++lineNumber;
                  break;
            }
      }

      cout << "Done" << endl;
      return 0;
}
