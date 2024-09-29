#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   /*
   ofstream outFile;
   
   outFile.open("userName.txt");
   
   if(!outFile.is_open())
   {
       cout<<"The file is not open !!!"<<endl;
       
   }
   else
   {
       cout<<"The file has been successfully opened !!!"<<endl;
       
       outFile.close();
   }
   */
   
      ifstream outFile;
   
   outFile.open("userNames.txt");
   
   if(!outFile.is_open())
   {
       cout<<"The file is not open !!!"<<endl;
       
   }
   else
   {
       cout<<"The file has been successfully opened !!!"<<endl;
       
       string fileItem;
       
       outFile>>fileItem;
       
       cout<<"The input file value is : "<<fileItem<<endl;
       
       outFile.close();
   }
   
   
   
    return 0;
}


