/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/


#ifndef _FSUPERFICIE_H_
    #define _FSUPERFICIE_H_

#include "male_libs.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_gfxPrimitives.h>

class FSuperficie : public Excecoes {
    public:
        FSuperficie();

    public:
        static SDL_Surface * NoCarregar(char * Arquivo);
        
        static bool NoDesenhar(SDL_Surface * Surf_Dest, SDL_Surface * Surf_Ori, int X, int Y);
        static bool NoDesenhar(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Ori, int X, int Y, int X2, int Y2, int W, int H);
        static bool Transparencia(SDL_Surface* Surf_Dest, int R, int G, int B);

};
 
#endif
