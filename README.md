# The Fun Autoclicker

The Fun Autoclicker is an app made using Qt. It allows users to automate and customize mouse clicks in order to make clicking tasks more fun and efficient. Click up to 500 clicks per second consistently across all windows!

# Build Instructions

The Fun Autoclicker is built using the Qt Community Edition, which means it must be compiled within Qt Creator. Follow the steps below to set up and build the application.

### 1. Download and Install Qt Creator

If you haven't already, download Qt Creator from the official [Qt Developer Page](https://www.qt.io/download-dev) and this repository.

### 2. Clone the Repository in Qt Creator
1. Open Qt Creator.
2. Click "New Project" in the top left corner.
3. Select "Import Project" > "Git Clone".
4. In the Repository URL field, paste the link to this repository.
5. Click "Configure Project" after all directory options have been completed.

### 3. Build the Project
1. Once the project is loaded, locate the Build button in the bottom-left corner.
2. Click the Build button to compile the application.
3. This will compile a .exe file, ready for execution.

# The Application

<p align="center">
  <img src="https://github.com/user-attachments/assets/b3b54a38-1947-4083-9045-fa42aa0cfcd1" width="500" />
</p>

The Fun Autoclicker has many different forms of customizeability.

## The Click

The clicks from the autoclicker are done by using the Windows `mouse_event` to make a customized click. This ____ allows for precise click simulations anywhere on the screen. This is done within the `performClick` function which also takes into account many other customizeable factors which can be chosen based on many of the features described below.

## The Toggle Key

The toggle key is how this application toggles between clicking and not clicking. The user may choose which key they wish to use as a toggle key by pressing the 'Set toggle key' button and then pressing their desired key. This key will then be used to enable or disable the autoclicker.

This feature involves using a low-level keyboard hook (`LowLevelKeyboardProc` in `mainwindow.cpp`) as a listener for key presses globally. This allows the user to disable or enable the autoclicker, even when the application isn't in focus. To increase accuracy, the toggle key is set using Qt's `KeyPressEvent`. Due to this, the keyboard hook uses a conversion function from virtual keys to Qt keys found in the `keyconvert.cpp` file.

Uninitialized toggle key:

<p align="center">
  <img src="https://github.com/user-attachments/assets/ce6d924f-4794-4fbe-b6b7-9cd28afaf495" width="300" />
</p>

Initialized toggle key (can still be changed):

<p align="center">
  <img src="https://github.com/user-attachments/assets/8cfe89a9-089c-4a2f-aba0-04230a622521" width="300" />
</p>

## Click Type

The click type button is how the application checks which type of click it should be making. The user may choose which click type they desire by clicking on the corresponding click type button. This button cycles through the left click, right click, and middle click options.

This feature is done by using an enum class called `Click_Type`, which has possible values of LEFT, RIGHT, or MIDDLE. A variable of this class, called `click_type` is then used by the functions driving the accessible button and the click performance function to make the same type of click as the user desires.

<p align="center">
  <img src="https://github.com/user-attachments/assets/8a96ef20-aae5-4913-ac40-fea1df199a78" width="300" />
</p>

## Click Speed

The click speed line edit determines how fast the application will be clicking. This setting allows the user to set the applications click speed to any integer value between 1 and 999 clicks per second. Unfortunately, the higher the clicks per second value, the less accurate the clicking is due to limits of the actual code. Despite this, there seems to be extremely high accuracy up to several hundred clicks per second.

This feature is done by utilizing a QTimer called `clickTimer`. This QTimer's interval is changed upon the change to the 'cps' line edit. Every [1 / CPS] seconds, the QTimer uses the `performClick` function to perform the customized click.

<p align="center">
  <img src="https://github.com/user-attachments/assets/0032e4d6-53b5-4abf-bbbd-78c1dd51787d" width="300" />
</p>


## Click Location

The Click Location box includes several different features.
<p align="center">
  <img src="https://github.com/user-attachments/assets/34f84add-3763-4ed4-8000-7f84b396705a" width="500" />
</p>

### Match Cursor

The "Match Cursor" setting can be chosen opposed to the "Specific Location" setting. The "Match Cursor" setting allows the autoclicker to click wherever the user's cursor is.

This is done by setting the `mouse_event` coordinates so that it matches the cursor's coordinates.

### Specific Location

