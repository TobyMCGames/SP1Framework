// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "Map.h"
#include "SplashScreen.h"
#include "mainmenu.h"
#include "inventory.h"
#include "UI.h"
#include "gameover.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

double  g_dElapsedTime; //time since start of program
double  g_dDeltaTime; //val of update(dt)
SKeyEvent g_skKeyEvent[(int)EKEYS::K_COUNT];
SMouseEvent g_mouseEvent;

// Game specific variables here
Player  g_sChar;
item_general g_sItem;
Map map;
SplashScreen splashscreen;
mainmenu _mainmenu;
inventory _inventory;
gameover _gameover;
UI ui;
EGAMESTATES g_eGameState = EGAMESTATES::S_SPLASHSCREEN; // initial state

// Console object
Console g_Console(180, 42, "Escape 2020");  // Setting console size and name (width, height, programme name)


//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init( void )
{
    // Set precision for floating point output
    g_dElapsedTime = 0.0;    

    // sets the initial state for the game
    g_eGameState = EGAMESTATES::S_SPLASHSCREEN;
    
    //Temporary Load
    loadMainMenu();
    loadGameOver();
    splashscreen.loadSplashScreen();
    ui.loadstate();
    ui.loaddisasterindicator();

    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

    // remember to set your keyboard handler, so that your functions can be notified of input events
    g_Console.setKeyboardHandler(keyboardHandler);
    g_Console.setMouseHandler(mouseHandler);
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Get all the console input events
//            This function sets up the keyboard and mouse input from the console.
//            We will need to reset all the keyboard status, because no events will be sent if no keys are pressed.
//
//            Remember to set the handlers for keyboard and mouse events.
//            The function prototype of the handler is a function that takes in a const reference to the event struct
//            and returns nothing. 
//            void pfKeyboardHandler(const KEY_EVENT_RECORD&);
//            void pfMouseHandlerconst MOUSE_EVENT_RECORD&);
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput( void )
{
    // then call the console to detect input from user
    g_Console.readConsoleInput();    
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the keyboard input. Whenever there is a keyboard event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            The KEY_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any keyboard event in the Splashscreen state
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent - reference to a key event struct
// Output   : void
//--------------------------------------------------------------
void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent)
{    
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN:  // don't handle anything for the splash screen
        break;
    case EGAMESTATES::S_MAINMENU: 
        gameplayKBHandler(keyboardEvent);
        break;
    case EGAMESTATES::S_GAMEOVER:
        gameplayKBHandler(keyboardEvent);
        break;
    case EGAMESTATES::S_GAME: 
        gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the mouse input. Whenever there is a mouse event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            For the mouse event, if the mouse is not moved, no event will be sent, hence you should not reset the mouse status.
//            However, if the mouse goes out of the window, you would not be able to know either. 
//
//            The MOUSE_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any mouse event in the Splashscreen state
//            
// Input    : const MOUSE_EVENT_RECORD& mouseEvent - reference to a mouse event struct
// Output   : void
//--------------------------------------------------------------
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{    
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN:  // don't handle anything for the splash screen
        break;
    case EGAMESTATES::S_MAINMENU: gameplayMouseHandler(mouseEvent); 
        break;
    case EGAMESTATES::S_GAMEOVER: gameplayMouseHandler(mouseEvent);
        break;
    case EGAMESTATES::S_GAME: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the keyboard handler in the game state. Whenever there is a keyboard event in the game state, this function will be called.
//            
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent)
{
    // here, we map the key to our enums
    EKEYS key = EKEYS::K_COUNT;
    switch (keyboardEvent.wVirtualKeyCode)
    {
    case 0x57: key = EKEYS::K_W; break;
    case 0x53: key = EKEYS::K_S; break;
    case 0x41: key = EKEYS::K_A; break;
    case 0x44: key = EKEYS::K_D; break;
    case VK_TAB: key = EKEYS::K_TAB; break;
    case VK_SPACE: key = EKEYS::K_SPACE; break;
    case VK_RETURN: key = EKEYS::K_RETURN; break;
    }
    // a key pressed event would be one with bKeyDown == true
    // a key released event would be one with bKeyDown == false
    // if no key is pressed, no event would be fired.
    // so we are tracking if a key is either pressed, or released
    if (key != EKEYS::K_COUNT)
    {
        g_skKeyEvent[(int)key].keyDown = keyboardEvent.bKeyDown;
        g_skKeyEvent[(int)key].keyReleased = !keyboardEvent.bKeyDown;
    }    
}

//--------------------------------------------------------------
// Purpose  : This is the mouse handler in the game state. Whenever there is a mouse event in the game state, this function will be called.
//            
//            If mouse clicks are detected, the corresponding bit for that mouse button will be set.
//            mouse wheel, 
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{
    if (mouseEvent.dwEventFlags & MOUSE_MOVED) // update the mouse position if there are no events
    {
        g_mouseEvent.mousePosition = mouseEvent.dwMousePosition;
    }
    g_mouseEvent.buttonState = mouseEvent.dwButtonState;
    g_mouseEvent.eventFlags = mouseEvent.dwEventFlags;
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = time
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN: 
        splashScreenWait(); // game logic for the splash screen                 #217
        break;
    case EGAMESTATES::S_MAINMENU: 
        updateMenu();
        break;
    case EGAMESTATES::S_GAMEOVER:
        updateGameOver();
        break;
    case EGAMESTATES::S_GAME: 
        updateGame(); // gameplay logic when we are in the game                 #223
        break;
    }
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 3.0) // wait for 3 seconds to switch to game mode, else do nothing
        //Change this to test whatever u doing
        g_eGameState = EGAMESTATES::S_GAMEOVER; 
}

