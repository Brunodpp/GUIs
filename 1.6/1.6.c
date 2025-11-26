#include <SDL2/SDL.h>

#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL2_gfxPrimitives_font.h>


#include <stdio.h>

struct cd{
	int x;
	int y;
}cd ;

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

int main (int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("1.6",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 500, SDL_WINDOW_SHOWN
                      	);
    SDL_Renderer* ren = SDL_CreateRenderer(window, -1, 0);
	
	
	struct cd    p1 = {.x = 30, .y = 200},p2 = {.x = 30, .y = 300},p3 = {.x = 30, .y = 400};
    SDL_Rect r1 = {p1.x,p1.y,100,20},r2 = {p2.x,p2.y,100,20},r3 = {p3.x,p3.y,100,20};
    SDL_Rect chegada = {450,0,30,500};
    
    
    int mousex, mousey;
    Uint32 wait,ww;
    SDL_Event evt;
        wait = 10;
int r1b=0;
int r2b=0;
int r3b=0;
int primeiro =0;
    while (!SDL_QuitRequested()) {


  
        int isevt= AUX_WaitEventTimeout(&evt, &wait);
        if(isevt){

                if (evt.type == SDL_MOUSEMOTION) {
                
				SDL_GetMouseState(&mousex,&mousey);}
                
            
                
             else if (evt.type == SDL_KEYDOWN) {
                if(r3b!=1){
	            switch (evt.key.keysym.sym) {
                    
	                case SDLK_LEFT:
	                	if (r2.x > 0) {
	                    	r2.x -= 15;
	                	} else {
	                		r2.x=0;
						}
	                    break;
	                case SDLK_RIGHT:
	                	if (r2.x+100 < 400) {
	                    	r2.x += 10;
	                	} else {
	                		r2.x = 350;
                            r3b=1;
                                if(primeiro==0){primeiro=2;}
						}
	                    break;}}
            }
  

        }
        if(wait<=0){
            wait=10;
        if (r1.x < 350 ){
			r1.x++;}
        else{r1b=1;if(primeiro==0){primeiro=1;}}
                SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 255,0,0,0x00);
        
      if(r2b!=1){
            if(mousex>=350){
            r2b=1; 
                r3.x=350;
                if(primeiro==0){primeiro=3;}
            }
            else{
            r3.x= mousex;}
        }
        
        SDL_RenderFillRect(ren, &r1);
        SDL_RenderFillRect(ren, &r2);
        SDL_RenderFillRect(ren, &r3);
        SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
        SDL_RenderFillRect(ren, &chegada);
        
        if(r1b==1 && r2b==1 && r3b==1){
                char string[20];
                int sleep;
                uint aa= SDL_GetTicks();
                        sprintf(string,"O retangulo %d ganhou!",primeiro);
                        stringRGBA(ren,250,100,string,0,0,0,255);
                        SDL_RenderPresent(ren);
                while(SDL_GetTicks()-aa<2000){
         
                    sleep=1;
                    r1b=0;
                    r1.x = 30;
r2.x=30;
r3.x=30;

                    r2b=0;
                    r3b=0;
                    primeiro=0;
                }
        


            }
        SDL_RenderPresent(ren);
}

    

    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
