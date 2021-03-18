/*
  ==============================================================================

    PluginKnob.cpp
    Created: 17 Mar 2021 8:03:44pm
    Author:  Kasperi

  ==============================================================================
*/

#include "PluginKnob.h"
#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace juce;

//==============================================================================
PluginKnob::PluginKnob ()
{
    knobSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    knobSlider.setRange(0.0f, 1.0f, 0.01f);
    knobSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
}

PluginKnob::~PluginKnob()
{
}

void PluginKnob::resized()
{
    //knobSlider.setBounds(knobDimensions);

    DBG("\n\n\n\n custom resize \nn\n\n\n\n\n\n");
}

void PluginKnob::paint(Graphics& g)
{
    
    DBG("\n\n\n\n custom paint \nn\n\n\n\n\n\n");
}
