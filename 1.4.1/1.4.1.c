#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect r = { 40,20, 10,10 };
    SDL_Event evt;
    SDL_Rect clicked_rects[10];
	int rect_count = 0;
    while (!SDL_QuitRequested()) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        
	for (int i = 0; i < rect_count; i++) {
        SDL_SetRenderDrawColor(ren, clicked_rects[i].x, 255-(2*clicked_rects[i].y), 40, 0x00);
    	SDL_RenderFillRect(ren, &clicked_rects[i]);
	}
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);

        SDL_WaitEvent(&evt);
        if (evt.type == SDL_KEYDOWN) {
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    if(r.y-5<0){r.y=0; break;}
                    else{
                    r.y -= 5;
                    break;}
                case SDLK_DOWN:
                    if(r.y+5>90){r.y=90; break;}
                    else{
                    r.y += 5;
                    break;}
                case SDLK_LEFT:
                    if(r.x-5<0){r.x=0; break;}
                    else{
                    r.x -= 5;
                    break;}
                case SDLK_RIGHT:
                    if(r.x+5>190){r.x=190; break;}
                    else{
                    r.x += 5;
                    break;}
                
                	
                
                	
            }
        }
      if(evt.type == SDL_MOUSEBUTTONDOWN){
      	switch(evt.button.button){
      		case SDL_BUTTON_LEFT:
      			if (rect_count < 10) {
                	SDL_Rect w = {evt.button.x, evt.button.y, 10, 20};
                	clicked_rects[rect_count++] = w;
            	}
                else{
                     SDL_Rect w = {evt.button.x, evt.button.y, 10, 20};
                     rect_count=0;

                	 clicked_rects[rect_count++] = w; 
                        
                    
                }
                
        		break;
        		 
      			
      	}
      
      }
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
