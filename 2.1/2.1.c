#include <SDL2/SDL.h>

#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL2_gfxPrimitives_font.h>


#include <stdio.h>

struct cd{
	int x;
	int y;
}cd ;

typedef struct clique{
    int nr;
    SDL_Point local;
}clique;

void eventGenerator(int n) {
    SDL_Event nevt;
    SDL_UserEvent uevt;
    uevt.type = SDL_USEREVENT;
    uevt.code = n;
    uevt.data1 = NULL;
    uevt.data2 = NULL;
    
    nevt.user = uevt;
    SDL_PushEvent(&nevt);
}

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
    SDL_Window* window = SDL_CreateWindow("2.1",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 500, SDL_WINDOW_SHOWN
                      	);
    SDL_Renderer* ren = SDL_CreateRenderer(window, -1, 0);

    	
	    Uint32 wait = 25;
    int nc=0;
    SDL_Event evt;
    SDL_Point local={0,0};
    int cliques=0;
    Uint32 lastclick=0;
    clique vt[10];
    int cvt=0;

    while (!SDL_QuitRequested()) {
            int isevt = AUX_WaitEventTimeout(&evt, &wait);
     switch (evt.type) {
		case SDL_MOUSEBUTTONDOWN:
			if (nc==0) {
				nc = 1;
				lastclick = SDL_GetTicks();
				local = (SDL_Point){evt.button.x,evt.button.y};
                cliques=1;

			} else {
				if (evt.button.x == local.x && evt.button.y==local.y && SDL_GetTicks()-lastclick < 250) {
					lastclick = SDL_GetTicks();
					cliques++;
				} else {
				    nc = 0;
					eventGenerator(cliques);
				}
			}
			break;

		default:
			if (nc && SDL_GetTicks()-lastclick >= 250) {
				nc = 0;
				eventGenerator(cliques);
			}
			break;
	}

    if(isevt && evt.type==SDL_USEREVENT && evt.user.code > 1){
            vt[cvt%10].local = (SDL_Point){local.x,local.y};
            vt[cvt%10].nr= evt.user.code;
        }



  
   if(wait<=0){
        wait=250;
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 255,255,255,0x00);
        
        char string[20];
        if(cvt <10){
            for(int i=0;i<=cvt;i++){
                    sprintf(string,"%d",vt[i].nr);
                    stringRGBA(ren,vt[i].local.x,vt[i].local.y,string,0,0,0,255);  
                }
        }
        else{
            for(int i=0;i<10;i++){
                    sprintf(string,"%d",vt[i].nr);
                    stringRGBA(ren,vt[i].local.x,vt[i].local.y,string,0,0,0,255);  
                }
        }
        SDL_RenderPresent(ren);
    }

    

    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
