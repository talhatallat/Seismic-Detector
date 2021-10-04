
#ifndef SESISMOMETER
#define SESISMOMETER

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sesismometer // class seismic
{
private:
	float STP; // short time power
	float LTP; //long time power
	float T; //  threshold
	//float time;
	float Ratio;
public:
	//Seismic(void); //Default constructor
	//Seismic (float aSTP, int aLTP, float aT); //overloaded constructor
	//~Seismic(void);

	void calc_first_time_Samples(float stp_1 , float stp_2 , float ltp_1 , float ltp_2 , float ltp_3, float ltp_4, float ltp_5);
	void calc_secound_time_Samples(float stp1 , float stp2 , float ltp1 , float ltp2 , float ltp3, float ltp4, float ltp5);
	int getread(int astp, int altp, int at);
	void askUserSTP(); // ask user the short time power value
	void askUserLTP(); // ask user the long time power value
	void askUserT(); // ask User the threshold value
	//void askUserRatio(); // ask user the ratio value

	float CSTP(float x , float y); // Calculate short time power
	float CLTP (float r , float s , float t, float u, float v); // Calculate long time power
	void ratio();//float aSTP, float aLTP);
	float getRatio();
	int CTI();
	void fileRead();
};

//------------------------Class Methods-------------------------
/*	void Sesismometer :: fileRead() {

	fstream infile;
	infile.open("SEISMIC.DAT");

	//check for errors
	if (infile.fail()) {
		cout << "Error Openning File" << endl;
		exit(1);
	}
	
	else {
		infile>>data 
	}
}*/
/*
Seismic::Seismic() {
	STP = 0 ;
	LTP = 0;
	T = 0;
	cout << "\n\nSeismic values from Default constructor => " 
		 << "\nShort time power => " <<STP 
		 << "\nLong time power => "<<LTP 
		 << "\nThreshold => " <<T <<endl;
} // default constructor

Seismic::Seismic (float aSTP, int aLTP, float aT) {
	STP = aSTP;
	LTP = aLTP;
	T = aT;
	cout << "\nSeismic values from Overloaded constructor => " 
		 << "\nShort time power => " <<STP 
		 << "\nLong time power => "<<LTP 
		 << "\nThreshold => " <<T <<endl;
} // Overloaded construtor

// Destructor
Seismic :: ~Seismic(void)
{
	cout << "\nSeismic values from destructor => " 
		 << "\nShort time power => " <<STP 
		 << "\nLong time power => "<<LTP 
		 << "\nThreshold => " <<T <<endl;
}

/*
void Seismic::set_STP (float aSTP) {
	STP = aSTP;
	cout << "The Number is >>" <<STP<<endl;
} // set the short time power
*/
/*
void Sesismometer::askUserSTP() {
	
	cout <<"Enter sample for short time power !!NOTE: short time can only have 2 or 3 sample!! => " ;
	cin >> STP;
	if (STP !=2 && STP !=3) {
		cout <<"ERROR !! Incorrect sample is entered. Please enter 2 or 3: " <<endl;
		cin >> STP;
	}

	if (STP !=2 && STP !=3) { 
		cout <<"ERROR !! Incorrect sample is entered. Please enter 2 or 3: " <<endl;
		cin >> STP;
	}
}

void Sesismometer::askUserLTP() {
	cout <<"Enter sample for long time power !!NOTE: long time can only have 5 or 6 sample!! => " ;
	cin >> LTP;
	if (LTP !=5 && LTP !=6) {
		cout <<"ERROR !! Incorrect sample is entered. Please enter 5 or 6: " <<endl;
		cin >> STP;
	}

	if (LTP !=5 && LTP !=6) { 
		cout <<"ERROR !! Incorrect sample is entered. Please enter 5 or 6: " <<endl;
		cin >> LTP;
	}
}

void Sesismometer::askUserT() {
	cout <<"Enter value for threshold => " <<endl;
	cin >> T;
}

float Sesismometer::getRatio() {
	Ratio = STP/LTP;
	return Ratio;
}
*/
//ask functions
void Sesismometer:: askUserT() {
	
cout <<"\n\nEnter sample for short time power !!NOTE: short time can only have 2 sample!! => " ;
	cin >> STP;
	cout <<"Enter sample for long time power !!NOTE: long time can only have 5 sample!! => " ;
	cin >> LTP;
	cout <<"Enter value for threshold => " ;
	cin >> T;
	

}
// calcultaing Short time window of 2 samples and Long time window of 5 samples

