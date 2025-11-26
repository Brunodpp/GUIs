#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <SDL2/SDL_image.h>

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
    SDL_Window* win = SDL_CreateWindow("Goblin",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         256, 256, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    SDL_Texture * atk = IMG_LoadTexture(ren, "./ataque.png"),
				* idle = IMG_LoadTexture(ren, "./idle.png");
    Uint32 wait;
    wait = 20;
    SDL_Event evt;
    /* EXECUÇÃO */
    int ataque=0;
    int idt=0;
    int att=0;
    double x =1;
    int cor = 18;
        SDL_SetRenderDrawColor(ren,0,0,0,255);
		SDL_RenderClear(ren);
    while(!SDL_QuitRequested()){
        
			
        int isevt= AUX_WaitEventTimeout(&evt, &wait);
        
        if(isevt && evt.type == SDL_MOUSEBUTTONDOWN){
  
                        ataque=1;
                    

                }
        if(wait<=0){
    wait =200;
                SDL_SetRenderDrawColor(ren,0,0,0,255);
		SDL_RenderClear(ren);

        SDL_FRect id = {0,0,256,256};
        if(ataque==1){
            if(att>7){
                att=0; 
                ataque=0;
                
                }
            idt=0;
            SDL_Rect recorte = {64*(att),0,64,64};
            SDL_RenderCopyExF(ren,atk,&recorte,&id,0,NULL,SDL_FLIP_NONE);
            att+=1;
            
        }
        else{
        idt+=1;
        
        SDL_Rect recorte = {64*(idt%4),0,64,64};
        SDL_RenderCopyExF(ren,idle,&recorte,&id,0,NULL,SDL_FLIP_NONE);
    	}
        
        SDL_RenderPresent(ren);

    	
}
        
    }
   
    
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
