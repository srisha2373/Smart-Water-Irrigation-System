String dataString;
char bacaData;
int index1,index2,index3, index4;
String cmd, ssid_name, ssid_pass;

//=== function to print the command list:  
void printHelp(void){
  Serial.println("###### Arduino-ESP8266 Command Test ######");
  Serial.println("Select your command!!");
  Serial.println("a* -> Status Module");
  Serial.println("b* -> Reset Module");
  Serial.println("c* -> Cek Firmware");
  Serial.println("d* -> Cek Wifi Hotspot");
  Serial.println("e* -> Koneksi Wifi (E*SSID*Password Wifi*)");
  Serial.println("f* -> Cek IP Address");
  Serial.println("g* -> Diskonek Wifi");
  Serial.println("?* -> Print pesan ini lagi");
  Serial.println("===========================================");
}

void setup() {
  Serial.begin(115200);
  
  while (!Serial);
  Serial.flush();       
  printHelp();         
}

void loop() {
  while (Serial.available()>0){
    delay(10);
    bacaData = Serial.read();
    Serial.flush(); 
    dataString += bacaData;
   }
   
    if (dataString.length()>0){
        index1 = dataString.indexOf('*');
        index2 = dataString.indexOf('*', index1+1);
        index3 = dataString.indexOf('*', index2+1);
        index4 = dataString.indexOf('*', index3+1);
        
        cmd  = dataString.substring(0, index1);
        ssid_name = dataString.substring(index1+1, index2);
        ssid_pass  = dataString.substring(index2+1, index3);
                
        if(cmd=="e"||cmd=="E"){
         String cmd_connect="AT+CWJAP=\"";
         cmd_connect+=ssid_name;
         cmd_connect+="\",\"";
         cmd_connect+=ssid_pass;
         cmd_connect+="\"";
          Serial.println(cmd_connect);
         delay(500);
         cmd_connect="";
        }
        
         if(cmd=="a"||cmd=="A"){Serial.write("AT\r\n");}
         if(cmd=="b"||cmd=="B"){Serial.write("AT+RST\r\n");}
         if(cmd=="c"||cmd=="C"){Serial.write("AT+GMR\r\n");}
         if(cmd=="d"||cmd=="D"){Serial.write("AT+CWLAP\r\n");}
         if(cmd=="f"||cmd=="F"){Serial.write("AT+CIFSR\r\n");}
         if(cmd=="g"||cmd=="G"){Serial.write("AT+CWQAP\r\n");}
        if(cmd=="?"||cmd=="h"){printHelp();}
        dataString="";
    }
  
     if (Serial.available()) {     // If anything comes in Serial1 (pins 0 & 1)
      Serial.write(Serial.read());   // read it and send it out Serial (USB)
    } 
}