#ifndef TEXTURES_H
#define TEXTURES_H

SDL_Window* window = nullptr;
SDL_Renderer* Main_Renderer = nullptr;
SDL_Texture* Foreground_Texture = nullptr;
SDL_Texture* Background_Texture = nullptr;
SDL_Texture* LastBackground_Texture = nullptr;
SDL_Texture* Player_shipTexture = nullptr;
SDL_Texture* Enemy_shipTexture = nullptr;
SDL_Texture* Enemy2_shipTexture = nullptr;
SDL_Texture* Enemy2_ShotTexture = nullptr;
SDL_Texture* Shoot_Texture = nullptr;
SDL_Texture* Score_Texture = nullptr;
SDL_Texture* Numbers_Texture = nullptr;
SDL_Texture* PressEnter_Texture = nullptr;
SDL_Texture* Start_Texture = nullptr;
SDL_Texture* AwesomeGame_Texture = nullptr;
SDL_Texture* GameOver_Texture = nullptr;
SDL_Texture* TryAgain_Texture = nullptr;
SDL_Texture* Yes_texture = nullptr;
SDL_Texture* No_Texture = nullptr;
SDL_Texture* Selector_texture = nullptr;
SDL_Texture* Impulsor_Texture = nullptr;
SDL_Texture* Background_Dead = nullptr;
SDL_Texture* Explosion_Texture = nullptr;

SDL_Texture* loadTexture(const char* filename) {

	//Final Texture
	SDL_Texture* newTexture = nullptr;

	//Load image from path
	SDL_Surface* loadedSurface = IMG_Load(filename);
	newTexture = SDL_CreateTextureFromSurface(Main_Renderer, loadedSurface);
	//Delete the old loaded surface;
	SDL_FreeSurface(loadedSurface);

	return newTexture;
}

bool loadMedia() {

	bool succes = true;
	Start_Texture = loadTexture("Text/Start.png");
	PressEnter_Texture = loadTexture("Text/Main_Title_Press.png");
	AwesomeGame_Texture = loadTexture("Text/Titles.png");
	Shoot_Texture = loadTexture("Images/Plasma_Shoot.png");
	Foreground_Texture = loadTexture("Images/Foreground.png");
	Background_Texture = loadTexture("Images/Parallax_Background.png");
	LastBackground_Texture = loadTexture("Images/End_Background.png");
	Player_shipTexture = loadTexture("Images/Player_Ship.png");
	Enemy_shipTexture = loadTexture("Images/Enemy_Ship.png");
	Score_Texture = loadTexture("Text/Score.png");
	Numbers_Texture = loadTexture("Text/Numbers.png");
	Enemy2_shipTexture = loadTexture("Images/Enemy_2.png");
	Enemy2_ShotTexture = loadTexture("Images/Shot_enemy.png");
	GameOver_Texture = loadTexture("Text/Game_Over.png");
	TryAgain_Texture = loadTexture("Text/Try_Again.png");
	Yes_texture = loadTexture("Text/YES.png");
	No_Texture = loadTexture("Text/NO.png");
	Selector_texture = loadTexture("Text/Selector.png");
	Impulsor_Texture = loadTexture("Images/Impuls.png");
	Background_Dead = loadTexture("Images/Background_GameOver.png");
	Explosion_Texture = loadTexture("Images/Explosion.png");
	if (Background_Texture == NULL || Player_shipTexture == NULL || Enemy_shipTexture == NULL || Shoot_Texture == NULL || Score_Texture == NULL || Numbers_Texture == NULL) {
		succes = false;
	}

	return succes;
}




#endif // !TEXTURES_H
