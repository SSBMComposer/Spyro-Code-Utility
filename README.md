## Spyro Code Utility

Spyro Code Utility is a tool that allows you to easily and efficiently create 
gameshark codes to instantly load Spyro's position, camera, and angle to a desired location, or to change Spyro's
respawn position, and then instantly kill/respawn him. Similar to a savestate, but can be used to
practice on real hardware! It finds the position from a bizhawk dump file you create.

## 1. Create Bizhawk Dump

This tool does require use of the [BizHawk Emulator](https://github.com/TASVideos/BizHawk/releases/)
to create a RAM dump of your game. This dump will be used to create the codes based on whatever position you choose
First, you open the game in the emulator, and go to the position in-game you want to save.
Then, you create a dump by opening the Hex Editor in Bizhawk by clicking Tools -> Hex Editor. 
While inside the Hex Editor you click File -> Save as Text...
You can name this whatever you want, but remember where you saved it. 

## 2. Choose Game

When you first open the program, you are greeted with a dialog to choose which spyro game
you have saved the dump for/will be creating the code for.
Spyro 3 has two versions, a 1.0 version, and a 1.1 version which is the Collector's Edition/Greatest Hits version. 
It's important to choose the right version as codes for one will not be compatiable with the other.

## 3. Open Bizhawk Dump

After you choose your game, you open your bizhawk dump file with the "Open Bizhawk Dump" button.
You will be greeted with a file browser to open the .txt file you saved.
## 4. Choose Button Combonation
After you open your bizhawk dump, you are greeted with a a dropdown menu to choose your button combination.
This is the button combination you will use to activate your code to load your state or respawn.

## 5a. Generate Code to Teleport Spyro

This button will generate a gameshark code to instantly teleport Spyro's position, angle, and camera to the postion 
you were in when you saved your Bizhawk dump. You activate the code by inputting the button combination you chose above.
The program may freeze for a brief moment while its generating the code.

## 5b. Generate Code to Respawn Spyro

This will generate a gameshark code that will instantly kill, then respawn Spyro at the postion you were in when you 
saved your bizhawk dump. You activate the code by inputting the button combination you chose above.
The program may freeze for a brief moment while its generating the code.

## Conclusion

After you generate your code, you can press Copy to Clipboard to do exactly that, or press reset to start from the beginning
I hope this program helps you in some way! :)

## Credits

This program uses [imgui](https://github.com/ocornut/imgui) as it's GUI Lirbrary
and [imgui filebroswer](https://github.com/AirGuanZ/imgui-filebrowser) as a file browser library for imgui

Shoutouts to Drashed for the help in providing the Spyro 2 death/respawn memory addresses, and the Spyro 2 camera addresses!
