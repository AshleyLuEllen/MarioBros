
#include <stdio.h>
#include "SDL_Plotter.h"

//Threaded Function
static int Sound(void *data) {
    param *p = (param *) data;
    p->running = true;
    Mix_Chunk *gScratch = NULL;
    gScratch = Mix_LoadWAV(p->name.c_str());
    
    while (p->running) {
        SDL_mutexP(p->mut);
        SDL_CondWait(p->cond, p->mut);
        Mix_PlayChannel(-1, gScratch, 0);
        p->play = false;
        SDL_mutexV(p->mut);
    }
    
    Mix_FreeChunk(gScratch);
    p->running = false;
    return 0;
}

// SDL Plotter Function Deffinitions

SDL_Plotter::SDL_Plotter(int r, int c, bool WITH_SOUND) {
    row = r;
    col = c;
    leftMouseButtonDown = false;
    quit = false;
    SOUND = WITH_SOUND;
    
    SDL_Init(SDL_INIT_AUDIO);
    
    window = SDL_CreateWindow("SDL2 Pixel Drawing",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, col, row, 0);
    
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    texture = SDL_CreateTexture(renderer,
                                SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_STATIC, col, row);
    
    pixels = new Uint32[col * row];
    
    memset(pixels, WHITE_, col * row * sizeof(Uint32));
    
    //SOUND Thread Pool
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    soundCount = 0;
}

SDL_Plotter::~SDL_Plotter() {
    delete[] pixels;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDL_Plotter::update() {
    SDL_UpdateTexture(texture, NULL, pixels, col * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

bool SDL_Plotter::getQuit() {
    return quit;
}

bool SDL_Plotter::kbhit() {
    bool flag = false;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            flag = true;
        } else if (event.type == SDL_QUIT) {
            quit = true;
        } else if (event.type == SDL_MOUSEBUTTONUP) {
            SDL_PushEvent(&event);
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_PushEvent(&event);
        } else if (event.type == SDL_MOUSEMOTION) {
            SDL_PushEvent(&event);
        }
    }
    return flag;
}

char SDL_Plotter::getKey() {
    
    char key = '\0';
    
    currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_A]) key = 'A';
    else if (currentKeyStates[SDL_SCANCODE_B]) key = 'B';
    else if (currentKeyStates[SDL_SCANCODE_C]) key = 'C';
    else if (currentKeyStates[SDL_SCANCODE_D]) key = 'D';
    else if (currentKeyStates[SDL_SCANCODE_E]) key = 'E';
    else if (currentKeyStates[SDL_SCANCODE_F]) key = 'F';
    else if (currentKeyStates[SDL_SCANCODE_G]) key = 'G';
    else if (currentKeyStates[SDL_SCANCODE_H]) key = 'H';
    else if (currentKeyStates[SDL_SCANCODE_I]) key = 'I';
    else if (currentKeyStates[SDL_SCANCODE_J]) key = 'J';
    else if (currentKeyStates[SDL_SCANCODE_K]) key = 'K';
    else if (currentKeyStates[SDL_SCANCODE_L]) key = 'L';
    else if (currentKeyStates[SDL_SCANCODE_M]) key = 'M';
    else if (currentKeyStates[SDL_SCANCODE_N]) key = 'N';
    else if (currentKeyStates[SDL_SCANCODE_O]) key = 'O';
    else if (currentKeyStates[SDL_SCANCODE_P]) key = 'P';
    else if (currentKeyStates[SDL_SCANCODE_Q]) key = 'Q';
    else if (currentKeyStates[SDL_SCANCODE_R]) key = 'R';
    else if (currentKeyStates[SDL_SCANCODE_S]) key = 'S';
    else if (currentKeyStates[SDL_SCANCODE_T]) key = 'T';
    else if (currentKeyStates[SDL_SCANCODE_U]) key = 'U';
    else if (currentKeyStates[SDL_SCANCODE_V]) key = 'V';
    else if (currentKeyStates[SDL_SCANCODE_W]) key = 'W';
    else if (currentKeyStates[SDL_SCANCODE_X]) key = 'X';
    else if (currentKeyStates[SDL_SCANCODE_Y]) key = 'Y';
    else if (currentKeyStates[SDL_SCANCODE_Z]) key = 'Z';
    else if (currentKeyStates[SDL_SCANCODE_1]) key = '1';
    else if (currentKeyStates[SDL_SCANCODE_2]) key = '2';
    else if (currentKeyStates[SDL_SCANCODE_3]) key = '3';
    else if (currentKeyStates[SDL_SCANCODE_4]) key = '4';
    else if (currentKeyStates[SDL_SCANCODE_5]) key = '5';
    else if (currentKeyStates[SDL_SCANCODE_6]) key = '6';
    else if (currentKeyStates[SDL_SCANCODE_7]) key = '7';
    else if (currentKeyStates[SDL_SCANCODE_8]) key = '8';
    else if (currentKeyStates[SDL_SCANCODE_9]) key = '9';
    else if (currentKeyStates[SDL_SCANCODE_0]) key = '0';
    else if (currentKeyStates[SDL_SCANCODE_SPACE]) key = ' ';
    else if (currentKeyStates[SDL_SCANCODE_DOWN]) key = DOWN_ARROW;
    else if (currentKeyStates[SDL_SCANCODE_UP]) key = UP_ARROW;
    else if (currentKeyStates[SDL_SCANCODE_LEFT]) key = LEFT_ARROW;
    else if (currentKeyStates[SDL_SCANCODE_RIGHT]) key = RIGHT_ARROW;
    else if (currentKeyStates[SDL_SCANCODE_RETURN]) key = SDL_SCANCODE_RETURN;
    else if (currentKeyStates[SDL_SCANCODE_ESCAPE]) quit = true;
    
    return key;
}

