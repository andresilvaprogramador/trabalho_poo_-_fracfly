#Makefile

#Compilador
CC=g++

# Objects
OBJETOS=FracFly_NaLimpeza.o FracFly_NoEvento.o FracFly_NoInic.o FracFly_NoLaco.o FracFly_NaRenderizacao.o FSuperficie.o FEvento.o FAnimacao.o FEntidade.o FEntidade_Tiro.o FEntidade_Arma.o FracFly.o 

# Compilador flags - Warning, debug, sdl
CPPFLAGS=-std=c++0x -Wall -g -lm `sdl-config --cflags`

# Ligador flags - sdl
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image

EXECUTAVEL=fracfly

#Compila o binario do jogo
#jogo: NaLimpeza FSuperficie NoEvento NoInic NoLaco NaRenderezicao FracFly FracFly.cpp
jogo: $(OBJETOS) FracFly.h FracFly.cpp
	$(CC) $(OBJETOS) $(CPPFLAGS) $(LDFLAGS) -o $(EXECUTAVEL)
FracFly: $(OBJETOS) FracFly.h FracFly.cpp
	$(CC) $(CPPFLAGS) -c FracFly.cpp
NoInic: FracFly.h FracFly_NoInic.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NoInic.cpp
NoEvento: FracFly.h FracFly_NoEvento.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NoEvento.cpp
NoLaco: FracFly.h FracFly_NoLaco.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NoLaco.cpp
NaRenderezicao: FracFly.h FracFly_NaRenderizacao.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NaRenderizacao.cpp
NaLimpeza: FracFly.h FracFly_NaLimpeza.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NaLimpeza.cpp
FSuperficie: FSuperficie.h FSuperficie.cpp
	$(CC) $(CPPFLAGS) -c FSuperficie.cpp
FEvento: FEvento.h FEvento.cpp
	$(CC) $(CPPFLAGS) -c FEvento.cpp
FAnimacao: FAnimacao.h FAnimacao.cpp
	$(CC) $(CPPFLAGS) -c FAnimacao.cpp
FEntidade: FEntidade.h FEntidade.cpp
	$(CC) $(CPPFLAGS) -c FEntidade.cpp
FEntidade_Tiro: FEntidade_Tiro.h FEntidade_Tiro.cpp
	$(CC) $(CPPFLAGS) -c FEntidade_Tiro.cpp
FEntidade_Arma: FEntidade_Arma.h FEntidade_Arma.cpp
	$(CC) $(CPPFLAGS) -c FEntidade_Arma.cpp

#Instalar SDL
pacotes:
	sudo apt-get install libsdl-image1.2-dev libsdl-image1.2 libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl1.2-dev libsdl1.2debian

#limpeza
clean:
	rm -rf $(OBJETOS)
#	rm -rf $(EXECUTAVEL)
