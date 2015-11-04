#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double semitone_ratio;
  double c0;
  double c5;
  double fracmidi;
  double frequency;
  double freq1;
  double freq2;
  int bend;
  int midinote1;
  int midinote2;
  char message[256];

  // base calulations for conversion from frequency to midi
  semitone_ratio = pow(2.0, 1.0/12.0);
  c5 = 220.0 * pow(semitone_ratio, 3.0);
  c0 = c5 * pow(0.5, 5.0);

  // getting user input and testing input
  printf("Please enter a frequency range of 8 to 12543.853951 hz:\n");
  if(gets(message) == NULL){
    printf("There was an error reading the input.\n");
    return 1;
  }
  if(message[0] == '\0'){
    printf("Have a nice day!\n");
    return 1;
  }
  frequency = atof(message);
  if(frequency < 8){
    printf("%s hz goes below MIDI range.\n", message);
    return 1;
  }
  fracmidi = log(frequency / c0) / log(semitone_ratio);
  //calculating nearest midi notes +-
  midinote1 = (int) (fracmidi + 0.5);
  midinote2 = (int) (fracmidi - 0.5);

  if(frequency > 12543.853951){
    printf("Sorry - %s hz is beyond the MIDI range!\n", message);
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
