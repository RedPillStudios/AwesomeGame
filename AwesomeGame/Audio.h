#ifndef AUDIO_H
#define AUDIO_H

#include "Module.h"
#include "UpdateStatus.h"


class Audio : public Module {

/*public:

	bool Init() {

		SDL_Init(SDL_INIT_AUDIO);
		Mix_Init(MIX_INIT_OGG);
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		return true;
	}

	update_status PreUpdate() {

		Mix_Music *Music = nullptr;
		Mix_Chunk *Laser = nullptr;
		Mix_Chunk *EnemyLaser = nullptr;
		Mix_Chunk *Collision = nullptr;
		Mix_Chunk *ButtonNo = nullptr;
		Mix_Chunk *ButtonYes = nullptr;
		
		Music = Mix_LoadMUS("Audio/Mus1.ogg");
		Laser = Mix_LoadWAV("Audio/Laser_Gun.wav");
		EnemyLaser = Mix_LoadWAV("Audio/Enemy_Laser.wav");
		Collision = Mix_LoadWAV("Audio/Collision.wav");
		ButtonNo = Mix_LoadWAV("Audio/No.wav");
		ButtonYes = Mix_LoadWAV("Audio/Yes.wav");

		return update_status::UPDATE_CONTINUE;
	}

	update_status Update(){

		//PLAYCHANNEL Y ESAS COSAS...
		
	
	
	}

	update_status PostUpdate(){} //Necesario??
	
	bool CleanUp() {

		//Limpiar y eliminar todo
	}
	*/

};

#endif
