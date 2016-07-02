/*
        Copyright 2016 Valeriy Kireev

        This file is part of VLook.

        VLook is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        VLook is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with VLook. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Audio/AudioALSA.h"


AudioALSA::AudioALSA()
  : mixName("Master"),
    card("default"),
    mixIndex(0)
{ }


long AudioALSA::getVolume() const {
    snd_mixer_t* handle;
    snd_mixer_elem_t* elem;
    snd_mixer_selem_id_t* sid;

    // Open sound card
    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, this->mixIndex);
    snd_mixer_selem_id_set_name(sid, this->mixName.c_str());

    if (snd_mixer_open(&handle, 0) < 0) {
        throw std::runtime_error("Error while mixer channel \"" + mixName + "\" opening");
    }
    if (snd_mixer_attach(handle, this->card.c_str())) {
        snd_mixer_close(handle);
        throw std::runtime_error("Error while attaching soundcard \"" + card + "\" to mixer");
    }
    if (snd_mixer_selem_register(handle, NULL, NULL) < 0) {
        snd_mixer_close(handle);
        throw std::runtime_error("Error while mixer channel registering");
    }
    if (snd_mixer_load(handle) < 0) {
        snd_mixer_close(handle);
        throw std::runtime_error("Error while loading mixer elements");
    }
    elem = snd_mixer_find_selem(handle, sid);
    if (!elem) {
        throw std::runtime_error("Error while finding mixer element");
        return -5;
    }

	// Get sound volume
	long volume, vmin, vmax;
	snd_mixer_selem_get_playback_volume_range(elem, &vmin, &vmax);
	if (snd_mixer_selem_get_playback_volume(elem, SND_MIXER_SCHN_FRONT_LEFT, &volume) < 0) {
		snd_mixer_close(handle);
        throw std::runtime_error("Error while getting playback volume");
	}
	volume -= vmin;
	vmax -= vmin;
	volume = 100 * volume / vmax;

    snd_mixer_close(handle);

	return volume;
}


void AudioALSA::setMixName(const std::string mixName) {
	this->mixName = mixName;
}


void AudioALSA::setCard(const std::string cardName) {
	this->card = cardName;
}

AudioALSA::~AudioALSA() { }