void Sesismometer:: calc_first_time_Samples (float stp_1 , float stp_2 , float ltp_1 , float ltp_2 , float ltp_3, float ltp_4, float ltp_5)
{
	
	//cout <<"\n\n\t\t----- First valid point is at time: "<< time <<"s -----" <<endl << endl;
	

	if (STP == 2 && LTP == 5 ) {
		float i=6; 
	float time = i-2;
	time = time * 0.01;
		STP = (((stp_1 * stp_1) + (stp_2 * stp_2) ) /2);
		cout<<"The Short-time power is => " <<STP <<endl;

		LTP = (((ltp_1*ltp_1) + (ltp_2*ltp_2) + (ltp_3*ltp_3) + (ltp_4*ltp_4) + (ltp_5*ltp_5)) /5);
		cout<<"The long-time power is => " <<LTP <<endl;

		Ratio = (STP / LTP);
	    cout <<"The ratio is => " <<Ratio <<endl;

		cout << "The Threshold is => " << T <<endl;

		if (Ratio >= T) {
		cout<<"\n!!Event at => " << time << "s!!" <<endl;
		}

		else {
		cout <<"\nNo event at this time => " <<time <<"s" <<endl;
		}





		//return STP && LTP;
	}
	/*
		else if (STP == 2 && LTP == 5 ) {
		STP = (((stp_1 * stp_1) + (stp_2 * stp_2) ) /2);
		cout<<"The Short-time power is => " <<STP <<endl;

		LTP = (((ltp_1*ltp_1) + (ltp_2*ltp_2) + (ltp_3*ltp_3) + (ltp_4*ltp_4) + (ltp_5*ltp_5)) /5);
		cout<<"The long-time power is => " <<LTP <<endl;

		Ratio = (STP / LTP);
	    cout <<"The ratio is => " <<Ratio <<endl;

		cout << "The Threshold is => " << T <<endl;

		if (Ratio >= T) {
		cout<<"\n!!Event at => " << time << "s!!" <<endl;
		}

		else {
		cout <<"\nNo event at this time => " <<time <<"s" <<endl;
		}

	return STP && LTP;
	}
	*/
	//else {
	//cout <<"\n1ERROR !! Incorrect sample is entered. " <<endl;
	//}
	
}








/*
int Sesismometer :: getread(int astp, int altp, int at){
	STP = astp;
	LTP = altp;
	T = at;
	return STP;
}
*/

void Sesismometer :: calc_secound_time_Samples (float stp1 , float stp2 , float ltp1 , float ltp2 , float ltp3, float ltp4, float ltp5) {
	
	
	/*
	//cout <<"\n\n\t\t----- First valid point is at time: "<< time <<"s -----" <<endl << endl;
	cout <<"\n\nEnter sample for short time power !!NOTE: short time can only have 2 sample!! => " ;
	cin >> STP;
	cout <<"Enter sample for long time power !!NOTE: long time can only have 5 sample!! => " ;
	cin >> LTP;
	cout <<"Enter value for threshold => " ;
	cin >> T;
	*/
	//if (STP == 2 && LTP == 5 ) {
		float i=6; 
	float time = i-2;
	time = time * 0.01;
		STP = (((stp1 * stp1) + (stp2 * stp2) ) /2);
		cout<<"The Short-time power is => " <<STP <<endl;

		LTP = (((ltp1*ltp1) + (ltp2*ltp2) + (ltp3*ltp3) + (ltp4*ltp4) + (ltp5*ltp5)) /5);
		cout<<"The long-time power is => " <<LTP <<endl;

		Ratio = (STP / LTP);
	    cout <<"The ratio is => " <<Ratio <<endl;

		cout << "The Threshold is => " << T <<endl;

		if (Ratio >= T) {
		cout<<"\n!!Event at => " << time << "s!!" <<endl;
		}

		else {
		cout <<"\nNo event at this time => " <<time <<"s" <<endl;
		}

	//return STP && LTP;
	//}

	//else {
	//cout <<"\n2ERROR !! Incorrect sample is entered. " <<endl;
	//}

}











