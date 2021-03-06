/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef _FNAVE_H_
	#define _FNAVE_H_

#include "FEntidade.h"

class FNave: public FEntidade {
	private:
		int vida;
		int escudo;
		int escore;
		int forca;

		bool atirandoEsquerda;
		bool atirandoDireita;

	public:
		FNave();
		void NoLaco();
		void NaRenderizacao(SDL_Surface * planoExibicao);
		void NaLimpeza();
		void NaAnimacao();
		bool NaColisao(FEntidade * entidade);
		
	public:
		bool Atirar(FEntidade * entidade, float x, float y, int aX, int aY);
		int GetEscore();
		void SetEscore(int escore);
};


#endif
