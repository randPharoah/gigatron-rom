#ifndef EDITOR_H
#define EDITOR_H

#include <stdint.h>
#include <string>

#ifndef STAND_ALONE
#include <SDL.h>
#endif


#define INPUT_RIGHT   0x01
#define INPUT_LEFT    0x02
#define INPUT_DOWN    0x04
#define INPUT_UP      0x08
#define INPUT_START   0x10
#define INPUT_SELECT  0x20
#define INPUT_B       0x40
#define INPUT_A       0x80

#define HW_PS2_LEFT    1
#define HW_PS2_RIGHT   2
#define HW_PS2_UP      3
#define HW_PS2_DOWN    4
#define HW_PS2_START   7
#define HW_PS2_SELECT  8
#define HW_PS2_INPUT_A 9
#define HW_PS2_INPUT_B 27
#define HW_PS2_CTLR_C  3
#define HW_PS2_CR      13
#define HW_PS2_DEL     127
#define HW_PS2_ENABLE  5
#define HW_PS2_DISABLE 6

#define HEX_BASE_ADDRESS   0x0200
#define LOAD_BASE_ADDRESS  0x0200
#define VARS_BASE_ADDRESS  0x0030
#define VIDEO_Y_ADDRESS    0x0009

#define INPUT_CONFIG_INI  "input_config.ini"


namespace Editor
{
    enum MemoryMode {RAM=0, ROM0, ROM1, NumMemoryModes};
    enum EditorMode {Hex=0, Rom, Load, Dasm, NumEditorModes};
    enum KeyboardMode {Giga=0, PS2, HwGiga, HwPS2, NumKeyboardModes};
    enum FileType {File=0, Dir, Fifo, Link, NumFileTypes};
    enum OnVarType {OnNone=0, OnCpuA, OnCpuB, OnHex, OnVars, OnWatch, NumOnVarTypes};

    struct MouseState
    {
        int _x, _y;
        uint32_t _state;
    };

    struct RomEntry
    {
        uint8_t _type;
        std::string _name;
    };


    int getCursorX(void);
    int getCursorY(void);
    bool getHexEdit(void);
    bool getSingleStepEnabled(void);
    bool getStartMusic(void);

    bool getPageUpButton(void);
    bool getPageDnButton(void);
    bool getDelAllButton(void);

    MemoryMode getMemoryMode(void);
    EditorMode getEditorMode(void);
    KeyboardMode getKeyboardMode(void);
    OnVarType getOnVarType(void);

    uint8_t getMemoryDigit(void);
    uint8_t getAddressDigit(void);
    uint16_t getHexBaseAddress(void);
    uint16_t getVpcBaseAddress(void);
    uint16_t getLoadBaseAddress(void);
    uint16_t getVarsBaseAddress(void);
    uint16_t getSingleStepAddress(void);
    uint16_t getCpuUsageAddressA(void);
    uint16_t getCpuUsageAddressB(void);

    int getBreakPointsSize(void);
    uint16_t getBreakPointAddress(int index);
    void addBreakPoint(uint16_t address);
    void clearBreakPoints(void);

    int getFileEntriesIndex(void);
    int getFileEntriesSize(void);
    FileType getFileEntryType(int index);
    FileType getCurrentFileEntryType(void);
    std::string* getFileEntryName(int index);
    std::string* getCurrentFileEntryName(void);

    int getRomEntriesIndex(void);
    int getRomEntriesSize(void);
    uint8_t getRomEntryType(int index);
    uint8_t getCurrentRomEntryType(int& index);
    std::string* getRomEntryName(int index);
    std::string* getCurrentRomEntryName(int& index);
    int getCurrentRomEntryIndex(void);
    void addRomEntry(uint8_t type, std::string& name);

    void resetEditor(void);
    void setEditorMode(EditorMode editorMode);

    void setCursorX(int x);
    void setCursorY(int y);
    void setHexEdit(bool hexEdit);
    void setStartMusic(bool startMusic);
    void setSingleStepAddress(uint16_t address);
    void setLoadBaseAddress(uint16_t address);
    void setCpuUsageAddressA(uint16_t address);
    void setCpuUsageAddressB(uint16_t address);

    void getMouseState(MouseState& mouseState);
    void getMouseMenuCursor(int& x, int& y, int& cy);

    std::string getBrowserPath(bool removeSlash=false);

    void initialise(void);
    void browseDirectory(void);

#ifndef STAND_ALONE
    void handleGuiEvents(SDL_Event& event);
#endif
    bool handleDebugger(void);
    void handleInput(void);

    void startDebugger(void);
    void resetDebugger(void);
}

#endif