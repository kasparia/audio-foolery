/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace juce;

//==============================================================================
NeinFilterAudioProcessorEditor::NeinFilterAudioProcessorEditor (NeinFilterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    gainKnob.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    gainKnob.setRange(0.0f, 1.0f, 0.01f);
    gainKnob.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    gainKnob.setTextValueSuffix ("%)");
    gainKnob.addListener(this);
    addAndMakeVisible(gainKnob);

    addAndMakeVisible(gainLabel);
    gainLabel.attachToComponent(&gainKnob, false);
    gainLabel.setJustificationType(20);
    gainLabel.setText("Volume", dontSendNotification);
}

NeinFilterAudioProcessorEditor::~NeinFilterAudioProcessorEditor()
{
}

//==============================================================================
void NeinFilterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void NeinFilterAudioProcessorEditor::resized()
{
    Rectangle <int> dimensions (30, 30, 90, 90);
    gainKnob.setBounds(dimensions);
}

void NeinFilterAudioProcessorEditor::sliderValueChanged (Slider *slider) {
    if (slider == &gainKnob) {
        audioProcessor.gainValue = gainKnob.getValue();
    }
}
