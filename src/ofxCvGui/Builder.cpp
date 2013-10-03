#include "ofxCvGui/Builder.h"

#define MAKE_PANEL_AND_RETURN auto newPanel = this->makePanel(asset, caption); PanelPtr panel(newPanel); controller.add(panel); return newPanel;
#define LABEL_PANEL_AND_RETURN newPanel->setCaption(caption); return newPanel;
namespace ofxCvGui {
	//----------
	void Builder::init() {
		PanelGroupPtr rootGroup( new Panels::Groups::Grid() );
		controller.init(rootGroup);
	}
	
#pragma mark add
	//----------
	void Builder::add(PanelPtr panel) {
		controller.add(panel);
	}

	//----------
	ofPtr<Panels::Draws> Builder::add(ofBaseDraws& asset, string caption) {
		MAKE_PANEL_AND_RETURN
	}

	//----------
	ofPtr<Panels::Image> Builder::add(ofImage& asset, string caption) {
		MAKE_PANEL_AND_RETURN
	}
	
    //----------
	ofPtr<Panels::Pixels> Builder::add(const ofPixels& asset, string caption) {
		MAKE_PANEL_AND_RETURN
	}

	//----------
	ofPtr<Panels::PixelsVector> Builder::add(const vector<ofPixels>& asset, string caption) {
		MAKE_PANEL_AND_RETURN
	}

	//----------
	ofPtr<Panels::Node> Builder::add(ofNode & asset, string caption) {
		MAKE_PANEL_AND_RETURN
	}
    
	//----------
	ofPtr<Panels::Base> Builder::addBlank(string caption) {
		auto newPanel = this->makeBlank();
		auto panel = PanelPtr(newPanel);
		this->controller.add(panel);
		return newPanel;
	}

	//----------
	ofPtr<Panels::Instructions> Builder::addInstructions() {
		auto newPanel = this->makeInstructionsPanel();
		auto panel = PanelPtr(newPanel);
		this->controller.add(panel);
		return newPanel;
	}

	//----------
	ofPtr<Panels::Groups::Grid> Builder::addGrid() {
		auto newPanel = this->makeGrid();
		auto panel = PanelPtr(newPanel);
		this->controller.add(panel);
		return newPanel;
	}

#pragma mark make
	//----------
	ofPtr<Panels::Draws> Builder::makePanel(ofBaseDraws& asset, string caption) {
		auto newPanel = ofPtr<Panels::Draws> ( new Panels::Draws(asset) );
		LABEL_PANEL_AND_RETURN
	}

	//----------
	ofPtr<Panels::Image> Builder::makePanel(ofImage& asset, string caption) {
		auto newPanel = ofPtr<Panels::Image> ( new Panels::Image(asset) );
		LABEL_PANEL_AND_RETURN
	}

	//----------
	ofPtr<Panels::Pixels> Builder::makePanel(const ofPixels& asset, string caption) {
		auto newPanel = ofPtr<Panels::Pixels> ( new Panels::Pixels(asset) );
		LABEL_PANEL_AND_RETURN
	}

	//----------
	ofPtr<Panels::PixelsVector> Builder::makePanel(const vector<ofPixels>& asset, string caption) {
		auto newPanel = ofPtr<Panels::PixelsVector> (new Panels::PixelsVector(asset) );
		LABEL_PANEL_AND_RETURN
	}

	//----------
	ofPtr<Panels::Node> Builder::makePanel(ofNode & asset, string caption) {
		auto newPanel = ofPtr<Panels::Node> ( new Panels::Node(asset) );
		LABEL_PANEL_AND_RETURN
	}

	//----------
	ofPtr<Panels::Instructions> Builder::makeInstructionsPanel() {
		return ofPtr<Panels::Instructions>( new Panels::Instructions() );
	}

	//----------
	ofPtr<Panels::Groups::Grid> Builder::makeGrid() {
		return ofPtr<Panels::Groups::Grid>( new Panels::Groups::Grid() );
	}

	//----------
	ofPtr<Panels::Base> Builder::makeBlank() {
		return ofPtr<Panels::Base>( new Panels::Base() );
	}

	//----------
	void Builder::drop(PanelPtr &panel) {
		controller.drop(panel);
	}

	//----------
	void Builder::clear() {
		controller.clear();
	}
}