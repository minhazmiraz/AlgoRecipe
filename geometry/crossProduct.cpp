#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define mp(a,b) make_pair(a,b)

int crossProduct(pii p0,pii p1, pii p2)
{
    return ((p1.first - p0.first)*(p2.second - p0.second)) - ((p2.first - p0.first)*(p1.second-p0.second));
}

int main()
{
	int n = 10, d = 50;
	int x,y, a, b, p, q;
	cin>>x>>y;
	cin>>a>>b;
	cin>>p>>q;
	
	int r1  = crossProduct(mp(a,b), mp(x,y), mp(p,q));

/*
	if r1 == 0, three points are colinear
	if r1 is positive, (a,b) & (x,y) vector [or x,y point] is at right side/clockwise with respect to (a,b) & (p,q)
	if r1 is negative, (a,b) & (x,y) vector [or x,y point] is at left side /counter-clockwise with respect to (a,b) & (p,q)	
*/
	
	
return 0;	
}