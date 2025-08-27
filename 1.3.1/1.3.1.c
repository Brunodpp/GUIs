#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Sistema Solar",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         600, 300, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 18, 10, 30,0x00);
    SDL_RenderClear(ren);
    double x =1;
    while(x<=20){
    	SDL_SetRenderDrawColor(ren, 18, 10, 30,0x00);
    	SDL_RenderClear(ren);
    	int amp=120;
    	
    	
    	
    	filledCircleRGBA(ren,300,150,70,255, 223, 0,255);
    	circleRGBA(ren,300,150,120,255, 255,255,255);
    	filledCircleRGBA(ren,300+(amp*cos(x)),150+(amp*sin(x)),25,0, 119, 190,255);
   	    x+=0.0083;
    	SDL_RenderPresent(ren);
    	SDL_Delay(100); 

    }
   
    
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
