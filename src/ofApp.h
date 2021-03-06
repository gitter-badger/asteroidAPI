#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxGui.h"

#define BUFFER_SIZE 8192
#define SAMPLE_RATE 44100
#define INITIAL_BUFFER_SIZE 512
#define BIT 512


struct orbit{
    
    ofPolyline path;
    ofMesh mesh;
    double inclination;
    double omega;
    
};

class ofApp : public ofBaseApp {

public:

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void audioRequested(float * output, int bufferSize, int nChannels);

    
    float line;
    
    int	maxHertz;
    int	minHertz;
    
    double sineBufferLeft[514];
    double sineBufferRight[514];
    float remainderLeft;
    float remainderRight;
    float waveLeft;
    float waveRight;
    float ampLeft[BIT];
    float ampRight[BIT];
    int hertzScaleLeft[BIT];
    int hertzScaleRight[BIT];
    float phasesLeft[BIT];
    float phasesRight[BIT];

    bool bPlaying;
    
    float getPixelLeft(int x, int y);
    float getAmpLeft(float x, float y);
    float getFreqLeft(float y);
    float getPixelRight(int x, int y);
    float getAmpRight(float x, float y);
    float getFreqRight(float y);
    
    float getAmpLeft(float x, float y, ofPixels _p);

    
    ofxJSONElement json;

    ofEasyCam cam;
    float timePlanet;
    bool fullscreen;
    
    ofSpherePrimitive sun;
    
    vector<orbit> orbits;

    float rotateZ;
    
    float movingPathFactor;
    
    ofMesh mesh;
    
    vector<float> per_y;
    
    ofFbo astroidFBO;
    float threshold;
    
    orbit earthOrbit;
    
    void drawSun();
    ofTrueTypeFont sunName;
    
    // from TextFacingCameraSample sourcecode
    void billboardBegin();
    void billboardEnd();

    vector< vector<float> > _nYPos;


    
    
    ofxPanel gui;
    ofxToggle onOffInternet;
    
    void textInformation();
    
    ofSpherePrimitive one, two;
    
    
    
};