bool pressW = false, pressS = false , pressP = false; //probably can do something about this 
void updateMenu()
{
    processUserInput();
    switch (pressW)
    {
    case false:
        if (g_skKeyEvent[(int)EKEYS::K_W].keyDown) {
            _mainmenu.WSmenu(-1);
            pressW = true;
        }
    case true:
        if (g_skKeyEvent[(int)EKEYS::K_W].keyDown == false) {
            pressW = false;
        }
    }
    switch (pressS)
    {
    case false:
        if (g_skKeyEvent[(int)EKEYS::K_S].keyDown) {
            _mainmenu.WSmenu(1);
            pressS = true;
        }
    case true:
        if (g_skKeyEvent[(int)EKEYS::K_S].keyDown == false) {
            pressS = false;
        }
    }
    if (pressP == false)
    {
        if ((g_skKeyEvent[(int)EKEYS::K_RETURN].keyDown) || (g_skKeyEvent[(int)EKEYS::K_SPACE].keyDown))
        {
            switch (_mainmenu.getselector())
            {
                pressP = true;
            case 0: g_eGameState = EGAMESTATES::S_GAME; break;
            case 4: g_bQuitGame = true; break;
            }
        }
    }
    if ((g_skKeyEvent[(int)EKEYS::K_RETURN].keyDown != true) && (g_skKeyEvent[(int)EKEYS::K_SPACE].keyDown != true))
    {
        pressP = false;
    }
}

void updateGameOver()
{
    processUserInput();
    switch (pressW)
    {
    case false:
        if (g_skKeyEvent[(int)EKEYS::K_W].keyDown) {
            _gameover.WSmenu(-1);
            pressW = true;
        }
    case true:
        if (g_skKeyEvent[(int)EKEYS::K_W].keyDown == false) {
            pressW = false;
        }
    }
    switch (pressS)
    {
    case false:
        if (g_skKeyEvent[(int)EKEYS::K_S].keyDown) {
            _gameover.WSmenu(1);
            pressS = true;
        }
    case true:
        if (g_skKeyEvent[(int)EKEYS::K_S].keyDown == false) {
            pressS = false;
        }
    }
    if (pressP == false)
    {
        if ((g_skKeyEvent[(int)EKEYS::K_RETURN].keyDown) || (g_skKeyEvent[(int)EKEYS::K_SPACE].keyDown))
        {
            pressP = true;
            switch (_gameover.getSelector())
            {
            case 0: g_eGameState = EGAMESTATES::S_MAINMENU; break;
            case 1: g_bQuitGame = true; break;
            }
        }
    }
    if ((g_skKeyEvent[(int)EKEYS::K_RETURN].keyDown != true) && (g_skKeyEvent[(int)EKEYS::K_SPACE].keyDown != true))
    {
        pressP = false;
    }
}

