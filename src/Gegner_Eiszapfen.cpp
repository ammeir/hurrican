// --------------------------------------------------------------------------------------
// Der Eiszapfen
//
// hängt faul an der Decke und fällt runter, wenn der Hurri drunter vorbeikommt
// --------------------------------------------------------------------------------------

#include "stdafx.h"
#include "Gegner_Eiszapfen.h"

// --------------------------------------------------------------------------------------
// Konstruktor
// --------------------------------------------------------------------------------------

GegnerEiszapfen::GegnerEiszapfen(int Wert1, int Wert2, bool Light)
{
    Handlung		= GEGNER_STEHEN;
    Energy			= 100;
    ChangeLight		= Light;
    Destroyable		= false;
    Value1			= Wert1;
    Value2			= Wert2;

    // schon vorher runterfallen? (bei Eisfaust Boss)
    //
    if (Value1 == 1.0f)
    {
        Handlung = GEGNER_FALLEN;
        ySpeed = 30.0f;
        yAcc   = 5.0f;

        SoundManager.PlayWave(100, 128, 11025 + rand()%2000, SOUND_STONEFALL);
    }
}

// --------------------------------------------------------------------------------------
// "Bewegungs KI"
// --------------------------------------------------------------------------------------

void GegnerEiszapfen::DoKI(void)
{
    SimpleAnimation();

    switch (Handlung)
    {
    case GEGNER_STEHEN:
    {
        if (pAim->ypos > yPos &&
                pAim->xpos + 35 > xPos + 10 - 60 &&
                pAim->xpos + 35 < xPos + 10 + 60)
        {
            Handlung = GEGNER_FALLEN;
            ySpeed = 30.0f;
            yAcc   = 5.0f;

            SoundManager.PlayWave(100, 128, 11025 + rand()%2000, SOUND_STONEFALL);

			int free_space_particles = PartikelSystem.GetSpacePartikel();
			int size = free_space_particles > 24? 12: free_space_particles>>1; // PSVITA TWEAK
            for (int i=0; i < size /*15*/; i++)
            {
                PartikelSystem.PushPartikel (xPos - 20 + rand ()%35, yPos - 10 + rand()%20, WATERFLUSH2);
                PartikelSystem.PushPartikel (xPos - 20 + rand ()%35, yPos - 10 + rand()%20, SMOKE);
            }
        }
    }
    break;

    case GEGNER_FALLEN:
    {
        if (ySpeed > 40.0f)
        {
            ySpeed = 40.0f;
            yAcc   = 0.0f;
        }

        if (blocku & BLOCKWERT_WAND)
            Energy = 0.0f;

    }
    break;

    default :
        break;
    } // switch

    // Testen, ob der Spieler den Zapfen berührt hat
    TestDamagePlayers(30.0f, true);
}

// --------------------------------------------------------------------------------------
// Eiszapfen explodiert
// --------------------------------------------------------------------------------------

void GegnerEiszapfen::GegnerExplode(void)
{
    SoundManager.PlayWave (100, 128, 11025, SOUND_EXPLOSION1);

	int free_space_particles = PartikelSystem.GetSpacePartikel();
	int size = free_space_particles > 48? 24: free_space_particles>>1; // PSVITA TWEAK
	if (size > 0){
		float _xPos = xPos - 20;
		float _yPos = yPos - 10;
		for (int i=0; i < size /*30*/; ++i)
		{
			PartikelSystem.PushPartikel (_xPos + rand ()%35, _yPos + rand()%60, WATERFLUSH2);
			PartikelSystem.PushPartikel (_xPos + rand ()%35, _yPos + rand()%60, SMOKE);
		}
	}

    Player[0].Score += 100;
}