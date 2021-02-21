/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OscTestsAudioProcessor::OscTestsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), false)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

OscTestsAudioProcessor::~OscTestsAudioProcessor()
{
}

//==============================================================================
const juce::String OscTestsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool OscTestsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool OscTestsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool OscTestsAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double OscTestsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int OscTestsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int OscTestsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void OscTestsAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String OscTestsAudioProcessor::getProgramName (int index)
{
    return {};
}

void OscTestsAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void OscTestsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = getTotalNumOutputChannels();
    osc.prepare(spec);
    gain.prepare(spec);
    
    osc.setFrequency(420.0f);

}

void OscTestsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool OscTestsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void OscTestsAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto channelNum = totalNumInputChannels; channelNum < totalNumOutputChannels; ++channelNum) {
        buffer.clear (channelNum, 0, buffer.getNumSamples());
    }
    
    runner += 0.01f;
    fmSin = std::abs(std::sin(fmOscPitchValue + runner ) * oscPitchValue * fmAmountValue) + oscPitchValue;
    
    
    if (runner == 10000.0f) runner = 0.0f;
    
    gain.setGainLinear(gainValue);
    osc.setFrequency(fmSin);
    
    juce::dsp::AudioBlock<float> audioBlock { buffer };

    osc.process( juce::dsp::ProcessContextReplacing<float> (audioBlock) );
    gain.process( juce::dsp::ProcessContextReplacing<float> (audioBlock) );

}

//==============================================================================
bool OscTestsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* OscTestsAudioProcessor::createEditor()
{
    return new OscTestsAudioProcessorEditor (*this);
}

//==============================================================================
void OscTestsAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void OscTestsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OscTestsAudioProcessor();
}
