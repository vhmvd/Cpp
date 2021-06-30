#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Question
{
private:
  string question;
  int value;

public:
  Question(string theQuestion, int pointValue) : question(theQuestion), value(pointValue)
  {
  }
  string getQuestion()
  {
    return question;
  }
  int getValue()
  {
    return value;
  }
  virtual string printOptions()
  {
    return "";
  }
  virtual string getAnswer()
  {
    return "";
  }
};

class QuestionTF : public Question
{
private:
  string answer;

public:
  QuestionTF(string theQuestion, int pointValue, string theAnswer) : Question(theQuestion, pointValue), answer(theAnswer)
  {
  }
  string printOptions()
  {
    return "(true/false)";
  }
  string getAnswer()
  {
    return answer;
  }
};

class QuestionMC : public Question
{
private:
  string answer;
  vector<string> options;

public:
  QuestionMC(string theQuestion, int pointValue, string theAnswer) : Question(theQuestion, pointValue), answer(theAnswer)
  {
  }
  void addOption(string anOption)
  {
    options.push_back(anOption);
  }
  string printOptions()
  {
    string temp = "";
    for(string itr: options)
    {
      temp+=itr;
    }
    return temp;
  }
  string getAnswer()
  {
    return answer;
  }
};

int main(int argc, char *argv[])
{
  vector<Question*> myQuestions;
  unsigned int numberOfQuestion;
  int points, questionNumber = 0, numberOfOptions;
  bool flag = true;
  string qType, question, answer;
  cout << "\nEnter number of questions: ";
  try
  {
    cin >> numberOfQuestion;
  }
  catch(const exception& e)
  {
    cerr << "Invalid input. Only positive integer accepted\n";
    return 1;
  }
  for (int i = 0; i < numberOfQuestion; i++)
  {
    cout << "Enter question type (TF/MC): ";
    cin >> qType;
    if(qType != "TF" && qType != "MC")
    {
      i--;
      cerr << "Invalid question type. TF or MC only. \n";
      continue;
    }
    try
    {
      cout << "Enter points: ";
      cin >> points;
      if(points < 0)
      {
        throw (points);
      }
    }
    catch(int e)
    {
      cerr << "Points cannot be negative\n";
    }
    
    
    if (qType == "TF")
    {
      cin.ignore();
      cout << "Enter question: ";
      getline(cin, question);
      cout << "Enter answer: ";
      getline(cin, answer);
      myQuestions.push_back(new QuestionTF(question, points, answer));
    }
    else if (qType == "MC")
    {
      cin.ignore();
      cout << "Enter question: ";
      getline(cin, question);
      cin >> numberOfOptions;
      string start = "A. ", temp, option = "";
      getline(cin, answer);
      cout << "Enter answer: ";
      QuestionMC* ptr = new QuestionMC(question, points, answer);
      for(int i=0; i<numberOfOptions; i++)
      {
        getline(cin, temp);
        ptr->addOption(option);
      }
      myQuestions.push_back(ptr);
    }
    questionNumber++;
  }

  ofstream outFile("test.out");
  outFile << numberOfQuestion << endl;
  for(Question* itr: myQuestions)
  {
    outFile << itr->getQuestion() << " " << itr->getValue() << endl;
    outFile << itr->printOptions() << endl;
    outFile << itr->getAnswer() << endl;
  }
  return 0;
}
