//Create up to 83,000 nodes. 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int writeFile () 
{
  ofstream myfile;
  myfile.open ("snap_nodes.csv");
  string temporal= "";
  string value = "'Test value for million inserts'\n";
  myfile << "# NodeName Node_id\n";
  for(int i=0; i<83000; i++)
  {
      temporal = "Node";
      myfile << temporal;
      myfile << i;
      myfile<<",";
      myfile<< i;
      temporal="";
      myfile<<"\n";
  }
  myfile.close();
  return 0;
}

int main()
{
    writeFile();
}