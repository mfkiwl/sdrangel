///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
// Copyright (C) 2015-2020, 2023 Edouard Griffiths, F4EXB <f4exb06@gmail.com>    //
//                                                                               //
// Implementation of static web API adapters used for preset serialization and   //
// deserialization                                                               //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include "SWGDeviceSettings.h"
#include "audiocatsiso.h"
#include "audiocatsisowebapiadapter.h"

AudioCATSISOWebAPIAdapter::AudioCATSISOWebAPIAdapter()
{}

AudioCATSISOWebAPIAdapter::~AudioCATSISOWebAPIAdapter()
{}

int AudioCATSISOWebAPIAdapter::webapiSettingsGet(
        SWGSDRangel::SWGDeviceSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setAudioCatsisoSettings(new SWGSDRangel::SWGAudioCATSISOSettings());
    response.getAudioCatsisoSettings()->init();
    AudioCATSISO::webapiFormatDeviceSettings(response, m_settings);
    return 200;
}

int AudioCATSISOWebAPIAdapter::webapiSettingsPutPatch(
        bool force,
        const QStringList& deviceSettingsKeys,
        SWGSDRangel::SWGDeviceSettings& response, // query + response
        QString& errorMessage)
{
    (void) force; // no action
    (void) errorMessage;
    AudioCATSISO::webapiUpdateDeviceSettings(m_settings, deviceSettingsKeys, response);
    return 200;
}