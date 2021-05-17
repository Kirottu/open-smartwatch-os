#ifndef OSW_APP_DINO_GAME
#define OSW_APP_DINO_GAME

#include <osw_app.h>

class OswAppDinoGame : public OswApp {
  public:
	OswAppDinoGame(void){};
	void setup(OswHal* hal);
	void loop(OswHal* hal);
	void stop(OswHal* hal);
	~OswAppDinoGame(){};

  private:
	int score = 0;
	float velY = 0;
	float velX = 10;
	float speedIncrease = 1;
	
	uint8_t groundlvl = 140;
	uint8_t perttiX = 80;
	float perttiY = groundlvl;
	uint8_t perttiHeight = 20;
	uint8_t perttiWidth = 20;

	uint8_t cactusX = 255;

	bool jumping = false;
	bool gameRunning = false;
};

#endif
