#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Bandeira do Brasil",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         600, 300, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0,146,62,0x00);
    SDL_RenderClear(ren);

    filledTrigonRGBA(ren,50,150,300,50,550,150,248,193,0,255);
    filledTrigonRGBA(ren,50,150,300,250,550,150,248,193,0,255);
    filledCircleRGBA(ren,300,150,80,40,22,111,255);
   
    SDL_RenderPresent(ren);
    SDL_Delay(5000);
    
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
