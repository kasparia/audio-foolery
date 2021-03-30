/*
  ==============================================================================

    GUIWrapper.cpp
    Created: 30 Mar 2021 11:30:15pm
    Author:  Kasperi

  ==============================================================================
*/

#include "GUIWrapper.h"

using namespace juce;

//==============================================================================
GUIWrapper::GUIWrapper ()
{
    //pluginGain.addListener(this);
    //pluginGain.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    addAndMakeVisible(pluginGain);
}

GUIWrapper::~GUIWrapper()
{
}

//==============================================================================
void GUIWrapper::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (pluginBackgroundColour);
}

void GUIWrapper::resized()
{
    Rectangle <int> dimensionsGain (20, 30, 90, 90);
    pluginGain.setBounds(dimensionsGain);
}

void GUIWrapper::sliderValueChanged (Slider *slider) {
}
