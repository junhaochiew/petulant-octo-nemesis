#define SH_CP_PORT PORTD
#define ST_CP_PORT PORTD
#define DS_PORT PORTD
#define SH_CP_PIN 5
#define ST_CP_PIN 6
#define DS_PIN 7

#define SH_CP_high() SH_CP_PORT |= _BV(SH_CP_PIN)
#define SH_CP_low() SH_CP_PORT &= ~_BV(SH_CP_PIN)
#define ST_CP_high() ST_CP_PORT |= _BV(ST_CP_PIN)
#define ST_CP_low() ST_CP_PORT &= ~_BV(ST_CP_PIN)
#define DS_high() DS_PORT |= _BV(DS_PIN)
#define DS_low() DS_PORT &= ~_BV(DS_PIN)
#define test(bits) (1 << bits)

void setup() {
  Serial.begin(9600);
  Serial.print("test(24)= ");
  Serial.println(test(16));
  Serial.print("_BV(0) & 9= ");
  Serial.println(_BV(0) & 9);
  
  pinMode(SH_CP_PIN, OUTPUT);
  pinMode(ST_CP_PIN, OUTPUT);
  pinMode(DS_PIN, OUTPUT);
  
//  customShift(0, 8);
//  customShift(0, 8);
//  customShift(B10101010, 8);
  
  //byte val = 1;
  byte val = _BV(0) + _BV(4);
  for (int i = 0; i != 2047; ++i) {
    ST_CP_low();
    
    for (int j = 0; j != 4; ++j)
//      shiftOut(DS_PIN, SH_CP_PIN, LSBFIRST, val);
      customShift(val, 8);

    ST_CP_high();
    //val = (val << 1 | val >> 3) & B00001111;
    val = (val << 1 | val >> 7);
    delay(25);
  }
  
  customShift(0, 8);
  customShift(0, 8);
  customShift(0, 8);
  customShift(0, 8);
  ST_CP_low();
  ST_CP_high();
}

void loop() {}

void customShift(const unsigned long& val, const int& bits) {
//  Serial.print("val: ");
//  Serial.println(val);
  for (int i = 0; i < bits; ++i) {
    if ((_BV(i) & val) == _BV(i)) {
      //Serial.print(1);
      DS_high();
    } else {
      //Serial.print(0);
      DS_low();
    }
    SH_CP_high();
    SH_CP_low();    
  }
}
