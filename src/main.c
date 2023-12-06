#include <SDL.h>
#include <SDL_ttf.h>

#include "func.h"

#define WIDTH 1280
#define HEIGHT 720

SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;
SDL_bool RUN = SDL_TRUE;
SDL_Event event;

double frame = 0;

void init(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ){
        SDL_Log("Error ; %s > %s\n", "Init SDL", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    if(SDL_CreateWindowAndRenderer(WIDTH,HEIGHT, 0, &win, &ren) != 0){
        SDL_Log("Error ; %s > %s\n", "Window and renderer creation", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    if (TTF_Init() == -1){
        SDL_Log("Error ; %s > %s\n", "TTF", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(win,"Ex");
}

void gameLoop(){
    while(SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT:
                RUN = SDL_FALSE;
        }
    }
    SDL_Color textColor = {255,255,255,255}; // R G B A (A = transparence)
    SDL_Color color1 = {255,50,80,255};
    SDL_Rect Textframe;  //Cadre du Text
    Textframe.w = 400;
    Textframe.x = (WIDTH/2) - (Textframe.w/2);
    Textframe.h = 150;
    Textframe.y = 20;

    char* txt = "EXEMPLE";
    SDL_Texture* textTextureExemple = GetTextTexture(ren,txt,600,textColor);

    SDL_RenderCopy(ren,textTextureExemple,NULL,&Textframe);
    
    drawFilledCircle(ren,color1,300,300,50);
    drawCircle(ren,textColor,200,400,20);
    
    SDL_RenderPresent(ren);
    SDL_DestroyTexture(textTextureExemple);
}


int main(int argc, char** argv)
{
    init();
    while(RUN){
        SDL_SetRenderDrawColor(ren, 0,0,0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(ren);

        gameLoop();
    }

    TTF_Quit();
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}