void SDL_Plotter::plotPixel(int x, int y, int r, int g, int b) {
    pixels[y * col + x] = RED_SHIFT * r + GREEN_SHIFT * g + BLUE_SHIFT * b;
}

void SDL_Plotter::plotPixel(int x, int y, Color color) {
    pixels[y * col + x] = RED_SHIFT * color.R + GREEN_SHIFT * color.G + BLUE_SHIFT * color.B;
}

void SDL_Plotter::clear() {
    memset(pixels, WHITE_, col * row * sizeof(Uint32));
}

int SDL_Plotter::getRow() {
    return row;
}

int SDL_Plotter::getCol() {
    return col;
}

void SDL_Plotter::initSound(string sound) {
    //int  *threadReturnValue;
    
    if (!soundMap[sound].running) {
        param *p = &soundMap[sound];
        p->name = sound;
        p->cond = SDL_CreateCond();
        p->mut = SDL_CreateMutex();
        
        p->threadID = SDL_CreateThread(Sound, sound.c_str(), (void *) p);
    }
}

void SDL_Plotter::setQuit(bool flag) {
    this->quit = flag;
}

void SDL_Plotter::playSound(string sound) {
    if (soundMap[sound].running) {
        SDL_CondSignal(soundMap[sound].cond);
    }
}

void SDL_Plotter::quitSound(string sound) {
    soundMap[sound].running = false;
    SDL_CondSignal(soundMap[sound].cond);
}

void SDL_Plotter::Sleep(int ms) {
    SDL_Delay(ms);
}

bool SDL_Plotter::getMouseClick(int &x, int &y) {
    bool flag = false;
    x = y = 0;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEBUTTONUP) {
            //Get mouse position
            flag = true;
            SDL_GetMouseState(&x, &y);
        } else {
            SDL_PushEvent(&event);
        }
    }
    return flag;
}

bool SDL_Plotter::getMouseDown(int &x, int &y) {
    bool flag = false;
    x = y = 0;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            //Get mouse position
            flag = true;
            SDL_GetMouseState(&x, &y);
        } else {
            SDL_PushEvent(&event);
        }
    }
    return flag;
}

bool SDL_Plotter::getMouseUp(int &x, int &y) {
    bool flag = false;
    x = y = 0;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEBUTTONUP) {
            //Get mouse position
            flag = true;
            SDL_GetMouseState(&x, &y);
        } else {
            SDL_PushEvent(&event);
        }
    }
    return flag;
}

bool SDL_Plotter::getMouseMotion(int &x, int &y) {
    bool flag = false;
    x = y = 0;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEMOTION) {
            //Get mouse position
            flag = true;
            SDL_GetMouseState(&x, &y);
        } else {
            SDL_PushEvent(&event);
        }
    }
    return flag;
}

void SDL_Plotter::getMouseLocation(int &x, int &y) {
    SDL_GetMouseState(&x, &y);
    cout << x << " " << y << endl;
}

SDL_Surface* SDL_Plotter::loadImage(string imagename)
{
    SDL_Surface* finalImage = NULL;
    SDL_Surface* loadedImage = SDL_LoadBMP(imagename.c_str());
    SDL_Surface* screen = SDL_GetWindowSurface(window);

    if(loadedImage != NULL)
    {
      finalImage = SDL_ConvertSurface(loadedImage, screen->format, NULL);
    }
    SDL_FreeSurface(loadedImage);

    return finalImage;
}

void displayImage(SDL_Surface* image, int x, int y)
{
    Uint32 *pixs = (Uint32 *)image->pixels;
    int width = image->w;
    int height = image->h;
    for(int r = 0; r < height; r++)
    {
      for(int c = 0; c < width; c++)
      {
        pixels[ ( (y + r) * col ) + ((x - (width  / 2)) + c) ] = pixs[ ( r * width ) + c];
      }
    }
}
