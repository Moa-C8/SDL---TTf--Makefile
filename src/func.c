#include <SDL.H>
#include <SDL_ttf.h>
#include <stdio.h>


void drawCircle(SDL_Renderer *ren, SDL_Color color, int centerX, int centerY, int radius) {
    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);

    int d = (5 - radius * 4) / 4;
    int x = 0;
    int y = radius;

    do {
        SDL_RenderDrawPoint(ren, centerX + x, centerY + y);
        SDL_RenderDrawPoint(ren, centerX + x, centerY - y);
        SDL_RenderDrawPoint(ren, centerX - x, centerY + y);
        SDL_RenderDrawPoint(ren, centerX - x, centerY - y);
        SDL_RenderDrawPoint(ren, centerX + y, centerY + x);
        SDL_RenderDrawPoint(ren, centerX + y, centerY - x);
        SDL_RenderDrawPoint(ren, centerX - y, centerY + x);
        SDL_RenderDrawPoint(ren, centerX - y, centerY - x);

        if (d < 0) {
            d += 2 * x + 1;
        } else {
            d += 2 * (x - y) + 1;
            y--;
        }
        x++;
    } while (x <= y);
}

void drawFilledCircle(SDL_Renderer *ren, SDL_Color color, int centerX, int centerY, int radius) {
    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);

    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                SDL_RenderDrawPoint(ren, centerX + x, centerY + y);
            }
        }
    }
}

TTF_Font *loadFont(const char *path, int size){
    TTF_Font *font = TTF_OpenFont(path,size);
    if (!font) {
        printf("Erreur lors du chargement de la police : %s\n", TTF_GetError());
    }
    return font;
}

SDL_Surface *createTextSurf(TTF_Font* font, const char *text,SDL_Color color){
    return TTF_RenderText_Solid(font, text, color);
}

SDL_Texture* GetTextTexture(SDL_Renderer *ren, char *name,int size,SDL_Color color){
    TTF_Font *NameFont = loadFont("src/fonts/Roboto-Black.ttf",size);
    SDL_Surface* nameTxtSurf = createTextSurf(NameFont,name,color);
    SDL_Texture* txtTexture = SDL_CreateTextureFromSurface(ren,nameTxtSurf);
    SDL_FreeSurface(nameTxtSurf);
    TTF_CloseFont(NameFont);
    return(txtTexture);
}
