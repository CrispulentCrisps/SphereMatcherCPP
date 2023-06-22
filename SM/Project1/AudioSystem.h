#pragma once
#include <SDL_audio.h>
#include <SDL_mixer.h>
#include <string>
#include "Scene.h"

using namespace std;

class AudioSystem
{
public:
	//variables
	const int AUDIO_RATE = 480000;
	vector<string> SfxPaths;
	vector<string> TrackPaths;

	int ChannelCount;
	int AudioBuffer;

	vector<Mix_Music*> M_Tracks;
	vector<Mix_Chunk*> M_Sfx;

	//functions
	void InitSystem(int AudioMode);
	void CloseSystem();
	void LoadAudio(vector<string> Sfx, vector<string> Msx);
	void PlayAudio(int AudioID, bool AudioType);
	void StopAudio();
	void FadeAudio();
	void UpdateAudio();
	void ListAudio();
};

