// Name - Yash Dabas
// Class - CSAI-2
// Roll No.- 2021UCA1912


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
  
// typedef struct 
// {
//     int x, y;
// }boat;
struct boat
{
    int x, y;
};
  
int compareX(const void* a, const void* b)
{
    boat *p1 = (boat *)a,  *p2 = (boat *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    boat *p1 = (boat *)a,   *p2 = (boat *)b;
    return (p1->y - p2->y);
}
  
float dist(boat p1, boat p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

float bruteForce(boat P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
  
float min(float x, float y)
{
    return (x < y)? x : y;
}
  

float stripClosest(boat strip[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
  
    qsort(strip, size, sizeof(boat), compareY); 
  
    // Pick all boats one by one and try the next boats till the difference
    // between y coordinates is smaller than d.
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
  
    return min;
}
  
float closestUtil(boat P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);
  
    int mid = n/2;
    boat midboat = P[mid];

    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);
    float d = min(dl, dr);
  
    boat strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midboat.x) < d)
            strip[j] = P[i], j++;
  
    return min(d, stripClosest(strip, j, d) );
}
  
float closest(boat P[], int n)
{
    qsort(P, n, sizeof(boat), compareX);
    return closestUtil(P, n);
}

int main()
{
    boat P[] = {{2, 7}, {23, 12}, {10, 16}, {1, 5}, {12, 30}, {11, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout<<"The closest distance is "<<closest(P,n)<<endl;
    return 0;
}