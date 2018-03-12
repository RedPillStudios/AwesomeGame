
#include "SDL\include\SDL.h"
#include <iostream>
#include "SDL_image\include\SDL_image.h"
#include"SDL_Mixer\include\SDL_mixer.h"
#include"Declarations.h"
#include"Textures.h"
#include"Functions.h"
#pragma comment(lib,"SDL/libx86/SDL2.lib")
#pragma comment(lib,"SDL/libx86/SDL2main.lib")
#pragma comment(lib,"SDL_image/libx86/SDL2_image.lib")
#pragma comment(lib,"SDL_Mixer/libx86/SDL2_mixer.lib")

/*Mix_PlayChannel(-1, Laser, 0);
Mix_PlayChannel(-1, EnemyLaser, 0);
Mix_PlayChannel(-1, EnemyLaser, 0);
Mix_PlayChannel(-1, EnemyLaser, 0);
Mix_PlayChannel(-1, Collision, 0);
Mix_PlayChannel(-1, ButtonNo, 0);
Mix_PlayChannel(-1, ButtonYes, 0);*/



int main(int argc, char* argv[]) {

	srand(9);

	//----- DECLARING LOGIC OPERANDS-------//
	int framesExplosion=0;
	int frames = 0;
	int Velocity = 10;
	int VelocityShoot = 50;
	int VelocityShootEnemy = 20;
	int PosSprite=0;
	int SpriteColumn1=0;
	int SpriteColumn2=0;
	int SpriteColumn3=0;
	int SpriteColumn4=0;
	int StartExploson = 0;


	float timeCharging=0.0;
	bool MainMenu = true;
	bool exploding = false;
	bool test = true;
	bool Alive = true ;
	bool ChargeShot = false;
	bool EnemyAlive= false;
	bool Enemy2Alive = false;
	bool Enemy2reachedpoint = false;
	bool Enemy2Shooting = false;
	bool Enemy3Alive = false;
	bool Enemy3reachedpoint = false;
	bool Enemy3Shooting = false;
	bool Enemy4Alive = false;
	bool Enemy4reachedpoint = false;
	bool Enemy4Shooting = false;
	bool Charged = false;
	bool ePress = false;
	bool Enter = false;
	bool Up = false;
	bool Down = false;
	bool Left = false;
	bool Right = false;
	bool Space = false;
	bool Shoot_Enabled = false;
	bool Shooting = false;
	bool MenuOut = false;
	bool quit = false;
	bool collx = false;
	bool colly = false;


	//start up SDL and create a window
	init();
	loadMedia();
	Set_Initial_States();
	SpriteSheet(NumClipper);
	SpriteSheetExplosion(Explosion_Clipping);

	if (!loadMedia||!init) {
		quit = true;
	}
	while(!quit){

			while (SDL_PollEvent(&e) != 0) // This gets an event so this will happens until SDLQUIT(in this case pres the x button) happens)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}

				if (e.type == SDL_KEYDOWN) {

					switch (e.key.keysym.sym)
					{
					case SDLK_d:
						Right = true;
						break;
					case SDLK_a:
						Left = true;
						break;
					case SDLK_w:
						Up = true;
						break;
					case SDLK_s:
						Down = true;
						break;
					case SDLK_SPACE:
						Space = true;
						break;
					case SDLK_e:
						ePress = true;
						break;
					case SDLK_RETURN:
						Enter = true;
						break;
					}
				}
				if (e.type == SDL_KEYUP) {
					switch (e.key.keysym.sym)
					{
					case SDLK_d:
						Right = false;
						break;
					case SDLK_a:
						Left = false;
						break;
					case SDLK_w:
						Up = false;
						break;
					case SDLK_s:
						Down = false;
						break;
					case SDLK_SPACE:
						Space = false;
						break;
					case SDLK_e:
						ePress = false;
						break;
					case SDLK_RETURN:
						Enter = false;
						break;
					default:
						break;
					}
				}
			}

			if (Enter&&MainMenu) {
				MainMenu = false;
				Set_Initial_States();
				Alive = true;
			}
    
  /*	if (Mix_PlayingMusic() == 0){

				Mix_FadeInMusic(Music, 0, 1000);
				Mix_PlayMusic(Music, -1);
				Mix_VolumeMusic(64);
			}*/
  
			if (Alive) {
				Impulsor.x = Ship.x-135;
				Impulsor.y = Ship.y;
				if (!MainMenu) {
					if (Left && (Ship.x >= 0)) {
						Ship.x -= Velocity;
					}
					if (Right && (Ship.x <= SCREEN_WIDTH - Ship.w)) {
						Ship.x += Velocity;
					}
					if (Up && (Ship.y >= 0)) {
						Ship.y -= Velocity;
					}
					if (Down && (Ship.y <= SCREEN_HEIGHT - Ship.h)) {
						Ship.y += Velocity;
					}
					if (Space && !Shooting) {
						Shoot.x = Ship.x + Ship.w - 50;
						Shoot.y = Ship.y + (Ship.h / 2) - 40;
						Shooting = true;
						Shoot_Enabled = true;
					}
					if (SDL_HasIntersection(&Enemy2Shoot, &Ship) || SDL_HasIntersection(&Enemy3Shoot, &Ship) || SDL_HasIntersection(&Enemy4Shoot, &Ship) || SDL_HasIntersection(&Enemy, &Ship)) {
						Alive = false;
					}
				}
				if (Shooting) {

					if (Shoot.x < SCREEN_WIDTH) {
						Shoot.x += VelocityShoot;

						if (SDL_HasIntersection(&Shoot, &Enemy) || SDL_HasIntersection(&Shoot, &Enemy2) || SDL_HasIntersection(&Shoot, &Enemy3) || SDL_HasIntersection(&Shoot, &Enemy4)) {
						
							PosSprite++;
							if (PosSprite > 9) {
								PosSprite = 0;
								SpriteColumn1++;
								if (SpriteColumn1 > 9) {
									SpriteColumn1 = 0;
									SpriteColumn2++;
									if (SpriteColumn3 > 9) {
										SpriteColumn3 = 0;
									}
								}
							}
							if (SDL_HasIntersection(&Shoot, &Enemy) && Enemy.x < SCREEN_WIDTH - 40) {
								exploding = true;	
								Explosion.x = Enemy.x;
								Explosion.y = Enemy.y;																																
								Enemy.y = rand() % (SCREEN_HEIGHT - 100);
								EnemyAlive = false;															

							}
							if (SDL_HasIntersection(&Shoot, &Enemy2)) {
								exploding = true;
								Explosion.x = Enemy2.x;
								Explosion.y = Enemy2.y;
								Enemy2.x += SCREEN_WIDTH * 2;
								Enemy2Alive = false;
							}
							if (SDL_HasIntersection(&Shoot, &Enemy3)) {
								exploding = true;
								Explosion.x = Enemy3.x;
								Explosion.y = Enemy3.y;
								Enemy3.x += SCREEN_WIDTH * 2;
								Enemy3Alive = false;
							}
							if (SDL_HasIntersection(&Shoot, &Enemy4)) {
								exploding = true;
								Explosion.x = Enemy4.x;
								Explosion.y = Enemy4.y;
								Enemy4.x += SCREEN_WIDTH * 2;
								Enemy4Alive = false;
							}
							Shoot.x = OUTSCREEN;
						}
					}
					else
						Shooting = false;
				}
				if (Enemy2Alive) {
					if (Enemy2.x >= 500) {
						Enemy2.x -= Velocity;
						Enemy2Shoot.x = -100;
						Enemy2reachedpoint = false;
					}
					else {
						Enemy2reachedpoint = true;
					}
					if (Enemy2reachedpoint && !Enemy2Shooting) {
						Enemy2Shoot.x = Enemy2.x;
						Enemy2Shoot.y = Enemy2.y + 10;
						Enemy2Shooting = true;
					}
					if (Enemy2Shooting&&Enemy2reachedpoint) {
						Enemy2Shoot.x -= VelocityShootEnemy;
						if (Enemy2Shoot.x <= 0) {
							Enemy2Shooting = false;
						}
					}
				}
				else {
					Enemy2Alive = true;
				}

				if (Enemy3Alive) {
					if (Enemy3.x >= 500) {
						Enemy3.x -= Velocity;
						Enemy3Shoot.x = -100;
						Enemy3reachedpoint = false;
					}
					else {
						Enemy3reachedpoint = true;
					}
					if (Enemy3reachedpoint && !Enemy3Shooting) {
						Enemy3Shoot.x = Enemy3.x;
						Enemy3Shoot.y = Enemy3.y + 10;
						Enemy3Shooting = true;
					}
					if (Enemy3Shooting&&Enemy3reachedpoint) {
						Enemy3Shoot.x -= VelocityShootEnemy;
						if (Enemy3Shoot.x <= 0) {
							Enemy3Shooting = false;
						}
					}
				}
				else {
					Enemy3Alive = true;
				}

				if (Enemy4Alive) {
					if (Enemy4.x >= 500) {
						Enemy4.x -= Velocity;
						Enemy4Shoot.x = -100;
						Enemy4reachedpoint = false;
					}
					else {
						Enemy4reachedpoint = true;
					}
					if (Enemy4reachedpoint && !Enemy4Shooting) {
						Enemy4Shoot.x = Enemy4.x;
						Enemy4Shoot.y = Enemy4.y + 10;
						Enemy4Shooting = true;
					}
					if (Enemy4Shooting&&Enemy4reachedpoint) {
						Enemy4Shoot.x -= VelocityShootEnemy;
						if (Enemy4Shoot.x <= 0) {
							Enemy4Shooting = false;
						}
					}
				}
				else {
					Enemy4Alive = true;
				}

				if (EnemyAlive) {
					Enemy.x -= Velocity;
					if (Enemy.x < 0 - Enemy.w) {
						Enemy.x = SCREEN_WIDTH;
						Enemy.y = rand() % (SCREEN_HEIGHT - 100);

					}
				}
				else {
					Enemy.x = SCREEN_WIDTH;
					EnemyAlive = true;
				}
			
				Foreground.x-=2;
				if (Foreground.x <= 0 - SCREEN_WIDTH) {
					Foreground.x = SCREEN_WIDTH;
				}
				Foreground2.x-=2;
				if (Foreground2.x <= 0 - SCREEN_WIDTH) {
					Foreground2.x = SCREEN_WIDTH;
				}

				Background.x--;
				if (Background.x <= 0 - SCREEN_WIDTH) {
					Background.x = SCREEN_WIDTH;
				}
				Background2.x--;
				if (Background2.x <= 0 - SCREEN_WIDTH) {
					Background2.x = SCREEN_WIDTH;
				}
				LastBackground.x-0.5f;
				if (LastBackground.x <= 0 - SCREEN_WIDTH) {
					LastBackground.x = SCREEN_WIDTH;
				}
				LastBackground2.x-0.5f;
				if (LastBackground2.x <= 0 - SCREEN_WIDTH) {
					LastBackground2.x = SCREEN_WIDTH;
				}
				if (exploding) {
					framesExplosion+=2;
					
				}
				if (framesExplosion / 4 >= EXPLOSION_FRAMES) {
					framesExplosion = 0;
					Explosion.x = OUTSCREEN;
					Explosion.y = OUTSCREEN;
					exploding = false;

				}
				frames+=2;
				if (frames / 4 >= ANIM_FRAMES) {
					frames = 0;
				}
			}
			else {
				MenuOut = true;
				if (Left) {
					Selector.x = Yes.x - 30;
				}
				else if (Right) {
					Selector.x = No.x - 35;
				
				}
				if (Selector.x == Yes.x - 30&&Enter) {
					Set_Initial_States();
					PosSprite = 0;
					SpriteColumn1 = 0;
					SpriteColumn2 = 0;
					SpriteColumn3 = 0;
					Alive = true;
					MenuOut = false;
					
				
				}
				else if (Selector.x == No.x - 35 && Enter) { 
					quit = true;	
				}
			}
		
			//Updating the windows surface.

			Draw(SpriteColumn1, SpriteColumn2, SpriteColumn3, PosSprite,MenuOut,frames,framesExplosion,MainMenu);

			SDL_Delay(30);

	}	
	Mix_HaltMusic();
	close();

	return 0;
}


