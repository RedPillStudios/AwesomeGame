#ifndef MOUDLE1_H
#define MODULE1_H

#include "Module.h"
#include "UpdateStatus.h"

//Module that will do Init, update...

class Module1 : public Module {

	bool Init() {

		LOG("INIT");
		return true;
	}

	update_status PreUpdate() {

		LOG("PREUPDATE");
		return update_status::UPDATE_CONTINUE;
	}

	update_status PostUpdate() {

		LOG("UPDATE");
		return update_status::UPDATE_CONTINUE;
	}

	update_status PostUpdate() {

		LOG("POSTUPDATE");
		return update_status::UPDATE_CONTINUE;
	}

	bool CleanUp() {

		LOG("CLEANUP");
		return true;
	}
};


#endif
