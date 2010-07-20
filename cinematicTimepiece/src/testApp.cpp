#include "testApp.h"
#include "stdio.h"

//--------------------------------------------------------------
testApp::testApp(){
}


//--------------------------------------------------------------
void testApp::setup(){
	count=0;
	//ofSetDataPathRoot("./");

	ofBackground(255,255,255);
	
	char file[255];
	//sprintf(file,"movies/arc09.m4v");
	sprintf(file,"movies/1939.The.Wizard.of.Oz.350.m4v");
	yearM.loadMovie( file);
	monthM.loadMovie(  file);
	dayM.loadMovie(  file);
	hourM.loadMovie(file);
	minuteM.loadMovie(  file);
	
	font.loadFont("HelveticaNeue.ttc", 12);
	
	
	//sync milliseconds to clock's second tick
	int s = ofGetSeconds();
	while(s == ofGetSeconds());
	millisoff = ofGetElapsedTimeMillis();
	
	//ofSetFrameRate(15);
	ofEnableSmoothing();
}

//--------------------------------------------------------------
void testApp::update(){
	
	//no idle Movie because we are setting movie positions frame by frame
	/*
	 yearM.idleMovie();
	 monthM.idleMovie();
	 dayM.idleMovie();
	 hourM.idleMovie();
	 minuteM.idleMovie();
	 secondM.idleMovie();
	 */
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(0,0,0);
	ofSetColor(255,255,255);
	
	float movieSize=.5;
	int mwidth=320*movieSize;
	int mheight=240*movieSize;
	
	int xspacing=ofGetWidth()/5.0;
	int yspacing=(ofGetHeight()-mheight)/2.0;
	
	int xpos=(ofGetWidth()-xspacing*4-mwidth)/2.0;
	
	//normalize time increments
	float minute=(ofGetSeconds() + ((ofGetElapsedTimeMillis()- millisoff) % 1000) / 1000.0f) / 60.0f;
	float hour=(ofGetMinutes() + minute)/60.0f;
	float day=(ofGetHours()+ hour)/24.0f;
	float month=(ofGetDay()+day)/31.0f;
	float year=(ofGetMonth()+month)/12.0f;

	if(ofGetElapsedTimeMillis()%5000<25)
	{
	//set the movie position 0.0-1.0
		yearM.setPosition( year );	
		monthM.setPosition( month );
	}
	
	if(ofGetElapsedTimeMillis()%1000<25)dayM.setPosition(day);

	hourM.setPosition( hour );
	minuteM.setPosition( minute );

	//draw the movie frame
	yearM.draw(xpos,yspacing,mwidth,mheight);
	monthM.draw(xpos+xspacing,yspacing,mwidth,mheight);
	dayM.draw(xpos+xspacing*2,yspacing,mwidth,mheight);
	hourM.draw( xpos+xspacing*3,yspacing,mwidth,mheight);
	minuteM.draw(xpos+xspacing*4,yspacing,mwidth,mheight);

	
	//draw text
	float sw;
	float sh;
	char tempstr[255];
	
	/*
	sprintf(tempstr,"%i/12",ofGetMonth() );
	ofSetColor(122, 122, 122);
	sw=font.stringWidth(tempstr);
	sh=font.stringHeight(tempstr);
	font.drawString(tempstr, xpos+mwidth/2.0-sw/2.0, yspacing+mheight+sh+10);
	
	sprintf(tempstr,"%i/31",ofGetDay() );
	sw=font.stringWidth(tempstr);
	sh=font.stringHeight(tempstr);
	font.drawString(tempstr, xpos+xspacing+mwidth/2.0-sw/2.0, yspacing+mheight+sh+10);
	
	sprintf(tempstr,"%i/24",ofGetHours() );
	sw=font.stringWidth(tempstr);
	sh=font.stringHeight(tempstr);
	font.drawString(tempstr, xpos+xspacing*2+mwidth/2.0-sw/2.0, yspacing+mheight+sh+10);
	
	sprintf(tempstr,"%i/60",ofGetMinutes() );
	sw=font.stringWidth(tempstr);
	sh=font.stringHeight(tempstr);
	font.drawString(tempstr, xpos+xspacing*3+mwidth/2.0-sw/2.0, yspacing+mheight+sh+10);
	
	sprintf(tempstr,"%i/60",ofGetSeconds() );
	sw=font.stringWidth(tempstr);
	sh=font.stringHeight(tempstr);
	font.drawString(tempstr, xpos+xspacing*4+mwidth/2.0-sw/2.0, yspacing+mheight+sh+10);
	*/
	
	
	drawClock(6,year,xpos+mwidth/2.0, yspacing+mheight+10);
	drawClock(6,month,xpos+xspacing+mwidth/2.0, yspacing+mheight+10);
	drawClock(6,day,xpos+xspacing*2+mwidth/2.0, yspacing+mheight+10);
	drawClock(6,hour,xpos+xspacing*3+mwidth/2.0, yspacing+mheight+10);
	drawClock(6,minute,xpos+xspacing*4+mwidth/2.0, yspacing+mheight+10);



	
	
//	char temp[255];
//	sprintf(temp,"%.4d.png",count);
//	ofSaveScreen(temp);
//	
//	count++;
//	if(ofGetElapsedTimeMillis()>15000){
//		exit();
//	}
}

void testApp::drawClock(float r, float n, float x, float y){
	ofPushMatrix();
	ofTranslate(x,y);
	ofSetColor(60,60,60);

	ofCircle(0,0,r);
	
	ofSetColor(0,0,0);
	ofLine(0,0,r*cos(n*TWO_PI-PI/2.0),r*sin(n*TWO_PI-PI/2.0));
	
	ofPopMatrix();
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}
