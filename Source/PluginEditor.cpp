/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), m_audio_processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    // these define the parameters of our slider object
    m_frequency_slider.setSliderStyle(juce::Slider::LinearHorizontal);
    m_frequency_slider.setRange(0,1);
    m_frequency_slider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    m_frequency_slider.setPopupDisplayEnabled(true, false, this);
    m_frequency_slider.setTextValueSuffix(" Volume");
    m_frequency_slider.setValue(m_audio_processor.m_normalized_frequency);
    addAndMakeVisible(m_frequency_slider);
    m_frequency_slider.setBounds(50, 50, 330,30);
    m_frequency_slider.addListener(this);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
//void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
//{
//    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
//
//    g.setColour (juce::Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
//
//    
//}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider *slider) {
    m_audio_processor.m_normalized_frequency = slider->getValue();
    //m_audio_processor.m_frequency_param->setValue(slider->getValue());
}