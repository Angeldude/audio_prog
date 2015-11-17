/* nscale.c Display E.T frequencies for an N-note octave, from a
         given MIDI note */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
  int notes, midinote, i;
  double frequency, ratio;
  double c0, c5;
  double intervals[24];

  if(argc != 3){
    printf("usage: nscale notes midinote\n");
    return 1;
  }
  notes = atoi(argv[1]);
  if(notes < 1){
    printf("Error: notes must be positive\n");
    return 1;
  }
  if(notes > 24){
    printf("Error: maximum value for notes is 24\n");
    return 1;
  }
  midinote = atoi(argv[2]);
  if(midinote < 0){
    printf("Error: cannot have negative MIDI notes!\n");
    return 1;
  }
  if(midinote > 127){
    printf("Error: maximum MIDI note is 127\n");
    return 1;
  }

  ratio = pow(2.0, 1.0/notes);
  /* find Middle C, three semitones above low A = 220 */
  c5 = 220.0 * pow(ratio, 3);
  /* MIDI note 0 is C, 5 octaves below Middle C */
  c0 = c5 * pow(0.5, 5);
  frequency = c0 * pow(ratio, midinote);

  // exercise 1.5.2 a) loop as a while
  i = 0;
  while(i < notes){
    intervals[i] = frequency;
    frequency *= ratio;
    i++;
  }
  i = 0;
  while(i <notes){
    printf("%f\n", intervals[i]);
    i++;
  }

  return 0;
}