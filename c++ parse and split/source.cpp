#include <iostream>
#include <fstream>
#include <cstring>

int  count[100] = {0};
int counter = 0;
int word_counter = 0;
char dict[100][16] = {'\0'};
char line[100] = {'\0'};
char temp[16] = {'\0'};
bool strcmp_found = false;
int total_words = 0;

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    std::cout << "Invalid number of arguments. The format is:\nsource <input file name> <output file name>";
  }
  else
  {
    std::ifstream inp_file;
    inp_file.open(argv[1]);
    if(inp_file.is_open())
    {
      while(inp_file.getline(line,100))
      {
        char *token = strtok(line," ");
        while (token)
        {
          total_words++;
          for(int i=0; i<strlen(token); i++)
          {
            if((int)token[i] >= 97)
            {
              temp[word_counter] = token[i];
              ++word_counter;
            }
          }
          word_counter = 0;
          for(int i=0; i<100; i++)
          {
            if(strcmp(temp, dict[i]) == 0)
            {
              ++count[i];
              strcmp_found = true;
              break;
            }
            else if(dict[i][0] == '\0')
            {
              break;
            }
          }
          if(!strcmp_found)
          {
            for(int j=0; j<strlen(temp); j++)
            {
              dict[counter][j] = temp[j];
            }
            ++count[counter];
            counter++;
          }
          strcmp_found = false;
          token = strtok(NULL," ");
          for(int i=0; i<16; i++)
          {
            temp[i] = '\0';
          }
        }
      }
      inp_file.close();


      std::ofstream out_file;
      out_file.open(argv[2]);
      for(int i=0; i<counter;i++)
      {
        out_file << count[i] << "\t" << dict[i] << std::endl;
        std::cout << count[i] << "\t" << dict[i] << std::endl;
      }
      out_file.close();

      std::cout << "Total words: " << total_words << std::endl;
      std::cout << "Unique words: " << counter << std::endl;
    }
    else
    {
      std::cout << "File does not exit!\n";
    }
  }
  return 0;
}