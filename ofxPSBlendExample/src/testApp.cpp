#include "testApp.h"

void testApp::setup()
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

void testApp::update()
{
    psBlend.begin();
    base.draw(0,0);
    psBlend.end();
}

void testApp::draw()
{
    psBlend.draw(target.getTextureReference(), blendMode);
    ofSetWindowTitle("blendMode: " + psBlend.getBlendMode(blendMode));
}

void testApp::keyPressed(int key)
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

void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y ){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}