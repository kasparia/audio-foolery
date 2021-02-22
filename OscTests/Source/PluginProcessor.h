/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class OscTestsAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    OscTestsAudioProcessor();
    ~OscTestsAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    float gainValue = 0.1f;
    float oscPitchValue = 420.0f;
    float fmOscPitchValue = 0.0f;
    float fmSin = 0.0f;
    float fmAmountValue = 0.0f;
    float runner = 0.0f;
    
    juce::dsp::Oscillator<float> osc {
        [](float sinX) {
            return std::sin(sinX);
        }
    };
    
    int lastPitch { 0 };
    int lastMidiNote { 0 };

private:
    juce::Slider pitchSlider;
    juce::dsp::Gain<float> gain;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscTestsAudioProcessor)
};
