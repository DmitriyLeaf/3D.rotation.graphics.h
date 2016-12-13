#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

class Figur {
	public:
		double coordXY[100][100];
		int x = 200, y = 100, radX = 100,  radY = 30, height = 200, width = 0, anglA = 210, anglB = 330;
		double PI = 3.141592653589;
		
		void init(int fi) {
			for (int i = 0; i < 6; i++) {
				if (fi + i * 60 >= 360) fi -= 360;
				coordXY[i][0] = x + radX * cos((fi + i * 60) * PI / 180);
				coordXY[i][1] = y + radY * sin((fi + i * 60) * PI / 180);
				coordXY[i][2] = fi + i * 60;
				//cout << coordXY[i][0] << " " << coordXY[i][1] << " " << coordXY[i][2] << endl;
			}
			coordXY[6][0] = coordXY[0][0];
			coordXY[6][1] = coordXY[0][1];
		}
		void drawLine() {
			//ellipse(x, y, 0, 360, wigth, len);
			//ellipse(x, y + height, 0, 360, wigth, len);
			
			for (int i = 0; i < 6; i++) {
				if (coordXY[i][2] > anglA && coordXY[i][2] < anglB) setcolor(8);
				else setcolor(15);
				line ((int)coordXY[i][0], (int)coordXY[i][1], (int)coordXY[i][0] + width, (int)coordXY[i][1] + height);
				setcolor(15);
				
				line((int)coordXY[i][0], (int)coordXY[i][1], (int)coordXY[i + 1][0], (int)coordXY[i + 1][1]);
					
				if (coordXY[i][2] > anglA - 60 && coordXY[i][2] < anglB) setcolor(8);
				else setcolor(15);
				line((int)coordXY[i][0] + width, (int)coordXY[i][1] + height, (int)coordXY[i + 1][0] + width, (int)coordXY[i + 1][1] + height);
				setcolor(15);
			}
		}
		void drawFill() {
			for (int i = 0; i < 6; i++) {
				if (coordXY[i][2] > anglA - 60 && coordXY[i][2] < anglB) continue;
				else {
					int poly[10] = {coordXY[i][0], coordXY[i][1], coordXY[i + 1][0], coordXY[i + 1][1],
									coordXY[i + 1][0] + width, coordXY[i + 1][1] + height,
									coordXY[i][0] + width, coordXY[i][1] + height, coordXY[i][0], coordXY[i][1]};
					
					setcolor(i);
					fillpoly(5, poly);
					floodfill((coordXY[i][0] + coordXY[i + 1][0]) / 2, (coordXY[i][1] + coordXY[i][1] + height) / 2, i);
					}
				setcolor(15);
			}
			int poly[14] = {coordXY[0][0], coordXY[0][1], coordXY[1][0], coordXY[1][1], 
							coordXY[2][0], coordXY[2][1], coordXY[3][0], coordXY[3][1],
							coordXY[4][0], coordXY[4][1], coordXY[5][0], coordXY[5][1],
							coordXY[0][0], coordXY[0][1]};
			setcolor(6);
			fillpoly(7,poly);
			setcolor(15);
		}
		void rotation(string type) {
			for (int i = 0; i <= 360 ; i++) {
				cleardevice();
				init(i);
				if (type == "line") drawLine();
				else if (type == "fill") drawFill();
				Sleep(30);
			}
		}
		Figur (): x(200), y(100), radX(100), height(200), radY(30), width(0), anglA(210), anglB(330) {}
		Figur (int x, int y, 
			   int radX, int radY, 
			   int height, int width, 
			   int anglF, int anglS) : x(x), y(y), 
			   						   radX(radX), radY(radY), 
									   height(height), width(width),
									   anglA(anglF), anglB(anglS) {}
};


int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	Figur y;
	y.init(0);
	y.drawLine();
	
	Figur x(100, 200, 30, 100, 0, 200, 120, 240);
	x.init(0);
	
	Figur z(200, 200, 100, 100, 140, 140, 165, 285);
	z.init(0);
	
	Figur fill;
	fill.init(0);
	
	while (true){
		char comand = getch();
		if (comand == '1') y.rotation("line");
		else if (comand == '2') x.rotation("line");
		else if (comand == '3') z.rotation("line");
		else if (comand == '4') fill.rotation("fill");
		else if (comand == '6') break;
	}
	
	//system ("PAUSE");
	closegraph();
	return 0;
}