void updateGame()       // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit   #261
    map.updateMap(g_dDeltaTime);
    moveCharacter();    // moves the character, collision detection, physics, etc                                    #230
                        // sound can be played here too.
    inventoryManagement();
}

void moveCharacter()
{    
    // Updating the location of the character based on the key release
    // providing a beep sound whenver we shift the character
    if (g_skKeyEvent[(int)EKEYS::K_W].keyDown)
    {
        g_sChar.setmodel('W');
        //Beep(1440, 30);
        if (map.collides('W', g_sChar) == false) {
            g_sChar.moveUP();
        }
        
    }
    if (g_skKeyEvent[(int)EKEYS::K_A].keyDown)
    {
        g_sChar.setmodel('A');
        //Beep(1440, 30);
        if (map.collides('A', g_sChar) == false) {
            g_sChar.moveLEFT();
        }
    }
    if (g_skKeyEvent[(int)EKEYS::K_S].keyDown)
    {
        g_sChar.setmodel('S');
        //Beep(1440, 30);
        if (map.collides('S', g_sChar) == false) {
            g_sChar.moveDOWN();
        }
        
    }
    if (g_skKeyEvent[(int)EKEYS::K_D].keyDown)
    {
        g_sChar.setmodel('D');
        //Beep(1440, 30);
        if (map.collides('D', g_sChar) == false) {
            g_sChar.moveRIGHT();
        }
    }
    if (g_skKeyEvent[(int)EKEYS::K_SPACE].keyDown)
    {
        g_sChar.changeActive();
        if (map.item_pickup(g_sChar.getFacing(), g_sChar, g_sItem) == true) {
            map.item_remove(g_sItem);
        }
    }
}


void inventoryManagement()
{
    if (g_skKeyEvent[(int)EKEYS::K_TAB].keyReleased)
    {
        _inventory.change_equipped_slot();
    }
    _inventory.renderEquipChange(g_Console);
}

void processUserInput()
{
    // quits the game if player hits the escape key
    if (g_skKeyEvent[(int)EKEYS::K_ESCAPE].keyReleased)
        g_bQuitGame = true;    
}

//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
    case EGAMESTATES::S_SPLASHSCREEN: renderSplashScreen();
        break;
    case EGAMESTATES::S_MAINMENU: renderMainMenu();
        break;
    case EGAMESTATES::S_GAMEOVER: renderGameOver();
        break;
    case EGAMESTATES::S_GAME: renderGame();
        break;
    }
    renderFramerate();      // renders debug information, frame rate, elapsed time, etc
    renderInputEvents();    // renders status of input events
    renderToScreen();       // dump the contents of the buffer to the screen, one frame worth of game
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x0);
}

void loadMainMenu()
{
    _mainmenu.loadmainmenu();
}

void loadGameOver()
{
    _gameover.loadgameover();
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}

void renderSplashScreen()  // renders the splash screen    #Loading screen
{
    splashscreen.renderSplashScreen(g_Console);
}

void renderMainMenu()
{
    _mainmenu.rendermenu(g_Console);
}

void renderGameOver()
{
    _gameover.renderGO(g_Console);
}

void renderGame()
{
    renderUI();
    renderMap();        // renders the map to the buffer first               #323
    renderCharacter();  // renders the character into the buffer             #341
}

void renderUI()
{
    ui.renderlife(g_Console);
    ui.rendermapborder(g_Console);
    _inventory.renderInventory(g_Console);
    ui.renderstate(g_Console);
    ui.renderdisasterindicator(g_Console);
}

