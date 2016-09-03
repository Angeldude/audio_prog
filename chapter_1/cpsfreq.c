#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
  double semitone_ratio, c0, c5, fracmidi, frequency, freq1, freq2;
  int bend;
  int midinote1;
  int midinote2;

  // base calulations for conversion from frequency to midi
  semitone_ratio = pow(2.0, 1.0/12.0);
  c5 = 220.0 * pow(semitone_ratio, 3.0);
  c0 = c5 * pow(0.5, 5.0);

  // command line code

  if(argc != 2){
    printf("%s : converts frequencies to MIDI numbers.\n", argv[0]);
    printf("usage: %s frequencyNumber\n", argv[0]);
    printf("range: 8 - 12543.853951\n");
    return 1;
  }
  frequency = atof(argv[1]);
  if(frequency < 8){
    printf("%s hz goes below MIDI range.\n", argv[1]);
    return 1;
  }
  fracmidi = log(frequency / c0) / log(semitone_ratio);
  //calculating nearest midi notes +-
  midinote1 = (int) (fracmidi + 0.5);
  midinote2 = (int) (fracmidi - 0.5);

  if(frequency > 12543.853951){
    printf("%s hz goes beyond the MIDI range!\n", argv[1]);
    return 1;
  }
  //calculating nearby frequencies
  freq1 = c0 * pow(semitone_ratio, midinote1);
  freq2 = c0 * pow(semitone_ratio, midinote2);
  //calculating pitch bend of nearest midi note
  bend = lround(100 * ((frequency - freq1)/(freq1 - freq2)));


  printf("The nearest MIDI note to the frequency %f is %d\n", frequency, midinote1);
  printf("with a pitchbend of %d%%\n", bend);
  return 0;
}
