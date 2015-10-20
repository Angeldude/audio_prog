#include <stdio.h>
#include <math.h>

int main()
{
  double semitone_ratio;
  double c0;
  double c5;
  double fracmidi;
  double frequency;
  int midinote;

  semitone_ratio = pow(2.0, 1.0/12.0);

  c5 = 220.0 * pow(semitone_ratio, 3.0);
  c0 = c5 * pow(0.5, 5.0);

  frequency = 400.0;
  fracmidi = log(frequency / c0) / log(semitone_ratio);
  midinote = (int) (fracmidi + 0.5);


  printf("The nearest MIDI note to the frequency %f is %d\n", frequency, midinote);
  return 0;
}