void renderMap()
{
    if (map.getMapChange() == true) 
    {
        map.nextlevel();
        //Change to TestMap.csv to well... test your items or something
        //map.loadMap("TestMap.csv", g_sChar, g_sItem);
        map.loadMap("map" + map.getlevel() + ".csv", g_sChar, g_sItem);
    }
    map.DrawMap(g_Console, g_sChar);
}

void renderCharacter()
{
    // Draw the location of the character
    map.DrawPlayer(g_Console, g_sChar, g_sChar.getColor());
}

void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 10;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = g_Console.getConsoleSize().X - 10;;
    c.Y = 1;
    g_Console.writeToBuffer(c, ss.str(), 0x0F);
}

// this is an example of how you would use the input events
void renderInputEvents()
{
    // keyboard events
    COORD startPos = {160, 35};
    std::ostringstream ss;
    std::string key;
    for (int i = 0; i < (int)EKEYS::K_COUNT; ++i)
    {
        ss.str("");
        switch (i)
        {
        case (int)EKEYS::K_W: key = "UP";
            break;
        case (int)EKEYS::K_S: key = "DOWN";
            break;
        case(int)EKEYS::K_A: key = "LEFT";
            break;
        case (int)EKEYS::K_D: key = "RIGHT";
            break;
        case (int)EKEYS::K_TAB: key = "TAB";
            break;
        case (int)EKEYS::K_SPACE: key = "SPACE";
            break;
        default: continue;
        }
        if (g_skKeyEvent[i].keyDown)
            ss << key << " pressed";
        else if (g_skKeyEvent[i].keyReleased)
            ss << key << " released";
        else
            ss << key << " not pressed";

        COORD c = { startPos.X, startPos.Y + i };
        g_Console.writeToBuffer(c, ss.str(), 0x5F);
    }

    // mouse events    
    ss.str("");
    ss << "Mouse position (" << g_mouseEvent.mousePosition.X << ", " << g_mouseEvent.mousePosition.Y << ")";
    g_Console.writeToBuffer(g_mouseEvent.mousePosition, ss.str(), 0x5F);
    ss.str("");
    
    switch (g_mouseEvent.eventFlags)
    {
    case 0:
        if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {      
            switch (_mainmenu.checkButtons(g_mouseEvent.mousePosition))
            {
            case 0:
                g_eGameState = EGAMESTATES::S_GAME;
                break;

            case 4:
                g_bQuitGame = true;
                break;
            }
            
        }
        //else if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED && g_mouseEvent.mousePosition.X == 33 && g_mouseEvent.mousePosition.Y == 25)
        //{
        //   /* ss.str("How to play");
        //    COORD c = {70, 25};
        //    gotoXY(c);
        //    g_Console.writeToBuffer(c, "Survive till the end, Avoid the Disasters using WASD");*/
        //}
        else if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED && g_mouseEvent.mousePosition.X == 33 && g_mouseEvent.mousePosition.Y == 26)
        {
            ss.str("Options");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x5F);
        }
        else if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED && g_mouseEvent.mousePosition.X == 33 && g_mouseEvent.mousePosition.Y == 27)
        {
            ss.str("Credits");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x5F);
        }
        else if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED && g_mouseEvent.mousePosition.X == 33 && g_mouseEvent.mousePosition.Y == 28)
        {
            ss.str("Leave Game");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x5F);
        }
        else
        {
            ss.str("Some Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 3, ss.str(), 0x5F);
        }
        break;
   /* case DOUBLE_CLICK:
        ss.str("Double Clicked");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 4, ss.str(), 0x5F);
        break;        
    case MOUSE_WHEELED:
        if (g_mouseEvent.buttonState & 0xFF000000)
            ss.str("Mouse wheeled down");
        else
            ss.str("Mouse wheeled up");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 5, ss.str(), 0x5F);
        break;*/
    default:        
        break;
    }
    
}



