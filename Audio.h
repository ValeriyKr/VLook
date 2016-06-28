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

#ifndef VLOOK_AUDIO_H
#define VLOOK_AUDIO_H

#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <alsa/asoundlib.h>

class Audio {
public:
	Audio();
	long getVolume();
	void setMixName(std::string mixName);
	void setCard(std::string cardName);

private:
	std::string mixName;
	std::string card;
	unsigned int mixIndex;
};


#endif //VLOOK_AUDIO_H
