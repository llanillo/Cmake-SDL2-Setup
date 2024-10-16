#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <../SDL2/SDL.h>
using namespace std;

SDL_Window* window = nullptr;
SDL_Surface* screen = nullptr;

#define windowWidth 640
#define windowHeight 400

#define title "SM2024 - Lab 2 - Nazwisko Imie"

SDL_Color getPixel (int x, int y);
void setPixelSurface(int x, int y, Uint8 R, Uint8 G, Uint8 B);
void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B);
void clearScreen(Uint8 R, Uint8 G, Uint8 B);
void loadBmp(char const* name);
void functionOne();
void functionTwo();
void functionThree();
void functionFour();
void functionFive();
void functionSix();
void functionSeven();
void functionEight();
void functionNine();


void functionOne() {

    //...

    SDL_UpdateWindowSurface(window);
}

void functionTwo() {

    //...

    SDL_UpdateWindowSurface(window);
}

void functionThree() {

    //...

    SDL_UpdateWindowSurface(window);
}

void functionFour() {

    //...

    SDL_UpdateWindowSurface(window);
}

void functionFive() {

    //...

    SDL_UpdateWindowSurface(window);
}

void functionSix() {

    //...

    SDL_UpdateWindowSurface(window);
}

void functionSeven() {

    //...

    SDL_UpdateWindowSurface(window);
}

void functionEight() {

    //...

    SDL_UpdateWindowSurface(window);
}

void functionNine() {

    //...

    SDL_UpdateWindowSurface(window);
}

void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B) {

    if ((x>=0) && (x < windowWidth) && (y >= 0) && (y < windowHeight)) {
        /* Replacing each color component with corresponding color format*/
        Uint32 pixel = SDL_MapRGB(screen->format, R, G, B);

        /* Obtaining size of single pixel */
        int bpp = screen->format->BytesPerPixel;

        /* Calculating address of pixel */
        Uint8 *p1 = (Uint8 *)screen->pixels + (y*2) * screen->pitch + (x*2) * bpp;
        Uint8 *p2 = (Uint8 *)screen->pixels + (y*2+1) * screen->pitch + (x*2) * bpp;
        Uint8 *p3 = (Uint8 *)screen->pixels + (y*2) * screen->pitch + (x*2+1) * bpp;
        Uint8 *p4 = (Uint8 *)screen->pixels + (y*2+1) * screen->pitch + (x*2+1) * bpp;

        /* Setting value of pixel according to the given surface's format*/
        switch(bpp) {
            case 1: //8-bit
                *p1 = pixel;
                *p2 = pixel;
                *p3 = pixel;
                *p4 = pixel;
                break;

            case 2: //16-bit
                *(Uint16 *)p1 = pixel;
                *(Uint16 *)p2 = pixel;
                *(Uint16 *)p3 = pixel;
                *(Uint16 *)p4 = pixel;
                break;

            case 3: //24-bit
                p1[0] = pixel & 0xff;
                p1[1] = (pixel >> 8) & 0xff;
                p1[2] = (pixel >> 16) & 0xff;
                p2[0] = pixel & 0xff;
                p2[1] = (pixel >> 8) & 0xff;
                p2[2] = (pixel >> 16) & 0xff;
                p3[0] = pixel & 0xff;
                p3[1] = (pixel >> 8) & 0xff;
                p3[2] = (pixel >> 16) & 0xff;
                p4[0] = pixel & 0xff;
                p4[1] = (pixel >> 8) & 0xff;
                p4[2] = (pixel >> 16) & 0xff;
                break;

            case 4: //32-bit
                *(Uint32 *)p1 = pixel;
                *(Uint32 *)p2 = pixel;
                *(Uint32 *)p3 = pixel;
                *(Uint32 *)p4 = pixel;
                break;

            default:
                std::cout << "Unknown surface format" << std::endl;
        }
    }
}

SDL_Color getPixelSurface(int x, int y, SDL_Surface *surface) {
    SDL_Color color ;
    Uint32 col = 0 ;
    if ((x >= 0) && (x < windowWidth) && (y >= 0) && (y < windowHeight)) {

        //Defining position
        char* pPosition=(char*)surface->pixels ;

        //Y-axis offset
        pPosition+=(surface->pitch*y) ;

        //X-axis offset
        pPosition+=(surface->format->BytesPerPixel*x);

        //Copying pixel's data
        memcpy(&col, pPosition, surface->format->BytesPerPixel);

        //Color converting
        SDL_GetRGB(col, surface->format, &color.r, &color.g, &color.b);
    }
    return ( color ) ;
}

void clearScreen(Uint8 R, Uint8 G, Uint8 B) {
    SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, R, G, B));
    SDL_UpdateWindowSurface(window);
}

void loadBmp(const char *name) {
    SDL_Surface* bmp = SDL_LoadBMP(name);
    if (!bmp) {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
    }else {
        SDL_Color color;
        for (int yy = 0; yy < bmp->h; yy++) {
            for (int xx = 0; xx < bmp->w; xx++) {
                color = getPixelSurface(xx, yy, bmp);
                setPixel(xx, yy, color.r, color.g, color.b);
            }
        }
        SDL_FreeSurface(bmp);
        SDL_UpdateWindowSurface(window);
    }
}

