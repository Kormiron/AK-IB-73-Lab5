#include<iostream>
#include<getopt.h>

using namespace std;
int main (int argc, char *argv[]){

	const char* short_options = "hk::l:";

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"kek",optional_argument,NULL,'k'},
		{"lol",required_argument,NULL,'l'},
		{NULL,0,NULL,0}
	};

	int rez;
	int option_index=-1;
	int hctr = 0;
	int sctr = 0;
	int fctr = 0;
	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){
		switch(rez){
			case 'h': {
				if (hctr==0)
					if (option_index<0)
						cout << "ARG:h"<<endl;
					else
						cout << "ARG:help"<<endl;
				hctr++;
				break;
			};
			case 'k': {
				if (sctr==0)
					if (option_index<0)	
						if (optarg!=NULL&&optarg!=" ")
							cout <<"ARG:k\tfound kek with value "<<optarg<<endl;
						else
							cout <<"ARG:k\tfound kek without value"<<endl;
					else
						if (optarg!=NULL)
							cout <<"ARG:kek\tfound kek with value "<<optarg<<endl;
						else
							cout <<"ARG:kek\tfound kek without value"<<endl;
				sctr++;
				break;
			};
			case 'l': {
				if (fctr==0)
					if (option_index<0)
						cout <<"ARG:l\tlol = "<<optarg<<endl;
					else
						cout << "ARG:lol\tlol = "<<optarg<<endl;
				fctr++;
				break;
			};
			case '?': {
				cout <<"found unknown option"<<endl;
				break;
			};
		};
		// option_index=-1;
	};
	return 0;
};

