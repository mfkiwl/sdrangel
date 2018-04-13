/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube     ---   Limitations and specifcities:       * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Stopping instance i.e. /sdrangel with DELETE method is a server only feature. It allows stopping the instance nicely.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV demodulator, Channel Analyzer, Channel Analyzer NG, LoRa demodulator, TCP source   * The content type returned is always application/json except in the following cases:     * An incorrect URL was specified: this document is returned as text/html with a status 400    --- 
 *
 * OpenAPI spec version: 4.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGSSBModSettings.h
 *
 * SSBMod
 */

#ifndef SWGSSBModSettings_H_
#define SWGSSBModSettings_H_

#include <QJsonObject>


#include "SWGCWKeyerSettings.h"
#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGSSBModSettings: public SWGObject {
public:
    SWGSSBModSettings();
    SWGSSBModSettings(QString* json);
    virtual ~SWGSSBModSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGSSBModSettings* fromJson(QString &jsonString) override;

    qint64 getInputFrequencyOffset();
    void setInputFrequencyOffset(qint64 input_frequency_offset);

    float getBandwidth();
    void setBandwidth(float bandwidth);

    float getLowCutoff();
    void setLowCutoff(float low_cutoff);

    qint32 getUsb();
    void setUsb(qint32 usb);

    float getToneFrequency();
    void setToneFrequency(float tone_frequency);

    float getVolumeFactor();
    void setVolumeFactor(float volume_factor);

    qint32 getSpanLog2();
    void setSpanLog2(qint32 span_log2);

    qint32 getAudioBinaural();
    void setAudioBinaural(qint32 audio_binaural);

    qint32 getAudioFlipChannels();
    void setAudioFlipChannels(qint32 audio_flip_channels);

    qint32 getDsb();
    void setDsb(qint32 dsb);

    qint32 getAudioMute();
    void setAudioMute(qint32 audio_mute);

    qint32 getPlayLoop();
    void setPlayLoop(qint32 play_loop);

    qint32 getAgc();
    void setAgc(qint32 agc);

    float getAgcOrder();
    void setAgcOrder(float agc_order);

    qint32 getAgcTime();
    void setAgcTime(qint32 agc_time);

    qint32 getAgcThresholdEnable();
    void setAgcThresholdEnable(qint32 agc_threshold_enable);

    qint32 getAgcThreshold();
    void setAgcThreshold(qint32 agc_threshold);

    qint32 getAgcThresholdGate();
    void setAgcThresholdGate(qint32 agc_threshold_gate);

    qint32 getAgcThresholdDelay();
    void setAgcThresholdDelay(qint32 agc_threshold_delay);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    QString* getTitle();
    void setTitle(QString* title);

    QString* getAudioDeviceName();
    void setAudioDeviceName(QString* audio_device_name);

    qint32 getModAfInput();
    void setModAfInput(qint32 mod_af_input);

    SWGCWKeyerSettings* getCwKeyer();
    void setCwKeyer(SWGCWKeyerSettings* cw_keyer);


    virtual bool isSet() override;

private:
    qint64 input_frequency_offset;
    bool m_input_frequency_offset_isSet;

    float bandwidth;
    bool m_bandwidth_isSet;

    float low_cutoff;
    bool m_low_cutoff_isSet;

    qint32 usb;
    bool m_usb_isSet;

    float tone_frequency;
    bool m_tone_frequency_isSet;

    float volume_factor;
    bool m_volume_factor_isSet;

    qint32 span_log2;
    bool m_span_log2_isSet;

    qint32 audio_binaural;
    bool m_audio_binaural_isSet;

    qint32 audio_flip_channels;
    bool m_audio_flip_channels_isSet;

    qint32 dsb;
    bool m_dsb_isSet;

    qint32 audio_mute;
    bool m_audio_mute_isSet;

    qint32 play_loop;
    bool m_play_loop_isSet;

    qint32 agc;
    bool m_agc_isSet;

    float agc_order;
    bool m_agc_order_isSet;

    qint32 agc_time;
    bool m_agc_time_isSet;

    qint32 agc_threshold_enable;
    bool m_agc_threshold_enable_isSet;

    qint32 agc_threshold;
    bool m_agc_threshold_isSet;

    qint32 agc_threshold_gate;
    bool m_agc_threshold_gate_isSet;

    qint32 agc_threshold_delay;
    bool m_agc_threshold_delay_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    QString* title;
    bool m_title_isSet;

    QString* audio_device_name;
    bool m_audio_device_name_isSet;

    qint32 mod_af_input;
    bool m_mod_af_input_isSet;

    SWGCWKeyerSettings* cw_keyer;
    bool m_cw_keyer_isSet;

};

}

#endif /* SWGSSBModSettings_H_ */
