#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>

int AUX_WaitEventTimeout(SDL_Event* evt, Uint32 * ms) {
	Uint32 ww = SDL_GetTicks();
	int isevt = SDL_WaitEventTimeout(evt, *ms);
	Uint32 diff = SDL_GetTicks()-ww, nwait = *ms-diff;
	if (nwait > *ms)
		*ms = 0;
	else
		*ms -= diff;
	return isevt;
}



int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Sistema Solar com evento",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         600, 300, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    Uint32 wait,ww;
    wait = 20;
    SDL_Event evt;
    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 18, 10, 30,0x00);
    SDL_RenderClear(ren);
    double x =1;
    int cor = 18;
    while(!SDL_QuitRequested()){
        ww= SDL_GetTicks();
        int isevt= AUX_WaitEventTimeout(&evt, &wait);
        
        if(isevt){
 
                if(evt.type == SDL_MOUSEBUTTONDOWN){    
                        cor+=18;
                        
                    }

                }
        if(wait<=0){
        wait =20;
    	SDL_SetRenderDrawColor(ren, cor%255, cor%120, 30,0x00);
    	SDL_RenderClear(ren);
    	int amp=120;
    	
    	
    	
    	filledCircleRGBA(ren,300,150,70,255, 223, 0,255);
    	circleRGBA(ren,300,150,120,255, 255,255,255);
    	filledCircleRGBA(ren,300+(amp*cos(x)),150+(amp*sin(x)),25,0, 119, 190,255);
   	    x+=0.0083;
    	SDL_RenderPresent(ren);
}

    }
   
    
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
