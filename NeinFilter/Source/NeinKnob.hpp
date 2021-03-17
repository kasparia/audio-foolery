//
//  NeinKnob.hpp
//  NeinFilter - VST3
//
//  Created by kasparia on 03/03/2021.
//

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

using namespace juce;

class NeinKnob
{
public:
    NeinKnob ();
    ~NeinKnob ();

private:
    Slider knobElement;
    Label knobLabel;
};
