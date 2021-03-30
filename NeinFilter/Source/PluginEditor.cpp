/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "PluginKnob.h"

using namespace juce;

//==============================================================================
NeinFilterAudioProcessorEditor::NeinFilterAudioProcessorEditor (NeinFilterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (guiSizeX, guiSizeY);

    /*gainKnob.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    gainKnob.setRange(0.0f, 1.0f, 0.01f);
    gainKnob.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    gainKnob.addListener(this);
    addAndMakeVisible(gainKnob);

    addAndMakeVisible(gainLabel);
    gainLabel.attachToComponent(&gainKnob, false);
    gainLabel.setJustificationType(20);
    gainLabel.setText("Volume", dontSendNotification);*/
    /*gainKnob.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    gainKnob.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(gainKnob);
    
    
    cutoffKnob.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    cutoffKnob.setRange(20.0f, 20000.0f, 1.0f);
    cutoffKnob.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    cutoffKnob.setValue(20000.0f);
    cutoffKnob.addListener(this);
    addAndMakeVisible(cutoffKnob);

    addAndMakeVisible(cutoffLabel);
    cutoffLabel.attachToComponent(&cutoffKnob, false);
    cutoffLabel.setJustificationType(20);
    cutoffLabel.setText("Cutoff", dontSendNotification);
    
    resonanceKnob.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    resonanceKnob.setRange(0.1f, 1.0f, 0.05f);
    resonanceKnob.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    resonanceKnob.setValue(0.8f);
    resonanceKnob.addListener(this);
    addAndMakeVisible(resonanceKnob);

    addAndMakeVisible(resonanceLabel);
    resonanceLabel.attachToComponent(&resonanceKnob, false);
    resonanceLabel.setJustificationType(20);
    resonanceLabel.setText("Resonance", dontSendNotification);*/
    addAndMakeVisible(pluginGUI);
}

NeinFilterAudioProcessorEditor::~NeinFilterAudioProcessorEditor()
{
}

//==============================================================================
void NeinFilterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void NeinFilterAudioProcessorEditor::resized()
{
    /*Rectangle <int> dimensionsGain (20, 30, 90, 90);
    Rectangle <int> dimensionsC (120, 30, 90, 90);
    Rectangle <int> dimensionsR (220, 30, 90, 90);
    gainKnob.setBounds(dimensionsGain);
    cutoffKnob.setBounds(dimensionsC);
    resonanceKnob.setBounds(dimensionsR);*/
    pluginGUI.setBounds(getLocalBounds());
}

void NeinFilterAudioProcessorEditor::sliderValueChanged (Slider *slider) {
    /*if (slider == &gainKnob) {
        audioProcessor.gainValue = gainKnob.getValue();
    }
    if (slider == &cutoffKnob) {
        audioProcessor.cutoffKnobValue = cutoffKnob.getValue();
    }
    if (slider == &resonanceKnob) {
        audioProcessor.resonanceKnobValue = resonanceKnob.getValue();
    }*/
}
