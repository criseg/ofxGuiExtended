#pragma once

#include "ofxGuiElement.h"
#include "containers/ofxGuiGroup.h"
#include "containers/ofxGuiSliderGroup.h"
#include "containers/ofxGuiPanel.h"
#include "containers/ofxGuiTabs.h"
#include "controls/ofxGuiToggle.h"
#include "controls/ofxGuiSlider.h"
#include "controls/ofxGuiButton.h"
#include "controls/ofxGuiLabel.h"
#include "controls/ofxGuiValuePlotter.h"
#include "controls/ofxGuiFpsPlotter.h"
#include "controls/ofxGuiFunctionPlotter.h"
#include "controls/ofxGuiInputField.h"
#include "controls/ofxGuiGraphics.h"
#include "controls/ofxGuiZoomableGraphics.h"

#include "DOM/ofxDOM.h"

#include "view/ofxGuiDefaultConfig.h"
#include "view/ofxDOMFlexBoxLayout.h"
#include "view/ofxDOMBoxLayout.h"
#include "view/JsonConfigParser.h"

class ofxGui {
	public:
		ofxGui();
		~ofxGui();
		DOM::Document* getDocument();

		ofxGuiGroup* addGroup(const std::string& name="", const ofJson& config = ofJson());
		ofxGuiGroup* addGroup(const ofParameterGroup & parameters, const ofJson& config = ofJson());

		ofxGuiPanel* addPanel(const std::string& name="", const ofJson& config = ofJson());
		ofxGuiPanel* addPanel(const ofParameterGroup & parameters, const ofJson& config = ofJson());

		ofxGuiTabs* addTabs(const std::string& name="", const ofJson& config = ofJson());

		/// \brief Sets a config recursively for all elements of the gui
		void setConfig(const ofJson &config);

		template<typename T>
		void add(ofParameter<T>& parameter){
			if(!defaultPanel){
				defaultPanel = addPanel();
			}
			defaultPanel->add(parameter);
		}

		template<typename T, typename... Args>
		void add(ofParameter<T>& parameter, Args... args) {
			add(parameter);
			add(args...) ;
		}

	private:
		std::unique_ptr<DOM::Document> document;

		void setup();
		bool setup_done;

		ofJson rootGroupConfig(const ofJson& config = ofJson());

		ofxGuiGroup* defaultPanel = nullptr;
};

