#include <SDL2/SDL.h>

#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL2_gfxPrimitives_font.h>


#include <stdio.h>




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
    SDL_Window* window = SDL_CreateWindow("2.2",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 500, SDL_WINDOW_SHOWN
                      	);
    SDL_Renderer* ren = SDL_CreateRenderer(window, -1, 0);

    	
int dentro(SDL_Rect *r, int mx, int my) {
    return (mx >= r->x && mx <= r->x + r->w &&
            my >= r->y && my <= r->y + r->h);
}


    SDL_Rect rect = {100, 100, 200, 50};
    SDL_Point posini = {rect.x, rect.y};
    SDL_Point posCini;

    int press = 0;
    int state = 0;
    int cor=0;
    Uint32 wait = 20;
    SDL_Event evt;
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    while (!SDL_QuitRequested()) {
            int isevt = AUX_WaitEventTimeout(&evt, &wait);
        if(isevt){
            switch(evt.type){
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    if(state==2 && keys[SDL_SCANCODE_ESCAPE]){
                        rect.x = posini.x;
                        rect.y = posini.y;
                        press = 0;
                        state = 3;
                        } break;
                case SDL_MOUSEBUTTONDOWN:
                    posini = (SDL_Point){rect.x,rect.y};
                    posCini = (SDL_Point){evt.button.x,evt.button.y};

                    if (dentro(&rect, evt.button.x, evt.button.y)){
                        press = 1;}

                    break;
                case SDL_MOUSEBUTTONUP:

                    posini = (SDL_Point){rect.x, rect.y};

                    if (evt.button.x == posCini.x && evt.button.y == posCini.y){
                        state = 1;  }

                    if (state == 2){
                        state = 4;  }

                    press = 0;
                    break;
                    case SDL_MOUSEMOTION:
                    if (press &&
                        (evt.motion.x != posCini.x ||
                         evt.motion.y != posCini.y))
                    {
                        state = 2; // arrastando
                        rect.x = posini.x +
                                 (evt.motion.x - posCini.x);
                        rect.y = posini.y +
                                 (evt.motion.y - posCini.y);
                    }
                    break;
                
        




                }
         }
          if (wait == 0) {

            wait = 20;
            
            SDL_SetRenderDrawColor(ren, 255,255,255,255);
            SDL_RenderClear(ren);
            if(state==1){cor+=30;}
            SDL_SetRenderDrawColor(ren, (10+cor)%256,(200+cor)%256,(78+cor)%256,255);
            SDL_RenderFillRect(ren, &rect);

            

            SDL_RenderPresent(ren);
        }

    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
