#include <SDL2/SDL.h>



struct cd{
	int x;
	int y;
}cd ;


int main (int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("1.5.1",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 500, SDL_WINDOW_SHOWN
                      	);
    SDL_Renderer* ren = SDL_CreateRenderer(window, -1, 0);
	
	
	struct cd    p1 = {.x = 30, .y = 200},p2 = {.x = 30, .y = 300},p3 = {.x = 30, .y = 400};
    SDL_Rect r1 = {p1.x,p1.y,100,20},r2 = {p2.x,p2.y,100,20},r3 = {p3.x,p3.y,100,20};
    
    
    int wait,ww,mousex, mousey;
    SDL_Event evt;
    while (!SDL_QuitRequested()) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 255,0,0,0x00);
        r3.x= mousex;
        r3.y = mousey;
        SDL_RenderFillRect(ren, &r1);
        SDL_RenderFillRect(ren, &r2);
        SDL_RenderFillRect(ren, &r3);
        SDL_RenderPresent(ren);
        wait = 30;
        ww = SDL_GetTicks();
        int isevt= SDL_WaitEventTimeout(&evt, wait);
        if(isevt){
                wait -= (SDL_GetTicks()-ww);
                if (evt.type == SDL_MOUSEMOTION) {
				mousex = evt.motion.x;
				mousey = evt.motion.y;}
                
            
                
             else if (evt.type == SDL_KEYDOWN) {
	            switch (evt.key.keysym.sym) {
	                case SDLK_UP:
	                	if (r2.y > 0) {
	                		r2.y -= 15;
						} else {
							r2.y=0;
						}
	                    break;
	                case SDLK_DOWN:
	                	if (r2.y+20 < 500) {
	                    	r2.y += 15;
	                	} else {
	                		r2.y=480;
						}
	                    break;
	                case SDLK_LEFT:
	                	if (r2.x > 0) {
	                    	r2.x -= 15;
	                	} else {
	                		r2.x=0;
						}
	                    break;
	                case SDLK_RIGHT:
	                	if (r2.x+100 < 500) {
	                    	r2.x += 10;
	                	} else {
	                		r2.x = 400;
						}
	                    break;}
            }
            else wait = 30;

        }
        if (r1.x < 500 )
			r1.x++;

		else
			r1.x--;
        

    

    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
