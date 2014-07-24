#include "ofApp.h"

void ofApp::setup()
{
    base.loadImage("imgs/base.jpeg");
    target.loadImage("imgs/target.jpeg");
    target.resize(target.getWidth()/2, target.getHeight()/2);
    
    ofSetWindowShape(target.getWidth(), target.getHeight());
    base.crop(base.getWidth()/2 - target.getWidth()/2, 0,
              target.getWidth(), target.getHeight());
    
    psBlend.setup(target.getWidth(), target.getHeight());
    blendMode = 0;
}

void ofApp::update()
{
    psBlend.begin();
    base.draw(0,0);
    psBlend.end();
}

void ofApp::draw()
{
    psBlend.draw(target.getTextureReference(), blendMode);
    ofSetWindowTitle("blendMode: " + psBlend.getBlendMode(blendMode));
    ofDrawBitmapString("press UP/DOWN key", 10, 20);
}

void ofApp::keyPressed(int key)
{
    if (key == OF_KEY_UP)
    {
        if (blendMode >= 24)
        {
            blendMode = 0;
        }
        else {
            blendMode++;
        }
    }
    if (key == OF_KEY_DOWN)
    {
        if (blendMode <= 0)
        {
            blendMode = 24;
        }
        else
        {
            blendMode--;
        }
    }
    if (key == ' ')
    {
        ofSaveFrame();
    }
}

void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}