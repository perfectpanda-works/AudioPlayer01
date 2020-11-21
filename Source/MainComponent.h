#pragma once

#include <JuceHeader.h>

class MainComponent  : public juce::AudioAppComponent,
                       public juce::ChangeListener//add
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    void changeListenerCallback(juce::ChangeBroadcaster* source) override;//add

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //add
    enum TransportState
    {
        Stopped,
        Starting,
        Playing,
        Stopping
    };

    void changeState(TransportState newState);//add
    void openButtonClicked();
    void playButtonClicked();
    void stopButtonClicked();

    juce::TextButton openButton;
    juce::TextButton playButton;
    juce::TextButton stopButton;

    juce::AudioFormatManager formatManager;
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
    juce::AudioTransportSource transportSource;
    TransportState state;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