The "Specific Location" setting can be chosen opposed to the "Match Cursor" setting and allows the user to set a specific location that automated clicks should take place. By using this setting, the user can set specific coordinates for the clicking to take place. These coordinates range from 0 to the corresponding screen's corresponding dimension size (e.g. 1080p screens will allow X values to range between 1 and 1920 and Y values to range between 1 and 1080.) The application will change the value to whatever the maximum value allowed by the screen is upon requests larger than the maximums.

This feature is done by setting the integer variables `pos_X` and `pos_Y` to the X and Y values provided in the line edits respectively. To determine the maximum screen size, the `screen_height` and `screen_width` integer values are initialized using the Windows GetSymetricMetrics function.

### Choose Location

The "Choose Location" button is enabled upon the "Specific Location" setting being chosen. This button, when clicked, allows the user to press the 'c' key in order to choose wherever they wish to click. Once the 'c' key is pressed, the X and Y coordinates are set to wherever the cursor is.

This feature is done by setting the integer variables `pos_X` and `pos_Y` to wherever the cursor is upon the 'c' key being pressed.

## Click Amount

The Click Amount box includes two different features.
<p align="center">
  <img src="https://github.com/user-attachments/assets/3d01cda3-d0f1-4e24-b8e0-4be42a3c6142" width="300" />
</p>

### Infinite Mode

The "Infinite" setting can be chosen opposed to the "Finite" setting. The "Infinite" setting allows for a practically infinite amount of clicks to be performed without clicking being toggled off.

This feature is done by setting the `total_clicks` variable to the maximum integer value. This variable is checked within the `performClick` function and allows for infinite clicks within any practical timeframe.

### Finite Mode

The "Finite" setting can be chosen opposed to the "Infinite" setting. The "Finite" setting allows for the user to specify the amount of clicks they wish the application to make and no more than that. This is done by editing the "Total Clicks" line edit to any integer value between 0 and 99,999.

This feature is done by setting the `total_clicks` variable to the integer value provided in the "Total Clicks" line edit. This variable is checked within the `performClick` function and will toggle off clicking once the specified click amount is reached.

## Click Interval

The Click Interval box includes two different features.
<p align="center">
  <img src="https://github.com/user-attachments/assets/5cb437bc-5dfe-4b2f-802d-aaaf255585cb" width="650" />
</p>

### Click Indefinitely

The "Click Indefinitely" setting can be chosen opposed to the "Click for this amount of time" setting. The "Click Indefinitely" setting allows for clicking within a practically infinite timeframe.

This feature is done by setting the `total_interval` variable to the maximum integer value. This variable is checked within the `performClick` function and allows for clicks within a practically infinite timeframe.

### Click For Set Amount Of Time

The "Click for this amount of time" setting can be chosen opposed to the "Click Indefinitely" setting. This setting allows for clicking to only be done within a specific interval of time unless toggled off. This interval can be up to 24 hours and is chosen using the hours, minutes, seconds, and milliseconds line edits.

This feature is done by setting the `total_interval` variable to the sum of weighted time values provided by the user. This variable is then checked within the `performClick` function and will toggle off clicking once the specified interval has been completed.

## Fun Time

The Fun Autoclicker also has a "Fun Time" mode. This mode allows for up to six possible sounds to be played upon simulated clicks.

This feature utilizes a QMediaPlayer called `soundPlayer` to play random sounds.
<p align="center">
  <img src="https://github.com/user-attachments/assets/85e2ac55-1cca-4955-ae12-7cdb9706162d" width="650" />
</p>

### Fun Time Toggle

Fun Time can be toggled on or off with the "Fun Time ON" and "Fun Time OFF" buttons.

This is simply done by changing the `fun_time` boolean variable which is checked within the `performClick` function before possibly playing sounds.

### Volume

The volume of Fun Time sounds can be modified using the "Volume" slider. This slider ranges between 0 and 99 and directly controls the volume of all possible Fun Time sounds.

This feature is done by changing the volume value of `soundPlayer` to 0.01 times the slider's value.

### The Sounds

The possible sounds played by Fun Time can be selected from the checkboxes within the "Fun Time Sounds" box. One of the sounds from the sounds selected by the user will be randomly played for every click while Fun Time is enabled. No sounds will be played if no sounds are selected.

This feature is done by adding the sounds selected by the user to a QSet and randomly choosing a sound from its values. This is done within the `performClick` function. If the QSet is empty, then the application will not try to play a sound from the set in order to avoid errors.
