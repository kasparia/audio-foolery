/*
  ==============================================================================

    GUIWrapper.h
    Created: 30 Mar 2021 11:30:15pm
    Author:  Kasperi

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "PluginKnob.h"

using namespace juce;

//==============================================================================
/**
*/
class GUIWrapper  : public juce::Component,
                    public juce::Slider::Listener
{
public:
    GUIWrapper ();
    ~GUIWrapper() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged (juce::Slider* slider) override;

private:
    Slider cutoffKnob;
    Slider resonanceKnob;
    
    Label gainLabel;
    Label cutoffLabel;
    Label resonanceLabel;
    
    juce::Colour pluginBackgroundColour = juce::Colour(255, 224, 153);
    
    PluginKnob pluginGain;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    //NeinFilterAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUIWrapper)
};
