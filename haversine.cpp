#include <iostream>
#include <math.h>
using namespace std;
float lat_1,lat_2,long_1,long_2;  //primary variables
const int radius_of_earth=6371;    //in Km
int Deg_lat_1,Deg_long_1,Min_lat_1,Min_long_1,Sec_lat_1,Sec_long_1,
Deg_lat_2,Deg_long_2,Min_lat_2,Min_long_2,Sec_lat_2,Sec_long_2; ///for inputs having format of Deg_min_sec with prefix as N/S &W/E
char Hemi_lat_1, Hemi_long_1,Hemi_lat_2, Hemi_long_2;
string input_type;
const float pi_processed =0.0174533;    //pi /180
double temp_1, temp_2, temp_3,output;
int main(){
cout<<"Enter the input_type: \n option 1: Deg min sec  with prefix as N/S &W/E. \n option 2: decimal degree or integer \n";
cin>>input_type;
if(input_type== "option_1"){

/********************************first input value******************************************/
    cout<<"Hemi_lat_1: ";
    cin>> Hemi_lat_1;
    cout<<"Deg_lat_1: ";
    cin>>Deg_lat_1;
    cout<<"Min_lat_1: ";
    cin>> Min_lat_1;
    cout<<"Sec_lat_1: ";
    cin>>Sec_lat_1;

    cout<<"Hemi_long_1: ";
    cin>> Hemi_long_1;
    cout<<"Deg_long_1: ";
    cin>>Deg_long_1;
    cout<<"Min_long_1: ";
    cin>> Min_long_1;
    cout<<"Sec_long_1: ";
    cin>>Sec_long_1;
/********************************Second input value******************************************/
    cout<<"Hemi_lat_2: ";
    cin>> Hemi_lat_2;
    cout<<"Deg_lat_2: ";
    cin>>Deg_lat_2;
    cout<<"Min_lat_2: ";
    cin>> Min_lat_2;
    cout<<"Sec_lat_2: ";
    cin>>Sec_lat_2;

    cout<<"Hemi_long_2: ";
    cin>> Hemi_long_2;
    cout<<"Deg_long_2: ";
    cin>>Deg_long_2;
    cout<<"Min_long_2: ";
    cin>> Min_long_2;
    cout<<"Sec_long_2: ";
    cin>>Sec_long_2;

    if(Hemi_lat_1=='N'){
        lat_1= Deg_lat_1+(Min_lat_1/60)+(Sec_lat_1/3600);
    }
    else if(Hemi_lat_1=='S'){
        lat_1= -1 * (Deg_lat_1+(Min_lat_1/60)+(Sec_lat_1/3600));
    }
    if(Hemi_lat_2=='N'){
        lat_2= Deg_lat_2+(Min_lat_2/60)+(Sec_lat_2/3600);
    }
    else if(Hemi_lat_2=='S'){
        lat_2= -1 * (Deg_lat_2+(Min_lat_2/60)+(Sec_lat_2/3600));
    }

    if(Hemi_long_1=='E'){
        long_1= Deg_long_1+(Min_long_1/60)+(Sec_long_1/3600);
    }
    else if(Hemi_long_1=='W'){
        long_1= -1 * (Deg_long_1+(Min_long_1/60)+(Sec_long_1/3600));
    }
    if(Hemi_long_2=='E'){
        long_2= Deg_long_2+(Min_long_2/60)+(Sec_long_2/3600);
    }
    else if(Hemi_long_2=='W'){
        long_2= -1 * (Deg_long_2+(Min_long_2/60)+(Sec_long_2/3600));
    }
    lat_1=lat_1*pi_processed;
    long_1=long_1*pi_processed;
    lat_2 = lat_2*pi_processed;
    long_2 = long_2*pi_processed;
    temp_1=(lat_2-lat_1)/2;
    temp_2=(long_2-long_1)/2;

    temp_1 = sin(temp_1);
    temp_2 = sin(temp_2);
    temp_1 = pow(temp_1,2);
    temp_2 = pow(temp_2,2);

    temp_3=temp_1+cos(lat_1)* cos(lat_2)*temp_2;
    output=2*radius_of_earth+ asin(sqrt(temp_3));
    cout<<"The distance between is "<<output<<" Km";

}
else if(input_type== "option_2"){
    cout<<"Enter Lat 1: ";
    cin>> lat_1;
    cout<<"Enter Long 1: ";
    cin>> long_1;

    cout<<"Enter Lat 2: ";
    cin>> lat_2;
    cout<<"Enter Long 2: ";
    cin>> long_2;

lat_1=lat_1*pi_processed;
    long_1=long_1*pi_processed;
    lat_2 = lat_2*pi_processed;
    long_2 = long_2*pi_processed;
    temp_1=(lat_2-lat_1)/2;
    temp_2=(long_2-long_1)/2;

    temp_1 = sin(temp_1);
    temp_2 = sin(temp_2);
    temp_1 = pow(temp_1,2);
    temp_2 = pow(temp_2,2);

    temp_3=temp_1+cos(lat_1)* cos(lat_2)*temp_2;
    output=2*radius_of_earth+ asin(sqrt(temp_3));
    cout<<"The distance between is "<<output<<" Km";}

return 0;

}