/*
//fstream fin;
void Seismic::read(){
 //  ifstream infile;
	//infile.open("SEISMIC.DAT");


  if (STP ==2 && LTP ==4) {

	  for (int i=5; i <= 12; i++) {

		float time = i-2;
		time = time * 0.01;
		cout <<"\nTime is: " <<time << endl ;

		float STP = (pow(infile[i],2) + pow(infile[i-1],2)) / (STP);
		cout <<"Short time power is => "<< STP <<endl;

		float LTP = (pow(data[i],2) + pow(data[i-1],2) + pow(data[i-2],2) + pow(data[i-3],2) + pow(data[i-4],2)) / (LTP);
		cout <<"Long time power is => "<< LTP <<endl;

		cout <<"Threshold is => "<<T <<endl;

		float Ratio = STP/LTP;
		cout <<"Ratio is => " <<Ratio <<endl;
		
		/*
		if (Ratio >= T) {
		cout <<"\n!!Event at => " << time << "s!!" <<endl;
	    }

		else {
		cout <<"\nNo event at => " <<time <<"s" <<endl;
		}

		/*fin.open("Earthquake_Values.txt", fstream::trunc);
		fstream out("Earthquake_Values.txt", fstream::app);
		out.seekg(0, ios::end);

		out <<"\nTime is: " <<time <<endl ;
		out <<"Short time power is => "<< STP <<endl;
		out <<"Long time power is => "<< LTP <<endl;
		out <<"Threshold is => "<<T << endl;
		out <<"Ratio is => " <<Ratio <<endl;

		if (Ratio >= T) {
		cout<<"\n!!Event at => " << time << "s!!" <<endl;
	    }

		else {
		cout <<"\nNo event at => " <<time <<"s" <<endl;
		}*/
/*
	}
  }
}*/
/*
int Seismic:: CTI () {
	//LTP = aTime;
	int z =0;
	for ( int i = 0; i<5; i++){
		z=z+1;
		float it = i * b;
}
	
	cout <<"The time interval is: " <<it <<endl;
	return z;
}

*/

/*
float Sesismometer::CSTP(float x , float y) {
	//float stp = (((x * x) + (y * y) ) /2);
	//cout<<"The Short-time power is => " <<stp <<endl;
	//return stp;
	STP = (((x * x) + (y * y) ) /2);
	cout<<"\n\nThe Short-time power is => " <<STP <<endl;
	return STP;
}

float Sesismometer::CLTP (float r , float s , float t, float u, float v) {
	//float ltp = (((r*r) + (s*s) + (t*t) + (u*u) + (v*v)) /5);
	//cout<<"The long-time power is => " <<ltp <<endl;
	//return ltp;

	LTP = (((r*r) + (s*s) + (t*t) + (u*u) + (v*v)) /5);
	cout<<"The long-time power is => " <<LTP <<endl;
	return LTP;

}

void Sesismometer::ratio() {
	Ratio = (STP/ LTP);
	cout <<"The ratio is => " <<Ratio <<endl;
}


/*
float Seismic:: getRatio() {
	return Ratio;
}

*/

#endif
