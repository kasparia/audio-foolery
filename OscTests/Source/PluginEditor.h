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
                                        public juce::Slider::Listener,
                                        private juce::MidiInputCallback,
                                        private juce::MidiKeyboardStateListener
{
public:
    OscTestsAudioProcessorEditor (OscTestsAudioProcessor&);
    ~OscTestsAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider* slider) override;
    void setOscPitch (const int pitch, const int midiNoteNumber);

private:
    juce::Slider gainSlider;
    juce::Slider pitchSlider;
    juce::Slider fmPitchSlider;
    juce::Slider fmAmountSlider;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OscTestsAudioProcessor& audioProcessor;
    
    
    /*    */
    juce::AudioDeviceManager deviceManager;
    juce::ComboBox midiInputList;
    juce::Label midiInputListLabel;
    int lastInputIndex = 0;
    bool isAddingFromMidiInput = false;
    juce::MidiKeyboardState keyboardState;
    juce::MidiKeyboardComponent keyboardComponent;
    /*    */
    

    // These methods handle callbacks from the midi device + on-screen keyboard..
    void handleIncomingMidiMessage (juce::MidiInput* source, const juce::MidiMessage& message) override
    {
        keyboardState.processNextMidiEvent (message);
    }

    void handleNoteOn (juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
    {
        auto midiNoteToOsc = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        audioProcessor.oscPitchValue = midiNoteToOsc;
    }

    void handleNoteOff (juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/) override
    {
        auto m = juce::MidiMessage::noteOff (midiChannel, midiNoteNumber);
    }

    

    
    
 
    juce::TextEditor midiMessagesBox;
    double startTime;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscTestsAudioProcessorEditor)
};
