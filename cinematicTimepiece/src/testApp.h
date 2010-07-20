#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
class testApp : public ofBaseApp{
	
public:
	
	testApp();
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	
	ofVideoPlayer yearM;
	ofVideoPlayer monthM;
	ofVideoPlayer dayM;
	ofVideoPlayer hourM;
	ofVideoPlayer minuteM;
	
	int millisoff;
	int count;

	ofTrueTypeFont font;

	void drawClock(float r, float n, float x, float y);
		

};

#endif
