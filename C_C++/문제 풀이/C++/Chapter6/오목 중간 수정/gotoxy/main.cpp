#include "SetMenu.h"
#include "PlayGame.h"

void main()
{
	Menu DrawManager;
	PlayGame GameManager;
	while (1)
	{
		switch (DrawManager.StartMenu())
		{
		case GAMESTART:
			GameManager.Init();
			break;
		case GAMESETTING:
			DrawManager.SetMenu();
			break;
		case EXIT:
			exit(0);
		default:
			break;
		}
	}
	
}
