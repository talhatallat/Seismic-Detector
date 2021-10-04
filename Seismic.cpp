#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Seismic.h"//@@@@@@@@@@@@@@@@@@@@@@@@@change this to yours and the file name down below 

#define SIZEOFTHENAME 25


using namespace std;


//----------------------Main----------------------

int main () {
	Sesismometer Values;

	fstream infile;
	infile.open("SEISMIC.txt");

	//check for errors
	if (infile.fail()) {
		cout << "Error Openning File" << endl;
		exit(1);
	}
	
	
	float a,b,c,d,e,f,g,h,i,j,k,l,m; 
	infile >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m;
/*
	for (n=0; n<9; n++){
		cout << "\narray value"<<	n * b<<endl;
	}
*/
	
	float testScores [] = {a,b,c,d,e,f,g,h,i,j,k,l,m};
	int numberOfElements = sizeof (testScores) / sizeof(testScores[0]);

	cout << "Data from the file contains the following data: " <<endl;
	for ( int i = 0 ; i <  numberOfElements; i++){
		cout  <<testScores[i] <<" ";
	}
	
	
	
	Values.askUserT();
	float r=6; 
	float timet = r-2;
	timet  = timet  * 0.01;
	//float timet = 6;
	cout <<"\n\n\t\t----- First valid point is at time: "<< timet <<"s -----" <<endl << endl;
	Values.calc_first_time_Samples(g,f,g,f,e,d,c);
	
	cout <<"\n\n\t\t----- Second valid point is at time: "<< timet <<"s -----" <<endl << endl;
	Values.calc_secound_time_Samples(g,h,h,g,f,e,d);

	cout <<"\n\n\t\t----- Third valid point is at time: "<< timet <<"s -----" <<endl << endl;
	Values.calc_secound_time_Samples(g,e,d,g,f,e,d);

	//Values.askUserSTP();
	//Values.CSTP(g,f);

	//Values.askUserLTP();
	//Values.CLTP(g,f,e,d,c);

	//Values.ratio();
	



	//Values.CTI();
	/*
	if (Values.getRatio() > 2) {
		cout<<"\nEvent at time 0.05" <<endl;
	}

	else {
		cout <<"\nNo event at time 0.04"<<endl;
	}
	*/
	
	
	//Values.askUserT();
	//cout << "the ratio is : " << Values.getRatio() <<endl;



	/*//float stp = (((testScores [6] * testScores [6]) + (testScores [5] * testScores [5])) /2);
	//float ltp = (((testScores [6] * testScores [6]) + (testScores [5] * testScores [5]) + (testScores [4] * testScores [4]) + (testScores [3] * testScores [3]) + (testScores [2] * testScores [2])) /5);
	//float ratio = (stp/ltp);
	cout << "\n\nThe first vaild point is at 0.04 " 
		 << "\nThe Short-time power => " << stp
		 << "\nThe Long-time power => " << ltp	 
		 << "\nThe Ratio => " << ratio ;

	if (Ratio > 2){
		cout<<"\nEvent at time 0.05" <<endl;
	}

	else {
		cout <<"\nNo event at time 0.04"<<endl;
	}
	*/
	
	/*
	//class se
	class Seismic {

private:
	float short_time; //Private data
	float long_time;
	float ratio;
	float threshold;
public:
	Seismic(); // default constructor
	Seismic(float aTemp); // Overloaded constructor 
	void set_degrees(float aDegree);  // mutator
	float get_degrees(); // accessor
};

*/


	return 0;

}
 
	