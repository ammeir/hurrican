// --------------------------------------------------------------------------------------
// Die WasserMine
//
// D�mpelt im Wasser rum und wartet auf eine Kollision ;)
// --------------------------------------------------------------------------------------

#include "stdafx.h"
#include "Gegner_WasserMine.h"

// --------------------------------------------------------------------------------------
// Konstruktor
// --------------------------------------------------------------------------------------

GegnerWasserMine::GegnerWasserMine(int Wert1, int Wert2, bool Light)
{
    Handlung		= GEGNER_LAUFEN;
    Energy			= 20;
    AnimSpeed		= 3.0f;
    ChangeLight		= Light;
    Destroyable		= false;
    AnimSpeed		= 4.0f;
    AnimEnde		= 10;
    Value1			= int (Wert1);
}

// --------------------------------------------------------------------------------------
// "Bewegungs KI"
// --------------------------------------------------------------------------------------

void GegnerWasserMine::DoKI(void)
{
    SimpleAnimation();

    // Spieler berührt ?
    TestDamagePlayers(50.0f, true);
}

// --------------------------------------------------------------------------------------
// WasserMine explodiert
// --------------------------------------------------------------------------------------

void GegnerWasserMine::GegnerExplode(void)
{
    SoundManager.PlayWave (100, 128, 8000, SOUND_EXPLOSION3);
    SoundManager.PlayWave (100, 128,14000, SOUND_EXPLOSION4);

    ShakeScreen(3.0f/*4.0f*/);

	float _xPos = xPos - 5;
	float _yPos = yPos - 5;
    for (int i = 0; i < 50; ++i)
        PartikelSystem.PushPartikel(_xPos + rand()%40, _yPos + rand()%60, WATERFLUSH_HIGH);

    for (int i = 0; i < 25; ++i)
        PartikelSystem.PushPartikel(xPos - 5 + rand()%40, yPos - 50 + rand()%110, SPIDERSPLITTER);

    PartikelSystem.PushPartikel(xPos - 40, yPos - 55, EXPLOSION_GIANT);
}
