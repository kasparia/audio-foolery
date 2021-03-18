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
class PluginKnob : public juce::Component
{
public:
    using SliderStyle = juce::Slider::SliderStyle;

    PluginKnob ();
    ~PluginKnob();
    
    void resized() override;
    void paint(juce::Graphics&) override;
    Rectangle<int> getKnobBound();

private:
    Slider knobSlider;
    Label knobLabel;
    String knobLabelText = "Gain";
    //Rectangle<int> knobDimensions (20, 30, 90, 90);
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    //NeinFilterAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginKnob);
};
