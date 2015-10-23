#include <stdio.h>
#include <math.h>

int main()
{
  double semitone_ratio;
  double frequency;
  int midinote;

  semitone_ratio = pow(2.0, 1.0/12.0);

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
