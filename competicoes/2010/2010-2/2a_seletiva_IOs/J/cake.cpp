// polygoniaT.cc
//Polygonia problem
// T Feil

#include <iomanip>
#include <iostream>
using namespace std;

double distance (double x1, double y1, double x2, double y2){
  return(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

double areaTri(double x1, double y1, double x2, double y2, double x3, double y3){
  double a,b,c,s;
  a = distance(x1,y1,x2,y2);
  b = distance(x2,y2,x3,y3);
  c = distance(x3,y3,x1,y1);
  s = (a+b+c)/2;
  return( sqrt(s*(s-a)*(s-b)*(s-c)));
}

double areaQuad(double x1, double y1,
                double x2, double y2,
                double x3, double y3,
                double x4, double y4){
  return(areaTri(x1,y1,x2,y2,x3,y3) + areaTri(x1,y1,x3,y3,x4,y4));
}

int main(){
  double x[4],y[4];
  int Case =1;

  for(int i=0;i<4;i++)
    cin>>x[i]>>y[i];
  while(x[0]!=0 || y[0]!=0 || x[1]!=0 ||y[1]!=0){
   double bestdiff, diff, mx, my, nx, ny, area1, area2, best1, best2;

   //try all 12 possibilities
   //pt 0 to mid point of 1 - 2
   mx = (x[1]+x[2])/2; my = (y[1]+y[2])/2;
   area1 = areaTri(x[0],y[0],x[1],y[1],mx, my);
   area2 = areaQuad(x[0],y[0],mx,my,x[2],y[2],x[3],y[3]);
   bestdiff = abs(area1 - area2);
   best1 = area1; best2=area2;
   //pt 0 to pt 2
   area1 = areaTri(x[0],y[0],x[1],y[1],x[2],y[2]);
   area2 = areaTri(x[0],y[0],x[2],y[2],x[3],y[3]);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //pt 0 to midpt of  2 - 3
   mx = (x[3]+x[2])/2; my = (y[3]+y[2])/2;
   area1 = areaTri(x[0],y[0],x[3],y[3],mx, my);
   area2 = areaQuad(x[0],y[0],mx,my,x[2],y[2],x[1],y[1]);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //pt1 to midpt of 2 - 3
   mx = (x[3]+x[2])/2; my = (y[3]+y[2])/2;
   area1 = areaTri(x[1],y[1],x[2],y[2],mx, my);
   area2 = areaQuad(x[1],y[1],mx,my,x[3],y[3],x[0],y[0]);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //pt 1 to pt 3
   area1 = areaTri(x[1],y[1],x[2],y[2],x[3],y[3]);
   area2 = areaTri(x[0],y[0],x[1],y[1],x[3],y[3]);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //pt1 to midpt of 3 - 0
   mx = (x[3]+x[0])/2; my = (y[3]+y[0])/2;
   area1 = areaTri(x[1],y[1],x[0],y[0],mx, my);
   area2 = areaQuad(x[1],y[1],x[2],y[2],x[3],y[3],mx,my);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //pt2 to midpt of 3 - 0
   mx = (x[3]+x[0])/2; my = (y[3]+y[0])/2;
   area1 = areaTri(x[2],y[2],x[3],y[3],mx, my);
   area2 = areaQuad(x[2],y[2],mx,my,x[0],y[0],x[1],y[1]);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //pt2 to midpt of 1 - 0
   mx = (x[1]+x[0])/2; my = (y[1]+y[0])/2;
   area1 = areaTri(x[2],y[2],x[1],y[1],mx, my);
   area2 = areaQuad(x[2],y[2],x[3],y[3],x[0],y[0],mx,my);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //pt3 to midpt of 1 - 0
   mx = (x[1]+x[0])/2; my = (y[1]+y[0])/2;
   area1 = areaTri(x[3],y[3],x[0],y[0],mx, my);
   area2 = areaQuad(x[1],y[1],x[2],y[2],x[3],y[3],mx,my);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //pt3 to midpt of 1 - 2
   mx = (x[1]+x[2])/2; my = (y[1]+y[2])/2;
   area1 = areaTri(x[2],y[2],x[3],y[3],mx, my);
   area2 = areaQuad(x[3],y[3],x[0],y[0],x[1],y[1],mx,my);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //mid 1-2 to mid 3-0
   nx=(x[3]+x[0])/2; ny=(y[3]+y[0])/2;
   area1 = areaQuad(mx,my,nx,ny,x[0],y[0],x[1],y[1]);
   area2 = areaQuad(mx,my,nx,ny,x[3],y[3],x[2],y[2]);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }
   //mid 1-0 to mid 3-2
   mx = (x[1]+x[0])/2; my = (y[1]+y[0])/2;
   nx=(x[3]+x[2])/2; ny=(y[3]+y[2])/2;
   area1 = areaQuad(mx,my,nx,ny,x[2],y[2],x[1],y[1]);
   area2 = areaQuad(mx,my,nx,ny,x[3],y[3],x[0],y[0]);
   diff = abs(area1 - area2);
   if(bestdiff>diff) {
     bestdiff=diff;
     best1 = area1; best2=area2;
   }

   cout<<setprecision(3)<<setiosflags(ios::fixed);
   cout<<"Cake "<<Case++<<": ";
   if(best1<best2)
     cout<<best1<<' '<<best2<<endl;
   else
     cout<<best2<<' '<<best1<<endl;
   
   for(int i=0;i<4;i++)
    cin>>x[i]>>y[i];
  }
  return 0;
}

