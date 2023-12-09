//program untuk membunyikkan buzzer / alarm

int buzz = 9; //buzzer kutub positif (+) di pin 9
//int length = 16;
//char notes[] = "cdefgabCCbagfedc";
//int beats[] = {1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,4};
//lagu2
int length = 15;
char notes[] = "ccggaagffeeddc";
int beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};
//lagu3
//int length = 8;
//char notes[] = "cegCCgec";
//int beats[] = {1,1,1,4,1,1,1,4};
int tempo = 300;

void playTone(int tone, int duration){
  for (long i=0;i<duration*1000L;i += tone*2){
    digitalWrite(buzz, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzz, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration){
  char names[]= {'c','d','e','f','g','a','b','C'};
  int tones[] = {1915,1700,1519,1432,1275,1136,1014,956};
  for (int i = 0; i<8; i++){
  if(names[i] == note) {
  playTone(tones[i], duration);
  } 
  }
}

void setup() {
  pinMode(buzz, OUTPUT);
}

void loop() {
  for (int i=0; i<length;i++){
    if(notes[i] == ""){
      delay(beats[i]*tempo);
    } else {
      playNote(notes[i],beats[i]*tempo);
    }
    delay(tempo / 2);
  }
}