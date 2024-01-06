struct nota{
  double tono;
  double duracion;
};

const int spin = 11; // Definir salida por el pin 11
const int ledBlanco = 9;
const int ledRojo = 4;

double  LAS_1 = 466.16, SIB_1 = LAS_1, // Definir frecuencia de las notas
        SI_1 = 493.88,
        DO=523,
        DOS=554,
        RE=587,
        RES=622, MIB=RES,
        MI=659.26,
        FA=698.46,
        FAS=739.99,
        SOL=783.99,
        SOLS=830.61, LAB = SOLS,
        LA=880,
        LAS=932.33, SIB=LAS,
        SI=987.77,
        DO2 = 1046.5,
        DOS2 = 1108.73,
        RE2=1174.66,
        RES2 = 1244.51,
        MI2 = 1318.51,
        FA2 = 1396.91, MIS2 = FA2,
        FAS2=1479.98,
        SOL2 = 1567.98,
        SOLS2 = 1661.22,
        LA2 = 1760,
        LAS2 = 1864.66,
        SI2 = 1975.53,
        S=0; // Silencio

double b=1000, n=500, c=250, sc=125; // Definir los tiempos de blanca, negra, corchea y semicorchea
double np = 750, cp = c+sc; // negra con punto, corchea con punto

double tempo = 1.1;

nota melodia[] = {
  {MI,sc},{SOL,sc},{SI,sc},//
  {MI2,sc},{SI,sc},{SOL,sc},{SI,sc},{MI2,sc},{SI,sc},{SOL,sc},{MI2,sc},
  {RE2,sc},{SI,sc},{SOL,sc},{SI,sc},
  {RE2,sc},{SI,sc},{SOL,sc},{SI,sc},//
  {MI2,sc},{SI,sc},{SOL,sc},{SI,sc},{MI2,sc},{SI,sc},{SOL,sc},{MI2,sc},
  {RE2,c},{SI,c},{SI,n},

  {MI2,sc},{SI,sc},{SOL,sc},{SI,sc},{MI2,sc},{SI,sc},{SOL,sc},{MI2,sc},
  {RE2,sc},{SI,sc},{SOL,sc},{SI,sc},
  {RE2,sc},{SI,sc},{SOL,sc},{SI,sc},//
  {MI2,sc},{SI,sc},{SOL,sc},{SI,sc},{MI2,sc},{SI,sc},{SOL,sc},{MI2,sc},
  {RE2,c},{SI,c},{SI,n},//
  {S,c},{SI,c},{LA,c},{LA,sc},{RE2,c},{SI,c},{SOL,sc},{LA,sc},{SI,sc},{SI,sc},

  {S,c},{SI,c},{LA,c},{FAS,sc},{SOL,c},{MI,c},{MI,sc},{SOL,sc},{SI,sc},{MI,c},//
  {S,c},{SI,c},{LA,c},{LA,sc},{RE,c},{SI,c},{SOL,sc},{LA,sc},{SI,sc},{SI,c},//
  {S,c},{SI,c},{LA,c},{FAS,sc},{SOL,c},{MI,c},{MI,sc},{SOL,sc},{SI,sc},{MI,c},

  {MI2,n},{RE2,n},{MI2,n},{S,sc},{MI,sc},{SOL,sc},{SI,sc},//
  {MI2,n},{RE2,n},{MI2,n},{S,sc},{MI,sc},{SOL,sc},{SI,sc},//
  {MI2,c},{MI2,c},{RE2,c},{RE2,sc},{MI2,c+sc},{S,sc},{MI,sc},{SOL,sc},{SI,sc},//

  {MI2,c},{MI2,c},{RE2,c},{FAS2,sc},{MI2,c},{SI,c},{SI,sc},{SOL2,c},{MI2,c},//
  {RE2,c},{RE2,c},{DO2,c},{DO2,sc},{MI2,c},{SI,c+sc},{S,sc},{MI,sc},{SOL,sc},{SI,sc},//
  {MI2,c},{MI2,c},{RE2,c},{FAS2,sc},{MI2,c},{SI,c},{SI,sc},{SOL2,c},{MI2,c},//

  {RE2,c},{RE2,c},{DO2,c},{DO2,sc},{MI2,c},{SI,c+sc},{S,sc},{MI,sc},{SOL,sc},{SI,sc},//
  {RE2,c},{RE2,c},{DO2,c},{DO2,sc},{MI2,c},{SI,c},{SI,sc},{SOL2,c},{MI2,c},//
  {RE2,c},{RE2,c},{DO2,c},{DO2,sc},{MI2,c},{SI,c+sc},{S,sc},{MI,sc},{SOL,sc},{SI,sc},//

  {RE2,c},{RE2,c},{DO2,c},{DO2,sc},{MI2,c},{SI,c},{SI,sc},{SOL2,c},{MI,c},//
  {RE2,c},{RE2,c},{DO2,c},{DO2,sc},{MI2,c},{SI,c},{MI2,sc},{SOL2,c},{SI2,c},//
  {S,c},{SI2,c},{LA2,c},{LA2,sc},{SI2,c},{SOL2,c},{MI2,sc},{SOL2,c},{SI2,c},//

  {S,c},{SI2,c},{LA2,c},{LA2,sc},{SI2,c},{SOL2,c},{MI2,sc},{SOL2,c},{SI2,c},//
  {S,c},{SI2,c},{LA2,c},{LA2,sc},{SI2,c},{SOL2,c},{MI2,sc},{SOL2,c},{SI2,c},//
  {S,c},{SI2,c},{LA2,c},{LA2,sc},{SI2,c},{SOL2,n},{S,b}//
};

int longitud = sizeof(melodia)/sizeof(*melodia);

void setup() {
  pinMode(spin, OUTPUT);
  pinMode(ledBlanco, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop() {
  for (int notaActual = 0; notaActual < longitud; notaActual++) {
    tone( spin, melodia[notaActual].tono ); // Esta línea da el tono a la frecuencia de la nota
    if (melodia[notaActual].tono > 950){
      digitalWrite(ledBlanco, HIGH);
    } else {
      digitalWrite(ledRojo, HIGH);
    }
    delay( melodia[notaActual].duracion*tempo); // Se toca la nota el tiempo definido para ella

    digitalWrite(ledBlanco, LOW);
    digitalWrite(ledRojo, LOW);
    noTone( spin );
    delay( 7 ); // Necesario para que notas consecutivas no suenen como una sola
  }
}
