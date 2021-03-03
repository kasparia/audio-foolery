//
//  FilterKnob.hpp
//  NeinFilter
//
//  Created by kasparia on 24/02/2021.
//
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

using namespace juce;

//==============================================================================
/**
*/
class FilterKnob  : public juce::AudioProcessorEditor,
                    public juce::Slider::Listener
{
public:
    NeinFilterAudioProcessorEditor (NeinFilterAudioProcessor&);
    ~NeinFilterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged (juce::Slider* slider) override;

private:
    Slider knobSlider;
    
    Label knobLabel;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NeinFilterAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NeinFilterAudioProcessorEditor)
};
