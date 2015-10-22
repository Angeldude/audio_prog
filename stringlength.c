#include <stdio.h>
#include <math.h>

int main()
{
  double semitone_ratio;
  double c0;
  double c5;
  double frequency;
  int midinote;

  semitone_ratio = pow(2.0, 1.0/12.0);

  c5 = 220.0 * pow(semitone_ratio, 3.0);

  c0 = c5 * pow(0.5, 5.0);

  //string 660cm long will sound at C4
  //A loop will save time from all this typing.
  frequency = 660;
  printf("Length of 660cm string will sound at C4\n");
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will sound a semitone higher\n", frequency);
  frequency = frequency/semitone_ratio;
  printf("Length %fcm will now sound an octave from original\n", frequency);


  return 0;
}
