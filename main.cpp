#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "End.h"
using namespace std;
//lynn is here
//hello world~
//for parameter not changed!!
const int Simulation_Time = 1000;
const int MAX = 10;
const int EndNum = 100;
const int PreambleNum = 54;
//
//for parameter measuring the efficiency!!!
int finish_time[EndNum];
int access_time = 0;
int collision_time = 0;
//
int _time = 1;// the order of the subframe
int preamble[PreambleNum] = {0};
int count = 0;//to record the tutle number of successful and abort End
void responseForUseSamePreamble();//for
// to set the probablity of successful receive, the input is the number of the restransmission
int setProbablity( int );

//for random
srand(time(NULL));
//

int main() {
  End end[EndNum];
  for(; count < EndNum ; _time +=5 ){
    for( int n = 0; n < EndNum; n++ )
      end[n].setpreamble();     
    responseForUseSamePreamble();
 
 /*!!!
 response...: 1. watch the preamble[], if == 1,
     if > 1, handle fail
     2.
 
 !!!*/
    for( int n = 0; n < EndNum; n++ ){
      end[n].responseForOnlyOne();
      end[n].settime();
    }
 
 cout << "time: " << _time << "    count: " << count << endl;
  }
 
 
 
  return 0;
}
void responseForUseSamePreamble()
{
  for( int i = 0; i < PreambleNum;  i++ ){
    if( preamble[i] > 1 ){
      //preamble[i] = setProbablity(1); 
   if (setProbablity(1) == 0) preamble[i] = 0;
 }
  }
}
int setProbablity( int retransmit )
{
 double p = 1 - exp((double) retransmit*(-1));
 int p1 = p*1000;
 int p2 = (1.0 - p)*1000;
 
  int key = rand() % (p1 + p2);
 
 if (key <= p1) return 1;
 else return 0;
}
