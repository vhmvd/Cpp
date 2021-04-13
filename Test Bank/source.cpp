#include <iostream>
#include <string>
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
  string options;

public:
  QuestionMC(string theQuestion, int pointValue, string theAnswer) : Question(theQuestion, pointValue), answer(theAnswer)
  {
  }
  void addOption(string anOption)
  {
    options = anOption;
  }
  string printOptions()
  {
    return options;
  }
  string getAnswer()
  {
    return answer;
  }
};

int main(int argc, char *argv[])
{
  ifstream inFile;
  Question *myQuestions[10];
  int numberOfQuestion = 0, points, questionNumber = 0, numberOfOptions;
  string qType, question, answer;
  inFile.open("testbank.txt");
  if (!inFile)
  {
    cerr << "Unable to open file testbank.txt";
    return 1;
  }
  inFile >> numberOfQuestion;
  for (int i = 0; i < numberOfQuestion; i++)
  {
    inFile >> qType;
    inFile >> points;
    if (qType == "TF")
    {
      inFile.get();
      getline(inFile, question);
      getline(inFile, answer);
      myQuestions[questionNumber] = new QuestionTF(question, points, answer);
    }
    else if (qType == "MC")
    {
      inFile.get();
      getline(inFile, question);
      inFile >> numberOfOptions;
      string start = "A. ", temp, option = "";
      inFile.get();
      for(int i=0; i<numberOfOptions; i++)
      {
        getline(inFile, temp);
        option += "\n" + start + temp;
        start[0]++;
      }
      getline(inFile, answer);
      QuestionMC* ptr = new QuestionMC(question, points, answer);
      ptr->addOption(option);
      myQuestions[questionNumber] = ptr;
    }
    questionNumber++;
  }
  inFile.close();

  for (int count = 0; count < numberOfQuestion; count++)
  {
    cout << myQuestions[count]->getQuestion();
    cout << myQuestions[count]->printOptions() << endl << endl;
  }
  return 0;
}
