#define ECHOPIN 2 // Pin untuk menerima pulsa echo
#define TRIGPIN 3 // Pin untuk mengirim pulsa trigger
void setup(){
Serial.begin(9600); // Memulai komunikasi dengan kecepatan transmisi 9600 baud
pinMode(ECHOPIN, INPUT); // Konfigurasi pin 2 sebagai input
}
void loop(){
// Deklarasi variabel
int waktu = 0;
int jarak = 0;
// Pembangkitan gelombang kotak selama 10 mikrosekon pada pin 3
tone(TRIGPIN,40000);
delayMicroseconds(10);
// Membuat nilai 0 pada triggerpin selama 2 mikrosekon
noTone(TRIGPIN);
delayMicroseconds(2);
// Membaca durasi pulsa saat keadaan HIGH pada pin 2
waktu = pulseIn(ECHOPIN, HIGH);
// Kalkulasi jarak
jarak = (waktu/58.82);
// Menampilkan pada Serial Monitor
Serial.print("Jarak: ");
Serial.print(jarak);
Serial.println("cm");
// Menunggu 50 milisekon untuk kembali ke perintah awal dari loop
delay(50);
}
