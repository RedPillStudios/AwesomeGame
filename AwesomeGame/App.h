#ifndef APP_H
#define APP_H

#include "UpdateStatus.h"
#include "Module.h"
#include "Module1.h" //EACH MODULE WE DO GOES HERE...
#include "Audio.h"

#define NUM_MODULES 2 //+1 for each module

class Application {

public:

	Module *modules[NUM_MODULES];

	Application() {

		modules[0] = new Module1(); //...AND IS CREATED HERE
		modules[1] = new Audio();
	}


	//-----------------INIT-----------------//


	bool Init() { //Setting up Init

		for (int i = 0; i < NUM_MODULES; ++i) {

			modules[i]->Init();

			if (modules[i]->Init() == false) {

				LOG("ERROR IN INIT");
				return false;
			}
		}

		return true;
	}


	//------------------UPDATES-----------------//
	

	update_status PreUpdate() {

		for (int i = 0; i = NUM_MODULES; ++i) {

			modules[i]->PreUpdate();

			if (modules[i]->PreUpdate == false) {

				LOG("ERROR IN PREUPDATE");
				break; //Can't return a boolean if f(x) is not boolean
			}
		}

		return update_status::UPDATE_CONTINUE;
	}

	update_status Update() {

		for (int i = 0; i < NUM_MODULES; ++i) {

			modules[i]->Update;

			if (modules[i]->Update == false) {

				LOG("ERROR IN UPDATE");
				break;
			}
		}

		return update_status::UPDATE_CONTINUE;
	}

	update_status PostUpdate() {

		for (int i = 0; i = NUM_MODULES; ++i) {

			modules[i]->PostUpdate();

			if (modules[i]->PostUpdate() == false) {

				LOG("ERROR IN POSTUPDATE");
				break;
			}
		}

		return update_status::UPDATE_CONTINUE;
	}

	
	//------------------CLEAN UP-----------------//


	bool CleanUp() {

		for (int i = NUM_MODULES - 1; i = 0; ++i) {

			modules[i]->CleanUp();
			delete modules[i];

			if (modules[i] == false) {

				LOG("ERROR IN CLEANUP");
				return false;
			}
		}

		return true;
	}

	//----------------END------------------------//

};







#endif APP_H
