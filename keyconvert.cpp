#include "keyconvert.h"

// This function converts any virtual key to a QT key and is used in the low-level hook
Qt::Key virtualKeyToQtKey(int vkCode) {
    switch (vkCode) {
    // Letters (A-Z)
    case 0x41: return Qt::Key_A;
    case 0x42: return Qt::Key_B;
    case 0x43: return Qt::Key_C;
    case 0x44: return Qt::Key_D;
    case 0x45: return Qt::Key_E;
    case 0x46: return Qt::Key_F;
    case 0x47: return Qt::Key_G;
    case 0x48: return Qt::Key_H;
    case 0x49: return Qt::Key_I;
    case 0x4A: return Qt::Key_J;
    case 0x4B: return Qt::Key_K;
    case 0x4C: return Qt::Key_L;
    case 0x4D: return Qt::Key_M;
    case 0x4E: return Qt::Key_N;
    case 0x4F: return Qt::Key_O;
    case 0x50: return Qt::Key_P;
    case 0x51: return Qt::Key_Q;
    case 0x52: return Qt::Key_R;
    case 0x53: return Qt::Key_S;
    case 0x54: return Qt::Key_T;
    case 0x55: return Qt::Key_U;
    case 0x56: return Qt::Key_V;
    case 0x57: return Qt::Key_W;
    case 0x58: return Qt::Key_X;
    case 0x59: return Qt::Key_Y;
    case 0x5A: return Qt::Key_Z;

        // Numbers (0-9)
    case 0x30: return Qt::Key_0;
    case 0x31: return Qt::Key_1;
    case 0x32: return Qt::Key_2;
    case 0x33: return Qt::Key_3;
    case 0x34: return Qt::Key_4;
    case 0x35: return Qt::Key_5;
    case 0x36: return Qt::Key_6;
    case 0x37: return Qt::Key_7;
    case 0x38: return Qt::Key_8;
    case 0x39: return Qt::Key_9;

        // Function Keys (F1-F24)
    case VK_F1: return Qt::Key_F1;
    case VK_F2: return Qt::Key_F2;
    case VK_F3: return Qt::Key_F3;
    case VK_F4: return Qt::Key_F4;
    case VK_F5: return Qt::Key_F5;
    case VK_F6: return Qt::Key_F6;
    case VK_F7: return Qt::Key_F7;
    case VK_F8: return Qt::Key_F8;
    case VK_F9: return Qt::Key_F9;
    case VK_F10: return Qt::Key_F10;
    case VK_F11: return Qt::Key_F11;
    case VK_F12: return Qt::Key_F12;
    case VK_F13: return Qt::Key_F13;
    case VK_F14: return Qt::Key_F14;
    case VK_F15: return Qt::Key_F15;
    case VK_F16: return Qt::Key_F16;
    case VK_F17: return Qt::Key_F17;
    case VK_F18: return Qt::Key_F18;
    case VK_F19: return Qt::Key_F19;
    case VK_F20: return Qt::Key_F20;
    case VK_F21: return Qt::Key_F21;
    case VK_F22: return Qt::Key_F22;
    case VK_F23: return Qt::Key_F23;
    case VK_F24: return Qt::Key_F24;

        // Modifier Keys
    case VK_SHIFT: return Qt::Key_Shift;
    case VK_CONTROL: return Qt::Key_Control;
    case VK_MENU: return Qt::Key_Alt;
    case VK_LSHIFT: return Qt::Key_Shift;
    case VK_RSHIFT: return Qt::Key_Shift;
    case VK_LCONTROL: return Qt::Key_Control;
    case VK_RCONTROL: return Qt::Key_Control;
    case VK_LMENU: return Qt::Key_Alt;
    case VK_RMENU: return Qt::Key_Alt;
    case VK_CAPITAL: return Qt::Key_CapsLock;
    case VK_TAB: return Qt::Key_Tab;
    case VK_RETURN: return Qt::Key_Return;
    case VK_ESCAPE: return Qt::Key_Escape;
    case VK_SPACE: return Qt::Key_Space;

        // Arrow Keys
    case VK_LEFT: return Qt::Key_Left;
    case VK_RIGHT: return Qt::Key_Right;
    case VK_UP: return Qt::Key_Up;
    case VK_DOWN: return Qt::Key_Down;

        // Special Keys
    case VK_BACK: return Qt::Key_Backspace;
    case VK_INSERT: return Qt::Key_Insert;
    case VK_DELETE: return Qt::Key_Delete;
    case VK_HOME: return Qt::Key_Home;
    case VK_END: return Qt::Key_End;
    case VK_PRIOR: return Qt::Key_PageUp;  // Page Up
    case VK_NEXT: return Qt::Key_PageDown; // Page Down
    case VK_PAUSE: return Qt::Key_Pause;
    case VK_PRINT: return Qt::Key_Print;
    case VK_SNAPSHOT: return Qt::Key_Print;

        // OEM Special Characters
    case VK_OEM_1: return Qt::Key_Semicolon;     // ;
    case VK_OEM_PLUS: return Qt::Key_Equal;      // =
    case VK_OEM_COMMA: return Qt::Key_Comma;     // ,
    case VK_OEM_MINUS: return Qt::Key_Minus;     // -
    case VK_OEM_PERIOD: return Qt::Key_Period;   // .
    case VK_OEM_2: return Qt::Key_Slash;        // /
    case VK_OEM_3: return Qt::Key_QuoteLeft;    // `
    case VK_OEM_4: return Qt::Key_BracketLeft;  // [
    case VK_OEM_5: return Qt::Key_Backslash;
    case VK_OEM_6: return Qt::Key_BracketRight; // ]
    case VK_OEM_7: return Qt::Key_Apostrophe;   // '

        // Numpad Keys
    case VK_NUMPAD0: return Qt::Key_0;
    case VK_NUMPAD1: return Qt::Key_1;
    case VK_NUMPAD2: return Qt::Key_2;
    case VK_NUMPAD3: return Qt::Key_3;
    case VK_NUMPAD4: return Qt::Key_4;
    case VK_NUMPAD5: return Qt::Key_5;
    case VK_NUMPAD6: return Qt::Key_6;
    case VK_NUMPAD7: return Qt::Key_7;
    case VK_NUMPAD8: return Qt::Key_8;
    case VK_NUMPAD9: return Qt::Key_9;
    case VK_MULTIPLY: return Qt::Key_Asterisk;
    case VK_ADD: return Qt::Key_Plus;
    case VK_SUBTRACT: return Qt::Key_Minus;
    case VK_DECIMAL: return Qt::Key_Period;
    case VK_DIVIDE: return Qt::Key_Slash;

        // Windows Keys
    case VK_LWIN: return Qt::Key_Meta;  // Left Windows Key
    case VK_RWIN: return Qt::Key_Meta;  // Right Windows Key
    case VK_APPS: return Qt::Key_Menu;  // Context Menu Key

    default: return static_cast<Qt::Key>(vkCode);  // Fallback for unknown keys
    }
}
