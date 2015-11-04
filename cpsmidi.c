#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
  double semitoneratio, c0,c5,frequency;
  int midinote;

  /* these next 3 lines of code calculate the semitone ratio
  and the base midi scale for further calculating */
  semitoneratio = pow(2.0, 1.0/12.0);
  c5 = 220.0 * pow(semitoneratio, 3.0);
  c0 = c5 * pow(0.5, 5.0);

  /* if the program is not called cpsmidi, either change the lines below,
  or use the argv[0] system */
  if(argc != 2){
    printf("%s : converts MIDI note to frequency.\n", argv[0]);
    printf("usage: %s MIDInote\n", argv[0]);
    printf("range: 0 <= MIDInote <= 127\n");
    return 1;
  }
  midinote = atoi(argv[1]);
  if(midinote < 0){
    printf("Bad MIDI note value: %s\n", argv[1]);
    return 1;
  }
  if(midinote > 127){
    printf("%s is beyond the MIDI range!\n", argv[1]);
    return 1;
  }
  // formula for converting midi note number to frequency in hertz
  frequency = c0 * pow(semitoneratio, midinote);

  // ex 1.3.4 a) removing  final double quotation mark from printf
  // compiler message: missing terminating " as well as errors
  // for b) missing variable name in format specifier: a warning was
  // generated but still compiled. program does not output correct nums
  printf("frequency of MIDI note %d = %f\n", midinote, frequency);
  return 0;
}
