#include "AudioSystem.h"

void AudioSystem::InitSystem(int AudioMode)
{
	SDL_INIT_AUDIO;
	if (Mix_OpenAudio(AUDIO_RATE, MIX_DEFAULT_FORMAT, AudioMode, 2048) < 0)
	{
		cout << "\nAUDIO SYSTEM FAILED TO INTIIALISE" << SDL_GetError();
	}
	else
	{
		for (unsigned i = 0; i < SfxPaths.size(); i++)
		{
			M_Sfx[i] = Mix_LoadWAV(SfxPaths[i].c_str());
		}

		for (unsigned i = 0; i < TrackPaths.size(); i++)
		{
			M_Tracks[i] = Mix_LoadMUS(TrackPaths[i].c_str());
		}
	}
}

void AudioSystem::CloseSystem()
{
	for (unsigned i = 0; i < M_Sfx.size(); i++)
	{
		Mix_FreeChunk(M_Sfx[i]);
	}

	for (unsigned i = 0; i < M_Tracks.size(); i++)
	{
		Mix_FreeMusic(M_Tracks[i]);
	}
}

void AudioSystem::LoadAudio(vector<string> Sfx, vector<string> Msx)
{	
	SfxPaths.resize(1);
	TrackPaths.resize(1);
	for (unsigned i = 0; i < Sfx.size(); i++)
	{
		SfxPaths.push_back(Sfx[i]);
	}
	for (unsigned i = 0; i < Sfx.size(); i++)
	{
		TrackPaths.push_back(Msx[i]);
	}
}

void AudioSystem::PlayAudio(int AudioID, bool AudioType)
{
	//True for music, false for SFX
	if (AudioType)
	{
		Mix_PlayChannel(-1, M_Sfx[AudioID], 0);
	}
	else
	{
		Mix_PlayMusic(M_Tracks[AudioID], -1);
	}
}

void AudioSystem::ListAudio()
{
	for (unsigned i = 0; i < TrackPaths.size(); i++)
	{
		cout << "\n" << TrackPaths[i] << " : " << i;
	}

	for (unsigned i = 0; i < SfxPaths.size(); i++)
	{
		cout << "\n" << SfxPaths[i] << " : " << i;;
	}
}
