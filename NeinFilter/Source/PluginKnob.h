/*
  ==============================================================================

    PluginKnob.h
    Created: 17 Mar 2021 8:03:58pm
    Author:  Kasperi

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

using namespace juce;

//==============================================================================
/**
*/
class PluginKnob
{
public:
    PluginKnob ();
    ~PluginKnob();

private:
    Slider knobSlider;
    Label knobLabel;
    String knobLabelText = "Gain";
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    //NeinFilterAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginKnob);
};
