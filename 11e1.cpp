#include<bits/stdc++.h>
using namespace std;
//code for convex hull taken from http://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/
//code for AngleTest taken from http://www.realtimerendering.com/resources/GraphicsGems//gemsiv/ptpoly_haines/ptinpoly.c
//http://stackoverflow.com/questions/11716268/point-in-polygon-algorithm
#define INF 10000
#define X 0
#define Y 1
#define M_PI 3.14159265358979323846
double pgon[301][2];
struct Point
{
    double x,y;
};

Point p0;

int AngleTest(int numverts, double point[2])
{
   double *vtx0, *vtx1, angle, len, vec0[2], vec1[2], vec_dot;
   int  j;
  int inside_flag;

  /* sum the angles and see if answer mod 2*PI > PI */
  vtx0 = pgon[numverts - 1];
  vec0[X] = vtx0[X] - point[X];
  vec0[Y] = vtx0[Y] - point[Y];
  len = sqrt(vec0[X] * vec0[X] + vec0[Y] * vec0[Y]);
  if (len <= 0.0) {
    /* point and vertex coincide */
    return(1);
  }
  vec0[X] /= len;
  vec0[Y] /= len;

  angle = 0.0;
  for (j = 0; j < numverts; j++) {
    vtx1 = pgon[j];
    vec1[X] = vtx1[X] - point[X];
    vec1[Y] = vtx1[Y] - point[Y];
    len = sqrt(vec1[X] * vec1[X] + vec1[Y] * vec1[Y]);
    if (len <= 0.0) {
      /* point and vertex coincide */
      return(1);
    }
    vec1[X] /= len;
    vec1[Y] /= len;

    /* check if vec1 is to "left" or "right" of vec0 */
    vec_dot = vec0[X] * vec1[X] + vec0[Y] * vec1[Y];
    if (vec_dot < -1.0) {
      /* point is on edge, so always add 180 degrees.  always
      * adding is not necessarily the right answer for
      * concave polygons and subtractive triangles.
      */
      angle += M_PI;
    }
    else if (vec_dot < 1.0) {
      if (vec0[X] * vec1[Y] - vec1[X] * vec0[Y] >= 0.0) {
        /* add angle due to dot product of vectors */
        angle += acos(vec_dot);
      }
      else {
        /* subtract angle due to dot product of vectors */
        angle -= acos(vec_dot);
      }
    } /* if vec_dot >= 1.0, angle does not change */

      /* get to next point */
    vtx0 = vtx1;
    vec0[X] = vec1[X];
    vec0[Y] = vec1[Y];
  }
  /* test if between PI and 3*PI, 5*PI and 7*PI, etc */
  inside_flag = fmod(fabs(angle) + M_PI, 4.0*M_PI) > 2.0*M_PI;

  return(inside_flag);
}


int pnpoly(int nvert, struct Point vert[], struct Point test)
{
  int i, j;
    double c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((vert[i].y>test.y) != (vert[j].y>test.y)) &&
     (test.x < (vert[j].x-vert[i].x) * (test.y-vert[i].y) / (vert[j].y-vert[i].y) + vert[i].x) )
       c = !c;
  }
  return c;
}


 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.

// A globle point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()

 
// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
// A utility function to swap two points
int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// A utility function to return square of distance
// between p1 and p2
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}


// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
// Prints convex hull of a set of n points.
int convexHull(Point points[], int n)
{
   // Find the bottommost point
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     // Pick the bottom-most or chose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Place the bottom-most point at first position
   swap(points[0], points[min]);
 
   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted ouput if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++;  // Update size of modified array
   }
 
   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return 1;
 
   // Create an empty stack and push first three points
   // to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
   // Now stack has the output points, print contents of stack
   cout<<S.size()<<"\n";
   while (!S.empty())
   {
       Point p = S.top();
       cout <<p.x << " " << p.y << endl;
       S.pop();
   }
   return 0;
}

int main() {

    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        Point pin;
        int n;
        cin>>n;
        for(int i=0;i<=301;i++)
        {
            
               pgon[i][0]=0;
               pgon[i][1]=0;
            
        }
        double x,y;
        Point pol[n];
        int arr[90602][2],k=0;
       // bool visit[601][601]={0};
        double minx=301,miny=302,maxx=-302,maxy=-302;
        for(int i=0;i<n;i++)
        {
         cin>>x>>y;
         pol[i].x=x;
         pol[i].y=y;
         pgon[i][0]=x;
         pgon[i][1]=y;


         if(minx > pol[i].x)
         {
             minx=pol[i].x;

         }
         if(miny>pol[i].y)
         {
             miny=pol[i].y;

         }
         if(maxx<pol[i].x)
         {
             maxx=pol[i].x;

         }
         if(maxy<pol[i].y)
         {
             maxy=pol[i].y;

         }
        /* if((pol[i].x - (int)pol[i].x)==0 && (pol[i].y - (int)pol[i].y)==0)
         {
             cout<<"here:"<<i<<"\n";
             arr[k][0]=pol[i].x;
             arr[k][1]=pol[i].y;
             k++;
         }*/
         /*if(ceil(pol[i].x)==pol[i].x && ceil(pol[i].y)==pol[i].y)
         {
             
             visit[(int)x][(int)y]=1;
             arr[k][0]=pol[i].x;
             arr[k][1]=pol[i].y;
             k++;
         }*/


        }

        //cout<<"x "<<minx<<" "<<maxx<<" "<<miny<<" "<<maxy<<"\n";
        k=0;
        for(int i=ceil(minx);i<=floor(maxx);i++)
        {
            for(int j=ceil(miny);j<=floor(maxy);j++)
            {
                double pt[2];
                pt[0]=i;
                pt[1]=j;
                Point parr;
                parr.x=i;
                parr.y=j;
                if(pnpoly(n,pol,parr)||AngleTest(n, pt) )
                {
                    //cout<<"ij "<<i<<j<<"\n";
                    arr[k][0]=i;
                    arr[k][1]=j;
                    k++;
                }
            }
        }
        cout<<"Case #"<<i1<<": \n";

        if(k==0)
        {
            cout<<k<<"\n";
            continue;
        }
        if(k==1)
        {
            cout<<k<<"\n";
            cout<<arr[0][0]<<" "<<arr[0][1]<<"\n";
            continue;
        }
        if(k==2)
        {
            cout<<k<<"\n";
            cout<<arr[0][0]<<" "<<arr[0][1]<<"\n";
            cout<<arr[1][0]<<" "<<arr[1][1]<<"\n";
            continue;
        }
        
        
        Point poly[90999];
        for(int i=0;i<k;i++)
        {
           // cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
           poly[i].x=arr[i][0];
           poly[i].y=arr[i][1];

        }

        
        if (convexHull(poly, k))
      {
          ///to handle m<3 (printing min of x and y from poly)
        int minx=306,miny=306,maxx=-306,maxy=-306;
        for (int i = 0; i < k; i++)
        {
          if (minx>poly[i].x)
            {
              minx=poly[i].x; 
            }
          if (miny>poly[i].y)
            {
              miny=poly[i].y; 
            }
          if (maxx<poly[i].x)
          {
            maxx=poly[i].x;
          }
          if (maxy<poly[i].y)
          {
            maxy=poly[i].y; 
          }
        }
        cout<<"2"<<endl;
        cout<<minx<<" "<<miny<<endl;
        cout<<maxx<<" "<<maxy<<endl;
      }
    }

    return 0;
}
