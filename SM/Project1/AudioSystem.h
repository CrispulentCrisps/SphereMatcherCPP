#pragma once
#include <SDL_audio.h>
#include <string>
#include <list>
#include "Scene.h"

using namespace std;

class AudioSystem
{
public:
	//variables
	const int AUDIO_RATE = 480000;
	const int NO_AUDIO = 0;
	const int MONO = 1;
	const int STEREO = 2;

	SDL_AudioDeviceID* device;
	Uint8* AudioBuffer;

	//structs
	struct Audio
	{
		SDL_AudioSpec* specs;
		string FilePath;
		float AudioLength;
	};

	list<Audio> Tracks;

	//functions
	void InitSystem();
	void PlayAudio();
	void StopAudio();
	void FadeAudio();
	void UpdateAudio();
};

