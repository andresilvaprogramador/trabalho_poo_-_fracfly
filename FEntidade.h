/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef _FENTIDADE_H
  #define _FENTIDADE_H

#include "male_libs.h"

#include "SDL/SDL.h"
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_gfxPrimitives.h>

#include "FAnimacao.h"
#include "FCamera.h"
#include "FFPS.h"
#include "FSuperficie.h"
#include "FFonte.h"


//tipo
enum {
	TIPO_ENTIDADE_GENERICO = 0,
	TIPO_ENTIDADE_TEXTO,
	TIPO_ENTIDADE_BOTAO,
	TIPO_ENTIDADE_CURSOR,
	TIPO_ENTIDADE_JOGADOR,
	TIPO_ENTIDADE_TIRO
};

//flags
enum {
	ENTIDADE_FLAG_NONE = 0,

	ENTIDADE_FLAG_GRAVIDADE		= 0x00000001, //Objetos com esta flag serao fonte de atracao para qualquer outro objeto
	ENTIDADE_FLAG_FANTASMA		= 0x00000002, //objetos que nao sao afetados por nenhum outro objeto (luzes por exemplo)
	ENTIDADE_FLAG_SOMENTEMAPA	= 0x00000004, //inutil
	ENTIDADE_FLAG_ESPACO		= 0x00000008, //inutil
	ENTIDADE_FLAG_CURSOR		= 0x00000010, //eh afetado pelo cursor
	ENTIDADE_FLAG_CURSOR_HOVER	= 0x00000020, //
	ENTIDADE_FLAG_CURSOR_CLICK	= 0x00000040,
	//ENTIDADE_FLAG_BOTAO_OPTIONS = 0x00000080,
	//ENTIDADE_FLAG_BOTAO_SAIR	= 0x00000100,
	//ENTIDADE_FLAG_BOTAO_CLICK	= 0x00000200
};

//acoes que podem ser tomados
enum  {
	MUDA_ESTADO,
	MUDA_RESOLUCAO
};

using namespace std;

class FEntidade {
public:
	static vector<FEntidade*> listaEntidades;
	static void OrdenaProfundidade(int esquerda, int direita);
	static FEntidade * RetornaEntidade(int pos);

protected:
	FAnimacao 			controleAnimacao;
	SDL_Surface * 		superficieEntidade;
	SDL_Surface * 		superficieEntidade_Original;

public:
	float	x;
	float 	y;
	float 	z;

	float	oX;
	float 	oY;
	double angulo;

	//entidades especiais que se movem para determinadas posicoes
	float movePraX;
	float movePraY;

	int 	width; //nomes da variavel em ingles
	int 	height; //pra facilitar o entendimento Width = largura, Height = altura

	bool 	moveCima;
	bool 	moveBaixo;
	bool 	moveDireita;
	bool 	moveEsquerda;

public:
	int 	tipo;

	bool 	morto;
	int 	flags;
	int		clique;

protected:
	float 	velX;
	float 	velY;

	float 	acelX;
	float 	acelY;

public:
	float 	velMaxX;
	float 	velMaxY;

protected: //variaveis de Animacao
	int 	frameAtualCol;
	int 	frameAtualLinha;

protected: //variaveis de colisao
	int 	colX;
	int 	colY;
	int 	colWidth;
	int 	colHeight;
public:
	void colBox(int x, int y, int width, int height);

public:
	FEntidade();

	virtual ~FEntidade();
	
public:
	virtual bool NoCarregar(char * arquivo, int width, int height, int maxFrames);
	virtual void NoLaco();
	virtual void NaRenderizacao(SDL_Surface * planoExibicao);
	virtual void NaLimpeza();
	virtual void NaAnimacao();
	virtual bool NaColisao(FEntidade * entidade);

	SDL_Surface * GetSuperficie();
	void SetSuperficie(SDL_Surface *);

	virtual bool RotaZoom(double angulo, double zoom, int smooth, int centerX, int centerY);
	virtual bool Rotacionar(double angulo, int centerX, int centerY);
	virtual bool Escalonar(double zoom, int centerX, int centerY);

public:
	void	NoMovimento(float moveX, float moveY);
	void	PararMovimento();
	void	SetAcel(float x, float y);
	float	GetAcelX();
	float	GetAcelY();

public:
	bool Colisoes(int oX, int oY, int oW, int oH);

public:
	bool PosValido(int novoX, int novoY);
private:
	bool PosValidoEntidade(FEntidade * entidade, int novoX, int novoY);
	
};


class FEntidadeColisao {
public:
	static std::vector<FEntidadeColisao> listaEntidadesColisoes;

public:
	FEntidade * entidadeA;
	FEntidade * entidadeB;

public:
	FEntidadeColisao();
};

class FEntidadeTexto : public FEntidade {
protected:
	TTF_Font * 			fonteEntidade;

public:
	string	texto;
	SDL_Color corTexto;
	
public:
	FEntidadeTexto();
	virtual bool NoCarregar(char * arquivo, string texto, int tam, SDL_Color corTexto);
	virtual bool NoCarregar(TTF_Font * fonte, string texto, SDL_Color corTexto);
	virtual void NaRenderizacao(SDL_Surface * planoExibicao);
	virtual void NaLimpeza();

public:
	//virtual void MudaFonte(TTF_Font * fonte, SDL_Color corTexto);
	virtual void MudaTexto(string texto);
};


class FEntidadeBotao : public FEntidadeTexto {
	private:
		SDL_Color corTextoAlterada;
		bool cursorSobre;
		
		int deslocamentoX;
		int deslocamentoY;
		
		int acao;
		int cliqueDireito;
		int cliqueEsquerdo;
		
	public:
		FEntidadeBotao();
		void	NoMovimento(float moveX, float moveY); //botao nao se movimenta

	public:
		void NoLaco();
		void NaRenderizacao(SDL_Surface * planoExibicao);
		
	public:
		bool NaColisao(FEntidade * entidade); //botao trata colisao de maneira diferete
		void MudaCor();
		//void MudaFonte(TTF_Font * fonte, SDL_Color corTexto);
		
		//Seta o comportamento ao passar o mouse por cima do botao
		void AoPassarPorCima(SDL_Color corTexto, int deslocaX, int deslocaY);
		//Seta o comportamento ao clicar com
		void AoClicarDireito(int acao);
		void AoClicarEsquerdo(int acao);
		void Acao(int acao);

};

#endif
