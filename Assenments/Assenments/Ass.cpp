#include <iostream>
#include <fstream>
#include <string>
float array [40];

using namespace std;

int main () {

	ifstream infile;
	infile.open("SEISMIC.DAT");

	//check for errors
	if (infile.fail()) {
		cerr << "Error Openning File" << endl;
		exit(1);
	}

	float a,b,c,d,e,f,g,h,i,j,k; 
	

	infile >> a >>  b >> c >> d >> e >> f >> g >> h >> i >> j >> k;
	cout << "Data from the file contains the followinf data: " << endl << a <<" "<<  b <<" "<< c <<" "<< d <<" "<< e <<" "<< f <<" "<< g <<" "<< h <<" "<< i <<" "<< j <<" "<< k << endl;

	array[0]= c;
	array[1]= d;
	array[2]= e;
		array[3]= f;
			array[4]= g;
				array[5]= h;
					array[6]=i;
						array[7]= j;
							array[8]= k;
								

	cout << "" << 4*b ;

	int n;
	//calculations
	int ze =0;
	while(  ze !=a)
	{


		cout << "\narray ............."<<	ze * b<<endl;
		ze++;

	}
	for (n=0; n<9; n++){
	
		cout << "\narray value"<<	n * b<<endl;

	}
	
	
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












	return 0;

}