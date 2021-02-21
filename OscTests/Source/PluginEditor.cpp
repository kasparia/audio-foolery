/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OscTestsAudioProcessorEditor::OscTestsAudioProcessorEditor (OscTestsAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    gainSlider.setSliderStyle( juce::Slider::SliderStyle::LinearVertical );
    gainSlider.setRange(0.0f, 1.0f, 0.05f);
    gainSlider.setValue(0.1f);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
    pitchSlider.setSliderStyle( juce::Slider::SliderStyle::LinearVertical );
    pitchSlider.setRange(0.0f, 16000.0f, 2.0f);
    pitchSlider.setValue(420.0f);
    pitchSlider.addListener(this);
    addAndMakeVisible(pitchSlider);
    
    setSize (400, 300);
}

OscTestsAudioProcessorEditor::~OscTestsAudioProcessorEditor()
{
}

//==============================================================================
void OscTestsAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void OscTestsAudioProcessorEditor::resized()
{
    gainSlider.setBounds(30, 30, 100, 100);
    pitchSlider.setBounds(150, 30, 100, 100);
}

void OscTestsAudioProcessorEditor::sliderValueChanged (juce::Slider *slider) {
    if (slider == &gainSlider) {
        audioProcessor.gainValue = gainSlider.getValue();
    } else if(slider == &pitchSlider) {
        audioProcessor.oscPitchValue = pitchSlider.getValue();
    }
}
