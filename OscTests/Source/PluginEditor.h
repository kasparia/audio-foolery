/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class OscTestsAudioProcessorEditor  :   public juce::AudioProcessorEditor,
                                        public juce::Slider::Listener
{
public:
    OscTestsAudioProcessorEditor (OscTestsAudioProcessor&);
    ~OscTestsAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider* slider) override;

private:
    juce::Slider gainSlider;
    juce::Slider pitchSlider;
    juce::Slider fmPitchSlider;
    juce::Slider fmAmountSlider;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OscTestsAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscTestsAudioProcessorEditor)
};
