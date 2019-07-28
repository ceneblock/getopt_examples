#include <apr_general.h>
#include <apr_getopt.h>
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
    apr_initialize();

    apr_status_t rv;
    apr_getopt_t *opt;
    apr_pool_t *pool;
   
    char optch;
    const char *optarg;
 
    bool have_o = false, have_n = false;
    string o_value, n_value;
 
    rv = apr_pool_create(&pool, NULL);
    if(rv != APR_SUCCESS)
    {
      cerr << "Error in apr_pool_create\n";
    }

    rv = apr_getopt_init(&opt, pool, argc, argv);
    if(rv != APR_SUCCESS)
    {
      cerr << "Error in apt_getopt_init\n";
    }

    while ((rv = apr_getopt(opt, "hvn:o::", &optch, &optarg)) == APR_SUCCESS) 
    {
     switch (optch) {
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
    if (rv != APR_EOF) {
        printf("bad options\n");
    }

    if(have_o)
   {
     cout << "O's value " << o_value << endl;
   }
   if(have_n)
   {
     cout << "N's value " << n_value << endl;
   }

    apr_terminate();
    return EXIT_SUCCESS;
}
