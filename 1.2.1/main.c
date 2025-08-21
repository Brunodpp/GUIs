#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Hello World!",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 21,92,192,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 255,255,0,0x00);
    SDL_Rect r = { 180,15, 15,15 };
    SDL_RenderFillRect(ren, &r);
    SDL_SetRenderDrawColor(ren, 10,255,0,0x00);
    SDL_Rect q = { 0,70, 200,30 };
    SDL_RenderFillRect(ren, &q);
   
    SDL_SetRenderDrawColor(ren, 62,38,26,0x00);
    SDL_Rect w = { 135,30, 40,40 };
    SDL_RenderFillRect(ren, &w);
     SDL_SetRenderDrawColor(ren, 255,255,255,0x00);
    SDL_Rect a = { 152,60, 6,10 };
    SDL_RenderFillRect(ren, &a);
     SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
    SDL_RenderDrawPoint(ren, 155, 67);
    SDL_RenderDrawLine(ren, 20, 70, 25, 64);
    SDL_RenderDrawLine(ren, 25, 64, 30, 70);
    SDL_RenderDrawLine(ren, 25, 64, 25, 58);
    SDL_RenderDrawLine(ren, 25, 60, 28,63 );
    SDL_RenderDrawLine(ren, 25, 60, 22, 63);
    SDL_Rect c = { 23,53, 5,5 };
    SDL_RenderDrawRect(ren,&c);
    SDL_RenderPresent(ren);
    SDL_Delay(5000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
