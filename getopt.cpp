#include <unistd.h>
#include <iostream>
#include <string>

#define VERSION_INFO "0.0.1"

using namespace std;

void show_help(char *prog_name)
{
  cout << prog_name << endl;
  cout << "-h\tDisplay this help message and exit\n";
  cout << "-v\tDisplay version info and exit\n";
  cout << "-o[VALUE]\tAn output file\n";
  cout << "-n VALUE\tA name\n"; 
  exit(EXIT_SUCCESS);
}

void show_version()
{
  cout << VERSION_INFO << endl;
  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
 char opt;
 
 bool have_o = false, have_n = false;
 string o_value, n_value;

 while ((opt = getopt(argc, argv, "hvn:o::")) != -1)
 {
     switch (opt) 
     {
       case 'h':
         show_help(argv[0]);
         break;
       case 'v':
         show_version();
         break;
       case 'o':
         have_o = true;
         if(optarg)
         {
           o_value = optarg;
         }
         break;
       case 'n':
         if(optarg)
         {
           have_n = true;
           n_value = optarg;
         }
         else
         {
           cerr << "No argument for -n!";
           exit(EXIT_FAILURE);
         }
         break;
     }
 }

 if(have_o)
 {
   cout << "O's value " << o_value << endl;
 }
 if(have_n)
 {
   cout << "N's value " << n_value << endl;
 }
 return EXIT_SUCCESS;
}

