#include <iostream>
#include <fstream>

using namespace std;

int
main ()
{
  ofstream output;
  string fileName = "binary.bin";
  output.open (fileName, ios::binary | ios::trunc);	// ios::trunc clears the output file if there is old content
  if (!output.is_open ())
    {
      cout << "Cannot open input file " << fileName << endl;
    }
  else
    {
      output.seekp (0);
      for (int i = 1; i <= 5; i++)
    	output << "This is line number " << i << endl;
    	
    	output.close();
    }

  ifstream input;
  input.open (fileName, ios::binary);
  if (!input.is_open ())
    {
      cout << "Cannot open output file " << fileName << endl;
    }
  else
    {
      input.seekg (0);  
      string line;
      while (input)
	{
	  getline (input, line);
	  cout << line << endl;
	}
	input.close();
    }
  return 0;
}
