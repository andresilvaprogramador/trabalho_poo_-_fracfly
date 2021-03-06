/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef _FESTADOMENU_H_
	#define _FESTADOMENU_H_

#include "Definicoes.h"

#include "FEstado.h"

#include "FCamera.h"
#include "FEntidade.h"
#include "FSuperficie.h"
#include "FFonte.h"

class FEstadoMenu : public FEstado {
	private:
		static FEstadoMenu instancia;
		int estadoSelecionado;
		FEntidadeTexto * titulo;
		FEntidadeBotao * iniciar;
		FEntidadeBotao * options;
		FEntidadeBotao * sair;
		FEntidade	fundo;
	private:
		TTF_Font * fonte;
		
	private:
		FEstadoMenu();
	
	public:
		void NaAtivacao();
		void NaDesativacao();
		void NoLaco();
		void NaRenderizacao(SDL_Surface * planoExibicao);
	
	public:
		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		//void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
		void OnLButtonDown(int mX, int mY);
		void OnLButtonUp(int mX, int mY);
		//void OnRButtonDown(int mX, int mY);
		//void OnRButtonUp(int mX, int mY);
		
	public:
		static FEstadoMenu * GetInstancia();
};

#endif
