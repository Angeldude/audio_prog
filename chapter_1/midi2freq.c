#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double semitone_ratio, c0,c5,frequency, dummy;
  int midinote;
  char message[256];

  /* these next 3 lines of code calculate the semitone ratio
  and the base midi scale for further calculating */
  semitone_ratio = pow(2.0, 1.0/12.0);
  c5 = 220.0 * pow(semitone_ratio, 3.0);
  c0 = c5 * pow(0.5, 5.0);

  printf("Enter MIDI note (0 - 127): ");
  if(gets(message) == NULL){
    printf("There was an error reading the input.\n");
    return 1;
  }
  if(message[0] == '\0'){
    printf("Have a nice day!\n");
    return 1;
  }

  dummy = atof(message);
  midinote = atoi(message);

  if(dummy != midinote)
  {
    printf("Sorry, MIDI notes can only be integers.");
    return 1;
  }

  if(midinote < 0){
    printf("Sorry - %s is a bad MIDI note number.\n", message);
    return 1;
  }
  if(midinote > 127){
    printf("Sorry - %s is beyond the MIDI range!\n", message);
    return 1;
  }
  // formula for converting midi note number to frequency in hertz
  frequency = c0 * pow(semitone_ratio, midinote);

  // ex 1.3.4 a) removing  final double quotation mark from printf
  // compiler message: missing terminating " as well as errors
  // for b) missing variable name in format specifier: a warning was
  // generated but still compiled. program does not output correct nums
  printf("frequency of MIDI note %d = %f\n", midinote, frequency);
  return 0;
}
