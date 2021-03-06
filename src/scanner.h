#define _GLIBCXX_USE_CXX11_ABI 0

#ifndef scanner_H
#define scanner_H
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include "error_stdo_logging.h"
#include "load.h"
using namespace std;
void run_scanner();
vector<double> get_GC_content(map<string, vector<segment>>);
map<string, vector<segment> > run_accross(map<string, vector<segment>>, 
	vector<PSSM *>,vector<double>, double,int,int);
map<int, map<int, vector<segment> >> scan_simulations(map<int, map<int, vector<segment> >> ,
	vector<PSSM *> , vector<double> ,double );

map<string, vector<segment> > run_accross2(map<string, vector<segment>>   ,
 vector<PSSM *>  , vector<vector<double>>,vector<vector<double>>  , double  , int, string,string  );

vector<int> get_sig_positions(vector<int> , 
			      vector<int>, int, PSSM *  , double );
void scan_intervals(map<string, vector<segment>> ,vector<PSSM *>  , vector<double> , double  , int  , int  , 
		    int  , int  , Log_File *, int,string,double );



void scan_intervals_genome_wide(map<string, vector<segment>>, vector<PSSM *> , vector<double> , 
									double , int , 
									int , Log_File * , string );

#endif
