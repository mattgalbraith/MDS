#include "ACGT_profile.h"

using namespace std;
map<string, double [3000][4]> get_average_ACGT_profile(map<string, vector<segment> > S, 
	vector<PSSM *> PSSMS, int pad,map<string,   double>   & NN , 
	map<string, double [3000][4]> & G )
{
	typedef map<string, vector<segment> >::iterator it_type;
	typedef vector<segment>::iterator it_type_2;
	double current[3000][4];
	for (int p = 0; p < PSSMS.size(); p++){
		for (int i = 0 ; i < 3000; i++ ){
			current[i][0]=1.0,current[i][1]=1.0,current[i][2]=1.0,current[i][3]=1.0;
		}
		NN[PSSMS[p]->name] 			= 0.0;
		bool FOUND 					= false;
		for (it_type c = S.begin(); c!=S.end(); c++){
			for (it_type_2 s=c->second.begin(); s!=c->second.end(); s++){
				if ( !s->motif_positions[p].empty() and s->N == 3000 ){
					FOUND 	= true;
					for (int i = 0 ; i <3000 ; i++ ){
						current[i][s->forward[i]]=1+current[i][s->forward[i]];
					}
					NN[PSSMS[p]->name]+=1;
				}
				
			}
						

		}
		for (int i = 0 ; i <3000; i++ ){
			double S = 0.0;
			for (int j = 0 ; j <4; j++ ){
				//printf("%f\n",current[i][j] );
				S+=current[i][j];
			}
			for (int j = 0 ; j <4; j++ ){
				current[i][j]=current[i][j]/S;
			}
		}
		for (int i = 0 ; i < 3000; i++){
			for (int j = 0; j < 4; j++){
				G[PSSMS[p]->name][i][j] 	= current[i][j];
			}
		}
	}
	return G;


}