__attribute__((unused)) void setPixelSurface(int x, int y, Uint8 R, Uint8 G, Uint8 B) {

    if ((x>=0) && (x < windowWidth * 2) && (y >= 0) && (y < windowHeight * 2)) {
        /* Replacing each color component with corresponding color format*/
        Uint32 pixel = SDL_MapRGB(screen->format, R, G, B);

        /* Obtaining size of single pixel */
        int bpp = screen->format->BytesPerPixel;

        /* Calculating address of pixel */
        Uint8 *p = (Uint8 *)screen->pixels + y * screen->pitch + x * bpp;

        /* Setting value of pixel according to the given surface's format*/
        switch(bpp) {
            case 1: //8-bit
                *p = pixel;
                break;

            case 2: //16-bit
                *(Uint16 *)p = pixel;
                break;

            case 3: //24-bit
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
                break;

            case 4: //32-bit
                *(Uint32 *)p = pixel;
                break;

            default:
                std::cout << "Unknown surface format" << std::endl;
        }
    }
}

SDL_Color getPixel(int x, int y) {
    SDL_Color color ;
    Uint32 col = 0 ;
    if ((x >= 0) && (x < windowWidth) && (y >= 0) && (y < windowHeight)) {

        //Defining position
        char* pPosition=(char*)screen->pixels ;

        //Y-axis offset
        pPosition+=(screen->pitch*y*2) ;

        //X-axis offset
        pPosition+=(screen->format->BytesPerPixel * x * 2);

        //Copying pixel's data
        memcpy(&col, pPosition, screen->format->BytesPerPixel);

        //Color converting
        SDL_GetRGB(col, screen->format, &color.r, &color.g, &color.b);
    }
    return ( color ) ;
}

void line(int x1, int y1, int x2, int y2, Uint8 R, Uint8 G, Uint8 B) {

    int dx = x2 - x1;
    int dy = y2 - y1;

    int kx = 1;
    int ky = 1;

    if (dx<0) {
        dx = x1 - x2;
        kx = -1;
    }

    if (dy<0) {
        dy = y1 - y2;
        ky = -1;
    }

    int d;

    int x = x1;
    int y = y1;

    setPixel(x, y, R, G, B);

    if (dx >= dy) {
        d = 2*dy - dx;
        while (x != x2) {
            if (d >=0) {
                x+=kx;
                y+=ky;
                d = d + 2*(dy-dx);
            }
            else {
                x+=kx;
                d = d + 2*dy;
            }
            setPixel(x, y, R, G, B);
        }
    }
    else {
        d = 2 * dx - dy;
        while (y != y2) {
            if (d >= 0) {
                y += ky;
                x += kx;
                d = d + 2 * (dx - dy);
            }
            else {
                y += ky;
                d = d + 2 * dx;
            }
            setPixel(x, y, R, G, B);
        }
    }
    SDL_UpdateWindowSurface(window);
}


int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth * 2, windowHeight * 2, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    screen = SDL_GetWindowSurface(window);
    if (screen == nullptr) {
        fprintf(stderr, "SDL_GetWindowSurface Error: %s\n", SDL_GetError());
        return false;
    }
    SDL_UpdateWindowSurface(window);
    bool exitProgram = false;
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exitProgram = true;
                break;
            case SDL_KEYDOWN: {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    exitProgram = true;
                if (event.key.keysym.sym == SDLK_1)
                    functionOne();
                if (event.key.keysym.sym == SDLK_2)
                    functionTwo();
                if (event.key.keysym.sym == SDLK_3)
                    functionThree();
                if (event.key.keysym.sym == SDLK_4)
                    functionFour();
                if (event.key.keysym.sym == SDLK_5)
                    functionFive();
                if (event.key.keysym.sym == SDLK_6)
                    functionSix();
                if (event.key.keysym.sym == SDLK_7)
                    functionSeven();
                if (event.key.keysym.sym == SDLK_8)
                    functionEight();
                if (event.key.keysym.sym == SDLK_9)
                    functionNine();
                if (event.key.keysym.sym == SDLK_a)
                    loadBmp("../images/file1.bmp");
                if (event.key.keysym.sym == SDLK_s)
                    loadBmp("../images/file2.bmp");
                if (event.key.keysym.sym == SDLK_d)
                    loadBmp("../images/file3.bmp");
                if (event.key.keysym.sym == SDLK_f)
                    loadBmp("../images/file4.bmp");
                if (event.key.keysym.sym == SDLK_g)
                    loadBmp("../images/file5.bmp");
                if (event.key.keysym.sym == SDLK_h)
                    loadBmp("../images/file6.bmp");
                if (event.key.keysym.sym == SDLK_b)
                    clearScreen(0, 0, 0);
                else
                    break;
            }
        }
        if (exitProgram) break;
    }

    if (screen) {
        SDL_FreeSurface(screen);
    }

    if (window) {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
    return 0;
}
