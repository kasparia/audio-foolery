//
//  NeinKnob.cpp
//  NeinFilter - VST3
//
//  Created by kasparia on 03/03/2021.
//
//  Heute nicht
//

#include "NeinKnob.hpp"

using namespace juce;

//==============================================================================
NeinKnob::NeinKnob ()
{
    
    /*Rectangle <int> knobDimensions (20, 30, 90, 90);
    knobElement.setBounds(knobDimensions);

    knobElement.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    knobElement.setRange(0.0f, 1.0f, 0.01f);
    knobElement.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    knobElement.addListener(this);
    addAndMakeVisible(knobElement);

    addAndMakeVisible(knobLabel);
    knobLabel.attachToComponent(&knobLabel, false);
    knobLabel.setJustificationType(20);
    knobLabel.setText("Volume", dontSendNotification);*/
}

NeinKnob::~NeinKnob()
{
}

/*
void NeinKnob::sliderValueChanged (Slider *slider) {
    if (slider == &knobElement) {
        // audioProcessor.gainValue = gainKnob.getValue();
    }
}*/
