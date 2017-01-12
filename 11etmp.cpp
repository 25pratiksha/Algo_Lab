#include<bits/stdc++.h>
using namespace std;

//http://stackoverflow.com/questions/11716268/point-in-polygon-algorithm
#define INF 10000
struct Point
{
    float x,y;
};

Point p0;

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}
 
// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(Point polygon[], int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;
 
    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);
            if (orientation(polygon[next], p, extreme) != 0)
            {
                count++;   
            }
            
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}

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
void convexHull(Point points[], int n)
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
   if (m < 3) return;
 
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
   while (!S.empty())
   {
       Point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}

int main() {

    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        Point pin;
        int n;
        cin>>n;
        float x,y;
        Point pol[n];
        int arr[90602][2],k=0;
        bool visit[601][601]={0};
        float minx=301,miny=302,maxx=-302,maxy=-302;
        for(int i=0;i<n;i++)
        {
         cin>>x>>y;
         pol[i].x=x;
         pol[i].y=y;


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
         if(ceil(pol[i].x)==pol[i].x && ceil(pol[i].y)==pol[i].y)
         {
             if(x<0)
             {
                 x=x+300;
             }
             if(y<0)
             {
                 y=y+300;
             }
             visit[(int)x][(int)y]=1;
             arr[k][0]=pol[i].x;
             arr[k][1]=pol[i].y;
             k++;
         }


        }

        //cout<<"x "<<minx<<" "<<maxx<<" "<<miny<<" "<<maxy<<"\n";
        for(int i=minx;i<=maxx+1;i++)
        {
            for(int j=miny;j<=maxy+1;j++)
            {
                int h=i;
                if(h<0)
                h=h+300;

                int v=j;
                if(v<0)
                v=v+300;



                cout<<"ij "<<i<<j<<"\n";
                Point parr;
                parr.x=i;
                parr.y=j;
                if(visit[h][v]==0 && isInside(pol,n,parr))
                {

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

        Point poly[90602];
        for(int i=0;i<k;i++)
        {
           // cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
           poly[i].x=arr[i][0];
           poly[i].y=arr[i][1];

        }

        convexHull(poly, k);







    }

    return 0;
}
