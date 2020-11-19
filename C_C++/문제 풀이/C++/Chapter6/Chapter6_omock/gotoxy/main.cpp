#include "MapDraw.h"

void main()
{
	MapDraw DrawManager;
	while (1)
	{
		switch (DrawManager.StartMenu())
		{
		case GAMESTART:
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
