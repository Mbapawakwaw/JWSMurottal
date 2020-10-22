
// implement a notification class,
// its member methods will get called 
//
class Mp3Notify
{
public:
  static void OnError(uint16_t errorCode)
  {
    // see DfMp3_Error for code meaning
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }
  static void OnPlayFinished(uint16_t track)
  {
    Serial.print("Play finished for #");
    Serial.println(track);  
  }
  static void OnCardOnline(uint16_t code)
  {
    Serial.println("Card online ");
  }
  static void OnUsbOnline(uint16_t code)
  {
    Serial.println("USB Disk online ");
  }
  static void OnCardInserted(uint16_t code)
  {
    Serial.println("Card inserted ");
  }
  static void OnUsbInserted(uint16_t code)
  {
    Serial.println("USB Disk inserted ");
  }
  static void OnCardRemoved(uint16_t code)
  {
    Serial.println("Card removed ");
  }
  static void OnUsbRemoved(uint16_t code)
  {
    Serial.println("USB Disk removed ");
  }
};

// instance a DFMiniMp3 object, 
// defined with the above notification class and the hardware serial class
//
DFMiniMp3<HardwareSerial, Mp3Notify> mp3(Serial);

// Some arduino boards only have one hardware serial port, so a software serial port is needed instead.
// comment out the above definition and uncomment these lines
//SoftwareSerial secondarySerial(10, 11); // RX, TX
//DFMiniMp3<SoftwareSerial, Mp3Notify> mp3(secondarySerial);

uint16_t volume;
uint16_t currentTrack;

void mulaiMP3() {

  
  mp3.begin();
  mp3.reset(); 
  
  // show some properties and set the volume   
  
  uint16_t count = mp3.getTotalTrackCount();
  Serial.print("files ");
  Serial.println(count);

  uint16_t mode = mp3.getPlaybackMode();
  Serial.print("playback mode ");
  Serial.println(mode);
  
  Serial.println("starting...");
  
  mp3.setEq(DfMp3_Eq_Classic); // _Normal, _Pop, _Rock, _Jazz, _Classic, _Bass
  //mp3.playRandomTrackFromAll(); // random of all folders on sd
  //mp3.playFolderLoop(2);
  
}
