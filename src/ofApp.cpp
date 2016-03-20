#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Load image    
    gui.setup();
    
    gui.add(wavelength.setup("wavelength", 0.125, 0.05, 0.2));
    gui.add(amplitude.setup("amplitude", 0, 0, 50));
    gui.add(noiseScale.setup("noiseScale", 0, 0, 10));
    gui.add(distortion.setup("distortion", 0, 0, 50));
    gui.add(ySpeed.setup("ySpeed", 0, 0, 10));
    
    image1.load("Sylvie_Pic.jpg");

}

//--------------------------------------------------------------
void ofApp::update(){
    
    image2 = wave(image1);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::gray);
    
    // draw image
    ofSetColor(255, 255, 255);
    image2.draw(0, 0);
    
    gui.draw();
}

//---------------------------------------------------------------
ofImage ofApp::wave(ofImage sourceImg) {
    
    // create clone image and keep current image in memory as cloned also
    ofImage newImg;
    newImg.clone(sourceImg);
    
    float time = ofGetElapsedTimef();
    
    int image1h = image1.getHeight();
    int image1w = image1.getWidth();
    
    // iterating every pixel
    for (int y=0; y<image1h; y++) {
        for (int x=0; x<image1w; x++) {
            
            // calculating wave distortion
            float noise = ofNoise(time + y * 0.001) * noiseScale; // 0.001 defines smoothness of waveform
            float noiseAmp = noise * amplitude; // scale noise value
            float waveform = sin((y * wavelength) + time * ySpeed); // classic Sin waveform
            float wave = (waveform + distortion) * noiseAmp; // distortion is shifting everything on X axis
            
            // xWave represents distorted pixel that is moved along the X axis
            int xWave = x + wave;
            
            //Set newImg pixel color (@ x,y) equal to sourceImg pixel color (@ xWave, y)
            ofColor color = sourceImg.getColor(xWave, y);
            newImg.setColor(x, y, color);
        }
    }
    
    newImg.update();
    return newImg;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
