    #include <stdio.h>
    #include <stdlib.h> // #include<conio.h>
    #include <graphics.h>
    // #include <dos.h>
    int main() {
    	int gd = DETECT, gm = DETECT;
    	int x, y = 0, t = 400, c = 1;
    	initgraph(&gd, &gm, "");
    	setcolor(RED);
    	setlinestyle(SOLID_LINE, 0, 1); // setfillstyle(SOLID_LINE, RED);
    	for (x = 40; x < 602; x++) {
    		cleardevice();
    		circle(x, y, 30);
    		floodfill(x, y, RED);
    		delay(40);
    		if (y >= 400) {
    			c = 0;
    			t -= 20;
    		}
    		if (y <= (400 - t))
    			    c = 1;
    		y = y + (c ? 15 : -15);
    	}
    	getch();
        return 0;
    }