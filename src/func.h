#pragma once

#include <SDL.h>

void drawCircle(SDL_Renderer *ren, SDL_Color color, int centerX, int centerY, int radius);
void drawFilledCircle(SDL_Renderer *ren, SDL_Color color, int centerX, int centerY, int radius);

TTF_Font *loadFont(const char *path, int size);
SDL_Surface *createTextSurf(TTF_Font* font, const char *text,SDL_Color color);
SDL_Texture* GetTextTexture(SDL_Renderer *ren, char *name,int size,SDL_Color color);