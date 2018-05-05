#include <bits/stdc++.h>
using namespace std;
const double R = 6371009;
const double pi = 4 * atan(1.0);

struct Point {
	double x, y, z;
} p[2];

Point getPoint(double a, double b) {

	double z = R * sin(a);
	double t = R * cos(a);

	double x = t * cos(b);
	double y = t * sin(b);
	return (Point) {
		x, y, z
	};
}

double distant(Point a, Point b) {
	double x = a.x - b.x;
	double y = a.y - b.y;
	double z = a.z - b.z;
	return sqrt(x * x + y * y + z * z);
}

int main () {
	int cas;
	cin>>cas;
	while (cas--) {

		double a, b;
		for (int i = 0; i < 2; i++) {
			cin>>a>>b;
			p[i] = getPoint(a / 180 * pi, b / 180 * pi);
		}
		double D = distant(p[0], p[1]);//÷±œﬂæ‡¿Î 
        double tha = 2 * asin(D / (2 * R));  
        double L = R * tha;//«Ú√Êæ‡¿Î 
		cout<<(int)(L-D+0.5)<<endl;  
	}
	return 0;
}
