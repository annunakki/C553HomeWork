//==========================================================
//==============Fady Safar======================================
//==========================================================
/*
 * 365 days in a year

    LEAP YEAR: any year divisible by 4 --> LEAP
    EXCEPT:   if year divisible by 100 --> NOT LEAP
    EXCEPT:   if year divisible by 400 --> LEAP
    year = 365.2425 days

    2000 LEAP
    2004 LEAP
    2100 NOT LEAP

    J2000 = Jan. 1, 2000 = 0


    Jan. 2, 2000 = 1
    Jan. 3, 2000 = 2


https://en.wikipedia.org/wiki/Julian_day
http://aa.usno.navy.mil/faq/docs/JD_Formula.php

Look it up, cite it, feel free to use it.  Just make it object oriented.
 */
//==================================================

#include <iostream>
#include <math.h>
using namespace std;

class JulianDate {
private:

    int  year,month,day,hour,minute,second;
public:
    JulianDate();
    JulianDate (int y, int m, int d, int h,int min, int s) : year(y),month(m),day(d),hour(h),minute(min),second(s) {}
    JulianDate (int y, int m, int d) : year(y),month(m),day(d),hour(0),minute(0),second(0) {}

    friend ostream& operator << (ostream& op, const JulianDate j ){
        return op << j.year <<' '<< j.month <<' '<< j.day <<' '<< j.hour <<' '<<j.minute<<' '<<j.second;
    }


    friend JulianDate  operator - ( JulianDate a,  JulianDate b) {
        double  jday, jdaya, jdayb;

        int xa=(100*a.year+a.month-190002.5);
        xa = xa>0 ? 1 : -1;

        int xb=(100*b.year+b.month-190002.5) ;
        xb=xb>0 ? 1 : -1 ;

          jdaya =	(367*a.year - (int)((7*(a.year+(a.month+9)/12))/4)+ ((275*a.month)/9)
                     + a.day + 1721013.5 + a.hour/24- 0.5* xa + 0.5);

         jdayb = (367*b.year -(int)((7*(b.year+(b.month+9)/12))/4)+ ((275*b.month)/9)
                  + b.day + 1721013.5 + b.hour/24- 0.5* xb+ 0.5);

         jday=jdayb-jdaya;

        double l, n, i, j, k,hh,mm,ss ;
        l=jday+68569;
        n=4*l/146097;
        l=l-(146097*n+3)/4;
        i=4000*(l+1)/1461001;
        l=l-1461*i/4+31;
        j=80*l/2447;
        k=l-2447*j/80;
        l=j/11;
        j=j+2-12*l;
        i=100*(n-49)+i+l;
        hh=b.hour-a.hour;
        mm=abs(b.minute-a.minute);
        ss=abs(b.second-a.second);

      return  JulianDate (i,j,k,hh,mm,ss);}

   friend JulianDate  operator +(const JulianDate& a, int f){

        int xa=(100*a.year+a.month-190002.5);
        xa = xa>0 ? 1 : -1;

        double jday =	(367*a.year - (int)((7*(a.year+(a.month+9)/12))/4)+ ((275*a.month)/9)
                   + a.day + 1721013.5 + a.hour/24- 0.5* xa + 0.5);

        jday +=f;

        double l, n, i, j, k ;
        l=jday+68569;
        n=4*l/146097;
        l=l-(146097*n+3)/4;
        i=4000*(l+1)/1461001;
        l=l-1461*i/4+31;
        j=80*l/2447;
        k=l-2447*j/80;
        l=j/11;
        j=j+2-12*l;
        i=100*(n-49)+i+l;

      return  JulianDate (i,j,k,a.hour,a.minute,a.second);}


    int  getYear() const {return year;}

    int getMonth() const {return month;}

    int getDay()const {return day;}

    int getHour() const {return hour;}

    int getMin() const {return minute;}

    int getSec() const {return second;}


};


int main() {
    const  JulianDate d1(2017, 2, 13, 20, 00, 00);
    const JulianDate d1b(2017, 2, 13, 22, 00, 00);

    cout << d1b - d1 << '\n ' ; // 2 hours = 2/24 day

    const JulianDate tomorrow = d1 + 1;
    cout << tomorrow; // 2017 2 14 20 00 00
    cout << tomorrow - d1 << '\n';
    // hh:mm:ss  20/24  20/24.0
    const JulianDate d2(2017, 2, 19); // 00:00:00
  const JulianDate d3 = d2 + 3; // what is it 3 days later?
 //   double days   = d3 - d1;

    int year = d3.getYear();
    int month = d3.getMonth();
    int day = d3.getDay();
    int hour = d3.getHour();
    int min = d3.getMin();
    int sec = d3.getSec();
    cout << d1 << '\n';
    cout << d2 << '\n';
    cout << d3 << '\n';
    cout << year << " " << month << " " << day << hour << " " << min << " " << sec << '\n';

    // Not every operation makes sense!
    //	JulianDate d5 = d3 * d1;

    JulianDate torture(2017, 2, 27); // 00:00:00

    for (int i = 0; i < 3; i++) {
        cout << torture.getYear() << " " << torture.getMonth() << " " << torture.getDay() << '\n';
        torture = torture + 1;
    }
}

