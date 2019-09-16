#pragma comment(linker, "/STACK:6677721600")
#include <windows.h>
#include "Calc.hpp"
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <iterator>
#include "Parser.hpp"
#include <ctime>

#define RADIUS 60

class VECTOR {
public:
	VECTOR() = default;
	VECTOR(int x, int y) {
		this->x = x;
		this->y = y;
	}
	friend const VECTOR operator*(const VECTOR left, const int right);
	friend const VECTOR operator*(const int left, const VECTOR right);
	friend const VECTOR operator+(const VECTOR left, const VECTOR right);
	int x;
	int y;
};

HDC hDC;

void ReallySimpleCircle(HDC hdc, LONG radius, POINT ptCenter, COLORREF crColor);



//void set_not() {
//	std::set_difference(universal_set.begin(), universal_set.end(), A.begin(), A.end(), std::inserter(A, A.begin()));
//}



//POINT* intersect(POINT one, POINT two, int radius) {
//	float d = sqrt(pow(two.x - one.x, 2) + pow(two.y - one.y, 2));
//	float a = pow(d, 2) / (2 * d);
//	float h = sqrt(pow(radius, 2) - pow(a, 2));
//	VECTOR P2(one.x + (a / d) * (two.x - one.x), one.y +(a / d) * (two.y - one.y));
//	POINT three;
//	three.x = P2.x - h * (two.y - one.y) / d; 
//	three.y = P2.y + h * (two.x - one.x) / d;
//	POINT four;
//	four.x = P2.x + h * (two.y - one.y) / d;
//	four.y = P2.y - h * (two.x - one.x) / d;
//	POINT* temp = (POINT*)malloc(sizeof(POINT) * 2);
//	temp[0] = three;
//	temp[1] = four;
//	return temp;
//}
//
//int graph_intersect(int x, int y, POINT circle, int radius) {
//	int dx = circle.x - x;
//	int dy = circle.y - y;
//	if (pow(dx, 2) + pow(dy, 2) <= pow(radius, 2))
//		return TRUE;
//	return FALSE;
//}
//
//
//void Fill(int x, int y, POINT circle1, POINT circle2) {
//	SetPixel(hDC, x, y, 80000);
//	if (graph_intersect(x, y, circle1, 60)&&graph_intersect(x,y, circle2, 60)) {
//		Fill(x + 1, y, circle1, circle2);
//		Fill(x - 1, y, circle1, circle2);
//		Fill(x, y + 1, circle1, circle2);
//		Fill(x, y - 1, circle1, circle2);
//	}
//}
//
//
//void circles(int count, HDC hdc) {
//	POINT base_point;
//	base_point.x = 200;
//	base_point.y = 200;  
//	std::vector<POINT> circles;
//	POINT* temp = (POINT*)malloc(sizeof(POINT));
//	for (int i = 0; i < count; i++) {
//		base_point.x += 50;
//		temp->x = base_point.x;
//		temp->y = base_point.y;
//		circles.push_back(*temp);
//		ReallySimpleCircle(hdc, 60, *temp, 8000);
//	}
//	POINT *m = intersect(circles[0], circles[1], 60);
//	ReallySimpleCircle(hdc, 60, m[0], 80000);
//	ReallySimpleCircle(hdc, 60, m[1], 80000);
//	POINT* t = intersect(m[0], m[1], 60);
//	Fill(t[0].x, t[0].y, m[0], m[1]);
//}
//
//
//const VECTOR operator*(const VECTOR left, const int right){
//	return VECTOR(left.x*right, left.y*right);
//}
//
//const VECTOR operator*(const int left, const VECTOR right){
//	return VECTOR(right.x*left, right.y*left);
//}
//
//const VECTOR operator+(const VECTOR left, const VECTOR right)
//{
//	return VECTOR(left.x+right.x, left.y+right.y);
//}
//
//
//
//void ReallySimpleCircle(HDC hdc, LONG radius, POINT ptCenter, COLORREF crColor)
//{
//	LONG    cx = 0, cy;
//	double  xLimit = sqrt((double)(radius * radius) / 2);
//
//	while (cx++ <= xLimit)
//	{
//		cy = (LONG)floor(sqrt(radius * radius - cx * cx));
//		SetPixel(hdc, cx + ptCenter.x, cy + ptCenter.y, crColor);      // 45-90    degrees
//		SetPixel(hdc, cx + ptCenter.x, -cy + ptCenter.y, crColor);     // 270-315  degrees
//		SetPixel(hdc, -cx + ptCenter.x, cy + ptCenter.y, crColor);     // 90-135   degrees
//		SetPixel(hdc, -cx + ptCenter.x, -cy + ptCenter.y, crColor);    // 225-270  degrees
//		SetPixel(hdc, cy + ptCenter.x, cx + ptCenter.y, crColor);      // 0-45     degrees
//		SetPixel(hdc, cy + ptCenter.x, -cx + ptCenter.y, crColor);     // 315-360  degrees
//		SetPixel(hdc, -cy + ptCenter.x, cx + ptCenter.y, crColor);     // 135-180  degrees
//		SetPixel(hdc, -cy + ptCenter.x, -cx + ptCenter.y, crColor);    // 180-225  degrees
//	}
//}

int main(){
	/*srand(time(0));
	HWND hWnd = GetConsoleWindow();
	hDC = GetDC(hWnd);
	circles(2, hDC);*/
	// ѕолучаем размер клиентской области окна
	//RECT rc;
	//GetClientRect(hWnd, &rc);

	std::string input;
	std::cin >> input;
	Calc *calc = new Calc(input);
	Parser parser(input, *calc);
	auto x = parser.execute();
	return 0;
}