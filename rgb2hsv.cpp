#include<iostream>
#include <algorithm>   

using namespace std;


 void rgb2hsv(float r, float g, float b) {

     float h = 0.0;
     float s = 0.0;
     float v = 0.0;

     float min = std::min( std::min(r, g), b );
     float max = std::max( std::max(r, g), b );
     v = max;               // v

     float delta = max - min;

     if( max != 0.0 )
         s = delta / max;       // s
     else {
         // r = g = b = 0       // s = 0, v is undefined
         s = 0.0;
         h = -1.0;
         cout<<h<<" , "<<s<<" , "<<v<<endl;
     }
     if( r == max )
         h = ( g - b ) / delta;     // between yellow & magenta
     else if( g == max )
         h = 2.0 + ( b - r ) / delta;   // between cyan & yellow
     else
         h = 4.0 + ( r - g ) / delta;   // between magenta & cyan

     h = h * 60.0;              // degrees

     if( h < 0.0 )
         h += 360.0;

     cout<<h<<" , "<<s<<" , "<<v<<endl;
 }


int main(){
while(1){
float r,g,b;

cin>>r>>g>>b;

rgb2hsv(r,g,b);
}

return 0;
}
