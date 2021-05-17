#include "./apps/main/dino_game.h"
#include <osw_ui.h>

#define COLOR_WHITE rgb565(255, 255, 255)
#define COLOR_BLUE rgb565(0, 121, 241)

void OswAppDinoGame::setup(OswHal *hal) {
  score = 0;
  velY = 0;
  velX = 10;
  speedIncrease = 1;

  cactusX = 255;
  
  perttiY = groundlvl;

  jumping = false;
  gameRunning = false;
}

void OswAppDinoGame::loop(OswHal *hal) {
  hal->gfx()->fill(0);
  
  if (gameRunning) {
	if (hal->btnHasGoneDown(BUTTON_3) && !jumping) {
	  jumping = true;
	  velY = 10;
	}
  
	velY -= 30 * 0.0333;
	perttiY -= velY;

	if (perttiY >= groundlvl + 1) {	
	  perttiY = groundlvl;
	  jumping = false;
	  velY = 0;
	}
	OswUI::getInstance()->setTextCursor(BUTTON_2);
	hal->gfx()->print(score);
	hal->gfx()->print("SCORE: ");

	OswUI::getInstance()->setTextCursor(BUTTON_3);
	hal->gfx()->print("JUMP");
  }
  else {
	OswUI::getInstance()->setTextCursor(BUTTON_2);
	hal->gfx()->print("START");

	if (hal->btnHasGoneDown(BUTTON_2)) {
	  gameRunning = true;
	  jumping = true;
	  velY = 10;
	}
  }


  hal->gfx()->drawLine(0, groundlvl, 240, groundlvl, COLOR_WHITE);
  hal->gfx()->drawFrame(perttiX, perttiY - perttiHeight, perttiWidth, perttiHeight, COLOR_BLUE);

  hal->requestFlush();
}

void OswAppDinoGame::stop(OswHal *hal) {}
