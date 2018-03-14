#ifndef MODULE_H
#define MODULE_H

class Module { //Defining a module

public:

	virtual bool Init() { return true; }
	virtual update_status PreUpdate() { return UPDATE_CONTINUE; }
	virtual update_status Update() { return UPDATE_CONTINUE; }
	virtual update_status PostUpdate() { return UPDATE_CONTINUE; }
	virtual bool CleanUp() { return true; }

};

#endif