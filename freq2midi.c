#include <stdio.h>
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

  semitone_ratio = pow(2.0, 1.0/12.0);

  c5 = 220.0 * pow(semitone_ratio, 3.0);
  c0 = c5 * pow(0.5, 5.0);

  frequency = 460.0;
  fracmidi = log(frequency / c0) / log(semitone_ratio);
  //calculating nearest midi notes +-
  midinote1 = (int) (fracmidi + 0.5);
  midinote2 = (int) (fracmidi - 0.5);
  //calculating nearby frequencies
  freq1 = c0 * pow(semitone_ratio, midinote1);
  freq2 = c0 * pow(semitone_ratio, midinote2);
  //calculating pitch bend of nearest midi note
  bend = 100 *((frequency - freq1)/(freq1 - freq2));


  printf("The nearest MIDI note to the frequency %f is %d\n", frequency, midinote1);
  printf("with a pitchbend of %d%%\n", bend);
  return 0;
}
